/*
 * bar.h
 *
 *  Created on: 23 Aug 2011
 *      Author: aat
 */

#ifndef BAR_H_
#define BAR_H_

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <fstream>
#include <iostream>


class bars
{

private:
SDL_Surface *surface;
SDL_Rect barbar;
SDL_Rect original;
unsigned short percent, wcorr,hcorr;
bool vertical, inverted;

public:
bars();
bars(SDL_Surface*,int,int);
SDL_Surface* get_surface();
void set_surface(SDL_Surface*);
unsigned short get_percent();
void set_vertical(bool);
bool get_vertical();
void set_inverted(bool);
bool get_inverted();
void set_percent(short);
void plus_percent(unsigned short);
void min_percent(unsigned short);
void set_height(unsigned int);
void set_length(unsigned int);
unsigned int get_height();
unsigned int get_lenght();
int get_x();
int get_y();
int percentoff(float , int );
int set_round_corr(short,short);

SDL_Rect get_rectangle();
SDL_Rect get_raw_rectangle();

};

#endif /* BAR_H_ */
