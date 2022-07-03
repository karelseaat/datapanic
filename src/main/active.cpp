/*
 * active.cpp
 *
 *  Created on: 1 Aug 2011
 *      Author: aat
 */
#include "active.h"

active::active(sprite *asprite, sprite *bsprite)
{

    //Initialize the offsets

    this->pcollbox.x = 0;
    this->pcollbox.y = 0;
    this->pcollbox.w = 10;
    this->pcollbox.h = 10;

    this->acollbox.x = 0;
    this->acollbox.y = 0;
    this->acollbox.w = 10;
    this->acollbox.h = 10;

    this->tcollbox.x = 0;
    this->tcollbox.y = 0;
    this->tcollbox.w = 10;
    this->tcollbox.h = 10;

	//animation
    this->currcanim = new animation("RIGHT","1,1,2,2,3,3,4,4");
    this->currsanim = new animation("RIGHT","1,2,3,4,5,6,7,8");

    this->currsanim = new animation("LEFT","16,15,14,13,12,11,10,9");
    this->currcanim = new animation("LEFT","16,15,14,13,12,11,10,9");

    //Initialize the velocity
    //Vector2D position(0,0);

    frame = 0;
   // this->set_name("act+ar",rand()%50+1);


    	this->csprite = csprite;
    	this->ssprite = ssprite;


}

active::active()
{

 //Initialize the offsets
    this->pcollbox.x = 0;
    this->pcollbox.y = 0;
    this->pcollbox.w = 10;
    this->pcollbox.h = 10;

    this->acollbox.x = 0;
    this->acollbox.y = 0;
    this->acollbox.w = 10;
    this->acollbox.h = 10;

      this->tcollbox.x = 0;
      this->tcollbox.y = 0;
      this->tcollbox.w = 10;
      this->tcollbox.h = 10;

    //Vector2D position(0,0);

    //this->set_name("act-ar",rand()%50+1);
    this->currcanim = new animation("RIGHT","1,2,3,4,5,6,7,8");
    this->currsanim = new animation("RIGHT","1,2,3,4,5,6,7,8");

    this->currsanim = new animation("LEFT","16,15,14,13,12,11,10,9");
    this->currcanim = new animation("LEFT","16,15,14,13,12,11,10,9");

	this->csprite = new sprite();
	this->ssprite = new sprite();

    //Initialize the velocity

    frame = 0;

}

active::~active(){}

void active::update(){}

void active::animate(){}

void active::steer(){}

void active::move(){}


//void active::add_c_ani(animation an)
//{
//	this->canims.push_back(an);
//}

//void active::add_s_ani(animation an)
//{
//	this->sanims.push_back(an);
//}


animation* active::get_curr_c_ani()
{

	return this->currcanim;
}

animation* active::get_curr_s_ani()
{
	return this->currsanim;
}

void active::set_curr_c_ani(animation *cc)
{
	this->currcanim = cc;
}

void active::set_curr_s_ani(animation *ss)
{
	this->currcanim = ss;
}

SDL_Rect active::get_tcoll_box()
{
	return this->tcollbox;
}

SDL_Rect active::get_acoll_box()
{
	return this->acollbox;
}

SDL_Rect active::get_pcoll_box()
{
	return this->pcollbox;
}

sprite active::get_c_sprite()
{
	return *this->csprite;
}

sprite active::get_s_sprite()
{
	return *this->ssprite;
}
/*
void active::set_name(string na,int nr)
{
	ostringstream n_str;

	n_str << nr;
	this->name=na + n_str.str();
}

string active::get_name()
{
 return this->name;
}

string active::get_base_name()
{
 return this->name.substr(0,3);
}

bool active::compare(const active &ac)
{
	if (this->name == ac.name)
	{
		return true;
	}
return false;
}
*/

Vector2D active::get_position()
{
	return this->position;
}

void active::set_position(Vector2D pos)
{
	this->position = Vector2D(100,100);
	cout << "setting position "<< position.y << endl;

}



void active::copy(active ac)
{
}
/*
bool active::get_by_name(string na)
{

	if (this->name.substr(0,3) == na)
	{
		return true;
	}
	return false;
}
*/



