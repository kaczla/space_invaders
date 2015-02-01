#pragma once
#include "SDL/SDL.h"
#ifndef NPC_HPP_
#define NPC_HPP_

class Npc{
	public:
		Npc();
		virtual ~Npc();
		int attackspeed;
		SDL_Rect position;
		int hp;
		int movementspeed;
		int attackdamage;
		virtual void movement(int X, int Y);
		virtual bool check(unsigned int a);
		virtual bool check();
		void setS(int X, int Y);
		bool toDelete;
	protected:
		int s_x,s_y;
};

#endif
