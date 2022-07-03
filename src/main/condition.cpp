/*
 * condition.cpp
 *
 *  Created on: 6 Aug 2011
 *      Author: aat
 */

#include "condition.h"

condition::condition()
{
	this->health = this->maxhealth = 10;
	this->damage = this->maxdamage = 10;
	this->weight = this->maxweight = 10;
	this->invincible = false;
	this->active = false;
	this->showname = false;
	this->set_name("con+",rand()%50+1);
}

condition::condition(int dam,int he,int we)
{
	this->maxhealth = this->health = he;
	this->maxdamage = this->damage = dam;
	this->maxweight = this->weight = we;
	this->invincible = false;
	this->active = false;
	this->showname = false;
	this->set_name("con+",rand()%50+1);
}


unsigned int condition::get_health()
{
	return this->health;
}

int condition::set_health(unsigned int f)
{
	if((f) > this->maxhealth)
	{
		this->health = this->maxhealth;
		return 0;
	}
	else
	{
		this->health = f;
		return 1;
	}
}

int condition::plus_health(int f)
{
	if(f + this->health > 0)
	{
	if((f + this->health) > this->maxhealth)
	{
		this->health = this->maxhealth;
		return 0;
	}
	else
	{
		this->health += f;
		return 1;
	}
	}
	else
	{
		this->health = 0;
		return 0;
	}
}

void condition::set_max_health(unsigned int he)
{
	this->maxhealth = he;
}

unsigned int condition::get_panic(){}

int condition::set_panic(unsigned int){}

int condition::plus_panic(int){}

void condition::set_max_panic(unsigned int){}

unsigned int condition::get_damage()
{
	return this->damage;
}

int condition::set_damage(unsigned int dam)
{
	if (dam <= this->maxdamage)
	{
	this->damage = dam;
	return 1;
	}
	else
	{
	this->damage = this->maxdamage;
	return 0;
	}
}

int condition::plus_damage(int dam)
{
	if((dam + this->damage) > this->maxdamage)
	{
		this->damage = this->maxdamage;
		return 0;
	}
	else
	{
		this->damage += dam;
		return 1;
	}
}

void condition::set_max_damage(unsigned int maxd)
{
	this->maxdamage = maxd;
}

unsigned int condition::get_stamina(){}

int condition::set_stamina(unsigned int){}

int condition::plus_stamina(int){}

void condition::set_max_stamina(unsigned int){}

int condition::set_punchdamage(unsigned int){}

unsigned int condition::get_puchdamage(){}

void condition::set_max_punchdamage(unsigned int){}

int condition::set_kickdamage(unsigned int){}

unsigned int condition::get_kickdamage(){}

void condition::set_max_kickdamage(unsigned int){}

void condition::set_invincible(bool in)
{
	this->invincible = in;
}

bool condition::get_invincible()
{
	return this->invincible;
}

void condition::set_name(string na,int nr)
{
	ostringstream n_str;
	n_str << nr;
	this->name=na + n_str.str();
}

bool condition::get_showname()
{
	return this->showname;
}

void condition::set_showname(bool show)
{
	this->showname = show;
}

string condition::get_com_name()
{
	return this->name.substr(0,3);
}

string condition::get_tot_name()
{
	return this->name;
}

string condition::get_game_name()
{
	return this->name.substr(3,100);
}

unsigned int condition::get_weight()
{}

int condition::set_weight(unsigned int)
{}

void condition::set_max_weight(unsigned int)
{}



bool condition::get_active()
{
	return this->active;
}

void condition::set_active(bool ac)
{
	this->active = ac;
}

bool condition::get_win(){}

void condition::set_win(bool){}

bool condition::get_lose(){}

void condition::set_lose(bool){}

unsigned int condition::get_score(){}

int condition::set_score(unsigned int){}

int condition::plus_score(int){}

//de fuctions die in een klasse anders heten voor poppetje, methoden ofzo ?

void condition::reset()
{
this->health = 50;
}

popcondition::popcondition()
{
	this->maximpulse = this->impulse = 10;
	this->maxkickdamage = this->kickdamage = 10;
	this->maxpanic = this->panic = 10;
	this->maxpunchdamage = this->punchdamage = 10;
	this->maxstamina = this->stamina = 10;
	this->maxweight = this->weight = 10;
	this->maxdamage = this->damage = 10;
	this->maxhealth = this->health = 10;
	this->invincible = false;
	this->lose = false;
	this->win = false;
	this->active = false;
	this->showname = false;
	this->set_name("pop+",rand()%50+1);
}

