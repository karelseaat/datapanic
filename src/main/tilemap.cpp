/*
 * tilemap.cpp
 *
 *  Created on: 27 Jul 2011
 *      Author: aat
 */
#include "tilemap.h"


tilemap::~tilemap()
{
 this->alltiles.clear();
}

tilemap::tilemap(int w, int h,sprite *spr)
{
	this->width = w;
	this->height = h;
	this->tilemapspr = spr;
	this->map=NULL;
	this->ofsetx = 0;
	this->ofsety = 0;
	this->toth = this->height * this->tilemapspr->get_height();
	this->totw = this->width * this->tilemapspr->get_width();

}

tilemap::tilemap(int w, int h)
{
	this->width = w;
	this->height = h;
	this->tilemapspr = NULL;
	this->map=NULL;
	this->ofsetx = 0;
	this->ofsety = 0;
}

tilemap::tilemap()
{
	this->width = 0;
	this->height = 0;
	this->tilemapspr = NULL;
	this->map=NULL;
	this->ofsetx = 0;
	this->ofsety = 0;
}

bool tilemap::loadxmlmap(string filename)
{
	string rootelement;
	TiXmlDocument doc(filename.c_str());
	//cout << fileName << endl;
	if (!doc.LoadFile()) return false;
	TiXmlHandle hDoc(&doc);
	TiXmlElement* pElem;
	TiXmlHandle hRoot(0);
	pElem=hDoc.FirstChildElement().Element();
	// should always have a valid root but handle gracefully if it does
	if (!pElem) return false;
	if (rootelement.compare(pElem->Value())) return false;
	return false;
}


bool tilemap::loadmap(string mapname, string cmapname)
{
	string tempstr,tempstr2;
		//char buffer[33];

		tempstr = this->loadfile(mapname.c_str());
		//cout << "hier" << endl;
		//cout << tempstr << endl;

		this->filterstr(tempstr,'\n');
		this->replacestr(tempstr,'\r',' ');

		if (this->nooftiles(tempstr,3) > this->width + (this->width * this->height) || this->nooftiles(tempstr,3) < this->width - (this->width * this->height))
		{
			cout << this->nooftiles(tempstr,3) << endl;
			cout << this->width * this->height << endl;
			return false;
		}

		tempstr2 = this->loadfile(cmapname.c_str());
		this->replacestr(tempstr2,'\n',' ');
		this->replacestr(tempstr2,'\r',' ');

		//cout << mapname.c_str() << endl;
		alltiles.resize(this->height);


		for (int i=0;this->height-1>=i;i++)
		{
			alltiles[i].resize(this->width);
		}



		for (int i =0;this->height-1>=i;i++)
		{
			for (int i2 = 0;this->width-1>=i2;i2++)
			{
				//cout << atoi(split(tempstr,' ',(i*this->width)+i2).c_str()) << endl;
				int tempint = atoi(split(tempstr,' ',(i*this->width)+i2).c_str());
				if (tempint < 1 || tempint > 25)
				{
					this->tileanimas.push_back(new animation(convertInt(i2),"1"));
					//cout << "slecht:" << tempint << " andere:" << split(tempstr,' ',(i*this->width)+i2) << endl;
				}
				else
				{
					this->tileanimas.push_back(new animation(convertInt(i2),split(tempstr,' ',(i*this->width)+i2)));
					//cout << "goed:" <<  tempint << " andere:" << split(tempstr,' ',(i*this->width)+i2) << endl;
				}
				//cout << "i:" << i << " i2:" << i2 <<" data:"<<atoi(split(tempstr,' ',(i*this->width)+i2).c_str()) << endl;
				//this->tileanimas.push_back(new animation(convertInt(i2),split(tempstr,' ',(i*this->width)+i2)));



				alltiles[i][i2] = new tile(this->tilemapspr->get_width(),this->tilemapspr->get_height(),(this->tilemapspr->get_width()*i2),(this->tilemapspr->get_height()*i));

				alltiles[i][i2]->set_animation(this->tileanimas.back());
				alltiles[i][i2]->set_sprite(tilemapspr);
				cout << this->tileanimas.back()->get_cur() << endl;




				if (split(tempstr2,' ',(i*this->width)+i2) == "00")
				{
					alltiles[i][i2]->set_collide(true);
					alltiles[i][i2]->set_ending(false);
				}
				else if (split(tempstr2,' ',(i*this->width)+i2) == "02")
				{
					alltiles[i][i2]->set_collide(false);
					alltiles[i][i2]->set_ending(true);
				}
				else
				{
					alltiles[i][i2]->set_collide(false);
					alltiles[i][i2]->set_ending(false);
				}


			}

		}
		cout << "nr" << endl;
		return true;


}

