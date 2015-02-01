#pragma once
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "engine.hpp"
#include <iostream>
#ifndef MENU_HPP_
#define MENU_HPP_

class Pause{
	public:
		Pause();
		~Pause();
		bool start(SDL_Surface *ekran, unsigned int X, unsigned Y);		//zwraca quit 1 gdy naduszony zostal przycisk EXIT
	protected:
		bool quit,exit;
		int ile;
		SDL_Event zdarzenie_pause;
		SDL_Rect polozenie1, polozenie2;
		SDL_Rect polozenie1_text, polozenie2_text, polozenie_textInfo;
		SDL_Surface *textResume, *textExit, *textInfo;
		SDL_Color text_color, text_colorInfo;
		void IncIle(int a);
		void wyswietlPrzycisk(SDL_Surface *ekran);
		void setCordinate(unsigned int X=600, unsigned int Y=400);
		void setValue();
};

class Menu:protected Pause{
	public:
		Menu();
		bool start(SDL_Surface *ekran, unsigned int X, unsigned Y);		//Zwraca 0 - NEW GAME		//Zwraca 1 - EXIT
	protected:
		SDL_Rect polozenie3;
		void wyswietlPrzycisk(SDL_Surface *ekran);
		void setCordinate(unsigned int X=600, unsigned int Y=400);
		void setValue(SDL_Surface *ekran, unsigned int X, unsigned Y);
		void IncIle(int a);
		void About(SDL_Surface *ekran, unsigned int X, unsigned Y);
};

#endif