popcondition::popcondition(int im,int ki,int pa,int pu,int st,int we,int da,int he)
{
	this->maximpulse = this->impulse = im;
	this->maxkickdamage = this->kickdamage = ki;
	this->maxpanic = this->panic = pa;
	this->maxpunchdamage = this->punchdamage = pu;
	this->maxstamina = this->stamina = st;
	this->maxweight = this->weight = we;
	this->maxdamage = this->damage = da;
	this->maxhealth = this->health = he;
	this->invincible = false;
	this->lose = false;
	this->win = false;
	this->active = false;
	this->showname = false;
	this->set_name("pop+",rand()%50+1);
}

int popcondition::plus_health(int f)
{
	if((f + this->health) > 1 && this->health != 1)
	{
		//cout << (f + this->health) << endl;
	if((f + this->health) > this->maxhealth)
	{
		this->health = this->maxhealth;
		return 0;
	}
	else
	{
		this->health += f;
		return 1;
	}
	}
	else
	{
		cout << (f + this->health) << endl;
		this->health = 1;
		this->lose = true;
	}
}

unsigned int popcondition::get_panic()
{
	return this->panic;
}

int popcondition::set_panic(unsigned int pa)
{
	if (pa <= this->maxpanic)
	{
	this->panic = pa;
	return 1;
	}
	else
	{
	this->panic = this->maxpanic;
	return 0;
	}
}

int popcondition::plus_panic(int pa)
{
	if (pa + this->panic <= this->maxpanic)
	{
		this->panic =+ pa;
		return 1;
	}
	else
	{
		this->panic = this->maxpanic;
		return 0;
	}
}

void popcondition::set_max_panic(unsigned int pa)
{
	this->maxpanic = pa;
}

unsigned int popcondition::get_stamina()
{
	return this->stamina;
}

int popcondition::set_stamina(unsigned int st)
{
	if (st <= this->maxstamina)
	{
	this->stamina = st;
	return 1;
	}
	else
	{
	this->stamina = this->maxstamina;
	return 0;
	}
}

int popcondition::plus_stamina(int st)
{
	if (st + this->stamina <= this->maxstamina)
	{
		this->stamina =+ st;
		return 1;
	}
	else
	{
		this->stamina = this->maxstamina;
		return 0;
	}
}

void popcondition::set_max_stamina(unsigned int st)
{
	this->maxstamina = st;
}

int popcondition::set_punchdamage(unsigned int pd)
{
	if (pd <= this->maxpunchdamage)
	{
	this->punchdamage = pd;
	return 1;
	}
	else
	{
	this->punchdamage = this->maxpunchdamage;
	return 0;
	}
}

unsigned int popcondition::get_puchdamage()
{
	return this->punchdamage;
}

void popcondition::set_max_punchdamage(unsigned int mpd)
{
	this->maxpunchdamage = mpd;
}

int popcondition::set_kickdamage(unsigned int skd)
{
	if (skd <= this->maxkickdamage)
	{
		this->kickdamage = skd;
		return 1;
	}
	else
	{
		this->kickdamage = this->maxkickdamage;
		return 0;
	}
}

unsigned int popcondition::get_kickdamage()
{
	return this->kickdamage;
}

void popcondition::set_max_kickdamage(unsigned int ki)
{
	this->maxkickdamage = ki;
}

unsigned int popcondition::get_weight()
{
	return this->weight;
}

int popcondition::set_weight(unsigned int we)
{
	if (we <= this->maxweight)
	{
		this->weight = we;
		return 1;
	}
	else
	{
		this->weight = this->maxweight;
		return 0;
	}
}

void popcondition::set_max_weight(unsigned int maxw)
{
	this->maxweight = maxw;
}

bool popcondition::get_win()
{
	return this->win;
}

void popcondition::set_win(bool wi)
{
	this->win = wi;
}

bool popcondition::get_lose()
{
	return this->lose;
}

void popcondition::set_lose(bool lo)
{
	this->lose = lo;
}

unsigned int popcondition::get_score()
{
	return this->score;
}

int popcondition::set_score(unsigned int sco)
{
	if (sco <= 4294967294)
	{
		this->score = sco;
		return 1;
	}
	else
	{
		this->score = 4294967294;
		return 0;
	}
}

int popcondition::plus_score(int sco)
{
	if ((sco + this->score <= 4294967295) && (sco + this->score >= 0))
	{
		this->score =+ sco;
		return 1;
	}
	else if (sco + this->score >= 0)
	{
		this->score = 4294967295;
		return 0;
	}
	else
	{
		this->score = 4294967295;
		return 0;
	}
}

void popcondition::reset()
{
	this->active = true;
	this->health = this->maxhealth;
	this->invincible = false;
	this->showname = false;
	this->lose = false;
	this->win = false;
	this->panic = 0;
	this->score = 0;
	this->stamina = this->maxstamina;
}

// de methoden voor de vijhanden

