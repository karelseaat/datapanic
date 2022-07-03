
#ifndef ACTIVE_H_
#define ACTIVE_H_

#include "condition.h"
#include "fsm.h"

#include "sprite.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include "Vector2D.h"
#include "animation.h"
#include "condition.h"

using namespace std;

typedef  boost::shared_ptr<condition>  cond;

class active
{
    protected:
    //The dot's collision box
    SDL_Rect tcollbox; //tiles
    SDL_Rect acollbox; //actives
    SDL_Rect pcollbox; //punches
    Vector2D position;

    animation *currcanim;
    animation *currsanim;
    sprite *csprite;
    sprite *ssprite;
    //Its animation status
    int frame;


    public:
    //Initializes the variables

    active(sprite*,sprite*);
    active();
    virtual ~active();
    //Shows the dot on the screen

    void add_c_ani(animation);
    void add_s_ani(animation);

    animation* get_curr_c_ani();
    animation* get_curr_s_ani();

    void set_curr_s_ani(animation*);
    void set_curr_c_ani(animation*);

    sprite get_c_sprite();

    sprite get_s_sprite();

    bool compare(const active&);

    void set_name(string na,int nr);

    string get_name();

    void set_tcoll_box(SDL_Rect);

    SDL_Rect get_tcoll_box();

    void set_acoll_box(SDL_Rect);

    SDL_Rect get_acoll_box();

    void set_pcoll_box(SDL_Rect);

    SDL_Rect get_pcoll_box();

    bool get_by_name(string);

    void copy(active);

    virtual void move();

    virtual void steer();

    virtual void animate();

    virtual void update();

    virtual void set_fsm(FSM*){};

    virtual void set_condition(condition*){};

    virtual condition* get_condition(){};

    virtual void set_velocity(Vector2D){};

    virtual Vector2D get_velocity(){};

    virtual FSM* get_fsm(){};

    virtual Vector2D get_position();

    virtual void set_position(Vector2D);

    virtual void set_start_pos(Vector2D){};

    virtual Vector2D get_start_pos(){};

    string get_base_name();



};

class popetje : public active
{
    private:

    Vector2D velocity;
    Vector2D startpos;
    SDL_Event *event;
    FSM *enmfsm;
    cond thecond;

    public:
    //Initializes the variables

    popetje(SDL_Event*,sprite*,sprite*);
    popetje();

    //ads event to the main char to interpert keypresses
    void set_event(SDL_Event*);

    void set_life(int);

    void get_life(int);

     void steer();

    //Moves the dot
    void move();

    int get_xvel();

    int get_yvel();

    void set_velocity(Vector2D);

    Vector2D get_velocity();

    void animate();

    void update();

    void set_start_pos(Vector2D);

    Vector2D get_start_pos();

    void set_fsm(FSM*);

    FSM* get_fsm();

    Vector2D get_position();

    void set_position(Vector2D);

    void set_condition(condition*);

    condition* get_condition();

};


class enemy : public active
{
    private:
    //The dot's collision box
    //SDL_Rect box;

    //The velocity of the dot
	//Vector2D Velocity;
	FSM *enmfsm;
	cond thecond;
	Vector2D velocity;
	Vector2D startpos;



    public:
    //Initializes the variables

    enemy(sprite*,sprite*);
    enemy();


    void set_fsm(FSM*);

    FSM* get_fsm();

    //Takes key presses and adjusts the dot's velocity
    void steer();

    void move();

    void update();

    void animate();

    int get_xvel();

    int get_yvel();

    void set_velocity(Vector2D);

    Vector2D get_position();

    void set_position(Vector2D);

    Vector2D get_velocity();

    void set_condition(condition*);

    condition* get_condition();

    void set_start_pos(Vector2D);

    Vector2D get_start_pos();

};

class statisch : public active
{
    private:
    //The dot's collision box
    //SDL_Rect box;

    //The velocity of the dot
	//Vector2D Velocity;
	FSM *enmfsm;
	cond thecond;
	Vector2D velocity;
	Vector2D startpos;

    public:
    //Initializes the variables

	statisch(sprite*,sprite*);
	statisch();

    void set_fsm(FSM*);

    FSM* get_fsm();

    //Takes key presses and adjusts the dot's velocity
    void steer();

    void update();

    void animate();

    Vector2D get_position();

    void set_position(Vector2D);

    void set_condition(condition*);

    condition* get_condition();

    void set_start_pos(Vector2D);

    Vector2D get_start_pos();

};


#endif /* ACTIVE_H_ */



