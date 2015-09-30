#include "engine.hpp"
/*
SDL_Surface *SDL_SetVideoMode(int width, int height, int bpp, Uint32 flags);
flags:
	SDL_SWSURFACE	Create the video surface in system memory
	SDL_HWSURFACE	Create the video surface in video memory
	SDL_ASYNCBLIT	Enables the use of asynchronous updates of the display surface. This will usually slow down blitting on single CPU machines, but may provide a speed increase on SMP systems.
	SDL_ANYFORMAT	Normally, if a video surface of the requested bits-per-pixel (bpp) is not available, SDL will emulate one with a shadow surface. Passing SDL_ANYFORMAT prevents this and causes SDL to use the video surface, regardless of its pixel depth.
	SDL_DOUBLEBUF	Enable hardware double buffering; only valid with SDL_HWSURFACE. Calling SDL_Flip will flip the buffers and update the screen. All drawing will take place on the surface that is not displayed at the moment. If double buffering could not be enabled then SDL_Flip will just perform a SDL_UpdateRect on the entire screen.
	SDL_FULLSCREEN	SDL will attempt to use a fullscreen mode. If a hardware resolution change is not possible (for whatever reason), the next higher resolution will be used and the display window centered on a black background.
	SDL_RESIZABLE	Create a resizable window. When the window is resized by the user a SDL_VIDEORESIZE event is generated and SDL_SetVideoMode can be called again with the new size.
	SDL_NOFRAME	If possible, SDL_NOFRAME causes SDL to create a window with no title bar or frame decoration. Fullscreen modes automatically have this flag set.


*/

void setColorText(SDL_Color *color, Uint8 R, Uint8 G, Uint8 B){
	color->r=R;
	color->g=G;
	color->b=B;
}

void setRect(SDL_Rect &a, Sint16 X, Sint16 Y, Uint16 W, Uint16 H){
	a.x=X;
	a.y=Y;
	a.w=W;
	a.h=H;
}

void DrawSurface(SDL_Surface *screen, SDL_Surface *sprite, int x, int y){
   SDL_Rect dest;
   dest.x = x - sprite->w / 2;
   dest.y = y - sprite->h / 2;
   dest.w = sprite->w;
   dest.h = sprite->h;
   SDL_BlitSurface(sprite, NULL, screen, &dest);
}

void DrawSurface(SDL_Surface *screen, SDL_Surface *sprite, SDL_Rect &where){
   SDL_BlitSurface(sprite, NULL, screen, &where);
}

void DrawSurface(SDL_Surface *screen, SDL_Surface *sprite, SDL_Rect &where, SDL_Rect &how){
   SDL_BlitSurface(sprite, &how, screen, &where);
}

void SetScreen(SDL_Surface *screen){
	//Po wyjsciu z funckji zapomina jakie były ustawienia okna
	//Nie można wskaźnikowi tego przypisać ;/
}

Engine engine;

void TextBold(){
	TTF_SetFontStyle(engine.font, TTF_STYLE_BOLD);
}

void TextNormal(){
	TTF_SetFontStyle(engine.font, TTF_STYLE_NORMAL);
}

void TextItalic(){
	TTF_SetFontStyle(engine.font, TTF_STYLE_ITALIC);
}

void LoadImages(){
	engine.bg = IMG_Load("images/bg.png");
	if(engine.bg == NULL){
		std::cerr<<"Nie wczytano tła: images/bg.png !"<<std::endl;
		ClearGame();
		exit(1);
	}

	SDL_WM_SetCaption("Space Invaders", 0);
	engine.icon = IMG_Load("images/icon.png");
	if(engine.icon == NULL){
		std::cerr<<"Nie wczytano ikonki: images/icon.png !"<<std::endl;
		ClearGame();
		exit(1);
	}
	SDL_WM_SetIcon(engine.icon,NULL);

	engine.button = IMG_Load("images/buttons.png");
	if(engine.button == NULL){
		std::cerr<<"Nie wczytano grafiki przycisków: images/buttons.png !"<<std::endl;
		ClearGame();
		exit(1);
	}

	engine.font = TTF_OpenFont("fonts/FreeSans.ttf", 24);
	if(!engine.font) {
	    std::cerr<<"Nie wczytano czcionki fonts/FreeSans.ttf :"<<TTF_GetError()<<std::endl;
	    ClearGame();
		exit(1);
	}
	engine.font_small = TTF_OpenFont("fonts/FreeSans.ttf", 14);
	if(!engine.font_small) {
		    std::cerr<<"Nie wczytano czcionki fonts/FreeSans.ttf :"<<TTF_GetError()<<std::endl;
		    ClearGame();
			exit(1);
		}
	//TextBold();

	engine.player = IMG_Load("images/player.png");
	if(engine.player == NULL){
		std::cerr<<"Nie wczytano grafiki gracza: images/player.png !"<<std::endl;
		ClearGame();
		exit(1);
	}
}

