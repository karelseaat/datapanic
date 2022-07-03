/*
 * tile.h
 *
 *  Created on: 27 Jul 2011
 *      Author: aat
 */

#ifndef TILE_H_
#define TILE_H_

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "animation.h"
#include "sprite.h"

class tile
{

private:
	sprite *tilesprite;
	SDL_Rect colbox;
	animation *tileani;
	bool collide,ending;

public:
	tile(int,int,int,int,sprite*,animation*);
	tile(int,int,int,int);
	tile(int,int);
	tile();
	void animate();
	void set_animation(animation*);
	animation get_animation();
	void testing();
	SDL_Rect get_box();
	sprite get_sprite();
	void set_sprite(sprite*);
	void set_collide(bool);
	bool get_collide();
	bool get_ending();
	void set_ending(bool);



};

#endif /* TILE_H_ */
