#include "game.hpp"

void Game::SetResolution(unsigned int X, unsigned int Y){
	if(X<800)
		x=800;
	else if(X>1440)
		x=1440;
	else
		x=X;

	if(Y<600)
		y=600;
	else if(Y>900)
		y=900;
	else
		y=Y;
}

bool Game::MenuStart(){
	return menu.start(pDisplaySurface,x,y);
}

bool Game::PauseStart(){
	return pause.start(pDisplaySurface,x,y);
}

void Game::GameOver(){
	text_where.x=(int)x/2-80;
	text_where.y=(int)y/2-150;
	TextBold();
	DrawText(pDisplaySurface, "GAME OVER!", red_color, text_where);
	text_where.x+=190;
	text_where.y+=50;
	DrawText(pDisplaySurface, "Ammo: "+toString(stats.shoted_ammo) , other_color, text_where);
	text_where.y+=30;
	DrawText(pDisplaySurface, "Hit: "+toString(stats.hit_enemy) , other_color, text_where);
	text_where.y+=30;
	DrawText(pDisplaySurface, "Killed: "+toString(stats.killed_enemy) , other_color, text_where);
	text_where.x=110;
	text_where.y-=60;
	DrawText(pDisplaySurface, "..: RANKING :..", other_color, text_where);
	for(unsigned int i=0;i<to_File.returnSize();i++){
		text_where.y+=30;
		DrawText(pDisplaySurface, toString(i+1)+") "+to_File.returnName(i)+": "+toString(to_File.returnScore(i)), other_color, text_where);//
	}
	TextNormal();
	SDL_Flip(pDisplaySurface);
	bool exit=true;
	while(exit){
		while(SDL_PollEvent(&event)){
			if(event.type==SDL_QUIT){
				exit=false;
				break;
			}
			if(event.type==SDL_KEYDOWN){
				switch(event.key.keysym.sym){
					case SDLK_ESCAPE:
						exit=false;
						break;
					case SDLK_RETURN:
						exit=false;
						break;
					case SDLK_SPACE:
						exit=false;
						break;
					default:
						break;
				}
			}
		}
	}
}

bool Game::CheckEnd(){
	if(player.hp<=0 or player.level>100){
		to_File.addElement(player.nickname,player.score);
		GameOver();
		return true;
	}
	else if(player.hp<=25 && rand_item<=time_game){
		rand_item=time_game+8000; //srand(time(0));
		enemy.push_back(Enemy(x,y, rand()%2+9));
	}
	else if(player.exp!=0 && player.exp%player.level==0){
		player.exp=0;
		player.level++;
	}
	return false;
}

void Game::Help(){
	DrawBackgroud(pDisplaySurface);
	vector <Enemy> temp;
	SDL_Rect p;
	p.x=(int)x/2-60;
	p.y=10;
	TextBold();
	DrawText(pDisplaySurface, "...:: HELP ::...", red_color, p);
	TextNormal();
	p.x=200;
	p.y=-50;
	for(unsigned int i=0;i<9;i++){
		temp.push_back(Enemy(i));
		if(i%3==0){
			p.y+=150;
			p.x=100;
		}
		else{
			p.x+=200;
		}	//std::cout<<i<<"="<<p.x<<";"<<p.y<<"\n";
		DrawEnemy(pDisplaySurface,p,i);
		p.y+=40;
		DrawTextSmall(pDisplaySurface, "HP: "+toString(temp[i].hp), other_color, p);
		p.y+=14;
		DrawTextSmall(pDisplaySurface, "Attack damage: "+toString(temp[i].attackdamage), other_color, p);
		p.y+=14;
		DrawTextSmall(pDisplaySurface, "Attack speed: "+toString(temp[i].attackspeed), other_color, p);
		p.y+=14;
		DrawTextSmall(pDisplaySurface, "Movement speed: "+toString(temp[i].movementspeed), other_color, p);
		p.y-=82;
	}
	SDL_Flip(pDisplaySurface);
	bool exit=true;
	while(exit){
		while(SDL_PollEvent(&event)){
			if(event.type==SDL_QUIT){
				exit=false;
				break;
			}
			if(event.type==SDL_KEYDOWN){
				switch(event.key.keysym.sym){
					case SDLK_ESCAPE:
						exit=false;
						break;
					case SDLK_RETURN:
						exit=false;
						break;
					case SDLK_F1:
						exit=false;
						break;
					default:
						break;
				}
			}
		}
	}
	temp.clear();
}