void DrawBackgroud(SDL_Surface *screen){
	SDL_BlitSurface(engine.bg, NULL, screen, NULL);
}

void DrawButton(SDL_Surface *screen,SDL_Rect &where, unsigned int i){
	if(i==0){
		SDL_BlitSurface(engine.button, &engine.button1, screen, &where);
	}
	else if(i==1){
		SDL_BlitSurface(engine.button, &engine.button2, screen, &where);
	}
	else{
		std::cerr<<"Nie prawidłowy argument 'i' dla 'DrawButton()'! Tylko i=0 lub i=1!"<<std::endl;
		ClearGame();
		exit(1);
	}
}

void DrawPlayer(SDL_Surface *screen, SDL_Rect &where, unsigned int a){
	if(a==1)
		SDL_BlitSurface(engine.player, &engine.player1[1] , screen, &where);
	else if(a==2)
		SDL_BlitSurface(engine.player, &engine.player1[2] , screen, &where);
	else if(a==3)
		SDL_BlitSurface(engine.player, &engine.player1[3] , screen, &where);
	else if(a==4)
		SDL_BlitSurface(engine.player, &engine.player1[4] , screen, &where);
	else if(a==5)
		SDL_BlitSurface(engine.player, &engine.player1[5] , screen, &where);
	else if(a==6)
		SDL_BlitSurface(engine.player, &engine.player1[6] , screen, &where);
	else if(a==7)
		SDL_BlitSurface(engine.player, &engine.player1[7] , screen, &where);
	else if(a==8)
		SDL_BlitSurface(engine.player, &engine.player1[8] , screen, &where);
	else
		SDL_BlitSurface(engine.player, &engine.player1[0] , screen, &where);
}

void DrawEnemy(SDL_Surface *screen, SDL_Rect &where, unsigned int a){
	if(a==1)
		SDL_BlitSurface(engine.player, &engine.enemy[1] , screen, &where);
	else if(a==2)
		SDL_BlitSurface(engine.player, &engine.enemy[2] , screen, &where);
	else if(a==3)
		SDL_BlitSurface(engine.player, &engine.enemy[3] , screen, &where);
	else if(a==4)
		SDL_BlitSurface(engine.player, &engine.enemy[4] , screen, &where);
	else if(a==5)
		SDL_BlitSurface(engine.player, &engine.enemy[5] , screen, &where);
	else if(a==6)
		SDL_BlitSurface(engine.player, &engine.enemy[6] , screen, &where);
	else if(a==7)
		SDL_BlitSurface(engine.player, &engine.enemy[7] , screen, &where);
	else if(a==8)
		SDL_BlitSurface(engine.player, &engine.enemy[8] , screen, &where);
	else if(a==9)
		SDL_BlitSurface(engine.player, &engine.item[0] , screen, &where);
	else if(a==10)
		SDL_BlitSurface(engine.player, &engine.item[1] , screen, &where);
	else
		SDL_BlitSurface(engine.player, &engine.enemy[0] , screen, &where);
}

void DrawAmmo(SDL_Surface *screen, SDL_Rect &where, unsigned int a){
	if(a==1)
		SDL_BlitSurface(engine.player, &engine.amo[1] , screen, &where);
	else if(a==2)
		SDL_BlitSurface(engine.player, &engine.amo[2] , screen, &where);
	else if(a==3)
		SDL_BlitSurface(engine.player, &engine.amo[3] , screen, &where);
	else
		SDL_BlitSurface(engine.player, &engine.amo[0] , screen, &where);
}

