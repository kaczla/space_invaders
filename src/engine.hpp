#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <iostream>
#include <time.h>
#include <string>
using namespace std;
#ifndef ENGINE_HPP_
#define ENGINE_HPP_

void setColorText(SDL_Color *color, Uint8 R, Uint8 G, Uint8 B);
void setRect(SDL_Rect &a, Sint16 X=0, Sint16 Y=0, Uint16 W=0, Uint16 H=0);
void DrawSurface(SDL_Surface *screen, SDL_Surface *sprite, int x, int y);
void DrawSurface(SDL_Surface *screen, SDL_Surface *sprite, SDL_Rect &where);
void DrawSurface(SDL_Surface *screen, SDL_Surface *sprite, SDL_Rect &where, SDL_Rect &how);

void SetScreen(SDL_Surface *screen);

void TextBold();
void TextNormal();
void TextItalic();
void LoadImages();
void DrawBackgroud(SDL_Surface *screen);
void DrawButton(SDL_Surface *screen,SDL_Rect &where, unsigned int i=0);
void DrawPlayer(SDL_Surface *screen,SDL_Rect &where, unsigned int a);
void DrawEnemy(SDL_Surface *screen,SDL_Rect &where, unsigned int a);
void DrawAmmo(SDL_Surface *screen,SDL_Rect &where, unsigned int a);
void DrawItem(SDL_Surface *screen,SDL_Rect &where, unsigned int a);
void ClearImages();
void refreshScreen(SDL_Surface *screen);
void DrawText(SDL_Surface *screen, string a, SDL_Color &color);
void DrawText(SDL_Surface *screen, string a, SDL_Color &color, SDL_Rect &where);
void DrawTextSmall(SDL_Surface *screen, string a, SDL_Color &color);
void DrawTextSmall(SDL_Surface *screen, string a, SDL_Color &color, SDL_Rect &where);
void DrawTimeGame(SDL_Surface *screen, clock_t a, SDL_Color &color, SDL_Rect &where);
string ReadNickname(SDL_Surface *screen);
void Wait(unsigned int How_Secund);

void InitGame();
void ClearGame();
void abc();
void ShowAllGraphics(SDL_Surface *screen,SDL_Rect &where, unsigned int a);
string toString(int a);
string toString(unsigned int a);
bool isNumer(char a);
unsigned int toNumber(char a);
int toInt(string a);
unsigned int toUInt(string a);

class Engine{
	public:
		Engine();
		~Engine();


	protected:
		SDL_Surface *bg ;
		SDL_Surface *icon ;
		SDL_Surface *button ;
		SDL_Rect button1, button2;
		SDL_Surface *player;
		unsigned int player_animation;
		SDL_Rect player1[9];
		SDL_Rect enemy[9];
		SDL_Rect amo[4];
		SDL_Rect item[2];
		TTF_Font *font, *font_small;
		SDL_Surface *text;
		char time_game_run[50];
		struct tm *struct_time;
	private:
		friend void TextBold();
		friend void TextNormal();
		friend void TextItalic();
		friend void LoadImages();
		friend void DrawBackgroud(SDL_Surface *screen);
		friend void DrawPlayer(SDL_Surface *screen, SDL_Rect &where, unsigned int a);
		friend void DrawEnemy(SDL_Surface *screen, SDL_Rect &where, unsigned int a);
		friend void DrawAmmo(SDL_Surface *screen, SDL_Rect &where, unsigned int a);
		friend void DrawItem(SDL_Surface *screen, SDL_Rect &where, unsigned int a);
		friend void DrawText(SDL_Surface *screen, string a, SDL_Color &color);
		friend void DrawText(SDL_Surface *screen, string a, SDL_Color &color, SDL_Rect &where);
		friend void DrawTextSmall(SDL_Surface *screen, string a, SDL_Color &color);
		friend void DrawTextSmall(SDL_Surface *screen, string a, SDL_Color &color, SDL_Rect &where);
		friend void DrawTimeGame(SDL_Surface *screen, clock_t a, SDL_Color &color, SDL_Rect &where);
		friend void ClearImages();
		friend void DrawButton(SDL_Surface *screen,SDL_Rect &where, unsigned int i);

		friend void abc();
		friend void ShowAllGraphics(SDL_Surface *screen,SDL_Rect &where, unsigned int a);
};

#endif
