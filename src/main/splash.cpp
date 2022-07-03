/*
 * splash.cpp
 *
 *  Created on: 14 Sep 2011
 *      Author: aat
 */

#include "splash.h"

splash::splash(SDL_Event* ev,int time)
{
	this->event = ev;
	this->surface = NULL;
	this->timeout = time;
	SDL_Rect recto = {10,10,10,10};
	this->timer = Timer();
	timer.stop();
	klaar = false;
}

SDL_Surface* splash::get_surface()
{
	return this->surface;
}

void splash::set_surface(SDL_Surface* sur)
{
	this->surface = sur;
}

void splash::update()
{
	if (SDL_PollEvent( event ) && !timer.is_started() && event->type == SDL_KEYDOWN )
	{
		timer.start();
	}

	if (timer.get_ticks() > timeout)
	{
		timer.stop();
		klaar = true;
	}
}

bool splash::get_klaar()
{
	return this->klaar;
}

void splash::set_klaar(bool kl)
{
	this->klaar = kl;
}

splash::~splash()
{}


