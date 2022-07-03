/*
 * bar.cpp
 *
 *  Created on: 23 Aug 2011
 *      Author: aat
 */

#include "bar.h"

bars::bars()
{}

bars::bars(SDL_Surface* sur, int x, int y)
{
this->surface = sur;

this->barbar = SDL_Rect{0,0,0,0};
std::cout << sur->w << std::endl;
barbar.w = sur->w;
barbar.h = sur->h;


this->original = SDL_Rect{0,0,0,0};

this->original.x = x;
this->original.y = y;
this->original.w = sur->w;
this->original.h = sur->h;

this->inverted = false;
this->vertical = false;
percent = 100;


}


SDL_Surface* bars::get_surface()
{
	return this->surface;
}

void bars::set_surface(SDL_Surface* sur)
{
	this->surface = sur;
}

unsigned short bars::get_percent()
{
	return this->percent;
}

void bars::set_percent(short per)
{
	if (per <= 100 && per >= 0)
	this->percent = per;
	else if (per > 100)
	this->percent = 100;
	else if (per < 0)
	this->percent =0;
}

void bars::plus_percent(unsigned short per)
{
	std::cout << this->barbar.w << std::endl;
	if (per > 0)
	{
			this->percent += per;
			if (this->percent + per > 100)
			{
				this->percent = 100;
			}

			if (this->percent + per < 0)
			{
				this->percent = 0;
			}

	}
}


void bars::min_percent(unsigned short per)
{
	if (per > 0)
		{

		this->percent -= per;
		if (this->percent - per > 100)
		{
			this->percent = 100;
		}

		if (this->percent - per < 0)
		{
				this->percent = 0;
		}

	}

}

int bars::get_x()
{
	return this->original.x;
}

int bars::get_y()
{
	return this->original.y;
}

SDL_Rect bars::get_rectangle()
{
	if (vertical)
	{
		this->barbar.h = percentoff(this->original.h,this->percent)+this->hcorr;
	}
	else
	{
		this->barbar.w = percentoff(this->original.w,this->percent)+this->wcorr;
	}

	return this->barbar;
}

SDL_Rect bars::get_raw_rectangle()
{
	return this->barbar;
}

int bars::percentoff(float number, int percent)
{
	return float((double)this->original.w / 100) * percent;
}

int bars::set_round_corr(short w,short h)
{
	this->hcorr = h;
	this->wcorr = w;
}

void bars::set_inverted(bool verted)
{
	this->inverted = verted;
}

bool bars::get_inverted()
{
	return this->inverted;
}



void bars::set_vertical(bool verti)
{
	this->vertical = verti;
}

bool bars::get_vertical()
{
	return this->vertical;
}