void DrawItem(SDL_Surface *screen, SDL_Rect &where, unsigned int a){
	if(a==1)
		SDL_BlitSurface(engine.player, &engine.item[1] , screen, &where);
	else
		SDL_BlitSurface(engine.player, &engine.item[0] , screen, &where);
}

void refreshScreen(SDL_Surface *screen){
	SDL_Flip(screen);
}

void DrawText(SDL_Surface *screen, string a, SDL_Color &color){
	const char *tmp=a.c_str();
	engine.text=TTF_RenderText_Solid(engine.font,tmp,color);
	SDL_BlitSurface(engine.text, NULL, screen, NULL);
}

void DrawText(SDL_Surface *screen, string a, SDL_Color &color, SDL_Rect &where){
	const char *tmp=a.c_str();
	engine.text=TTF_RenderText_Solid(engine.font,tmp,color);
	SDL_BlitSurface(engine.text, NULL, screen, &where);
}

void DrawTextSmall(SDL_Surface *screen, string a, SDL_Color &color){
	const char *tmp=a.c_str();
	engine.text=TTF_RenderText_Solid(engine.font_small,tmp,color);
	SDL_BlitSurface(engine.text, NULL, screen, NULL);
}

void DrawTextSmall(SDL_Surface *screen, string a, SDL_Color &color, SDL_Rect &where){
	const char *tmp=a.c_str();
	engine.text=TTF_RenderText_Solid(engine.font_small,tmp,color);
	SDL_BlitSurface(engine.text, NULL, screen, &where);
}

void DrawTimeGame(SDL_Surface *screen, time_t a, SDL_Color &color, SDL_Rect &where){
	engine.struct_time = localtime(&a);
	strftime(engine.time_game_run, 100, "Time: %M:%S", engine.struct_time);
	engine.text=TTF_RenderText_Solid(engine.font_small,engine.time_game_run,color);
	SDL_BlitSurface(engine.text, NULL, screen, &where);
}

string ReadNickname(SDL_Surface *screen){
	SDL_Rect textInfo,textNick;
	setRect(textInfo, 200, 200, 0, 0);
	setRect(textNick, 200, 250, 0, 0);
	string tmp="";
	bool exit=true;
	unsigned int key;
	SDL_Event zdarzenie;
	SDL_Color text_color,info_color;
	setColorText(&text_color,255,255,255);
	setColorText(&info_color,255,0,0);
	while(exit){
		while(SDL_PollEvent(&zdarzenie)){
			if(zdarzenie.type==SDL_QUIT){
				exit=false;
				break;
			}
			if(zdarzenie.type==SDL_KEYDOWN){
				switch(zdarzenie.key.keysym.sym){
					case SDLK_ESCAPE:
						exit=false;
						break;
					case SDLK_RETURN:
						exit=false;
						break;
					case SDLK_SPACE:
						if(tmp[tmp.size()-1]!=' ' && tmp.size()<19)
							tmp+=" ";
						break;
					case SDLK_BACKSPACE:
						if(tmp.size()!=0)
							tmp.erase(tmp.end()-1,tmp.end());
						break;
					default:
						key=zdarzenie.key.keysym.sym;
						if(key>=97 && key<=122 && tmp.size()<20)
							tmp+=(char)key;
						break;
				}
			}
		}
		DrawBackgroud(screen);
		TextBold();
		DrawText(screen, "Your nickname:", info_color, textInfo);
		TextNormal();
		DrawText(screen, "\""+tmp+"\"", text_color, textNick);
		//DrawText(screen,tmp,text_color);
		SDL_Flip(screen);
	}
	if(tmp=="" or tmp==" ")
		return "player";
	else if(tmp.length()<=2)
		return "player";
	return tmp;
}

