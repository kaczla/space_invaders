#include "menu.hpp"

Pause::Pause(){
	exit=true;
	quit=false;
	ile=0;
	setColorText(&text_color,255,150,10);
	setColorText(&text_colorInfo,250,0,0);
	textExit=NULL;
	textResume=NULL;
	textInfo=NULL;
}

Pause::~Pause(){

}

bool Pause::start(SDL_Surface *ekran, unsigned int X, unsigned Y){
	exit=true;
	ile=0;
	TextBold();
	setCordinate(X,Y);
	DrawText(ekran, "GAME PAUSED!", text_colorInfo, polozenie_textInfo);
	while(exit){
		while(SDL_PollEvent(&zdarzenie_pause)){
			if(zdarzenie_pause.type==SDL_QUIT){
				exit=false;
				quit=true;
				break;
			}
			if(zdarzenie_pause.type==SDL_KEYDOWN){
				switch(zdarzenie_pause.key.keysym.sym){
					case SDLK_ESCAPE:
						exit=false;
						quit=false;
						break;
					case SDLK_p:
						exit=false;
						quit=false;
						break;
					case SDLK_UP:
						IncIle(-1);
						break;
					case SDLK_DOWN:
						IncIle(1);
						break;
					case SDLK_SPACE:
						setValue();
						break;
					case SDLK_RETURN:
						setValue();
						break;
					default:
						break;
				}
			}
		}
		wyswietlPrzycisk(ekran);
		SDL_Flip(ekran);
	}
	TextNormal();
	return quit;
}

inline void Pause::IncIle(int a){
	ile+=a;
	if(ile>2)
		ile=0;
	else if(ile<0)
		ile=2;
}

inline void Pause::wyswietlPrzycisk(SDL_Surface *ekran){
	if(ile==1){
		DrawButton(ekran, polozenie1, 1);
		DrawButton(ekran, polozenie2, 0);
	}
	else if(ile==2){
		DrawButton(ekran, polozenie1, 0);
		DrawButton(ekran, polozenie2, 1);
	}
	else{
		DrawButton(ekran, polozenie1, 0);
		DrawButton(ekran, polozenie2, 0);
	}
	DrawText(ekran, "RESUME", text_color, polozenie1_text);
	DrawText(ekran, "EXIT", text_color, polozenie2_text);
}

inline void Pause::setCordinate(unsigned int X, unsigned int Y){
	polozenie1.x=X/2-115;
	polozenie1.y=Y/8;
	polozenie2.x=polozenie1.x;
	polozenie2.y=polozenie1.y+80;
	polozenie1_text.x=polozenie1.x+60;
	polozenie1_text.y=polozenie1.y+12;
	polozenie2_text.x=polozenie2.x+85;
	polozenie2_text.y=polozenie2.y+12;
	polozenie_textInfo.x=polozenie1.x+15;
	polozenie_textInfo.y=polozenie1.y-30;
}

inline void Pause::setValue(){
	if(ile==1){
		quit=false;
		exit=false;
	}
	else if(ile==2){
		quit=true;
		exit=false;
	}
}

// MENU
Menu::Menu():Pause(){

}

bool Menu::start(SDL_Surface *ekran, unsigned int X, unsigned Y){
	exit=true;
	ile=0;
	TextBold();
	DrawBackgroud(ekran);
	setCordinate(X,Y);
	while(exit){
		while(SDL_PollEvent(&zdarzenie_pause)){
			if(zdarzenie_pause.type==SDL_QUIT){
				exit=false;
				quit=true;
				break;
			}
			if(zdarzenie_pause.type==SDL_KEYDOWN){
				switch(zdarzenie_pause.key.keysym.sym){
					case SDLK_ESCAPE:
						exit=false;
						quit=true;
						break;
					case SDLK_UP:
						IncIle(-1);
						break;
					case SDLK_DOWN:
						IncIle(1);
						break;
					case SDLK_SPACE:
						setValue(ekran,X,Y);
						break;
					case SDLK_RETURN:
						setValue(ekran,X,Y);
						break;
					default:
						break;
				}
			}
		}
		wyswietlPrzycisk(ekran);
		SDL_Flip(ekran);
	}
	TextNormal();
	return quit;
}

inline void Menu::IncIle(int a){
	ile+=a;
	if(ile>3)
		ile=0;
	else if(ile<0)
		ile=3;
}

inline void Menu::wyswietlPrzycisk(SDL_Surface *ekran){
	if(ile==1){
		DrawButton(ekran, polozenie1, 1);
		DrawButton(ekran, polozenie2, 0);
		DrawButton(ekran, polozenie3, 0);
	}
	else if(ile==2){
		DrawButton(ekran, polozenie1, 0);
		DrawButton(ekran, polozenie2, 1);
		DrawButton(ekran, polozenie3, 0);
	}
	else if(ile==3){
		DrawButton(ekran, polozenie1, 0);
		DrawButton(ekran, polozenie2, 0);
		DrawButton(ekran, polozenie3, 1);
	}
	else{
		DrawButton(ekran, polozenie1, 0);
		DrawButton(ekran, polozenie2, 0);
		DrawButton(ekran, polozenie3, 0);
	}
	DrawText(ekran, "NEW GAME", text_color, polozenie1_text);
	DrawText(ekran, "ABOUT", text_color, polozenie2_text);
	DrawText(ekran, "EXIT", text_color, polozenie_textInfo);
}

inline void Menu::setCordinate(unsigned int X, unsigned int Y){
	Pause::setCordinate(X,Y);
	polozenie3.x=polozenie2.x;
	polozenie3.y=polozenie2.y+80;
	polozenie_textInfo.x=polozenie3.x+86;
	polozenie_textInfo.y=polozenie3.y+15;
	polozenie1_text.x=polozenie1.x+50;
	polozenie1_text.y=polozenie1.y+12;
	polozenie2_text.x=polozenie2.x+72;
	polozenie2_text.y=polozenie2.y+12;
}

inline void Menu::setValue(SDL_Surface *ekran, unsigned int X, unsigned Y){
	if(ile==1){
		exit=false;
		quit=false;
	}
	else if(ile==2){
		About(ekran,X,Y);
	}
	else if(ile==3){
		exit=false;
		quit=true;
	}
}

inline void Menu::About(SDL_Surface *ekran, unsigned int X, unsigned Y){
	SDL_Surface *logo;
	bool exit_about=true;
	logo=IMG_Load("images/SDL_logo.png");
	DrawBackgroud(ekran);
	DrawText(ekran, "SDL 1.2", text_colorInfo, polozenie1);
	SDL_BlitSurface(logo, NULL, ekran, &polozenie2);
	while(exit_about){
		while(SDL_PollEvent(&zdarzenie_pause)){
			if(zdarzenie_pause.type==SDL_QUIT){
				exit_about=false;
				break;
			}
			if(zdarzenie_pause.type==SDL_KEYDOWN){
				switch(zdarzenie_pause.key.keysym.sym){
					case SDLK_ESCAPE:
						exit_about=false;
						break;
					default:
						exit_about=false;
						break;
				}
			}
		}
		SDL_Flip(ekran);
	}
	DrawBackgroud(ekran);
	SDL_FreeSurface(logo);
}
