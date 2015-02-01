#include "ammo.hpp"

Ammo::Ammo(int X, int Y, char a, unsigned int power, unsigned int speed_ammo){
	this->position.x=X;
	this->position.y=Y;
	if(a!='r' && a!='l')
		this->left_right='r';
	else
		this->left_right=a;
	this->attack=power;
	this->speed=speed_ammo;
	toDelete=false;
}

Ammo::Ammo(){
	this->position.x=0;
	this->position.y=0;
	this->left_right='r';
	this->attack=10;
	this->speed=4;
	toDelete=false;
}

inline void Ammo::moveRight(){
	this->position.x+=this->speed;
}

inline void Ammo::moveLeft(){
	this->position.x-=this->speed;
}

void Ammo::move(){
	if(this->left_right=='l')
		this->moveLeft();
	else
		this->moveRight();
}

bool Ammo::check(int X){
	if(this->position.x>=0 and this->position.x<=X-20)
		return true;
	else
		return false;
}

char Ammo::returnLeft_right(){
	return this->left_right;
}