void InitGame(){
	if(SDL_Init(SDL_INIT_VIDEO)==-1){
		std::cerr<<"Błąd inicjalizacji: SDL_Init(SDL_INIT_VIDEO) :"<<SDL_GetError()<<std::endl;
		exit(1);
	}
	if(TTF_Init()!=0){
		std::cerr<<"Błąd inicjalizacji TTF_Init() :"<<TTF_GetError()<<std::endl;
		SDL_Quit();
		exit(1);
	}
	//std::cout<<"Pomyślnie zainicjalizowano SDL!"<<std::endl;
	SDL_ShowCursor(SDL_DISABLE);
	LoadImages();
	//std::cout<<"Pomyślnie wczytano grafikę!"<<std::endl;
}

void ClearGame(){
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
	//TIME <ctime>
	//std::cout<<"Pamięć została zwolniona pomyślnie zwolniona!"<<std::endl;
}

void Wait(unsigned int How_Secund){
	SDL_Delay( How_Secund * 1000 );
}

Engine::Engine(){
	//std::cout<<"ENGINE\n";
	InitGame();
	this->bg = NULL;
	this->icon = NULL;
	this->button = NULL;
	this->player = NULL;
	this->font = NULL;
	this->font_small = NULL;
	this->text = NULL;
	this->struct_time = NULL;

	this->button1.x=0;
	this->button1.y=0;
	this->button1.w=230;
	this->button1.h=53;

	this->button2.x=0;
	this->button2.y=78;
	this->button2.w=230;
	this->button2.h=53;

	this->player_animation=9;
	//this->player1 = new SDL_Rect [8];
	this->player1[0].x=20;
	this->player1[0].y=15;
	this->player1[0].w=39;
	this->player1[0].h=36;

	for(unsigned int i=1;i<this->player_animation;i++){
		this->player1[i].x=this->player1[0].x;
		this->player1[i].y=this->player1[i-1].y+37;
		this->player1[i].w=this->player1[0].w;
		this->player1[i].h=this->player1[0].h;
	}

	this->enemy[0].x=70;
	this->enemy[0].y=15;
	this->enemy[0].h=16;
	this->enemy[0].w=21;

	this->enemy[1].x=70;
	this->enemy[1].y=33;
	this->enemy[1].h=18;
	this->enemy[1].w=22;

	this->enemy[2].x=70;
	this->enemy[2].y=53;
	this->enemy[2].h=23;
	this->enemy[2].w=22;

	this->enemy[3].x=70;
	this->enemy[3].y=78;
	this->enemy[3].h=25;
	this->enemy[3].w=28;

	this->enemy[4].x=70;
	this->enemy[4].y=105;
	this->enemy[4].h=15;
	this->enemy[4].w=37;

	this->enemy[5].x=70;
	this->enemy[5].y=122;
	this->enemy[5].h=30;
	this->enemy[5].w=26;

	this->enemy[6].x=70;
	this->enemy[6].y=154;
	this->enemy[6].h=25;
	this->enemy[6].w=28;

	this->enemy[7].x=70;
	this->enemy[7].y=181;
	this->enemy[7].h=13;
	this->enemy[7].w=32;

	this->enemy[8].x=70;
	this->enemy[8].y=196;
	this->enemy[8].h=15;
	this->enemy[8].w=18;

	this->amo[0].x=115;
	this->amo[0].y=15;
	this->amo[0].h=3;
	this->amo[0].w=15;

	this->amo[1].x=115;
	this->amo[1].y=20;
	this->amo[1].h=3;
	this->amo[1].w=15;

	this->amo[2].x=115;
	this->amo[2].y=25;
	this->amo[2].h=7;
	this->amo[2].w=14;

	this->amo[3].x=115;
	this->amo[3].y=34;
	this->amo[3].h=7;
	this->amo[3].w=14;

	this->item[0].x=140;
	this->item[0].y=15;
	this->item[0].h=11;
	this->item[0].w=11;

	this->item[1].x=140;
	this->item[1].y=28;
	this->item[1].h=19;
	this->item[1].w=19;
}

Engine::~Engine(){
	SDL_FreeSurface(this->icon);
	SDL_FreeSurface(this->bg);
	SDL_FreeSurface(this->button);
	TTF_CloseFont(this->font);
	TTF_CloseFont(this->font_small);
	SDL_FreeSurface(this->player);
	ClearGame();
}

