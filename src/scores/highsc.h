/*
 * highsc.h
 *
 *  Created on: 25 Aug 2011
 *      Author: aat
 */

#ifndef HIGHSC_H_
#define HIGHSC_H_

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "ascore.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>


using namespace std;

class highsc
{
private:
	string filenames,names;
	vector <ascore*> scores;
	bool vertical;
	int posx,posy,length;

	public:
	highsc(string,int,int);
	~highsc();
	string readfile();
	void writefile(const char*);
	void set_filename(string);
	string get_filename();
	void set_vertical();
	void set_horizontal();
	ascore* get_score(int);
	void add_score(ascore*);
	void sort_score();
	void update();
	void translate();
	string split(string, char,int);
	bool sortonscore(ascore a,ascore b);
	void sort();
	void init_all();
	void finish_all();
	int numof(string ,char );
	int get_length();
	int get_xpos(int);
	int get_ypos(int);
	void filterstr(string&, char);
	string randomname();
	int countwords(string, char);



};

#endif /* HIGHSC_H_ */
