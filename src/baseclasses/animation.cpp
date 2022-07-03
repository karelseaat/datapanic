/*
 * animation.cpp
 *
 *  Created on: 25 Jul 2011
 *      Author: aat
 */
#include "animation.h"


animation::animation()
{
	name = "test";
	this->index = 0;
}
animation::animation(string n)
{
	name = n;
	this->index = 0;
}

animation::animation(string n, string seqen)
{
	this->set_all(n,seqen);
	this->index = 0;

}

int strToint(string stro)
{
	  int intReturn;
	  intReturn = atoi(stro.c_str());
	  return intReturn;
}

string animation::split(string s, char c, int index)
{
	int i = 0,count = 0, word_length = 0;
	char words[500][20];
	while(s[i] != '\0')
	  {

	    while(s[i] == c)
	      ++i;

	    while(s[i] != c  && s[i] != '\0')
	    {
	     words[count][word_length++] = s[i++];
	    }
	    words[count++][word_length] = '\0';
	    word_length = 0;
	  }
	return words[index];

}

int animation::strToint(string stro)
{
	  int intReturn;
	  intReturn = atoi(stro.c_str());
	  return intReturn;
}

string animation::get_name()
{
	return name;
}

void animation::set_name(string name)
{
	this->name=name;
}

int animation::get_next()
{
	if (!stop)
	{
		index++;
		if (index >= length)
			index =0;
		return anime[index]-1;
	}
}

int animation::get_pref()
{
	if (!stop)
	{
		index--;
		if (index < 0)
			index = length;
		return anime[index]-1;
	}
}

int animation::get_cur()
{
	return anime[index];
}

void animation::set_index(int i)
{

	if (i < length && i >= 0)
		index = i;
}

int animation::get_index()
{
	return index;
}

void animation::set_all(string n, string seqen)
{
	anime.clear();
	int toint = 1,i=0;
	string temp;
	name = n;
	index=0;
	do
	{
		toint =	strToint(split(seqen,',',i));

		anime.push_back(toint);
		i++;
	} while (toint > 0 && i < 100);
	anime.pop_back();
	length = anime.size();

}

void animation::set_animation(string seqen)
{
	anime.clear();
	int toint = 1,i=0;
	string temp;

	do
	{
		toint =	strToint(split(seqen,',',i));

		anime.push_back(toint);
		i++;
	} while (toint > 0 && i < 100);
	anime.pop_back();
	length = anime.size();
}

animation animation::getbyname(string str, vector<animation> koei)
{
	int leng = koei.size(),i = 0;
	for(i=0;i < leng;i++)
	{
		if (str.compare(koei[i].get_name()) == 0)
		return koei[i];
	}
}

vector<int> animation::get_animation()
{
	return anime;
}

void animation::copy(const animation& tocopy)
{
	anime.clear();
	name = tocopy.name;
	anime = tocopy.anime;
	length = anime.size();
	index=0;
}

void animation::reset_ani()
{
	index =0;

}

int animation::get_length()
{
	return length;
}

void animation::anitesting()
{
	cout << "anitest" << endl;
}

void animation::stopani()
{
 stop = true;
}

void animation::startani()
{
 stop = false;
}

