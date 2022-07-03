/*
 * tilemap.h
 *
 *  Created on: 27 Jul 2011
 *      Author: aat
 */

#ifndef TILEMAP_H_
#define TILEMAP_H_

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "tile.h"
#include "../baseclasses/sprite.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include "tinyxml.h"

class tilemap
{

private:
vector<vector<tile*> > alltiles;
vector<animation*> tileanimas;
sprite *tilemapspr;
animation *tempani;
SDL_Rect afmeet;
int width,height;
int totw,toth;
int ofsetx,ofsety;
ifstream *map;
//int tempani;

public:

~tilemap();

tilemap(int,int,sprite*);
tilemap(int,int);
tilemap();
string loadfile(const char*);
int nooftiles(string,int);
tile* get_tile(unsigned int,unsigned int);
void set_width(int);
void set_height(int);
void set_wihi(int,int);
void set_ofsetx(int);
void set_ofsety(int);
int get_ofsetx();
int get_ofsety();
void set_sprite(sprite*);
sprite* get_sprite();
int get_width();
int get_height();
void animate();
string split(string, char, int);
void filterstr(string& , char );
void replacestr(string& , char ,char);
string convertInt(int);
bool loadxmlmap(string);
bool loadmap(string,string);
bool loadmap(string);
int get_tot_width();
int get_tot_height();
void set_collide(int);
bool get_collide(int);

};

#endif /* TILEMAP_H_ */
