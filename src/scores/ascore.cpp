/*
 * ascore.cpp
 *
 *  Created on: 25 Aug 2011
 *      Author: aat
 */

#include "ascore.h"
using namespace std;
ascore::ascore(int a = 0)
{
	if (a > 0)
		this->rawscore = a;
	else
		a = 0;
}

ascore::ascore(int a = 0, string koei = "nix")
{
	if (a > 0)
		this->rawscore = a;
	else
		a = 0;
	this->name = koei;

	this->color.b = 1;
	this->color.r = 1;
	this->color.g = 1;
	this->color.unused = 1;
	//this->font =  NULL;
	this->fontname = "nix";
	this->fontsize = 12;
	this->ofsetx = 0;
	this->ofsety = 0;

}


SDL_Surface* ascore::get_picscore()
{

	return this->scores;
}

void ascore::convert()
{

	this->font = TTF_OpenFont( this->fontname.c_str(), this->fontsize );

	this->scores = TTF_RenderText_Blended( this->font, this->get_com_score().c_str(), this->color );
	if (this->scores == NULL)
		cout << "de text is niet omgezet naar een surface" << endl;

}

void ascore::update()
{
	SDL_FreeSurface(scores);
	this->scores = TTF_RenderText_Blended( this->font, this->get_com_score().c_str(), this->color );
		if (this->scores == NULL)
			cout << "de text is niet omgezet naar een surface" << endl;

}



void ascore::set_font(string nana,int size)
{
	this->fontsize = size;
	this->fontname = nana;
}



void ascore::set_color(SDL_Color coco)
{
	this->color = coco;
}


void ascore::set_name(string na)
{
	this->name = na;
}

void ascore::set_score(int i)
{
	if (i > 0)
	{
		this->rawscore = i;
	}
	else
	{
		this->rawscore = 0;
	}
}

string ascore::get_name()
{
	return this->name;
}

int ascore::get_score()
{
	return this->rawscore;
}

string ascore::get_com_score()
{
	string tempstr;
	this->my_itoa(this->rawscore,tempstr,10);
	return this->name + this->seperator + tempstr;
}

string ascore::get_com2_score()
{
	string tempstr;
	this->my_itoa(this->rawscore,tempstr,10);
	return this->name + " " + tempstr;
}


void ascore::my_itoa(int value, std::string& buf, int base)
{

	//int i = 30;

	buf = "";

	if (value == 0)
	{
	buf = "0";
	}
	else
	{
	for(int i = 30; value && i ; --i, value /= base) buf = "0123456789abcdef"[value % base] + buf;
	}
}

string ascore::get_font_name()
{
	return this->fontname;
}

int ascore::get_font_size()
{
	return this->fontsize;
}

void ascore::set_sep(string str)
{
	this->seperator = str;
}

void ascore::set_ofx(int x)
{
	this->ofsetx = x;
}

void ascore::set_ofy(int y)
{
	this->ofsety = y;
}

int ascore::get_ofx()
{
	return this->ofsetx;
}

int ascore::get_ofy()
{
	return this->ofsety;
}



