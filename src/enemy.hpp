#pragma once
#include "npc.hpp"
#include <cstdlib>
#ifndef ENEMY_HPP_
#define ENEMY_HPP_

class Enemy : public Npc{
	public:
		Enemy(int X, int Y, unsigned int type);
		Enemy(unsigned int type);
		void movement(int X, int Y);
		void movement();
		bool check(unsigned int a);
		bool check();
		bool shoted;
		unsigned int returnType();
		unsigned int returnScore();
		bool checkAmmo();
	private:
		void setType();
		unsigned int type_mob;
		unsigned int score;
};

#endif
