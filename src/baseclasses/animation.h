/*
 * animation.h
 *
 *  Created on: 25 Jul 2011
 *      Author: aat
 */

#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>


using namespace std;


class animation
{
	private:

	vector<int> anime;
	int index,length;
	string name;
	string split(string,char, int i);
	int strToint(string);
	bool stop;

	public:
	animation();
	animation(string);
	animation(string, string);

	int get_next();
	int get_pref();
	int get_cur();
	int get_index();
	void set_all(string,string);
	void set_index(int);
	string get_name();
	void set_name(string);
	void set_animation(string);
	animation getbyname(string, vector<animation>);
	vector<int>get_animation();
	void copy(const animation&);
	void reset_ani();
	int get_length();
	void anitesting();
	void stopani();
	void startani();


};

#endif /* ANIMATION_H_ */
