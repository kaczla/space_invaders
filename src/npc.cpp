#include "npc.hpp"

Npc::Npc(){
	attackspeed=0;
	position.x=0;
	position.y=0;
	position.h=0;
	position.w=0;
	hp=0;
	movementspeed=0;
	attackdamage=0;
	s_x=400;
	s_y=400;
	toDelete=false;
}

Npc::~Npc(){

}
void Npc::movement(int X, int Y){

}

void Npc::setS(int X, int Y){
	s_x=X;
	s_y=Y;
}

bool Npc::check(unsigned int a){
	return false;
}

bool Npc::check(){
	 return false;
 }
