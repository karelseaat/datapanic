/*
 * sprite.cpp
 *
 *  Created on: 24 Jul 2011
 *      Author: aat
 */


#include "sprite.h"

sprite::sprite()
{

}

sprite::sprite(sprite& tocopy)
{
	this->frames = tocopy.frames;
	this->height = tocopy.height;
	this->width = tocopy.width;
	this->nrframes = tocopy.nrframes;
	this->surface = tocopy.surface;
}


sprite::sprite(SDL_Surface *sc,int w,int h)
{

//check of het plaatje goed is


	this->width = w;
	this->height = h;
	surface = sc;
	nrframes = 0;
}

sprite::sprite(int w,int h)
{
	this->width = w;
	this->height = h;
	nrframes = 0;
}

sprite::sprite(std::string name,int w,int h)
{
	width = w;
	height = h;
	//surface = NULL;
    //load_image(name);

    //If there was a problem in loading the dot
    //some error handeling

//check of het plaatje goed is


}

void sprite::set_surface(SDL_Surface* sur)
{
	this->surface = sur;
}

SDL_Rect sprite::get_frame(int index)
{
	return frames[index];
}

SDL_Surface* sprite::get_surface()
{
	return surface;
}



SDL_Surface* sprite::load_image( std::string filename )
{
    //The image that's loaded
    SDL_Surface* loadedImage = NULL;

    //The optimized surface that will be used
    SDL_Surface* optimizedImage = NULL;

    cout << "we gaan plaatje laden" << endl;

    //Load the image
    loadedImage = IMG_Load( filename.c_str() );
    cout << "we gaan plaatje laden 2" << endl;
    //If the image loaded
    if( loadedImage != NULL )
    {
    	cout << "het plaatje optimizen" << endl;
        //Create an optimized surface
    	optimizedImage = SDL_DisplayFormat( loadedImage );
        if( loadedImage != NULL )
        {
        	cout << "optimized fail !!!" << endl;
        }
        cout << "het plaatje optimize done: " << optimizedImage  << endl;
        //Free the old surface
        SDL_FreeSurface( loadedImage );
        cout << "het plaatje colorkeyen" << endl;
        //If the surface was optimized
        if( optimizedImage != NULL )
        {
            //Color key surface
            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xCC, 0xDE ) );
        }
    }
    else
    {
    	cout << "het plaatje wilde niet laden" << endl;
    }

    //Return the optimized surface
    return optimizedImage;
}

void sprite::makesprite()
{

	int arpos =0;

	int arraysize = round((surface->w * surface->h) / (width * height))+1;
	cout << arraysize << endl;
	frames.resize(arraysize);

	for (int i=0;i<int(surface->h/height);i++)
	{
		for (int i2=0;i2<=int(surface->w/width);i2++)
		{
			arpos = ((ceil((float)surface->w/width)*i)+i2);
			//cout << "arpos:" << arpos << endl;
			frames[arpos].x = i2*width;
			frames[arpos].y = (i*height);
			frames[arpos].w = width;
			frames[arpos].h = height;

		}
	}


}

int sprite::get_height()
{
	return this->height;
}

int sprite::get_width()
{
	return this->width;
}
