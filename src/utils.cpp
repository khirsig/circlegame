/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:28:38 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/27 15:03:04 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"
#include <curl/curl.h>

float getRandomNumber(float min, float max)
{
    static std::default_random_engine engine;
    static std::uniform_real_distribution<> ret(min, max);
    return ret(engine);
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
    data.elo.change = false;
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
        data.circle->addMinSpeed(1000.0);
        data.circle->addMaxSpeed(1000.0);
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
      const char *input = prettyJson.c_str();
      curl_easy_setopt(curl, CURLOPT_POSTFIELDS, input);
      res = curl_easy_perform(curl);
      if (readBuffer == "{\"success\":false}")
        exit(EXIT_FAILURE);
      JS::ParseContext context(readBuffer);
      context.parseTo(data.user);
      std::cout << data.user.username << std::endl << data.user.password << std::endl << data.user.elo.rank << std::endl << data.user.elo.points << std::endl;
    }
    curl_easy_cleanup(curl);
}
