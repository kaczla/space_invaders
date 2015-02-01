#pragma once
#include "SDL/SDL.h"
#ifndef AMMO_HPP_
#define AMMO_HPP_

class Ammo{
	public:
		SDL_Rect position;
		unsigned int attack;
		Ammo(int X, int Y, char a, unsigned int power, unsigned int speed_ammo);
		Ammo();
		void move();
		bool check(int X);
		char returnLeft_right();
		bool toDelete;
	protected:
		unsigned int speed;
		char left_right;
		void moveLeft();
		void moveRight();
};

#endif