popetje::popetje(SDL_Event* ev,sprite *spritea, sprite *spriteb)
{

	//Initialize the offsets
    this->pcollbox.x = 0;
    this->pcollbox.y = 0;
    this->pcollbox.w = 10;
    this->pcollbox.h = 10;

    this->acollbox.x = spritea->get_width()/4;
    this->acollbox.y = 30;
    this->acollbox.w = spritea->get_width() - (spritea->get_width()/4);
    this->acollbox.h = 30;

    this->tcollbox.x = spritea->get_width()/4;
    this->tcollbox.y = 30;
    this->tcollbox.w = spritea->get_width() - (spritea->get_width()/4);
    this->tcollbox.h = 30;


    this->currcanim = new animation("RIGHT","1,1,2,2,3,3,4,4");
    this->currsanim = new animation("RIGHT","1,1,2,2,3,3,4,4");

    this->currsanim = new animation("LEFT","16,15,14,13,12,11,10,9");
    this->currcanim = new animation("LEFT","16,15,14,13,12,11,10,9");

    boost::shared_ptr<condition> aCond(new condition(10,10,false));
    this->thecond = aCond;
    frame = 0;
    event = ev;
    this->csprite = spritea;
    this->ssprite = spriteb;
    //this->set_name("pop+ar",rand()%50+1);
    this->position = Vector2D(0,0);
    this->velocity = Vector2D(0,0);

}


popetje::popetje()
{

 //Initialize the offsets
    this->pcollbox.x = 0;
    this->pcollbox.y = 0;
    this->pcollbox.w = 10;
    this->pcollbox.h = 10;

    this->acollbox.x = 0;
    this->acollbox.y = 0;
    this->acollbox.w = 10;
    this->acollbox.w = 10;

    this->tcollbox.x = 0;
    this->tcollbox.y = 0;
    this->tcollbox.w = 10;
    this->tcollbox.h = 30;


    this->currcanim = new animation("RIGHT","1,1,2,2,3,3,4,4");
    this->currsanim = new animation("RIGHT","1,1,2,2,3,3,4,4");

    this->currsanim = new animation("LEFT","16,15,14,13,12,11,10,9");
    this->currcanim = new animation("LEFT","16,15,14,13,12,11,10,9");
    event = 0;
    frame = 0;
    //status = 1;
    boost::shared_ptr<condition> aCond(new condition(10,10,false));
    this->thecond = aCond;
   // this->set_name("pop-ar",rand()%50+1);
    this->position =  Vector2D(0,0);
    this->velocity =  Vector2D(0,0);

}


void popetje::steer()
{

	//todo ipv get csteer uit een conditie te halen die er nu niet meer in zit kan ge worden
	//gecontroleerdof iets een poppetje is noor bijvoorbeeld de naam die nu wel in de conditie zit.
	//dit alles is natuurlijk deels voor de fsm die ook nog eens moet worden aangepast om uitgesplitst te worden in verschillende fsms
	//if (!this->cond.get_c_steer())
	//{
    //If a key was pressed
		if( event->type == SDL_KEYDOWN )
		{

        //Adjust the velocity
			switch( event->key.keysym.sym)
			{
				case SDLK_UP:
					velocity.y -= this->csprite->get_height()/ 8;
            	break;

				case SDLK_DOWN:
						velocity.y += this->csprite->get_height()/ 8;
            	break;

				case SDLK_LEFT:
						velocity.x -= this->csprite->get_width() / 8;
						this->currsanim = new animation("RIGHT","1,1,2,2,3,3,4,4");
						this->currcanim = new animation("RIGHT","1,1,2,2,3,3,4,4");
				break;
				case SDLK_RIGHT:
						velocity.x = this->csprite->get_width() / 8;
						this->currcanim = new animation("LEFT","5,5,6,6,7,7,8,8");
						this->currsanim = new animation("LEFT","5,5,6,6,7,7,8,8");
				break;
			}

			//todo de lastdit zoals hieronder stond ook in een condition, nu niet meer, de last velocity is eigenlijk een lapmiddel dat nog niet eens echt werkt.
			//wat er dan ook ijgenlijk moet gebeuren is de collode detection solide maken en een trug stuiter in een rechte hoek maken.
			//this->cond.set_last_dir(velocity);
		}
    //If a key was released

		else if( event->type == SDL_KEYUP )
		{

        //Adjust the velocity
			switch( event->key.keysym.sym )
			{
				case SDLK_UP: velocity.y = 0;
				break;
				case SDLK_DOWN: velocity.y = 0;
				break;
				case SDLK_LEFT: velocity.x = 0;
				break;
				case SDLK_RIGHT: velocity.x = 0;
				break;

			}
		}








}

void popetje::move()
{
		position.x += velocity.x;
		position.y += velocity.y;
}

void popetje::animate()
{

	if (velocity.x == 0 && velocity.y == 0)
	{
		this->currcanim->reset_ani();
		this->currsanim->reset_ani();
		this->currcanim->stopani();
		this->currsanim->stopani();
	}
	else
	{
		this->currcanim->startani();
		this->currsanim->startani();
	}
	//this->cond.
	currsanim->get_next();
	currcanim->get_next();

}


void popetje::set_velocity(Vector2D v)
{
	this->velocity = v;
}

