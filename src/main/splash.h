/*
 * splash.h
 *
 *  Created on: 14 Sep 2011
 *      Author: aat
 */

#ifndef SPLASH_H_
#define SPLASH_H_

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "Timer.h"

class splash
{
private:
	SDL_Surface *surface;
	SDL_Rect recto;
	SDL_Event *event;
	Timer timer;
	int timeout;
	bool klaar;

public:

	splash(SDL_Event*,int);
	~splash();
	void update();
	SDL_Surface* get_surface();
	void set_surface(SDL_Surface*);
	bool get_klaar();
	void set_klaar(bool);


};
#endif /* SPLASH_H_ */