void Game::ShowInfo(){
	DrawTextSmall(pDisplaySurface, player.nickname, info_color);
	text_where.x=0;
	text_where.y=14;
	DrawTextSmall(pDisplaySurface, "HP: "+toString(player.hp), info_color, text_where);
	text_where.y=28;
	DrawTextSmall(pDisplaySurface, "SCORE: "+toString(player.score), info_color, text_where);
	text_where.y=42;
	DrawTextSmall(pDisplaySurface, "LEVEL: "+toString(player.level), info_color, text_where);
	text_where.y=56;
	DrawTextSmall(pDisplaySurface, "EXP: "+toString(player.exp*10), info_color, text_where);
	text_where.y=70;
	DrawTextSmall(pDisplaySurface, "X:"+toString(player.position.x)+" Y:"+toString(player.position.y), info_color, text_where);
	text_where.x=x-150;
	text_where.y=0;
	time(&time_end_game);
	time_end_game=time_end_game-time_start_game;	//time_end_game=difftime(time_start_game,time_end_game);
	DrawTimeGame(pDisplaySurface, time_end_game , info_color, text_where);
}

void Game::ShowPlayer(){
	if(up_down=='1')
		DrawPlayer(pDisplaySurface,player.position,1);
	else if(up_down=='2')
		DrawPlayer(pDisplaySurface,player.position,2);
	else if(up_down=='3')
		DrawPlayer(pDisplaySurface,player.position,3);
	else if(up_down=='4')
		DrawPlayer(pDisplaySurface,player.position,4);
	else if(up_down=='5')
		DrawPlayer(pDisplaySurface,player.position,5);
	else if(up_down=='6')
		DrawPlayer(pDisplaySurface,player.position,6);
	else if(up_down=='7')
		DrawPlayer(pDisplaySurface,player.position,7);
	else if(up_down=='8')
		DrawPlayer(pDisplaySurface,player.position,8);
	else
		DrawPlayer(pDisplaySurface,player.position,0);
}