Vector2D popetje::get_velocity()
{
	return this->velocity;
}


int popetje::get_xvel()
{
return velocity.x;
}

int popetje::get_yvel()
{
return velocity.y;
}

void popetje::update()
{
	this->move();
	this->animate();
	this->enmfsm->Update(1);
}

void popetje::set_start_pos(Vector2D lepos)
{
	this->startpos = lepos;
	this->position = this->startpos;
}

Vector2D popetje::get_start_pos()
{
	return this->startpos;
}

void popetje::set_fsm(FSM* myf)
{
	this->enmfsm = myf;
	this->enmfsm->set_dir_controll(&this->velocity);
	this->enmfsm->set_cani_controll(this->currcanim);
	this->enmfsm->set_sani_controll(this->currsanim);
	this->enmfsm->set_condi_controll(this->thecond.get());
	//this->enmfsm->set_name_controll(&this->name);
}

FSM* popetje::get_fsm()
{
	return this->enmfsm;
}

Vector2D popetje::get_position()
{
	return this->position;
}

void popetje::set_position(Vector2D pos)
{
	this->position = pos;
}

condition* popetje::get_condition()
{
	return this->thecond.get();
}

void popetje::set_condition(condition* co)
{
	boost::shared_ptr<condition> aCond(co);
	this->thecond = aCond;
}





enemy::enemy(sprite *spritea,sprite *spriteb)
{

    //Initialize the offsets
    this->pcollbox.x = 0;
    this->pcollbox.y = 0;
    this->pcollbox.w = 10;
    this->pcollbox.h = 10;

    this->acollbox.x = spritea->get_width() /4;
    this->acollbox.y = 20;
    this->acollbox.w = spritea->get_width() /2;
    this->acollbox.h = 20;

    this->tcollbox.x = spritea->get_width() /4;
    this->tcollbox.y = 20;
    this->tcollbox.w = spritea->get_width() /2;
    this->tcollbox.h = 20;

    this->currcanim = new animation("RIGHT","1,2,3,4,5,6,7,8");
    this->currsanim = new animation("RIGHT","1,2,3,4,5,6,7,8");
    this->position =  Vector2D(0,0);
    this->velocity =  Vector2D(0,0);

    //Initialize the velocity
    boost::shared_ptr<condition> aCond(new condition(10,10,false));
    this->thecond = aCond;
	enmfsm = new FSM();
    frame = 0;
    csprite = spritea;
    ssprite = spriteb;
    //de naam is nu uit het poppetje zelf gehaald en zit in de condietie
    //todo hiervoor moet de rest van de code vast er zeker ook wel weer worden aangepast.
    //this->set_name("enm+ar",rand()%50+1);

}

enemy::enemy()
{

 //Initialize the offsets
    this->pcollbox.x = 0;
    this->pcollbox.y = 0;
    this->pcollbox.w = 10;
    this->pcollbox.h = 10;

    this->acollbox.x = 0;
    this->acollbox.y = 0;
    this->acollbox.w = 10;
    this->acollbox.h = 10;

    this->tcollbox.x = 0;
    this->tcollbox.y = 0;
    this->tcollbox.w = 10;
    this->tcollbox.h = 10;


    this->currcanim = new animation("RIGHT","1,2,3,4,5,6,7,8");
    this->currsanim = new animation("RIGHT","1,2,3,4,5,6,7,8");

    this->currcanim = new animation("LEFT","16,15,14,13,12,11,10,9");
    this->currsanim = new animation("LEFT","16,15,14,13,12,11,10,9");
    this->position = Vector2D(0,0);
    this->velocity = Vector2D(0,0);
    //todo de problemen die ontstaan door de naam van pop naar conditie te verplaatsen oplossen.
    //this->set_name("enm-ar",rand()%50+1);
    //this->enmfsm = new FSM();
    csprite = 0;
    ssprite = 0;

    //Initialize the velocity

    boost::shared_ptr<condition> aCond(new condition(10,10,false));
    this->thecond = aCond;
    frame = 0;
    //status = 1;
    //this->name = "-enemy";

}

int enemy::get_xvel()
{
	return  velocity.x;
}

int enemy::get_yvel()
{
	return  velocity.y;
}

void enemy::set_velocity(Vector2D v)
{
	this->velocity = v;
}

Vector2D enemy::get_velocity()
{
	return this->velocity;
}


void enemy::animate()
{
	currcanim->get_next();
	currsanim->get_next();
}

void enemy::update()
{
	this->animate();
	this->move();
	this->steer();
}

void enemy::move()
{
	    position.x += velocity.x;
	    position.y += velocity.y;
}


void enemy::steer()
{

		this->enmfsm->Update(1);

}

