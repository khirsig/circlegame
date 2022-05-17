/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:28:38 by khirsig           #+#    #+#             */
/*   Updated: 2022/05/17 11:41:38 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"
#include <curl/curl.h>

static void    newSettings(Data &data);

float getRandomNumber(float min, float max)
{
    static std::default_random_engine engine;
    static std::uniform_real_distribution<> ret(min, max);
    float test = ret(engine);
    return test;
}

void    setCurrentTime(Data &data)
{
    currentTime = GetTime();
}

void    setStartTime(Data &data)
{
    startTime = GetTime();
}

void    newRound(Data &data)
{
    for (int i = 0; i < data.circleAmount; ++i)
	{
		data.circle[i].activateCircle();
		data.circle[i].resetCircle();
	}
    for (int i = 0; i < data.playerAmount; ++i)
	    data.player[i].setupPlayer();
	data.gameMode = START_SCREEN;
	gameover = 0;
    setStartTime(data);
    setCurrentTime(data);
    data.modeTime = currentTime;
    data.user.elo.change = false;
    updateWindow(data);
}

void    setFPS(Data &data)
{
    currentFPS = GetFPS();
}

void    powerUpSpawn(Data &data)
{
    for (int i = 0; i < data.powerUpAmount; ++i)
    {
        if (data.powerUp[i].getState() == DISABLED && data.powerUp[i].getNextSpawnTime() == currentTime)
        {
            data.powerUp[i].setSpawnTime(currentTime);
            data.powerUp[i].resetPowerUp();
        }
    }
}

void    powerUpDraw(Data &data)
{
    for (int i = 0; i < data.powerUpAmount; ++i)
    {
        int powerUpState = data.powerUp[i].getState();
        if (powerUpState == SPAWNED || powerUpState == DESPAWNING)
        {
            if (currentTime - data.powerUp[i].getSpawnTime() > 7)
            {
                data.powerUp[i].setState(DESPAWNING);
            }
            data.powerUp[i].drawPowerUp();
        }
        if (powerUpState == DESPAWNED)
        {
            data.powerUp[i].setState(DISABLED);
            data.powerUp[i].setNextSpawnTime(currentTime + GetRandomValue(8, 20));
        }
    }
}

void    takePowerUp(Data &data)
{
    for (int j = 0; j < data.playerAmount; ++j)
    {
        for (int i = 0; i < data.powerUpAmount; ++i)
        {
            if (data.powerUp[i].getState() != DISABLED && CheckCollisionCircles(data.player[j].getPos(), data.player[j].getSize(), data.powerUp[i].getPos(), data.powerUp[i].getSize()))
            {
                data.player[j].setPowerUpHold(data.powerUp[i].getID());
                data.powerUp[i].setState(DISABLED);
                data.powerUp[i].setNextSpawnTime(currentTime + GetRandomValue(8, 20));
            }
        }
    }
}

void    increaseCircleSpeed(Data &data)
{
    if (data.circle[0].getIncreaseTime() != currentTime && (currentTime - startTime) % 10 == 0)
    {
        float mod;
        if (currentTime - startTime <= 30)
            mod = 0.2f;
        else
            mod = 0.5f;
        data.circle[0].setIncreaseTime(currentTime);
        data.circle[0].addMinSpeed(mod);
        data.circle[0].addMaxSpeed(mod);
    }
}

static size_t WriteCallback(char *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void    loginServerRequest(Data &data)
{
	std::string prettyJson = JS::serializeStruct(data.user);

    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();

    if(curl) {
      curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
      curl_easy_setopt(curl, CURLOPT_URL, "https://khirsig.de/login");
      curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
      curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
      struct curl_slist *headers = NULL;
      headers = curl_slist_append(headers, "Content-Type: application/json");
      curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
      curl_easy_setopt(curl, CURLOPT_POSTFIELDS, prettyJson.c_str());
      res = curl_easy_perform(curl);
      if (readBuffer == "{\"success\":false}")
      {
          data.gameType = NOGAME;
          data.gameMode = START_SCREEN;
      }
      JS::ParseContext context(readBuffer);
      context.parseTo(data.user);
    }
    curl_easy_cleanup(curl);
}

void    setEloServer(Data &data)
{
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl) {
      curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
      curl_easy_setopt(curl, CURLOPT_URL, "https://khirsig.de/sethighscore");
      curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
      curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
      struct curl_slist *headers = NULL;
	  std::string prettyJson = JS::serializeStruct(data.user);
      headers = curl_slist_append(headers, "Content-Type: application/json");
      curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
      curl_easy_setopt(curl, CURLOPT_POSTFIELDS, prettyJson.c_str());
      res = curl_easy_perform(curl);
    }
    curl_easy_cleanup(curl);
}

void    loginHandler(Data &data)
{
    int		loginStep = 0;
	char	inputChar;
	int		inputKey;
	std::string inputString;
	while (loginStep < 2)
	{
		inputKey = GetKeyPressed();
		if ((inputChar = GetCharPressed()) && isalnum(inputChar) && inputString.length() < 12)
			inputString.push_back(inputChar);
		if (inputKey == KEY_BACKSPACE && inputString.length() > 0)
			inputString.pop_back();
		if (inputKey == KEY_ESCAPE)
			exit(EXIT_SUCCESS);
		if (inputKey == KEY_ENTER && inputString.length() >= 3)
		{
			if (loginStep == 0)
				data.user.username = inputString;
			if (loginStep == 1)
				data.user.password = inputString;
			inputString.clear();
			loginStep++;
		}

		BeginDrawing();
		data.window.ClearBackground(RAYWHITE);
		DrawRectangle(screenWidth / 3, screenHeight / 3 * 2, screenWidth / 3, screenHeight / 14, BLACK);
		DrawText(inputString.c_str(), screenWidth / 3 + screenHeight / 40, screenHeight / 3 * 2 + screenHeight / 36, menuTextSize[1], WHITE);
		switch (loginStep) {
			case 0 :
				DrawText("Please enter your name:", screenWidth / 2 - MeasureText("Please enter your name:", menuTextSize[1]) / 2, screenHeight / 2, menuTextSize[1], BLACK);
				break ;
			case 1 :
				DrawText("Please enter your password:", screenWidth / 2 - MeasureText("Please enter your password:", menuTextSize[1]) / 2, screenHeight / 2, menuTextSize[1], BLACK);
				break ;
		}
		EndDrawing();
	}
	loginServerRequest(data);
    data.user.loggedIn = true;
}

void    updateWindow(Data &data)
{
	menuTextSize = { screenHeight / 8, screenHeight / 24, screenHeight / 36, screenHeight / 16, screenHeight / 28 };
    if ((double)screenWidth / 16 != (double)screenHeight / 9)
        newSettings(data);
	SetWindowSize(screenWidth, screenHeight);
	data.interface.heightStr = std::to_string(screenHeight);
	data.interface.widthStr = std::to_string(screenWidth);
    if (data.difficulty > 18 || data.difficulty < 0 || data.circleAmount < 1 || data.circleAmount > 8)
        newSettings(data);
	data.interface.difCircPos.x = screenWidth / 5 * 3.3 + (screenWidth / 4 / 19) * data.difficulty + (screenWidth / 4 / 19 * 0.5);
    if (data.gameType != RANKEDGAME)
    {
        data.circle[0].setMinSpeed(eloSpeed[data.difficulty]);
        data.circle[0].setMaxSpeed(eloSpeed[data.difficulty] + 1.0f);
    }
    else
    {
        data.circle[0].setMinSpeed(eloSpeed[data.user.elo.rank]);
        data.circle[0].setMaxSpeed(eloSpeed[data.user.elo.rank] + 1.0f);
    }
	data.interface.circAmtCircPos.x = screenWidth / 5 * 3.3 + (screenWidth / 4 / 8) * (data.circleAmount - 1) + (screenWidth / 4 / 8 * 0.5);
    data.circle.clear();
    for (int i = 0; i < data.circleAmount; ++i)
    {
        Circle temp;
        data.circle.push_back(temp);
    }
    for (int i = 0; i < data.circleAmount; ++i)
    {
		data.circle[i].activateCircle();
        data.circle[i].resetCircle();
    }
}

static void    newSettings(Data &data)
{
    std::ofstream settings;
    settings.open("./cfg/settings.cfg", std::ofstream::out | std::ofstream::trunc);
    settings << "width=" << "1408" << std::endl;
    screenWidth = 1408;
    settings << "height=" << "792" << std::endl;
    screenHeight = 792;
    settings << "difficulty=" << "5" << std::endl;
    data.difficulty = 5;
    settings << "circle_amount=" << "4" << std::endl;
    data.circleAmount = 4;
    updateWindow(data);
    settings.close();
}

void    saveSettings(Data &data)
{
    std::ofstream settings;
    settings.open("./cfg/settings.cfg", std::ofstream::out | std::ofstream::trunc);
    settings << "width=" << screenWidth << std::endl;
    settings << "height=" << screenHeight << std::endl;
    settings << "difficulty=" << data.difficulty << std::endl;
    settings << "circle_amount=" << data.circleAmount << std::endl;
    settings.close();
    updateWindow(data);
}

void    loadSettings(Data &data)
{
    std::ifstream settings;
    std::string line;

    settings.open("./cfg/settings.cfg");
    std::getline(settings, line);
    if (line.substr(0, 6) == "width=")
    {
        screenWidth = stoi(line.substr(6, line.length()));
    }
    else
    {
        settings.close();
        newSettings(data);
        return ;
    }
    std::getline(settings, line);
    if (line.substr(0, 7) == "height=")
        screenHeight = stoi(line.substr(7, line.length()));
    else
    {
        settings.close();
        newSettings(data);
        return ;
    }
    std::getline(settings, line);
    if (line.substr(0, 11) == "difficulty=")
        data.difficulty = stoi(line.substr(11, line.length()));
    else
    {
        settings.close();
        newSettings(data);
        return ;
    }
    std::getline(settings, line);
    if (line.substr(0, 14) == "circle_amount=")
        data.circleAmount = stoi(line.substr(14, line.length()));
    else
    {
        settings.close();
        newSettings(data);
        return ;
    }
    updateWindow(data);
    settings.close();
}

bool	moveThroughMenuMouse(int x, int y, int width, int height)
{
	raylib::Vector2 cursor = GetMousePosition();
	if (cursor.x >= x && cursor.x <= x + width && cursor.y >= y && cursor.y <= y + height)
		return true;
	else
		return false;

}

void	checkCircleCollision(Data &data)
{
	for (int a = 0; a < data.circleAmount; ++a)
	{
		for (int b = a + 1; b < data.circleAmount; ++b)
		{
			if (CheckCollisionCircles(data.circle[a].pos, data.circle[a].getCircleSize(), data.circle[b].pos, data.circle[b].getCircleSize()))
			{
                if (data.circle[a].justSpawned == true)
                {
                    data.circle[a].resetCircle();
                    a = 0;
                    b = a + 1;
                }
                else if (data.circle[b].justSpawned == true)
                {
                    data.circle[b].resetCircle();
                    a = 0;
                    b = a + 1;
                }
                else
                {
				    raylib::Vector2 speedA, speedB, axis, speedAPara, speedBPara, speedAOrtho, speedBOrtho, speedAParaWithMass, speedBParaWithMass;
                    double          massA, massB;

                    massA = data.circle[a].getCircleSize() / (data.circle[a].getColInt() + 200);
                    massB = data.circle[b].getCircleSize() / (data.circle[b].getColInt() + 200);
                    speedA = Vector2Scale(data.circle[a].direction, data.circle[a].speed);
                    speedB = Vector2Scale(data.circle[b].direction, data.circle[b].speed);
                    axis = Vector2Normalize(Vector2Subtract(data.circle[a].pos, data.circle[b].pos));
                    speedAPara = Vector2Scale(axis, Vector2DotProduct(axis, speedA));
                    speedBPara = Vector2Scale(axis, Vector2DotProduct(axis, speedB));
                    speedAOrtho = Vector2Subtract(speedA, speedAPara);
                    speedBOrtho = Vector2Subtract(speedB, speedBPara);
                    speedAParaWithMass = (speedAPara * massA + speedBPara * massB) * 2 / (massA + massB) - speedAPara;
                    speedBParaWithMass = (speedAPara * massA + speedBPara * massB) * 2 / (massA + massB) - speedBPara;
                    speedA = speedAParaWithMass + speedAOrtho;
                    speedB = speedBParaWithMass + speedBOrtho;
                    data.circle[a].speed = Vector2Length(speedA);
                    data.circle[b].speed = Vector2Length(speedB);
                    data.circle[a].direction = Vector2Normalize(speedA);
                    data.circle[b].direction = Vector2Normalize(speedB);
                }
			}
		}
	}
    for (int c = 0; c < data.circleAmount; ++c)
        data.circle[c].justSpawned = false;
}
