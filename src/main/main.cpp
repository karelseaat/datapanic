
//een test om te kijken of dit vanuit de main branch wordt meegenomen naar zij branches
#define OSCPKT_OSTREAM_OUTPUT
//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
#include <fstream>
#include <iostream>
#include "sprite.h"
#include "active.h"
#include "bar.h"
#include "tilemap.h"
#include "Timer.h"
#include "activecont.h"
#include "fsm.h"
#include "highsc.h"
#include "condition.h"
#include "base64.h"

#include "splash.h"
#include <ctime>

//aanpassing
using std::cout;
using std::cerr;

using namespace std;

//Screen attributes
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;
const int SCREEN_BPP = 32;

//The frame rate
const int FRAMES_PER_SECOND = 25;

//nog een aanpassing

// ff iets aanpassen

SDL_Surface *dotC = NULL;//poppetje
SDL_Surface *dotS = NULL;
SDL_Surface *enemazi1C = NULL;//tegenstander1
SDL_Surface *enemazi1S = NULL;

SDL_Surface *enemazi2C = NULL;//tegenstander2
SDL_Surface *enemazi2S = NULL;

SDL_Surface *enemazi3C = NULL;//tegenstander3
SDL_Surface *enemazi3S = NULL;

SDL_Surface *enemazi4C = NULL;//tegenstander4
SDL_Surface *enemazi4S = NULL;

SDL_Surface *statisch1C = NULL;//static object 1
SDL_Surface *statisch1S = NULL;

//splases, begin uitleg schermen, win, fail

SDL_Surface *splash1 = NULL;
SDL_Surface *splash2 = NULL;
SDL_Surface *win = NULL;
SDL_Surface *fail = NULL;
SDL_Surface *scores = NULL;//list met high scores

// het lijkt of deze tak ongerelateerd is

//tilesheets. 1 is achterste en zo naar voren geteld.
SDL_Surface *laag1 = NULL;
SDL_Surface *laag2 = NULL;
SDL_Surface *laag3 = NULL;
SDL_Surface *laag4 = NULL;
SDL_Surface *laag5 = NULL;
SDL_Surface *laag6 = NULL;

//jah zekers

//gui spul
SDL_Surface *message = NULL;//current score
SDL_Surface *lifebar = NULL;
SDL_Surface *scoregui = NULL;//gui omhulsel voor lifebar en score.

//main screen, waarop alles wordt geblit.
SDL_Surface *screen = NULL;

activecont *enmcontainer = new activecont();
int score = 0;

SDL_Event event;
splash kutje(&event,2000);
splash kutje1(&event,2000);
splash kutjewin(&event,2000);
splash kutjefail(&event,2000);
splash kutjescore(&event,2000);

SDL_Color acolor{250,50,50,50};
bars testing;
vector <FSM> fmsses;
TTF_Font *font = NULL;
//mijn popetje sprite aanmaak
sprite dot2Csprite(60,110);
sprite dot2Ssprite(120,100);

//todo zoals hier duidelijk wordt mag alles begrijpelijkere namen hebben, ook moeten de namen uiteindelijk naar een standaard syntax

highsc myscores = highsc("./Debug/scores.txt",100,100);

sprite enemy1C(50,100);
sprite enemy1S(50,100);

sprite enemy2C(50,100);
sprite enemy2S(50,100);

sprite enemy3C(50,100);
sprite enemy3S(50,100);

sprite enemy4C(50,100);
sprite enemy4S(50,100);

sprite staspriteC(50,100);
sprite staspriteS(50,100);

//popetje dot2(&event,&dot2Csprite,&dot2Ssprite);

sprite laag6sprite(32,32);
tilemap weg(68,24,&laag6sprite);

sprite laag5sprite(32,32);
tilemap decalls(68,24,&laag5sprite);

sprite laag1sprite(32,32);
tilemap lucht(68,24,&laag1sprite);

sprite laag2sprite(32,32);
tilemap achterbackdrop(68,12,&laag2sprite);

sprite laag3sprite(32,32);
tilemap achter1backdrop(68,12,&laag3sprite);

sprite laag4sprite(32,32);
tilemap achter2backdrop(68,12,&laag4sprite);

//The camera
SDL_Rect camera = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};