void Game::Action(){
	unsigned int i;
	int tmpX = player.position.x+39;
	int tmpY = player.position.y+36;
	if(player.level>20)
		player.level=20;
	for(i=0;i<ammo.size();i++){
		if(ammo[i].returnLeft_right()=='l'){
			if(player.position.x>=ammo[i].position.x && player.position.x<=ammo[i].position.x+ammo[i].position.w && player.position.y>=ammo[i].position.y && player.position.y<=ammo[i].position.y+ammo[i].position.h){
				player.hp-=ammo[i].attack;
				ammo.erase(ammo.begin()+i);
				break;
			}
			else if(player.position.x>=ammo[i].position.x && player.position.x<=ammo[i].position.x+ammo[i].position.w && tmpY>=ammo[i].position.y && tmpY<=ammo[i].position.y+ammo[i].position.h){
				player.hp-=ammo[i].attack;
				ammo.erase(ammo.begin()+i);
			}
			else if(tmpX>=ammo[i].position.x && tmpX<=ammo[i].position.x+ammo[i].position.w && tmpY>=ammo[i].position.y && tmpY<=ammo[i].position.y+ammo[i].position.h){
				player.hp-=ammo[i].attack;
				ammo.erase(ammo.begin()+i);
				break;
			}
			else if(tmpX>=ammo[i].position.x && tmpX<=ammo[i].position.x+ammo[i].position.w && player.position.y>=ammo[i].position.y && player.position.y<=ammo[i].position.y+ammo[i].position.h){
				player.hp-=ammo[i].attack;
				ammo.erase(ammo.begin()+i);
				break;
			}
			else if(ammo[i].position.x>=player.position.x && ammo[i].position.x<=tmpX && ammo[i].position.y>=player.position.y && ammo[i].position.y<=tmpY){
				player.hp-=ammo[i].attack;
				ammo.erase(ammo.begin()+i);
				break;
			}
			else if(ammo[i].position.x+ammo[i].position.w>=player.position.x && ammo[i].position.x+ammo[i].position.w<=tmpX && ammo[i].position.y+ammo[i].position.h>=player.position.y && ammo[i].position.y+ammo[i].position.h<=tmpY){
				player.hp-=ammo[i].attack;
				ammo.erase(ammo.begin()+i);
				break;
			}
		}
		else if(ammo[i].returnLeft_right()=='r'){
			int tmpX2 = ammo[i].position.x+15;
			int tmpY2 = ammo[i].position.y+3;
			for(unsigned j=0;j<enemy.size();j++){
				if(ammo[i].position.x>=enemy[j].position.x && ammo[j].position.x<=enemy[j].position.x+enemy[j].position.w && ammo[i].position.y>=enemy[j].position.y && ammo[i].position.y<=enemy[j].position.y+enemy[j].position.h){;
					enemy[j].hp-=ammo[i].attack;
					if(enemy[j].hp<=0){
						player.score+=enemy[j].returnScore();
						enemy.erase(enemy.begin()+j);
						stats.killed_enemy++;
						player.exp++;
					}
					player.score++;
					stats.hit_enemy++;
					ammo.erase(ammo.begin()+i);
					break;
				}
				else if(ammo[i].position.x>=enemy[j].position.x && ammo[i].position.x<=enemy[j].position.x+enemy[j].position.w && tmpY2>=enemy[j].position.y && tmpY2<=enemy[j].position.y+enemy[j].position.h){
					enemy[j].hp-=ammo[i].attack;
					if(enemy[j].hp<=0){
						player.score+=enemy[j].returnScore();
						enemy.erase(enemy.begin()+j);
						stats.killed_enemy++;
						player.exp++;
					}
					player.score++;
					stats.hit_enemy++;
					ammo.erase(ammo.begin()+i);
					break;
				}
				else if(tmpX2>=enemy[j].position.x && tmpX2<=enemy[j].position.x+enemy[j].position.w && tmpY2>=enemy[j].position.y && tmpY2<=enemy[j].position.y+enemy[j].position.h){
					enemy[j].hp-=ammo[i].attack;
					if(enemy[j].hp<=0){
						player.score+=enemy[j].returnScore();
						enemy.erase(enemy.begin()+j);
						stats.killed_enemy++;
						player.exp++;
					}
					player.score++;
					stats.hit_enemy++;
					ammo.erase(ammo.begin()+i);
					break;
				}
				else if(tmpX2>=enemy[j].position.x && tmpX2<=enemy[j].position.x+enemy[j].position.w && ammo[i].position.y>=enemy[j].position.y && ammo[i].position.y<=enemy[j].position.y+enemy[j].position.h){
					enemy[j].hp-=ammo[i].attack;
					if(enemy[j].hp<=0){
						player.score+=enemy[j].returnScore();
						enemy.erase(enemy.begin()+j);
						stats.killed_enemy++;
						player.exp++;
					}
					player.score++;
					stats.hit_enemy++;
					ammo.erase(ammo.begin()+i);
					break;
				}
				else if(enemy[j].position.x>=ammo[i].position.x && enemy[j].position.x<=tmpX2 && enemy[j].position.y>=ammo[i].position.y && enemy[j].position.y<=tmpY2){
					enemy[j].hp-=ammo[i].attack;
					if(enemy[j].hp<=0){
						player.score+=enemy[j].returnScore();
						enemy.erase(enemy.begin()+j);
						stats.killed_enemy++;
						player.exp++;
					}
					player.score++;
					stats.hit_enemy++;
					ammo.erase(ammo.begin()+i);
					break;
				}
				else if(enemy[j].position.x+enemy[j].position.w>=ammo[i].position.x && enemy[j].position.x+enemy[j].position.w<=tmpX2 && enemy[j].position.y+enemy[j].position.h>=ammo[i].position.y && enemy[j].position.y+enemy[j].position.h<=tmpY2){
					enemy[j].hp-=ammo[i].attack;
					if(enemy[j].hp<=0){
						player.score+=enemy[j].returnScore();
						enemy.erase(enemy.begin()+j);
						stats.killed_enemy++;
						player.exp++;
					}
					player.score++;
					stats.hit_enemy++;
					ammo.erase(ammo.begin()+i);
					break;
				}
			}
		}
	}
	for(i=0;i<enemy.size();i++){
		if(player.position.x>=enemy[i].position.x && player.position.x<=enemy[i].position.x+enemy[i].position.w && player.position.y>=enemy[i].position.y && player.position.y<=enemy[i].position.y+enemy[i].position.h){
			//std::cout<<"P:"<<tmpX<<";"<<tmpY<<" E"<<i+1<<": "<<enemy[i].position.x<<";"<<enemy[i].position.y<<" x+w: "<<enemy[i].position.x+enemy[i].position.w<<" y+h: "<<enemy[i].position.y+enemy[i].position.h<<"";
			//std::cout<<" HP: "<<hp<<"\n";
			player.hp-=enemy[i].hp;
			enemy.erase(enemy.begin()+i);
			break;
		}
		else if(player.position.x>=enemy[i].position.x && player.position.x<=enemy[i].position.x+enemy[i].position.w && tmpY>=enemy[i].position.y && tmpY<=enemy[i].position.y+enemy[i].position.h){
			player.hp-=enemy[i].hp;
			enemy.erase(enemy.begin()+i);
			break;
		}
		else if(tmpX>=enemy[i].position.x && tmpX<=enemy[i].position.x+enemy[i].position.w && tmpY>=enemy[i].position.y && tmpY<=enemy[i].position.y+enemy[i].position.h){
			player.hp-=enemy[i].hp;
			enemy.erase(enemy.begin()+i);
			break;
		}
		else if(tmpX>=enemy[i].position.x && tmpX<=enemy[i].position.x+enemy[i].position.w && player.position.y>=enemy[i].position.y && player.position.y<=enemy[i].position.y+enemy[i].position.h){
			player.hp-=enemy[i].hp;
			enemy.erase(enemy.begin()+i);
			break;
		}
		else if(enemy[i].position.x>=player.position.x && enemy[i].position.x<=tmpX && enemy[i].position.y>=player.position.y && enemy[i].position.y<=tmpY){
			player.hp-=enemy[i].hp;
			enemy.erase(enemy.begin()+i);
			break;
		}
		else if(enemy[i].position.x+enemy[i].position.w>=player.position.x && enemy[i].position.x+enemy[i].position.w<=tmpX && enemy[i].position.y+enemy[i].position.h>=player.position.y && enemy[i].position.y+enemy[i].position.h<=tmpY){
			player.hp-=enemy[i].hp;
			enemy.erase(enemy.begin()+i);
			break;
		}
	}
}

