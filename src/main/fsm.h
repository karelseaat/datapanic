
#ifndef FSM_H
#define FSM_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Timer.h"
#include "boost/smart_ptr.hpp"
#include "condition.h"
#include "Vector2D.h"
#include "animation.h"




class FSM;

//An individual state (must belong to a FSM)
//This is an abstract class and must be sub-classed
class FSMState
{
public:
  FSMState(){};
  FSMState(FSM *fsm){};
  virtual ~FSMState(){};
  virtual void Update(const float& dt) = 0;
  virtual void DoENTER(){};
  virtual void DoEXIT(){};
  void set_dir_controll(Vector2D&);
  void set_cani_controll(animation*);


  std::string stateName;  //used to switch between states
  FSM *fsm;
  Timer atimer;
  int timeout;


};

class naaronder : public FSMState
{
public:
	naaronder(FSM *fs, std::string na,int t){this->fsm = fs;this->timeout = t;Timer timer();this->atimer.start();;this->stateName = na;};
	naaronder(FSM *fs){this->fsm = fs;};
	   void Update(const float& dt);
	   void DoENTER();
	   void DoEXIT();
};

class naarboven : public FSMState
{
public:
	naarboven(FSM *fs, std::string na,int t){this->fsm = fs;this->timeout = t;Timer timer();this->atimer.start();this->stateName = na;};
	naarboven(FSM *fs){this->fsm = fs;};
	   void Update(const float& dt);
	   void DoENTER();
	   void DoEXIT();
};

class naarrechts : public FSMState
{
public:
	naarrechts(FSM *fs, std::string na,int t){this->fsm = fs;this->timeout = t;Timer timer();this->atimer.start();this->stateName = na;};
	naarrechts(FSM *fs){this->fsm = fs;};
	   void Update(const float& dt);
	   void DoENTER();
	   void DoEXIT();
};

class muurbump : public FSMState
{
public:
	muurbump(FSM *fs, std::string na,int t){this->fsm = fs;this->timeout = t;Timer timer();this->atimer.start();this->stateName = na;};
	muurbump(FSM *fs){this->fsm = fs;};
	   void Update(const float& dt);
	   void DoENTER();
	   void DoEXIT();
};

class naarlinks : public FSMState
{
public:
	naarlinks(FSM *fs, std::string na,int t){this->fsm = fs;this->timeout = t;Timer timer();this->atimer.start();this->stateName = na;};
	naarlinks(FSM *fs){this->fsm = fs;};
	   void Update(const float& dt);
	   void DoENTER();
	   void DoEXIT();
};

class naarlinksonder : public FSMState
{
public:
	naarlinksonder(FSM *fs, std::string na,int t){this->fsm = fs;this->timeout = t;Timer timer();this->atimer.start();this->stateName = na;};
	naarlinksonder(FSM *fs){this->fsm = fs;};
	   void Update(const float& dt);
	   void DoENTER();
	   void DoEXIT();
};

class naarlinksboven : public FSMState
{
public:
	naarlinksboven(FSM *fs, std::string na,int t){this->fsm = fs;this->timeout = t;Timer timer();this->atimer.start();this->stateName = na;};
	naarlinksboven(FSM *fs){this->fsm = fs;};
	   void Update(const float& dt);
	   void DoENTER();
	   void DoEXIT();
};

class stop : public FSMState
{
public:
	stop(FSM *fs, std::string na,int t){this->fsm = fs;this->timeout = t;Timer timer();this->atimer.start();this->stateName = na;};
	stop(FSM *fs){this->fsm = fs;};
	   void Update(const float& dt);
	   void DoENTER();
	   void DoEXIT();
};

class reveit : public FSMState
{
public:
	reveit(FSM *fs, std::string na,int t){this->fsm = fs;this->timeout = t;Timer timer();this->atimer.start();this->stateName = na;};
	reveit(FSM *fs){this->fsm = fs;};
	   void Update(const float& dt);
	   void DoENTER();
	   void DoEXIT();
};

class dying : public FSMState
{
public:
	dying(FSM *fs, std::string na,int t){this->fsm = fs;this->timeout = t;Timer timer();this->atimer.start();this->stateName = na;};
	dying(FSM *fs){this->fsm = fs;};
	   void Update(const float& dt);
	   void DoENTER();
	   void DoEXIT();
};

class party : public FSMState
{
public:
	party(FSM *fs, std::string na,int t){this->fsm = fs;this->timeout = t;Timer timer();this->atimer.start();this->stateName = na;};
	party(FSM *fs){this->fsm = fs;};
	   void Update(const float& dt);
	   void DoENTER();
	   void DoEXIT();
};

class bumprest : public FSMState
{
public:
	bumprest(FSM *fs, std::string na,int t){this->fsm = fs;this->timeout = t;Timer timer();this->atimer.start();this->stateName = na;};
	bumprest(FSM *fs){this->fsm = fs;};
	   void Update(const float& dt);
	   void DoENTER();
	   void DoEXIT();
};

class popcontroll : public FSMState
{
public:
	popcontroll(FSM *fs, std::string na,int t){this->fsm = fs;this->timeout = t;Timer timer();this->atimer.start();this->stateName = na;};
	popcontroll(FSM *fs){this->fsm = fs;};
	   void Update(const float& dt);
	   void DoENTER();
	   void DoEXIT();
};

class test1 : public FSMState
{
public:
	test1(FSM *fs, std::string na,int t){this->fsm = fs;this->timeout = t;Timer timer();this->atimer.start();this->stateName = na;};
	test1(FSM *fs){this->fsm = fs;};
	   void Update(const float& dt);
	   void DoENTER();
	   void DoEXIT();

};

class test2 : public FSMState
{
public:
	test2(FSM *fs, std::string na,int t){this->fsm = fs;this->timeout = t;Timer timer();this->atimer.start();this->stateName = na;};
	test2(FSM *fs){this->fsm = fs;};
	   void Update(const float& dt);
	   void DoENTER();
	   void DoEXIT();

};

//A vector of shared pointers housing all the states in the machine
typedef std::vector< boost::shared_ptr<FSMState> > StateBank;

//---------------------------------------
//A Simple Finite State Machine
class FSM
{
public:
  FSM();
  FSM(condition*);
  ~FSM();
  void Update(const float& dt);

  void TransitionTo(std::string stateName);
  void DelayTransitionTo(std::string stateName);
  void AddState(FSMState *newState, bool makeCurrent);
  std::string GetState();
  bool get_timedout();
  void set_condi_controll(condition*); //todo deze 4 dingen moeten we aangezien ze nix met de SFM te maken hebben, te speectfiek voor deze game
  void set_dir_controll(Vector2D*);
  void set_cani_controll(animation*);
  void set_sani_controll(animation*);


public:
  FSMState *currentState;
  condition *cond;
  Vector2D *dircont;
  animation *animes,*animec;
  std::string delayState;
  //string *name;
  //bool *compusteer;

   //Bank to house list of states
  StateBank stateBank;
  std::vector< boost::shared_ptr<FSMState> >::iterator iter;
};

#endif
