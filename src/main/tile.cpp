/*
 * tile.cpp
 *
 *  Created on: 27 Jul 2011
 *      Author: aat
 */

#include "tile.h"

tile::tile()
{

}

tile::tile(int colw,int colh)
{
	colbox.w = colw;
	colbox.h = colh;
	tilesprite = NULL;
	this->tileani = NULL;
}

tile::tile(int colw,int colh,int x,int y)
{
	colbox.w = colw;
	colbox.h = colh;
	colbox.x = x;
	colbox.y = y;
	tilesprite = NULL;
	this->tileani = NULL;
}


tile::tile(int colw,int colh,int x,int y, sprite *spr,animation *ani)
{
	//cout << "x*y:" << x << " " << y << " w*h:" << colw << " " << colh << endl;
	colbox.w = colw;
	colbox.h = colh;
	colbox.x = x;
	colbox.y = y;
	this->tilesprite = spr;
	this->tileani = ani;
	this->collide = false;
	this->ending = true;
}

void tile::animate()
{
	tileani->get_next();
}



void tile::set_animation(animation *ani)
{
	tileani = ani;
}

animation tile::get_animation()
{
	return *tileani;
}


SDL_Rect tile::get_box()
{
 return colbox;
}

sprite tile::get_sprite()
{
 return *tilesprite;
}

void tile::set_sprite(sprite* sprr)
{
	this->tilesprite= sprr;
}

void tile::set_collide(bool bb)
{
	this->collide = bb;
}

void tile::set_ending(bool bb)
{
	this->ending = bb;
}

bool tile::get_collide()
{
	return this->collide;
}

bool tile::get_ending()
{
	return this->ending;
}