enmcondition::enmcondition()
{
	this->maximpulse = this->impulse = 10;
	this->maxkickdamage = this->kickdamage = 10;
	this->maxpanic = this->panic = 10;
	this->maxpunchdamage = this->punchdamage = 10;
	this->maxstamina = this->stamina = 10;
	this->maxweight = this->weight = 10;
	this->maxdamage = this->damage = 10;
	this->maxhealth = this->health = 10;
	this->invincible = false;
	this->active = false;
	this->showname = false;
	this->set_name("enm",rand()%50+1);
}

enmcondition::enmcondition(int im,int ki,int pa,int pu,int st,int we,int da,int he)
{
	this->maximpulse = this->impulse = im;
	this->maxkickdamage = this->kickdamage = ki;
	this->maxpanic = this->panic = pa;
	this->maxpunchdamage = this->punchdamage = pu;
	this->maxstamina = this->stamina = st;
	this->maxweight = this->weight = we;
	this->maxdamage = this->damage = da;
	this->maxhealth = this->health = he;
	this->invincible = false;
	this->active = false;
	this->showname = false;
	this->set_name("enm+",rand()%50+1);
}


unsigned int enmcondition::get_panic()
{
	return this->panic;
}

int enmcondition::set_panic(unsigned int pa)
{
	if (pa <= this->maxpanic)
	{
	this->panic = pa;
	return 1;
	}
	else
	{
	this->panic = this->maxpanic;
	return 0;
	}
}

int enmcondition::plus_panic(int pa)
{
	if (pa + this->panic <= this->maxpanic)
	{
		this->panic =+ pa;
		return 1;
	}
	else
	{
		this->panic = this->maxpanic;
		return 0;
	}
}

void enmcondition::set_max_panic(unsigned int pa)
{
	this->maxpanic = pa;
}

unsigned int enmcondition::get_stamina()
{
	return this->stamina;
}

int enmcondition::set_stamina(unsigned int st)
{
	if (st <= this->maxstamina)
	{
	this->stamina = st;
	return 1;
	}
	else
	{
	this->stamina = this->maxstamina;
	return 0;
	}
}

int enmcondition::plus_stamina(int st)
{
	if (st + this->stamina <= this->maxstamina)
	{
		this->stamina =+ st;
		return 1;
	}
	else
	{
		this->stamina = this->maxstamina;
		return 0;
	}
}

void enmcondition::set_max_stamina(unsigned int st)
{
	this->maxstamina = st;
}

int enmcondition::set_punchdamage(unsigned int pd)
{
	if (pd <= this->maxpunchdamage)
	{
	this->punchdamage = pd;
	return 1;
	}
	else
	{
	this->punchdamage = this->maxpunchdamage;
	return 0;
	}
}

unsigned int enmcondition::get_puchdamage()
{
	return this->punchdamage;
}

void enmcondition::set_max_punchdamage(unsigned int mpd)
{
	this->maxpunchdamage = mpd;
}

int enmcondition::set_kickdamage(unsigned int skd)
{
	if (skd <= this->maxkickdamage)
	{
		this->kickdamage = skd;
		return 1;
	}
	else
	{
		this->kickdamage = this->maxkickdamage;
		return 0;
	}
}

unsigned int enmcondition::get_kickdamage()
{
	return this->kickdamage;
}

void enmcondition::set_max_kickdamage(unsigned int ki)
{
	this->maxkickdamage = ki;
}

unsigned int enmcondition::get_weight()
{
	return this->weight;
}

int enmcondition::set_weight(unsigned int we)
{
	if (we <= this->maxweight)
	{
		this->weight = we;
		return 1;
	}
	else
	{
		this->weight = this->maxweight;
		return 0;
	}
}

void enmcondition::set_max_weight(unsigned int maxw)
{
	this->maxweight = maxw;
}

bool enmcondition::get_win()
{
	return false;
}

void enmcondition::set_win(bool wi)
{
}

bool enmcondition::get_lose()
{
	return false;
}

void enmcondition::set_lose(bool lo)
{
}

unsigned int enmcondition::get_score()
{
	return 0;
}

int enmcondition::set_score(unsigned int sco)
{
	return 1;
}

int enmcondition::plus_score(int sco)
{
	return 1;
}

void enmcondition::reset()
{
	this->active = true;
	this->health = this->maxhealth;
	this->invincible = false;
	this->showname = false;
	this->panic = 0;
	this->stamina = this->maxstamina;
}

//einde van enemy classe methoden of functies

stacondition::stacondition()
{
	this->health = this->maxhealth = 10;
	this->damage = this->maxdamage = 10;
	this->weight = this->maxweight = 10;
	this->invincible = false;
	this->active = false;
	this->showname = false;
	this->set_name("sta+",rand()%50+1);
}

stacondition::stacondition(int dam,int he,int we)
{
	this->maxhealth = this->health = he;
	this->maxdamage = this->damage = dam;
	this->maxweight = this->weight = we;
	this->invincible = false;
	this->active = false;
	this->showname = false;
	this->set_name("sta+",rand()%50+1);
}
