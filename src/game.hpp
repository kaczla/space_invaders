#pragma once
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "engine.hpp"
#include "menu.hpp"
#include "player.hpp"
#include "ammo.hpp"
#include "enemy.hpp"
#include "template.cpp"
#include "stats.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <string>
#ifndef GAME_HPP_
#define GAME_HPP_

class Game{
	public:
		Game(unsigned int X, unsigned int Y);
		Game();
		~Game();
		inline void ShowInfo();
		inline void SetResolution(unsigned int X, unsigned int Y);
		inline bool MenuStart();
		inline bool PauseStart();
		void start();
		inline void GameOver();
		inline bool CheckEnd();
		inline void ShowPlayer();
		inline void Action();
		inline void Help();
	private:
		unsigned int x,y;
		Menu menu;
		Pause pause;
		Player player;
		vector <Ammo> ammo;		//vector <Ammo>::iterator it_ammo;
		vector <Enemy> enemy;		//vector <Enemy>::iterator it_enemy;
		ToFile <int> to_File;
		Stats stats;
		SDL_Surface *pDisplaySurface;
		SDL_Event event;
		SDL_Rect text_where;
		Uint8 *keystate;
		SDL_Color info_color,red_color, other_color;
		clock_t time_game;
		clock_t ready;
		clock_t rand_enemy;
		clock_t rand_item;
		time_t time_start_game;
		time_t time_end_game;
		char up_down;
		unsigned int move_speed_game;
};

#endif