void abc(){
	for(unsigned int i=0;i<engine.player_animation;i++){
			std::cout<<i<<" "
				<<engine.player1[i].x<<" "
				<<engine.player1[i].y<<" "
				<<engine.player1[i].w<<" "
				<<engine.player1[i].h<<"\n";
		}
}
void ShowAllGraphics(SDL_Surface *screen,SDL_Rect &where, unsigned int a){
	if(a==1){
		for(unsigned int i=0;i<engine.player_animation;i++){
			DrawBackgroud(screen);
			SDL_BlitSurface(engine.player, &engine.player1[i], screen, &where);
			SDL_Delay(1000);
			//SDL_UpdateRect(screen,50,50,20,20);
			SDL_Flip(screen);
		}
	}
	else if(a==2){
		for(unsigned int i=0;i<9;i++){
			DrawBackgroud(screen);
			SDL_BlitSurface(engine.player, &engine.enemy[i], screen, &where);
			SDL_Delay(1000);
			SDL_Flip(screen);
		}
	}
	else if(a==3){
		for(unsigned int i=0;i<4;i++){
			DrawBackgroud(screen);
			SDL_BlitSurface(engine.player, &engine.amo[i], screen, &where);
			SDL_Delay(1000);
			SDL_Flip(screen);
		}
	}
	else if(a==4){
		for(unsigned int i=0;i<2;i++){
			DrawBackgroud(screen);
			SDL_BlitSurface(engine.player, &engine.item[i], screen, &where);
			SDL_Delay(1000);
			SDL_Flip(screen);
		}
	}
	else{
		for(unsigned int i=0;i<engine.player_animation;i++){
			DrawBackgroud(screen);
			SDL_BlitSurface(engine.player, &engine.player1[i], screen, &where);
			SDL_Delay(1000);
			SDL_Flip(screen);
		}
		for(unsigned int i=0;i<9;i++){
			DrawBackgroud(screen);
			SDL_BlitSurface(engine.player, &engine.enemy[i], screen, &where);
			SDL_Delay(1000);
			SDL_Flip(screen);
		}
		for(unsigned int i=0;i<4;i++){
			DrawBackgroud(screen);
			SDL_BlitSurface(engine.player, &engine.amo[i], screen, &where);
			SDL_Delay(1000);
			SDL_Flip(screen);
		}
	}
}

string toString(int a){
	string tmp,ret;
	if(a<0)
		a=-a;
	do{
		tmp+=a%10+48;
		a-=a%10;
	}while(a/=10);
	for(int i=tmp.size()-1;i>=0;i--)
		ret += tmp[i];
	return ret;
}

string toString(unsigned int a){
	string tmp,ret;
	do{
		tmp+=a%10+48;
		a-=a%10;
	}while(a/=10);
	for(int i=tmp.size()-1;i>=0;i--)
		ret += tmp[i];
	return ret;
}

bool isNumer(char a){
	switch(a){
		case '1':
			return true;
		case '2':
			return true;
		case '3':
			return true;
		case '4':
			return true;
		case '5':
			return true;
		case '6':
			return true;
		case '7':
			return true;
		case '8':
			return true;
		case '9':
			return true;
		case '0':
			return true;
		default:
			return false;
	}
}

unsigned int toNumber(char a){
	switch(a){
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		case '0':
			return 0;
		default:
			return 0;
	}
}

int toInt(string a){
	int tmp=0;
	unsigned int end=1;
	char tmp2;
	for(int i=a.size()-1;i>=0;i--){
		tmp2=a[i];
		if(isNumer(tmp2)){
			tmp+=end*toNumber(tmp2);
			end*=10;
		}
	}
	for(unsigned int i=0;i<a.size();i++){
		tmp2=a[i];
		if(tmp2=='-'){
			tmp*=-1;
			break;
		}
		else if(isNumer(tmp2))
			break;
	}
	return tmp;
}

unsigned int toUInt(string a){
	int tmp=0;
	unsigned int end=1;
	char tmp2;
	//cout<<"\n";
	for(int i=a.length()-1;i>=0;i--){
		//cout<<i<<"\n";
		tmp2=a[i];
		if(isNumer(tmp2)){
			tmp+=end*toNumber(tmp2);
			end*=10;
		}
	}
	return tmp;
}
