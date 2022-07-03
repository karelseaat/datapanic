/*
 * actioncont.h
 *
 *  Created on: 14 Aug 2011
 *      Author: aat
 */

#ifndef ACTIONCONT_H_
#define ACTIONCONT_H_

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <vector>
#include <string>
#include "active.h"
#include "boost/smart_ptr.hpp"
#include <algorithm>
#include "tilemap.h"

typedef std::vector< boost::shared_ptr<active> > actives;

class activecont
{
private:

	actives activess;
	std::vector< boost::shared_ptr<active> >::iterator iter;
	tilemap *interactm;
	unsigned int index,length;
	int levelwidth,levelheight;

public:
	activecont();
	~activecont();

	void add_active(active*);
	active* get_active(unsigned int);
	active get_next();
	active get_prev();
	unsigned int get_length();
	void update();
	bool sorty( active*,  active*);
	bool sortx( active*,  active*);
	bool bordercol(active*);
	void set_col_tilem(tilemap*);
	bool tilecol(active*);
	bool endcol(active*);
	bool activecol(active*,int);
	bool check_collision( SDL_Rect, active* );
	bool check_collision( active*, active* );
	void get_savestart(SDL_Rect,string);


};


#endif /* ACTIONCONT_H_ */