void enemy::set_fsm(FSM* myf)
{

	this->enmfsm = myf;
	this->enmfsm->set_dir_controll(&this->velocity);
	this->enmfsm->set_cani_controll(this->currcanim);
	this->enmfsm->set_sani_controll(this->currsanim);
	this->enmfsm->set_condi_controll(this->thecond.get());
	//this->enmfsm->set_name_controll(&this->name);


}

FSM* enemy::get_fsm()
{
	return this->enmfsm;
}



Vector2D enemy::get_position()
{
	return this->position;
}

void enemy::set_position(Vector2D pos)
{
	this->position = pos;
}


condition* enemy::get_condition()
{
	return this->thecond.get();
}

void enemy::set_condition(condition* co)
{
	boost::shared_ptr<condition> aCond(co);
	this->thecond = aCond;
}

void enemy::set_start_pos(Vector2D lepos)
{
	this->startpos = lepos;
	this->position = this->startpos;
}

Vector2D enemy::get_start_pos()
{
	return this->startpos;
}

statisch::statisch(sprite *spritea,sprite *spriteb)
{

    //Initialize the offsets
    this->pcollbox.x = 0;
    this->pcollbox.y = 0;
    this->pcollbox.w = 10;
    this->pcollbox.h = 10;

    this->acollbox.x = spritea->get_width() /4;
    this->acollbox.y = 20;
    this->acollbox.w = spritea->get_width() /2;
    this->acollbox.h = 20;

    this->tcollbox.x = spritea->get_width() /4;
    this->tcollbox.y = 20;
    this->tcollbox.w = spritea->get_width() /2;
    this->tcollbox.h = 20;

    this->currcanim = new animation("RIGHT","1,2,3,4,5,6,7,8");
    this->currsanim = new animation("RIGHT","1,2,3,4,5,6,7,8");
    this->position =  Vector2D(0,0);
    this->velocity =  Vector2D(0,0);

    //Initialize the velocity
    boost::shared_ptr<condition> aCond(new condition(10,10,false));
    this->thecond = aCond;
	enmfsm = new FSM();
    frame = 0;
    csprite = spritea;
    ssprite = spriteb;
    //this->set_name("sta+ar",rand()%50+1);

}

statisch::statisch()
{

 //Initialize the offsets
    this->pcollbox.x = 0;
    this->pcollbox.y = 0;
    this->pcollbox.w = 10;
    this->pcollbox.h = 10;

    this->acollbox.x = 0;
    this->acollbox.y = 0;
    this->acollbox.w = 10;
    this->acollbox.h = 10;

    this->tcollbox.x = 0;
    this->tcollbox.y = 0;
    this->tcollbox.w = 10;
    this->tcollbox.h = 10;


    this->currcanim = new animation("RIGHT","1,2,3,4,5,6,7,8");
    this->currsanim = new animation("RIGHT","1,2,3,4,5,6,7,8");

    this->currcanim = new animation("LEFT","16,15,14,13,12,11,10,9");
    this->currsanim = new animation("LEFT","16,15,14,13,12,11,10,9");
    this->position = Vector2D(0,0);
    this->velocity = Vector2D(0,0);
    //this->set_name("sta-ar",rand()%50+1);
    //this->enmfsm = new FSM();
    csprite = 0;
    ssprite = 0;

    //Initialize the velocity

    boost::shared_ptr<condition> aCond(new condition(10,10,false));
    this->thecond = aCond;
    frame = 0;
    //status = 1;
    //this->name = "-enemy";

}

void statisch::animate()
{
	currcanim->get_next();
	currsanim->get_next();
}

void statisch::update()
{
	this->animate();
	this->steer();
}


void statisch::steer()
{
		this->enmfsm->Update(1);
}

void statisch::set_fsm(FSM* myf)
{
	this->enmfsm = myf;
	this->enmfsm->set_dir_controll(&this->velocity);
	this->enmfsm->set_cani_controll(this->currcanim);
	this->enmfsm->set_sani_controll(this->currsanim);
	this->enmfsm->set_condi_controll(this->thecond.get());
	//this->enmfsm->set_name_controll(&this->name);
}

FSM* statisch::get_fsm()
{
	return this->enmfsm;
}

Vector2D statisch::get_position()
{
	return this->position;
}

void statisch::set_position(Vector2D pos)
{
	this->position = pos;
}


condition* statisch::get_condition()
{
	return this->thecond.get();
}

void statisch::set_condition(condition* co)
{

	boost::shared_ptr<condition> aCond(co);
	this->thecond = aCond;
}

void statisch::set_start_pos(Vector2D lepos)
{
	this->startpos = lepos;
	this->position = this->startpos;
}

Vector2D statisch::get_start_pos()
{
	return this->startpos;
}