SDL_Surface *load_image( std::string filename )
{

	//The image that's loaded
	SDL_Surface* loadedImage = NULL;

	//The optimized surface that will be used
	SDL_Surface* optimizedImage = NULL;

	//Load the image
	loadedImage = IMG_Load( filename.c_str() );

	//If the image loaded
	if( loadedImage != NULL )
	{

		//Create an optimized surface
		optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
		//Free the old surface
		SDL_FreeSurface( loadedImage );
		//If the surface was optimized
		if( optimizedImage != NULL )
		{
			//Color key surface
			SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xCC, 0xDE ) );
		}
		cout << "plaatje:" << filename << " geladen !!!" << endl;
	}
	else
	{
		cout << "een plaatje wilde niet laden" << endl;
	}

	//Return the optimized surface
	return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
	//Holds offsets
	SDL_Rect offset;

	//Get offsets
	offset.x = x;
	offset.y = y;

	//Blit
	SDL_BlitSurface( source, clip, destination, &offset );
}

bool check_collision( SDL_Rect A, SDL_Rect B )
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
	leftB = B.x;
	rightB = B.x + B.w;
	topB = B.y;
	bottomB = B.y + B.h;

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

bool check_collision( SDL_Rect A, SDL_Rect B,int ofx,int ofy )
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
	leftB = B.x;
	rightB = B.x + B.w;
	topB = B.y;
	bottomB = B.y + B.h;

	//If any of the sides from A are outside of B
	if( (bottomA) <= topB )
	{
		return false;
	}

	if( (topA/ofy) >= bottomB )
	{
		return false;
	}

	if( (rightA) <= leftB )
	{
		return false;
	}

	if( (leftA/ofx) >= rightB )
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}

bool init()
{
	//Initialize all SDL subsystems
	if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
	{
		return false;
	}

	//Set up the screen
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_HWSURFACE | SDL_NOFRAME );

	//If there was an error in setting up the screen
	if( screen == NULL )
	{
		return false;
	}

	//Initialize SDL_ttf
	if( TTF_Init() == -1 )
	{
		return false;
	}

	//Set the window caption
	SDL_WM_SetCaption( "Move the Dot", NULL );

	//If everything initialized fine
	return true;
}



bool load_files()
{
	//Load the dot image
	dotC = load_image( "../thegame/graphs/main-char-spritesheet.png" );
	dotS = load_image( "../thegame/graphs/foo2.png" );

	enemazi1C = load_image( "../thegame/graphs/enm-walk-cycle.png" );
	enemazi1S = load_image( "../thegame/graphs/enm-walk-cycle.png" );

	enemazi2C = load_image( "../thegame/graphs/enm-walk-cycle-2.png" );
	enemazi2S = load_image( "../thegame/graphs/enm-walk-cycle-2.png" );

	enemazi3C = load_image( "../thegame/graphs/enm-walk-cycle-3.png" );
	enemazi3S = load_image( "../thegame/graphs/enm-walk-cycle-3.png" );

	enemazi4C = load_image( "../thegame/graphs/enm-walk-cycle-4.png" );
	enemazi4S = load_image( "../thegame/graphs/enm-walk-cycle-4.png" );


	splash1 = load_image("../thegame/graphs/intro-page1.jpg");
	splash2 = load_image("../thegame/graphs/intro-page2.jpg");
	scores = load_image("../thegame/graphs/main-menu.jpg");
	lifebar = load_image("../thegame/graphs/bar.png");
	scoregui = load_image("../thegame/graphs/scoregui.png");

	win = load_image("../thegame/graphs/ending-win.jpg");
	fail = load_image("../thegame/graphs/ending-loss.jpg");

	statisch1C = load_image( "../thegame/graphs/static-spritesheet-2.png" );
	statisch1S = load_image( "../thegame/graphs/static-spritesheet-2.png" );

	//If there was a problem in loading the dot
	if( dotC == NULL && dotS == NULL)
	{
		cout << "problem loading dot map" << endl;
		return false;
	}
	font = TTF_OpenFont( "./Debug/soviet_stencil.ttf", 16 );

	//Load the tile sheet
	laag1 = load_image("../thegame/graphs/tileset-sky.png");
	laag2 = load_image("../thegame/graphs/tileset-backdrop.png");
	laag3 = load_image("../thegame/graphs/tileset-backdrop2.png");
	laag4 = load_image("../thegame/graphs/tileset-backdrop3.png");
	laag5 = load_image("../thegame/graphs/tileset-floor.png");
	laag6 = load_image("../thegame/graphs/tileset-floor.png");

	//If there was a problem in loading the tiles
	if( laag1 == NULL || laag2 == NULL || laag3 == NULL || laag4 == NULL || laag5 == NULL || laag6 == NULL)
	{
		cout << "problem loading tile map" << endl;
		return false;
	}

	//If everything loaded fine
	return true;
}

