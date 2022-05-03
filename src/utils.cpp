/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:28:38 by khirsig           #+#    #+#             */
/*   Updated: 2022/05/03 12:11:20 by khirsig          ###   ########.fr       */
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
	data.gameover = 0;
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

static void playerUsePowerUp(Data &data, Player &player)
{
    int powerUpHold = player.getPowerUpHold();
     switch (powerUpHold) {
        case SHIELD :
            player.setShieldTimer(currentTime + 10);
            player.setActiveShield(1);
            player.setPowerUpHold(NONE);
            break ;
        case SKIPMODE :
            player.setMode(STANDARD);
            player.setPowerUpHold(NONE);
            break ;
        case RANDOMDIR :
            for (int i = 0; i < data.circleAmount; ++i)
                data.circle[i].setMoveDir(GetRandomValue(0, 3));
            player.setPowerUpHold(NONE);
            break ;
    }
}

void    usePowerUp(Data &data)
{
    if (IsKeyPressed(KEY_SPACE))
        playerUsePowerUp(data, data.player[0]);
    if (IsKeyPressed(KEY_RIGHT_CONTROL) && data.playerAmount > 1)
        playerUsePowerUp(data, data.player[1]);
    for (int i = 0; i < data.playerAmount; ++i)
    {
        if (data.player[i].getShieldTimer() == currentTime && data.player[i].getActiveShield() == 1)
        {
            data.player[i].setActiveShield(0);
        }
    }
}

void    increaseCircleSpeed(Data &data)
{
    if (data.circle->getIncreaseTime() != currentTime && (currentTime - startTime) % 10 == 0)
    {
        data.circle->setIncreaseTime(currentTime);
        data.circle->addMinSpeed(0.2f);
        data.circle->addMaxSpeed(0.2f);
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
    if (data.difficulty > 18 || data.difficulty < 0)
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
    for (int i = 0; i < data.circleAmount; ++i)
		data.circle[i].resetCircle();
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
    updateWindow(data);
    settings.close();
}