bool tilemap::loadmap(string mapname)
{
	string tempstr;
	animation *anne = new animation();
		//char buffer[33];
		cout << "tester" << endl;
		tempstr = this->loadfile(mapname.c_str());
		this->filterstr(tempstr,'\n');
		this->replacestr(tempstr,'\r',' ');

		if (this->nooftiles(tempstr,3) > this->width + (this->width * this->height) || this->nooftiles(tempstr,3) < this->width - (this->width * this->height))
		{
			//cout << this->nooftiles(tempstr,3) << endl;
			//cout << this->width * this->height << endl;
			//cout << "false out" << endl;
			return false;
		}


		alltiles.resize(this->height);


		for (int i=0;this->height-1>=i;i++)
		{
			alltiles[i].resize(this->width);
		}



		for (int i =0;this->height-1>=i;i++)
		{
			for (int i2 = 0;this->width-1>=i2;i2++)
			{
				int tempint = atoi(split(tempstr,' ',(i*this->width)+i2).c_str());
				//cout << split(tempstr,' ',(i*this->width)+i2) << endl;
				//anne->set_name(convertInt(i2));
				//anne->set_index(1);
				//anne->set_animation(split(tempstr,' ',(i*this->width)+i2));
				if (tempint < 1 || tempint > 25)
				{
					this->tileanimas.push_back(new animation(convertInt(i2),"1"));
					//cout << "slecht:" << tempint << " andere:" << split(tempstr,' ',(i*this->width)+i2) << endl;
				}
				else
				{
					this->tileanimas.push_back(new animation(convertInt(i2),split(tempstr,' ',(i*this->width)+i2)));
					//cout << "goed:" <<  tempint << " andere:" << split(tempstr,' ',(i*this->width)+i2) << endl;
				}

				alltiles[i][i2] = new tile(this->tilemapspr->get_width(),this->tilemapspr->get_height(),(this->tilemapspr->get_width()*i2),(this->tilemapspr->get_height()*i));
				alltiles[i][i2]->set_animation(this->tileanimas.back());
				alltiles[i][i2]->set_sprite(tilemapspr);
				alltiles[i][i2]->set_collide(false);
				alltiles[i][i2]->set_ending(false);

			}
		}



		//this->toth = this->height * this->tilemapspr->get_height();
		//this->totw = this->width * this->tilemapspr->get_width();

		return true;
}

int tilemap::nooftiles(string str, int pertile)
{
		int size = round(str.size() / pertile);
		return size;
}



string tilemap::loadfile(const char* mapstr)
{


	string templine,line;
	ifstream file(mapstr);
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
		 cout << "Unable to open file:" << mapstr << endl;
	}

	//file.close();
	//cout << line << endl;
	return line;
	//return memblock;
}

string tilemap::split(string s, char c, int index)
{
	int i = 0,count = 0, word_length = 0;
	char words[s.length()][10];
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


tile* tilemap::get_tile(unsigned int x,unsigned int y)
{

//std::vector< std::vector<tile*> >::iterator row_it = alltiles.begin();
//std::vector< std::vector<tile*> >::iterator row_end = alltiles.end();
//
//for ( ; row_it != row_end; ++row_it ) {
//	std::vector<tile*>::iterator col_it = row_it->begin();
//	std::vector<tile*>::iterator col_end = row_it->end();
//	   for ( ; col_it != col_end; ++col_it )
//		   std::cout<< std::setw ( 3 ) << *col_it;
//
//}
//
//for (vector< vector<tile*> >::iterator i = alltiles.begin();i != alltiles.end();++i)
//{
//	for (vector<tile*>::iterator y = alltiles->at(i).begin();y != alltiles->at(i).end();++i)
//	{


	if(x >= 0 && x < (unsigned int)alltiles.size())
	{
		if(y < (unsigned int)alltiles.at(x).size() && y >= 0)
		{
			return alltiles.at(x).at(y);
		}
	}
	std::cout << "error no tiles" << std::endl;
	this->tileanimas.push_back(new animation(convertInt(1),"1"));
	alltiles.resize(1);
	alltiles[0].resize(1);
	alltiles[0][0] = new tile(this->tilemapspr->get_width(),this->tilemapspr->get_height(),(this->tilemapspr->get_width()),(this->tilemapspr->get_height()));
	alltiles[0][0]->set_animation(this->tileanimas.back());
	alltiles[0][0]->set_sprite(tilemapspr);
	alltiles[0][0]->set_collide(false);
	alltiles[0][0]->set_ending(false);
	return alltiles.at(0).at(0);
}




void tilemap::set_width(int w)
{
	this->width = w;
}

void tilemap::set_height(int h)
{
	this->height = h;
}

int tilemap::get_width()
{
	return this->width;
}

int tilemap::get_height()
{
	return this->height;
}

void tilemap::set_wihi(int w,int h)
{
	this->width = w;
	this->height = h;
}


void tilemap::set_sprite(sprite* spr)
{
	this->tilemapspr = spr;
	this->toth = this->height * this->tilemapspr->get_height();
	this->totw = this->width * this->tilemapspr->get_width();
}


sprite* tilemap::get_sprite()
{
	return this->tilemapspr;
}



void tilemap::animate()
{

	//nog een check hierin dat als de tiles zich niet binnen de camera bevinden ze ook niet animaten.
	//wellichtnog een bsp plan om cam scherm in 4en te verdelen om zo colission checking sneller te maken.

	for (int i=0;i<=height-1;i++)
	{
		for (int i2=0;i2<=width-1;i2++)
		{
			this->alltiles[i][i2]->animate();
		}
	}
}




void tilemap::filterstr(string &tofilter, char todel)
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

void tilemap::replacestr(string &tofilter, char todel, char torep)
{
int lengte = tofilter.length();

for (int i=0;i < lengte-1;i++)
{

	if (tofilter[i] == todel)
	{
		tofilter[i] = torep;
	}
}

}




string tilemap::convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}

void tilemap::set_ofsetx(int x)
{
	this->ofsetx = x;
}

void tilemap::set_ofsety(int y)
{
	this->ofsety = y;
}

int tilemap::get_ofsetx()
{
	return ofsetx;
}

int tilemap::get_ofsety()
{
	return ofsety;
}

int tilemap::get_tot_width()
{
	return this->totw;
}

int tilemap::get_tot_height()
{
	return this->toth;
}