void Game::start(){
	to_File.read();
	srand(time(0));		//ShowAllGraphics(pDisplaySurface, tmp1, 4);
	bool exit;
	keystate = SDL_GetKeyState( NULL );
	player.setS(x,y);
	unsigned int i;
	while(!MenuStart()){
		time(&time_start_game);
		player.setPosition();
		player.setStart();//player.level=1;		player.exp=0;		player.hp=100;		player.score=0;
		exit=true;
		move_speed_game=0;
		ammo.clear();
		enemy.clear();
		ready=0;
		rand_enemy=0;
		rand_item=0;
		stats.setZero();
		while(exit){
			time_game=clock();
			while(SDL_PollEvent(&event)){
				if(event.type==SDL_QUIT){
					exit=!PauseStart();
					break;
				}
				if(event.type==SDL_KEYDOWN){
					switch(event.key.keysym.sym){
						case SDLK_ESCAPE:
							exit=!PauseStart();
							break;
						case SDLK_p:
							exit=!PauseStart();
							break;
						case SDLK_PAUSE:
							exit=!PauseStart();
							break;
						case SDLK_F1:
							Help();
							break;
						default:
							break;
					}
				}
			}
			up_down='0';
			if(keystate[SDLK_RETURN]){

			}
			if(keystate[SDLK_DOWN]){
				if(player.check(1)){
					player.movement(0,1);
					up_down='2';
				}
			}
			if(keystate[SDLK_UP]){
				if(player.check(2)){
					player.movement(0,-1);
					up_down='1';
				}
			}
			if(keystate[SDLK_LEFT]){
				if(player.check(3)){
					player.movement(-1,0);
					up_down='4';
				}
			}
			if(keystate[SDLK_RIGHT]){
				if(player.check(4)){
					player.movement(1,0);
					up_down='3';
				}
			}
			if(keystate[SDLK_SPACE]){
				if(ready<=time_game){
					ready=time_game+player.attackspeed*100;
					stats.shoted_ammo++;
					ammo.push_back(Ammo(player.position.x+player.position.w,player.position.y+player.position.h/2,'r',10,player.attackspeed));
				}
			}
			if(keystate[SDLK_RIGHT] && keystate[SDLK_DOWN]){
				up_down='8';
			}
			if(keystate[SDLK_LEFT] && keystate[SDLK_DOWN]){
				up_down='6';
			}
			if(keystate[SDLK_RIGHT] && keystate[SDLK_UP]){
				up_down='7';
			}
			if(keystate[SDLK_LEFT] && keystate[SDLK_UP]){
				up_down='5';
			}
			if(keystate[SDLK_LEFT] && keystate[SDLK_RIGHT]){
				up_down='0';
			}
			if(keystate[SDLK_UP] && keystate[SDLK_DOWN]){
				up_down='0';
			}

			DrawBackgroud(pDisplaySurface);
			if(move_speed_game==2){
				for(i=0;i<ammo.size();i++){	//std::cout<<i+1<<": "<<ammo[i].position.x<<" "<<ammo[i].position.y<<std::endl;
					ammo[i].move();
					if(!ammo[i].check(x)){//std::cout<<"Usunieto "<<1+i<<", zostalo:"<<ammo.size()<<std::endl;
						ammo.erase(ammo.begin()+i);
					}
				}
				for(i=0;i<enemy.size();i++){
					enemy[i].movement();
					if(!enemy[i].check()){	//std::cout<<"Enemy usunieto "<<1+i<<", zostalo:"<<enemy.size()<<std::endl;
						enemy.erase(enemy.begin()+i);
					}
				}
			}
			if(rand_enemy<=time_game){ //std::cout<<"global: "<<time_game<<" rand mob: "<<rand_enemy<<"\n";
				if(player.level>enemy.size()){
					rand_enemy=time_game+player.attackspeed*700;
					enemy.push_back(Enemy(x,y, rand()%9));
				}
			}
			else{
				for(i=0;i<enemy.size();i++){
					if(!enemy[i].shoted && rand()%80){
						ammo.push_back(Ammo(enemy[i].position.x-enemy[i].position.w,enemy[i].position.y+enemy[i].position.h/2,'l',enemy[i].attackdamage,enemy[i].attackspeed));
						enemy[i].shoted=true;
						break;
					}
				}
			}

			if(move_speed_game==2){
				move_speed_game=0;
			}
			else{
				move_speed_game++;
			}

			Action();
			for(i=0;i<enemy.size();i++){
				DrawEnemy(pDisplaySurface, enemy[i].position, enemy[i].returnType());
			}
			for(i=0;i<ammo.size();i++){
				if(ammo[i].returnLeft_right()=='r')
					DrawAmmo(pDisplaySurface, ammo[i].position , 1);
				else if(ammo[i].returnLeft_right()=='l')
					DrawAmmo(pDisplaySurface, ammo[i].position , 0);
			}			//DrawItem(pDisplaySurface, player.position , 0);
			ShowPlayer();
			ShowInfo();
			SDL_Flip(pDisplaySurface);

			if(CheckEnd())
				exit=false;
		}
	}
}

