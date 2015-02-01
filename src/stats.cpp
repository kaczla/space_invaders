#include "stats.hpp"

Stats::Stats(){
	this->shoted_ammo=0;
	this->killed_enemy=0;
	this->hit_enemy=0;
	this->items=0;
}

void Stats::setZero(){
	this->shoted_ammo=0;
	this->killed_enemy=0;
	this->hit_enemy=0;
	this->items=0;
}