bool init_joystick()
{
	if ( SDL_InitSubSystem ( SDL_INIT_JOYSTICK ) < 0 )
	{
		fprintf ( stderr, "Unable to initialize Joystick: %s\n", SDL_GetError() );
		return false;
	}

	printf ( "%i joysticks found\n", SDL_NumJoysticks () );

	SDL_JoystickEventState ( SDL_QUERY );
	return true;
}

void enemyshow()
{
	active *tempac = new active();

	for (int i =0;i < enmcontainer->get_length();i++)
	{
		tempac = enmcontainer->get_active(i);
		apply_surface( tempac->get_position().x - camera.x, tempac->get_position().y - (tempac->get_c_sprite().get_width() /2) - camera.y,tempac->get_c_sprite().get_surface(), screen, & tempac->get_c_sprite().get_frame(tempac->get_curr_c_ani()->get_cur()));
		apply_surface( tempac->get_position().x - camera.x, tempac->get_position().y - (tempac->get_s_sprite().get_width() /2) - camera.y,tempac->get_s_sprite().get_surface(), screen, & tempac->get_s_sprite().get_frame(tempac->get_curr_s_ani()->get_cur()));
	}
}

void set_camera(active* acc)
{
	//Center the camera over the dot
	camera.x = ( acc->get_position().x + acc->get_c_sprite().get_width() / 2 ) - SCREEN_WIDTH / 2;
	camera.y = ( acc->get_position().y + acc->get_c_sprite().get_height() / 2 ) - SCREEN_HEIGHT / 2;

	//Keep the camera in bounds.
	if( camera.x < 0 )
	{
		camera.x = 0;
	}
	if( camera.y < 0 )
	{
		camera.y = 0;
	}
	if( camera.x > weg.get_tot_width() - camera.w )
	{
		camera.x = weg.get_tot_width() - camera.w;
	}
	if( camera.y > weg.get_tot_height() - camera.h )
	{
		camera.y = weg.get_tot_height() - camera.h;
	}
}

void my_itoa(int value, std::string& buf, int base)
{

	//int i = 30;

	buf = "";

	if (value == 0)
	{
		buf = "0";
	}
	else
	{
		for(int i = 30; value && i; --i, value /= base) buf = "0123456789abcdef"[value % base] + buf;
	}
}