Game::Game(unsigned int X, unsigned int Y){
	pDisplaySurface = NULL;
	InitGame();
	SetResolution(X,Y);
	pDisplaySurface = SDL_SetVideoMode(x,y,0,SDL_ANYFORMAT | SDL_DOUBLEBUF | SDL_HWSURFACE | SDL_SWSURFACE  );
	if(pDisplaySurface==NULL){
		std::cerr<<"Nie utworzono okna gry!"<<std::endl;
		ClearGame();
		exit(1);
	}
	player.nickname=ReadNickname(pDisplaySurface);
	setColorText(&info_color,255,255,255);
	setColorText(&red_color,255,0,0);
	setColorText(&other_color,0,200,0);
	up_down='0';
	start();
}

Game::Game(){
	pDisplaySurface = NULL;
	InitGame();
	SetResolution(800,600);
	pDisplaySurface = SDL_SetVideoMode(x,y,0,SDL_ANYFORMAT | SDL_DOUBLEBUF | SDL_HWSURFACE );
	if(pDisplaySurface==NULL){
		std::cerr<<"Nie utworzono okna gry!"<<std::endl;
		ClearGame();
		exit(1);
	}
	player.nickname=ReadNickname(pDisplaySurface);
	setColorText(&info_color,255,255,255);
	setColorText(&red_color,255,0,0);
	setColorText(&other_color,0,200,0);
	up_down='0';
	start();
}

Game::~Game(){
	to_File.write();
	ClearGame();
}
