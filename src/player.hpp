#pragma once
#include "engine.hpp"
#include "npc.hpp"
#include <string>
#ifndef PLAYER_HPP_
#define PLAYER_HPP_

class Player : public Npc{
	public:
		Player();
		virtual ~Player();
		unsigned int level;
		unsigned int score;
		unsigned int exp;
		std::string nickname;
		void movement(int X, int Y);
		bool check(unsigned int a);
		bool check();
		void setPosition();
		void setStart();
};

#endif
