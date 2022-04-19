/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadResources.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:30:58 by khirsig           #+#    #+#             */
/*   Updated: 2022/04/19 23:35:36 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "circlegame.hpp"
#include <thread>
#include <mutex>

std::mutex lock;

void	loadModeImg(int i, std::vector<raylib::Texture> &modeImg)
{
	lock.lock();
	std::cout << "Hallo, ich bin ein Thread!" << std::endl;
	lock.unlock();
	std::string temp = "./resources/mode";
	if (i < 10)
	{
		temp += "00";
		temp += std::to_string(i);
		temp += ".png";
	}
	else
	{
		temp += std::to_string(i);
		temp += ".png";
	}
	lock.lock();
	modeImg.insert(modeImg.begin() + i, raylib::Texture(temp));
	lock.unlock();
}

void	loadResources(Data &data)
{
	int	xStart = screenWidth / 10 * 1, xEnd = screenWidth / 10 * 9;
	int	yStart = screenHeight / 10 * 8, yEnd = screenHeight / 10 * 9;
	int	maxWidth = xEnd - xStart;
	int	actualWidth, maxGraphics;
	std::vector<std::thread> threads;

	for (unsigned int loadingStep = 0; loadingStep < 100; loadingStep += 1)
	{
		actualWidth = maxWidth / 100 * loadingStep;
		if (actualWidth > maxWidth)
			actualWidth = maxWidth;
		BeginDrawing();
		data.window.ClearBackground(RAYWHITE);
		DrawRectangle(xStart, yStart, maxWidth, yEnd - yStart, GRAY);
		DrawRectangle(xStart, yStart, actualWidth, yEnd - yStart, RED);
		EndDrawing();
		data.player[0].modeImg[0].reserve(maxGraphics);
		data.player[1].modeImg[1].reserve(maxGraphics);
		switch (loadingStep) {
			case 0:
				data.interface.powerupImg.push_back(raylib::Texture("./resources/powerup00.png"));
				break ;
			case 25:
				maxGraphics = 5;
				for (unsigned int i = 0; i < maxGraphics; ++i)
					threads.push_back(std::thread(loadModeImg, i, std::ref(data.player[0].modeImg[0])));
				for (auto &th : threads)
					th.join();
				break ;
			case 50:
				if (data.playerAmount > 1)
				{
					for (unsigned int i = 0; i < 5; ++i)
					{
						std::string temp = "./resources/mode1";
						if (i < 10)
						{
							temp += "0";
							temp += std::to_string(i);
							temp += ".png";
						}
						else
						{
							temp += std::to_string(i);
							temp += ".png";
						}
						data.player[1].modeImg[1].insert(data.player[1].modeImg[1].begin() + i, raylib::Texture(temp));
					}
				}
				break ;
		}
	}
	data.gameMode = START_SCREEN;
}
