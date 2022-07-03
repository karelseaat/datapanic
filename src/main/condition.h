/*
 * condition.h
 *
 *  Created on: 6 Aug 2011
 *      Author: aat
 */

#ifndef CONDITION_H_
#define CONDITION_H_
#include "Vector2D.h"
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>


using namespace std;

class condition
{

protected:
	unsigned int damage,maxdamage;
	unsigned int health,maxhealth;
	bool invincible,active,showname;
	unsigned int weight,maxweight;
	string name;

public:
	condition();
	condition(int,int,int);


	virtual unsigned int get_health();
	virtual int set_health(unsigned int);
	virtual int plus_health(int);
	virtual void set_max_health(unsigned int);

	virtual unsigned int get_panic();
	virtual int set_panic(unsigned int);
	virtual int plus_panic(int);
	virtual void set_max_panic(unsigned int);

	unsigned int get_damage();
	int set_damage(unsigned int);
	int plus_damage(int);
	void set_max_damage(unsigned int);

	virtual unsigned int get_stamina();
	virtual int set_stamina(unsigned int);
	virtual int plus_stamina(int);
	virtual void set_max_stamina(unsigned int);

	virtual int set_punchdamage(unsigned int);
	virtual unsigned int get_puchdamage();
	virtual void set_max_punchdamage(unsigned int);

	virtual int set_kickdamage(unsigned int);
	virtual unsigned int get_kickdamage();
	virtual void set_max_kickdamage(unsigned int);

	void set_invincible(bool);
	bool get_invincible();

	bool get_showname();
	void set_showname(bool);

	void set_name(string,int);

	string get_com_name();
	string get_tot_name();
	string get_game_name();


	virtual unsigned int get_weight();
	virtual int set_weight(unsigned int);
	virtual void set_max_weight(unsigned int);

	virtual bool get_active();
	virtual void set_active(bool);

	virtual bool get_win();
	virtual void set_win(bool);

	virtual bool get_lose();
	virtual void set_lose(bool);

	virtual unsigned int get_score();
	virtual int set_score(unsigned int);
	virtual int plus_score(int);

	void reset();

};

class popcondition : public condition
{
private:
	unsigned int impulse,maximpulse;
	bool win, lose;
	unsigned int score;
	unsigned int punchdamage,maxpunchdamage;
	unsigned int kickdamage, maxkickdamage;
	unsigned int panic, maxpanic;
	unsigned int stamina,maxstamina;

public:
	popcondition();
	popcondition(int,int,int,int,int,int,int,int);

	int plus_health(int);

	unsigned int get_panic();
	int set_panic(unsigned int);
	int plus_panic(int);
	void set_max_panic(unsigned int);

	unsigned int get_stamina();
	int set_stamina(unsigned int);
	int plus_stamina(int);
	void set_max_stamina(unsigned int);

	int set_punchdamage(unsigned int);
	unsigned int get_puchdamage();
	void set_max_punchdamage(unsigned int);

	int set_kickdamage(unsigned int);
	unsigned int get_kickdamage();
	void set_max_kickdamage(unsigned int);

	unsigned int get_weight();
	int set_weight(unsigned int);
	void set_max_weight(unsigned int);

	bool get_win();
	void set_win(bool);

	bool get_lose();
	void set_lose(bool);

	unsigned int get_score();
	int set_score(unsigned int);
	int plus_score(int);

	void reset();


};

class enmcondition : public condition
{
private:
	unsigned int impulse,maximpulse;
	unsigned int punchdamage,maxpunchdamage;
	unsigned int kickdamage, maxkickdamage;
	unsigned int panic, maxpanic;
	unsigned int stamina,maxstamina;

public:
	enmcondition();
	enmcondition(int,int,int,int,int,int,int,int);

		unsigned int get_panic();
		int set_panic(unsigned int);
		int plus_panic(int);
		void set_max_panic(unsigned int);

		unsigned int get_stamina();
		int set_stamina(unsigned int);
		int plus_stamina(int);
		void set_max_stamina(unsigned int);

		int set_punchdamage(unsigned int);
		unsigned int get_puchdamage();
		void set_max_punchdamage(unsigned int);

		int set_kickdamage(unsigned int);
		unsigned int get_kickdamage();
		void set_max_kickdamage(unsigned int);

		unsigned int get_weight();
		int set_weight(unsigned int);
		void set_max_weight(unsigned int);

		bool get_win();
		void set_win(bool);

		bool get_lose();
		void set_lose(bool);

		unsigned int get_score();
		int set_score(unsigned int);
		int plus_score(int);

		virtual void reset();
};

class stacondition : public condition
{
public:
	stacondition();
	stacondition(int,int,int);

	void reset();


};
#endif /* CONDITION_H_ */
