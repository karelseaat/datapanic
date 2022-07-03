/*
 * ascore.h
 *
 *  Created on: 25 Aug 2011
 *      Author: aat
 */

#ifndef ASCORE_H_
#define ASCORE_H_

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

class ascore
{
private:

	SDL_Surface *scores;
	int rawscore,fontsize,ofsetx,ofsety;
	string fontname,seperator,name;
	TTF_Font *font;
	SDL_Color color;


public:

	ascore(int,string);
	ascore(int);
	void set_name(string);
	string get_name();
	void set_score(int);
	int get_score();
	void convert();
	SDL_Surface* get_picscore();
	void my_itoa(int,string&,int);
	string get_com_score();
	void set_font(string ,int);
	void set_color(SDL_Color);
	void ietss(string);
	string get_font_name();
	int get_font_size();
	void set_sep(string);
	void set_ofx(int x);
	void set_ofy(int y);
	int get_ofx();
	int get_ofy();
	string get_com2_score();
	void update();

};


#endif /* ASCORE_H_ */