int main( int argc, char* args[] )
{

	srand(unsigned(time(0)));
	//Quit flag
	bool quit = false;
	bool next = false;

	//The frame rate regulator
	Timer fps;

	//Initialize
	if( init() == false )
	{
		return 1;
	}

	//Load the files
	if( load_files() == false )
	{
		return 1;
	}

	//init joystick
	if( init_joystick() == false )
	{
		return 1;
	}

	kutje.set_surface(splash1);
	kutje1.set_surface(splash2);

	kutjewin.set_surface(win);
	kutjefail.set_surface(fail);

	kutjescore.set_surface(scores);

	enemy1C.set_surface(enemazi1C);
	enemy1S.set_surface(enemazi1S);
	enemy1C.makesprite();
	enemy1S.makesprite();

	enemy2C.set_surface(enemazi2C);
	enemy2S.set_surface(enemazi2S);
	enemy2C.makesprite();
	enemy2S.makesprite();

	enemy3C.set_surface(enemazi3C);
	enemy3S.set_surface(enemazi3S);
	enemy3C.makesprite();
	enemy3S.makesprite();

	enemy4C.set_surface(enemazi4C);
	enemy4S.set_surface(enemazi4S);
	enemy4C.makesprite();
	enemy4S.makesprite();

	staspriteC.set_surface(statisch1C);
	staspriteS.set_surface(statisch1S);
	staspriteC.makesprite();
	staspriteS.makesprite();

	dot2Ssprite.set_surface(dotS);
	dot2Csprite.set_surface(dotC);
	dot2Ssprite.makesprite();
	dot2Csprite.makesprite();


	enmcontainer->set_col_tilem(&weg);

	enmcontainer->add_active( new popetje(&event,&dot2Csprite,&dot2Ssprite));
	enmcontainer->get_active(0)->set_condition(new popcondition(100,100,100,100,100,10,100,100));
	enmcontainer->get_active(0)->set_start_pos(Vector2D(50,(rand()%30)*10+380));

	for(int i=1;i<2;i++)
	{
		int arand = (rand()%4)+1;
		switch (arand)
		{
			case(1):
			enmcontainer->add_active( new enemy(&enemy1C,&enemy1S));
			break;
			case(2):
			enmcontainer->add_active( new enemy(&enemy2C,&enemy2S));
			break;
			case(3):
			enmcontainer->add_active( new enemy(&enemy3C,&enemy3S));
			break;
			case(4):
			enmcontainer->add_active( new enemy(&enemy4C,&enemy4S));
			break;
		}
		enmcontainer->get_active(1)->set_condition(new enmcondition(100,100,100,100,100,100,100,100));
	}

	enmcontainer->add_active(new statisch(&staspriteC,&staspriteS));
	enmcontainer->get_active(2)->set_condition(new stacondition(100,100,100));

	for (unsigned int i =0;i < enmcontainer->get_length();i++)
	{
		cout << "naam: " << enmcontainer->get_active(i)->get_condition()->get_com_name() << endl;
		cout << "lost: " << enmcontainer->get_active(i)->get_condition()->get_lose() << endl;
		cout << "win: " << enmcontainer->get_active(i)->get_condition()->get_win() << endl;
		cout << "does damage: " << enmcontainer->get_active(i)->get_condition()->get_damage() << endl;
		cout << "invincible: " << enmcontainer->get_active(i)->get_condition()->get_invincible() << endl;
		cout << "stamina: " << enmcontainer->get_active(i)->get_condition()->get_stamina() << endl;
		cout << "health: " << enmcontainer->get_active(i)->get_condition()->get_health() << endl;
		cout << "-----------------------------------------------" << endl;
	}

	enmcontainer->get_savestart(SDL_Rect {7400,350,800,350},"enm");
	enmcontainer->get_savestart(SDL_Rect {200,325,6000,350},"sta");

	fmsses.resize(enmcontainer->get_length());
	for (unsigned int i =0;i < enmcontainer->get_length();i++)
	{

		fmsses[i] = FSM();

		fmsses[i].AddState(new naarboven(&fmsses[i],"naarboven",(rand()%100)+1000),false);
		fmsses[i].AddState(new naaronder(&fmsses[i],"naaronder",(rand()%100)+1000),false);
		fmsses[i].AddState(new naarlinksonder(&fmsses[i],"naarlinksonder",(rand()%100)+1000),false);
		fmsses[i].AddState(new naarlinksboven(&fmsses[i],"naarlinksboven",(rand()%100)+1000),false);
		//fmsses[i].AddState(new naarrechts(&fmsses[i],"naarrechts",(rand()%100)+1000),false);
		fmsses[i].AddState(new naarlinks(&fmsses[i],"naarlinks",(rand()%100)+2000),false);
		fmsses[i].AddState(new muurbump(&fmsses[i],"muurbump",10),false);
		fmsses[i].AddState(new stop(&fmsses[i],"stop",(rand()%100)+2000),true);
		fmsses[i].AddState(new party(&fmsses[i],"party",(rand()%10)+2000),false);
		fmsses[i].AddState(new reveit(&fmsses[i],"reveit",(rand()%10)+200),false);
		fmsses[i].AddState(new dying(&fmsses[i],"dying",(rand()%100)+1000),false);
		fmsses[i].AddState(new bumprest(&fmsses[i],"bumprest",(rand()%10)+50),false);
		fmsses[i].AddState(new popcontroll(&fmsses[i],"popcontroll",(rand()%100)+100),false);
		//enmcontainer->get_active(i)->set_condition(condition(10,10,true));
		enmcontainer->get_active(i)->set_fsm(&fmsses[i]);

		/*
		 if (enmcontainer->get_active(i)->get_base_name() == "pop")
		 {
		 enmcontainer->get_active(i)->set_condition(condition(100,100,false));
		 enmcontainer->get_active(i)->set_start_pos(Vector2D(50,(rand()%30)*10+380));
		 }

		 if (enmcontainer->get_active(i)->get_base_name() == "enm")
		 {
		 enmcontainer->get_active(i)->set_condition(condition(2000,2000,false));
		 }
		 */

	}
	laag6sprite.set_surface(laag6);
	laag6sprite.makesprite();

	weg.loadmap("/home/aat/Dropbox/coderepos/datapanic/thegame/maps/vloer.map","/home/aat/Dropbox/coderepos/datapanic/thegame/maps/collide.map");
	//weg.set_ofsetx(1);
	//weg.set_ofsety(1);

	//decalls.loadmap("./Debug/maps/decalls.map");
	//laag5sprite.set_surface(laag5);
	//laag5sprite.makesprite();
	//decalls.set_ofsetx(1);
	//decalls.set_ofsety(1);

	cout << lucht.loadmap("/home/aat/Dropbox/coderepos/datapanic/thegame/maps/lucht.map") << endl;
	laag1sprite.set_surface(laag1);

	laag1sprite.makesprite();
	lucht.set_ofsetx(1);
	lucht.set_ofsety(1);



	achterbackdrop.loadmap("/home/aat/Dropbox/coderepos/datapanic/thegame/maps/backdrop-1.map");
	laag2sprite.set_surface(laag2);
	laag2sprite.makesprite();
	achterbackdrop.set_ofsetx(2);
	achterbackdrop.set_ofsety(1);

	achter1backdrop.loadmap("/home/aat/Dropbox/coderepos/datapanic/thegame/maps/backdrop-2.map");
	laag3sprite.set_surface(laag3);
	laag3sprite.makesprite();
	achter1backdrop.set_ofsetx(3);
	achter1backdrop.set_ofsety(1);

	achter2backdrop.loadmap("/home/aat/Dropbox/coderepos/datapanic/thegame/maps/backdrop-3.map");
	laag4sprite.set_surface(laag4);
	laag4sprite.makesprite();
	achter2backdrop.set_ofsetx(4);
	achter2backdrop.set_ofsety(1);

	testing = bars(lifebar,146,743);
	testing.set_round_corr(1,0);
	myscores.add_score(new ascore(0,myscores.randomname()));

	myscores.sort();

	myscores.init_all();




	for(int i = 0;i<=myscores.get_length();i++)
	{
		myscores.get_score(i)->set_font("/home/aat/Dropbox/coderepos/datapanic/thegame/fonts/Adventure.ttf",24);
		myscores.get_score(i)->set_sep(" - ");
		myscores.get_score(i)->set_ofy(i*50);
		myscores.get_score(i)->set_color(acolor);
		myscores.get_score(i)->convert();
	}



	tile *atile = new tile();
	tile *ctile = new tile();
	tile *btile = new tile();
	tile *qtile = new tile();
	tile *xtile = new tile();
	string koei,extra;

	myscores.add_score(new ascore(1,myscores.randomname()));
	myscores.update();

	//todo een splash plaatje met een score, doet je er aan denken dat de splash class nog wat txtra mogelijkheden mag hebben.

	//todo ook deze splash maar naar een class

	myscores.update();
	myscores.sort();

	while (!quit)
	{
		while (!kutjescore.get_klaar())
		{

			kutjescore.update();
			apply_surface(0,0,kutjescore.get_surface(),screen);

			if (myscores.get_length() > 10)
			{
				for(int i = 0;i<10;i++)
				{
					apply_surface(100,i * 50+100,myscores.get_score(i)->get_picscore(),screen);
				}
			}
			else
			{
				for(int i = 0;i<=myscores.get_length();i++)
				{
					apply_surface(100,i * 50+100,myscores.get_score(i)->get_picscore(),screen);
				}
			}
			SDL_Flip( screen );
			SDL_JoystickUpdate ();

		}

		next = false;
		//todo alle splash screens in een class, hier splash 1 ding
		while (!kutje.get_klaar())
		{
			kutje.update();
			apply_surface(0,0,kutje.get_surface(),screen);
			SDL_Flip( screen );
		}

		kutje.set_klaar(false);

		while (!kutje1.get_klaar())
		{
			kutje1.update();
			apply_surface(0,0,kutje1.get_surface(),screen);
			SDL_Flip( screen );
		}

		kutje1.set_klaar(false);

		myscores.get_score(myscores.get_length())->set_font("/home/aat/Dropbox/coderepos/datapanic/thegame/fonts/Adventure.ttf",24);
		myscores.get_score(myscores.get_length())->set_sep(" - ");

		myscores.get_score(myscores.get_length())->set_color(acolor);
		myscores.get_score(myscores.get_length())->convert();

		// myscores.init_all();
		next = false;
		while(!next && !quit)
		{
			SDL_JoystickUpdate ();
			fps.start();

			//While there's events to handle
			while( SDL_PollEvent( &event ) )
			{

				for (unsigned int i =0;i < enmcontainer->get_length();i++)
				{

					if (event.key.keysym.sym == SDLK_q )
					{
						quit = true;
					}
					if(enmcontainer->get_active(i)->get_condition()->get_com_name().compare("pop") == 0)
					{
						//enmcontainer->get_active(i)->get_compu_steer() << endl;
						enmcontainer->get_active(i)->steer();
					}

				}

				//If the user has Xed out the window
				if( event.type == SDL_QUIT )
				{
					//Quit the program
					quit = true;
				}
			}

			for (int i =0;i < enmcontainer->get_length();i++)
			{
				//if (enmcontainer->get_active(i)->get_by_name("pop"))
				if(enmcontainer->get_active(i)->get_condition()->get_com_name().compare("pop") == 0)
				{
					set_camera(enmcontainer->get_active(i));
				}
			}


			enmcontainer->update();

			for (int i =0;i < weg.get_height();i++)
			{
				for (int k =0;k < weg.get_width();k++)
				{
					atile = weg.get_tile(i,k);
					//If the tile is on screen
					if( check_collision( camera, atile->get_box() ) == true )
					{
						apply_surface( atile->get_box().x - camera.x, atile->get_box().y - camera.y, atile->get_sprite().get_surface(), screen, &atile->get_sprite().get_frame(atile->get_animation().get_cur()));
					}
				}
			}

			for (int i =0;i < lucht.get_height();i++)
			{
				for (int k =0;k < lucht.get_width();k++)
				{
					ctile = lucht.get_tile(i,k);

					if( check_collision( camera, ctile->get_box(),lucht.get_ofsetx(), lucht.get_ofsety()) == true )
					{
						apply_surface(ctile->get_box().x - (camera.x/lucht.get_ofsetx()), ctile->get_box().y - (camera.y/lucht.get_ofsety()), ctile->get_sprite().get_surface(), screen, &ctile->get_sprite().get_frame(ctile->get_animation().get_cur()));
					}
				}
			}

			for (int i =0;i < achter2backdrop.get_height();i++)
			{
				for (int k =0;k < achter2backdrop.get_width();k++)
				{
					xtile = achter2backdrop.get_tile(i,k);

					if( check_collision( camera, xtile->get_box(),achter2backdrop.get_ofsetx(), achter2backdrop.get_ofsety()) == true )
					{
						apply_surface(xtile->get_box().x - (camera.x/achter2backdrop.get_ofsetx()), xtile->get_box().y - (camera.y/achter2backdrop.get_ofsety()), xtile->get_sprite().get_surface(), screen, &xtile->get_sprite().get_frame(xtile->get_animation().get_cur()));
					}
				}
			}

//			for (int i =0;i < achter1backdrop.get_height();i++)
//			{
//				for (int k =0;k < achter1backdrop.get_width();k++)
//				{
//					qtile = achter1backdrop.get_tile(i,k);
//
//					if( check_collision( camera, qtile->get_box(),achter1backdrop.get_ofsetx(), achter1backdrop.get_ofsety()) == true )
//					{
//						apply_surface(qtile->get_box().x - (camera.x/achter1backdrop.get_ofsetx()), qtile->get_box().y - (camera.y/achter1backdrop.get_ofsety()), qtile->get_sprite().get_surface(), screen, &qtile->get_sprite().get_frame(qtile->get_animation().get_cur()));
//					}
//				}
//			}


			for (int i =0;i < achterbackdrop.get_height();i++)
			{
				for (int k =0;k < achterbackdrop.get_width();k++)
				{
					btile = achterbackdrop.get_tile(i,k);

					if( check_collision( camera, btile->get_box(),achterbackdrop.get_ofsetx(), achterbackdrop.get_ofsety()) == true )
					{
						apply_surface(btile->get_box().x - (camera.x/achterbackdrop.get_ofsetx()), btile->get_box().y - (camera.y/achterbackdrop.get_ofsety()), btile->get_sprite().get_surface(), screen, &btile->get_sprite().get_frame(btile->get_animation().get_cur()));

					}
				}
			}



			for (unsigned int i =0;i < enmcontainer->get_length();i++)
			{
				if (enmcontainer->get_active(i)->get_condition()->get_com_name().compare("pop") == 0)
				{

					testing.set_percent(enmcontainer->get_active(i)->get_condition()->get_health());
					myscores.get_score(myscores.get_length())->update();
					int tempscore = (enmcontainer->get_active(i)->get_position().x * enmcontainer->get_active(i)->get_condition()->get_health()) + enmcontainer->get_active(i)->get_position().x;
					myscores.get_score(myscores.get_length())->set_score(tempscore);

					if (0)
					{
						next = true;
					}
					if (enmcontainer->get_active(i)->get_condition()->get_win())
					{
						next = true;
					}

				}
			}

			enemyshow();

			apply_surface(0,712,scoregui,screen);
			apply_surface(testing.get_x(),testing.get_y(),testing.get_surface(),screen,&testing.get_rectangle());
			apply_surface(780, 650, message, screen);
			apply_surface(600,742,myscores.get_score(myscores.get_length())->get_picscore(), screen);
			//Update the screen
			if( SDL_Flip( screen ) == -1 )
			{
				return 1;
			}

			//Cap the frame rate
			if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
			{
				SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
			}

		}

		next = false;

		if (!quit)
		{

//todo alle splash screens in een class, hier het win fail splash, weg
			for (unsigned int i =0;i < enmcontainer->get_length();i++)
			{
//todo alle klasses een << operator geven zodat ze in een cout kunnen worden geplaatst voor easy debugging
				//win scherm
				if (enmcontainer->get_active(i)->get_condition()->get_com_name().compare("pop") == 0)
				{

					if (enmcontainer->get_active(i)->get_condition()->get_win())
					{
						while (!kutjewin.get_klaar())
						{
							kutjewin.update();
							apply_surface(0,0,kutjewin.get_surface(),screen);
							SDL_Flip( screen );

						}
						kutjewin.set_klaar(false);
					}
					else if (enmcontainer->get_active(i)->get_condition()->get_lose())
					{ //fail scherm
						while (!kutjefail.get_klaar())
						{
							kutjefail.update();
							apply_surface(0,0,kutjefail.get_surface(),screen);
							SDL_Flip( screen );
						}
						kutjefail.set_klaar(false);

					}
				}
			}
		}

		next = false;

		//resetting the game

		for (unsigned int i =0;i < enmcontainer->get_length();i++)
		{

			if (enmcontainer->get_active(i)->get_condition()->get_com_name().compare("pop") == 0)
			{
				enmcontainer->get_active(i)->set_condition(new popcondition(100,100,100,100,100,100,100,100));
				enmcontainer->get_active(i)->set_start_pos(Vector2D(50,(rand()%30)*10+380));
			}
		}

		//myscores.add_score(new ascore(1,myscores.randomname()));
		//myscores.update();
		//myscores.get_score(myscores.get_length())->set_score(0);
		next = false;

	}
	//myscores.finish_all();
	//Clean up
	fmsses.clear();
	delete enmcontainer;
	//delete mytiles;
	//delete smalltilesprite;
	//delete midtiles;

	SDL_FreeSurface(scores);
	SDL_FreeSurface(lifebar);
	SDL_FreeSurface(scoregui);
	SDL_FreeSurface(splash2);
	SDL_FreeSurface(splash1);
	SDL_FreeSurface(laag1);
	SDL_FreeSurface(laag2);
	SDL_FreeSurface(laag3);
	SDL_FreeSurface(laag4);
	SDL_FreeSurface(laag5);
	SDL_FreeSurface(screen);

	return 1;
}
