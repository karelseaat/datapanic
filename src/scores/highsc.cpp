/*
 * highsc.cpp
 *
 *  Created on: 25 Aug 2011
 *      Author: aat
 */



#include "highsc.h"

highsc::~highsc()
{
	this->scores.clear();
}


void highsc::writefile(const char* data)
{
int i = 0, leng = strlen(data)+1;
	ofstream file(this->filenames.c_str(), ios::in|ios::binary|ios::trunc);
	  if (file.is_open())
	  {
		  for(int i=0;i<=leng;i++)
		  {
			  file.put(data[i]);
		  }
		  file.close();
	  }
	  else cout << "Unable to open file";
}

string highsc::randomname()
{
	return this->split(this->names,',',rand()%countwords(this->names,','));

}

void process(string* line) {
    cout << "line read: " << *line << endl;
    }

std::string highsc::readfile()
{

	string templine,line;
	ifstream file(this->filenames.c_str());
	//char* memblock;
	//long size;

	if (file.is_open())
	  {
		//size = file.gcount();
		//memblock = new char [size];
		while(!file.eof()) // To get you all the lines.
		{
			 getline(file,templine); // Saves the line in STRING.
			 line +=templine;
		}
			// file.read(memblock,size);
	  }
	else
	{
		 cout << "Unable to open file:" << this->filenames << endl;
	}

	//file.close();
	//cout << line << endl;
	return line;
	//return memblock;
}

void highsc::init_all()
{

	string allscores = this->readfile();
	string onescore;
	int lengte = numof(allscores,'\n') - 1;


	for(int i=0;i<=lengte;i++)
	{
		onescore = split(allscores, '\n', i);
		if (atoi(split(onescore,' ',1).c_str()) > 1)
		{
			cout << onescore << endl;
			this->add_score(new ascore(atoi(split(onescore,' ',1).c_str()),split(onescore,' ',0)));
		}
	}
	this->length = this->scores.size()-1;


}

void highsc::finish_all()
{
	string allscores;

	for(int i=0;i<=this->length;i++)
	{
		allscores += this->get_score(i)->get_com2_score() + "\n";
	}

	this->writefile(allscores.c_str());

}

void highsc::update()
{
	this->length = this->scores.size() - 1;
}

highsc::highsc(string ding,int x, int y)
{
	this->length = 0;
	this->posx = x;
	this->posy = y;
	this->filenames = ding;
	this->names = "bob,piet,klaas,jan,henk,janus,luuk,Daan,Lukas,Thijs,Stein,Jesse,Gijs,Thomas,Bram,Ruben,Max,Tom";
}

ascore* highsc::get_score(int i)
{

	if (scores.size() > i)
	return this->scores[i];
	else
	return this->scores[0];

}

string highsc::split(string s, char c, int index)
{
	int i = 0,count = 0, word_length = 0;
	char words[s.length()][20];
	while(s[i] != '\0')
	  {
	    /* Skip over spaces and commas */
	    while(s[i] == c)
	      ++i;

	    /* Copy characters that are not space, comma or \0 as part of a word */
	    while(s[i] != c  && s[i] != '\0')
	    {
	     words[count][word_length++] = s[i++];
	    }
	    words[count++][word_length] = '\0';  /* Append terminator         */
	    word_length = 0;
	  }
	return words[index];
}

int highsc::numof(string str,char cha)
{
	int leng = str.size(),nrof=0;

	for (int i=0;i<=leng;i++)
	{
		if (str[i] == cha)
		{
			nrof++;
		}
	}
	return nrof;
}

string highsc::get_filename()
{
	return this->filenames;
}

void highsc::set_filename(string na)
{
	this->filenames = na;
}

void highsc::set_vertical()
{
	this->vertical = true;
}

void highsc::set_horizontal()
{
	this->vertical = false;
}

void highsc::add_score(ascore *sc)
{
	this->scores.push_back(sc);
}

bool highsc::sortonscore(ascore a,ascore b)
{
	return a.get_score() < b.get_score();
}

void highsc::sort()
{
	ascore* temp;
	int leng = this->scores.size();
	for (int i2=0;i2<leng-1;i2++)
	{
	for (int i=0;i<leng-1;i++)
	{
		if (sortonscore(*scores[i],*scores[i+1]))
		{
			temp = scores[i];
			scores[i] = scores[i+1];
			scores[i+1] = temp;
		}
	}
	}
}

int highsc::get_length()
{
	return this->length;
}

int highsc::get_xpos(int i)
{
	return this->posx+ this->scores[i]->get_ofx();
}

int highsc::get_ypos(int i)
{
	return this->posy + this->scores[i]->get_ofy();
}

void highsc::filterstr(string &tofilter, char todel)
{
int lengte = tofilter.length();

for (int i=0;i < lengte-1;i++)
{
	if (tofilter[i] == todel)
	{
		lengte--;
		tofilter.erase(i,1);
	}
}

}

int highsc::countwords(string s, char c)
{
	int i = 0,woorden=0;
	int leng = s.size();
	  while(leng > i)
	  {
			if (s[i] == c)
		    woorden++;
			i++;
	  }
	  return woorden;
}


