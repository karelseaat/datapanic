/*
 * sprite.h
 *
 *  Created on: 24 Jul 2011
 *      Author: aat
 */

#ifndef SPRITE_H
#define SPRITE_H


#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;


class sprite
{

private:
SDL_Surface *surface;
vector<SDL_Rect> frames;

int width,height,nrframes;

public:
sprite();
sprite(sprite&);
sprite(SDL_Surface* ,int,int);
sprite(std::string,int,int);
sprite(int,int);
void set_surface(SDL_Surface*);
SDL_Rect get_frame(int);
SDL_Surface *get_surface();
SDL_Surface *load_image(std::string);
void makesprite();
int get_width();
int get_height();

};

#endif  /* SPRITE_H */
