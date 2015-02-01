#include "player.hpp"

Player::Player(){
	position.x=0;
	position.y=0;
	position.h=0;
	position.w=0;
	movementspeed=2;
	attackdamage=15;
	attackspeed=4;
	hp=100;
	score=0;
	level=1;
	s_x=0;
	s_y=0;
	toDelete=false;
	exp=0;
}
Player::~Player(){

}

inline void Player::movement(int X, int Y){
	position.x+=X;
	position.y+=Y;
}

void Player::setPosition(){
	position.x=100;
	position.y=s_y/2;
}

inline bool Player::check(unsigned int a){
	if(a==1 && position.y+37<=s_y)
		return true;
	else if(a==2 && position.y-1>=0)
		return true;
	else if(a==3 && position.x-1>=0)
		return true;
	else if(a==4 &&position.x+40<=s_x)
		return true;
	else{
		if(position.y+37<=s_y && position.y-1>=0 && position.x-1>=10 && position.x+40<=s_x)
			return true;
	}
	return false;
}

inline bool Player::check(){
	if(position.y+37<=s_y && position.y-1>=0 && position.x-1>=10 && position.x+40<=s_x)
		return true;
	return false;
}

void Player::setStart(){
	level=1;
	exp=0;
	hp=100;
	score=0;
}
