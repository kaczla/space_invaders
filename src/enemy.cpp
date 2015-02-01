#include "enemy.hpp"

inline void Enemy::setType(){
	switch(type_mob){
		case 0:
			movementspeed=1;
			hp=30;
			attackdamage=10;
			attackspeed=2;
			shoted=false;
			break;
		case 1:
			movementspeed=3;
			hp=10;
			attackdamage=10;
			attackspeed=4;
			shoted=false;
			break;
		case 2:
			movementspeed=2;
			hp=15;
			attackdamage=10;
			attackspeed=3;
			shoted=false;
			break;
		case 3:
			movementspeed=1;
			hp=30;
			attackdamage=10;
			attackspeed=2;
			shoted=false;
			break;
		case 4:
			movementspeed=1;
			hp=10;
			attackdamage=20;
			attackspeed=2;
			shoted=false;
			break;
		case 5:
			movementspeed=1;
			hp=50;
			attackdamage=5;
			attackspeed=2;
			shoted=false;
			break;
		case 6:
			movementspeed=2;
			hp=15;
			attackdamage=15;
			attackspeed=3;
			shoted=false;
			break;
		case 7:
			movementspeed=3;
			hp=10;
			attackdamage=5;
			attackspeed=4;
			shoted=false;
			break;
		case 8:
			movementspeed=3;
			hp=5;
			attackdamage=5;
			attackspeed=4;
			shoted=false;
			break;
		case 9:
			movementspeed=2;
			hp=-15;
			attackdamage=0;
			attackspeed=0;
			shoted=true;
			break;
		case 10:
			movementspeed=1;
			hp=-35;
			attackdamage=0;
			attackspeed=0;
			shoted=true;
			break;
		default:
			movementspeed=1;
			hp=5;
			attackdamage=5;
			attackspeed=2;
			shoted=false;
			break;
	}
	if(hp<=0)
		score=-hp;
	else
		score=hp;
	toDelete=false;
}

bool Enemy::checkAmmo(){
	if(type_mob==9 || type_mob==10)
		return true;
	return false;
}

unsigned int Enemy::returnType(){
	return type_mob;
}

Enemy::Enemy(int X, int Y, unsigned int type){
	position.x=X-50;
	position.y=rand()%500+25;
	position.h=0;
	position.w=0;
	type_mob=type;
	setType();
	s_x=X;
	s_y=Y;
	toDelete=false;
}

Enemy::Enemy(unsigned int type){
	position.x=300;
	position.y=300;
	position.h=0;
	position.w=0;
	type_mob=type;
	setType();
	s_x=600;
	s_y=400;
}

void Enemy::movement(){
	position.x-=movementspeed;
}

void Enemy::movement(int X, int Y){
	position.x-=X;
	position.y-=Y;
}

bool Enemy::check(unsigned int a){
	if(position.y+40<=s_y && position.y-1>=0 && position.x-1>=125)
		return true;
	return false;
}

bool Enemy::check(){
	if(position.y+40<=s_y && position.y-1>=0 && position.x-1>=125)
		return true;
	return false;
}
unsigned int Enemy::returnScore(){
	return score;
}
