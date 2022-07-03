/*
 * actioncont.cpp
 *
 *  Created on: 14 Aug 2011
 *      Author: aat
 */
#include "activecont.h"
using namespace std;

activecont::activecont()
{
	index = 0;
}

activecont::~activecont()
{
	this->activess.clear();
}

unsigned int activecont::get_length()
{
	return this->length;
}

void activecont::add_active(active *newactive)
{

	boost::shared_ptr<active> newAct(newactive);
	activess.push_back(newAct);

	this->length = this->activess.size();
}

active* activecont::get_active(unsigned int i)
{

	if (this->activess.size() >= i && i >= 0)
		return activess[i].get();
	else
		return activess[0].get();
}



active activecont::get_next()
{
	index++;
	if (index >= this->activess.size())
		index =0;
	return *activess[index];

}

active activecont::get_prev()
{
	index--;
	if (index < 0)
		index = this->activess.size();
	return *activess[index];
}

void activecont::get_savestart(SDL_Rect start, string name)
{
	Vector2D temppos;
	int save = this->activess.size();
	for (unsigned int i=0;i<length;i++)
	{

		//if (this->activess[i].get()->get_condition().get_com_name().compare(name) == 0)
		if (this->activess[i].get()->get_condition()->get_com_name().compare(name) == 0)
		{
			temppos.x = (rand()%start.w)+start.x;
			temppos.y = (rand()%start.h)+start.y;
			this->activess[i].get()->set_start_pos(temppos);
		}
	}


	while(save>0)
	{
		for (unsigned int i=0;i<length;i++)
		{
			if (activecol(this->activess[i].get(), i ))
			{
				save++;
				temppos.x = (rand()%start.w)+start.x;
				temppos.y = (rand()%start.h)+start.y;
				this->activess[i].get()->set_start_pos(temppos);
				//cout << "i:"<< i << " x:" << temppos.x << " y:" << temppos.y << endl;
			}
			else
			{
				save--;
			}
		}
	}

}

void activecont::update()
{
	unsigned int length = this->activess.size();

	for (unsigned int i=0;i<length-1;i++)
	{
		if (sorty(activess[i].get(),activess[i+1].get()))
			activess[i].swap(activess[i+1]);
	}
	active *aactive;
	for (unsigned int i=0;i<length;i++)
	{
		aactive = this->activess[i].get();

		if (tilecol(aactive)  || activecol(aactive,i))
		{
			aactive->get_fsm()->TransitionTo("reveit");
		}


		if (bordercol(aactive) && aactive->get_fsm()->GetState().compare("muurbump") && aactive->get_fsm()->GetState().compare("reveit"))
		{

			this->activess[i].get()->get_fsm()->TransitionTo("muurbump");
		}

		this->activess[i]->update();
		if (this->activess[i]->get_condition()->get_com_name().compare("pop") == 0 && endcol(aactive))
		{
			this->activess[i].get()->get_fsm()->TransitionTo("party");
		}

		if (this->activess[i]->get_condition()->get_health() < 1)
		{
			if (this->activess[i]->get_condition()->get_com_name().compare("pop") != 0)
			{
			this->activess[i]->set_position(this->activess[i]->get_start_pos());
			this->activess[i]->get_condition()->reset();
			//cout << this->activess[i]->get_condition()->get_health() << endl;
			//this->activess[i].get()->get_fsm()->TransitionTo("stop");
			}


		}
	}


}

bool activecont::sorty(active *a, active *b)
{
	return a->get_position().y > b->get_position().y;
}

bool activecont::sortx(active *a, active *b)
{
	return a->get_position().x > b->get_position().x;
}

bool activecont::bordercol(active *x)
{
		if (x->get_fsm()->currentState->stateName != "reveit" )
		{
			if ((x->get_tcoll_box().w + x->get_position().x > this->levelwidth) || (x->get_tcoll_box().w + x->get_position().x < 0))
			{
				return true;
			}

			if ((x->get_tcoll_box().h + x->get_position().y > this->levelheight) || (x->get_tcoll_box().h  + x->get_position().y < 0))
			{
				return true;
			}
		}
		return false;
}

bool activecont::tilecol(active *x)
{

	tile *atile = new tile();
	for (int k =0;k < this->interactm->get_height();k++)
	        {
	        	for (int i =0;i < this->interactm->get_width();i++)
	        	{
	        		//cout << atile->get_box().w << " ";
	        		atile = this->interactm->get_tile(k,i);
	        		//cout << atile->get_collide() << " ";
	        		//cout << atile->get_animation().get_cur() << " ";
	        		if (atile->get_collide())
	        		{
	        			if (check_collision(atile->get_box(),x))
	        			{
							return true;
	        			}
	        		}
	        	}
	        }
return false;

}

bool activecont::endcol(active *x)
{

	tile *atile = new tile();
	for (int k =0;k < this->interactm->get_height();k++)
	        {
	        	for (int i =0;i < this->interactm->get_width();i++)
	        	{

	        		atile = this->interactm->get_tile(k,i);

	        		if (atile->get_ending())
	        		{
	        			if (check_collision(atile->get_box(),x))
	        			{
							return true;
	        			}
	        		}
	        	}
	        }
return false;

}

bool activecont::activecol(active* activeA, int i2 )
{
	for (unsigned int i=0;i<length;i++)
	{
		if (check_collision(activeA , activess[i].get()) && i2 != i)
			return true;
	}
	return false;
}

bool activecont::check_collision( SDL_Rect A, active* B )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;


    //Calculate the sides of rect B
    leftB = B->get_position().x + B->get_tcoll_box().x ;
    rightB = B->get_position().x + B->get_tcoll_box().w;
    topB = B->get_position().y + B->get_tcoll_box().y ;
    bottomB = B->get_position().y + B->get_tcoll_box().h;

   // cout << B->get_tcoll_box().w << endl;
    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        //cout << "tiletop:" << topA << " tilebottom:" << bottomA << " poptop:" << topB << " popbot:" << bottomB << endl;
    	return false;
    }

    if( topA >= bottomB )
    {
    	//cout << "tiletop:" << topA << " tilebottom:" << bottomA << " poptop:" << topB << " popbot:" << bottomB << endl;
        return false;
    }

    if( rightA <= leftB )
    {
    	//cout << "tileleft:" << leftA << " tileright:" << rightA << " popleft:" << leftB << " popright:" << rightB << endl;
        return false;
    }

    if( leftA >= rightB )
    {
    	//cout << "tileleft:" << leftA << " tileright:" << rightA << " popleft:" << leftB << " popright:" << rightB << endl;
        return false;
    }

    //If none of the sides from A are outside B
	//cout << "left tile:" << leftA << "right tile:" << rightA << " right pop:" << rightB << endl;
    return true;
}

bool activecont::check_collision( active* A , active* B )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A->get_position().x;
    rightA = A->get_position().x + A->get_acoll_box().w;
    topA = A->get_position().y;
    bottomA = A->get_position().y + A->get_acoll_box().h;


    //Calculate the sides of rect B
     leftB = B->get_position().x;
     rightB = B->get_position().x + B->get_acoll_box().w;
     topB = B->get_position().y;
     bottomB = B->get_position().y + B->get_acoll_box().h;

    //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}

void activecont::set_col_tilem(tilemap *koeis)
{
	this->interactm = koeis;
	this->levelwidth = this->interactm->get_sprite()->get_width() *  this->interactm->get_width();
	this->levelheight = this->interactm->get_sprite()->get_height() *  this->interactm->get_height();
}


