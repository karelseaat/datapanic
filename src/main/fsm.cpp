//FSM.cpp
#include "fsm.h"

//Constructor
FSM::FSM()
{
  currentState = NULL;
  delayState = "NONE";
}

FSM::FSM(condition *cond)
{
  this->cond = cond;
  currentState = NULL;
  delayState = "NONE";
}


//Destructor
FSM::~FSM()
{
  stateBank.clear();
}

//Update each tick
void FSM::Update(const float& dt)
{
  //Make sure a current state is loaded
  if (currentState == NULL)
  {
	  cout << "state null" << endl;
	  return;
  }
  //Check if there are any delayed transition requests
  if (delayState != "NONE")
  {
    TransitionTo(delayState);
    delayState = "NONE";
  }
  //Update the current state, may trigger a transition.

  currentState->Update(dt);
}


//Called to transition to another state
//@param stateName the name of the state to transition to
void FSM::TransitionTo(std::string stateName)
{
  //Find the named state
  FSMState *goToState = NULL;
  for(iter= stateBank.begin(); iter!= stateBank.end(); iter++)
    if ( (*iter)->stateName == stateName )
      goToState = iter->get();

  //Error, trying to transition to a non-existant state
  if (goToState == NULL)
  {
    //Print an error here, or assert if you want
	std::cout << "NuLL eRROr:" << stateName << std::endl;
    return;
  }

  currentState->atimer.stop();
  goToState->atimer.start();
  currentState->DoEXIT();
  goToState->DoENTER();
  currentState = goToState;
}

//Transition to another state (delayed until beginning of next update)
//@param stateName the name of the state to transition to
void FSM::DelayTransitionTo(std::string stateName)
{
  delayState = stateName;
}

//Add a state to the bank, optionally make it the current state
//@param newState the new state to add to the state machine
//@param makeCurrent is this new state the current state?
void FSM::AddState(FSMState *newState, bool makeCurrent)
{
  //Add this state to the FSM
  boost::shared_ptr<FSMState> newStatePtr(newState);
  stateBank.push_back(newStatePtr);

  //Make this the current state?
  if (makeCurrent)
	  currentState = newState;

}

//What is the name of the current state?
std::string FSM::GetState()
{
  return currentState->stateName;
}

bool FSM::get_timedout()
{
	return (this->currentState->atimer.get_ticks()  > this->currentState->timeout);

}

void FSM::set_condi_controll(condition* condi)
{
	this->cond = condi;
}

void FSM::set_dir_controll(Vector2D* dir)
{
	this->dircont = dir;
}

void FSM::set_cani_controll(animation* anime)
{
	this->animec = anime;
}

void FSM::set_sani_controll(animation* anime)
{
	this->animes = anime;
}



void naarboven::DoENTER()
{
	this->fsm->dircont->y = -5;
	this->fsm->dircont->x = 0;
	this->fsm->animec->startani();
	this->fsm->animes->startani();
	this->fsm->animes->set_all("LEFT","1,1,2,2,3,3,4,4");
	this->fsm->animec->set_all("LEFT","1,1,2,2,3,3,4,4");
}

void naarboven::DoEXIT()
{

}

void naarboven::Update(const float& dt)
{
	if (this->atimer.get_ticks()  > this->timeout)
		{
			int arand = (rand()%2)+1;
				if (arand == 1)
				{
					this->fsm->TransitionTo("naarlinksboven");
				}
				else
				{
					this->fsm->TransitionTo("stop");
				}
		}
}

void naaronder::DoENTER()
{
	this->fsm->dircont->y = 5;
	this->fsm->dircont->x = 0;
	this->fsm->animec->startani();
	this->fsm->animes->startani();
	this->fsm->animes->set_all("LEFT","1,1,2,2,3,3,4,4");
	this->fsm->animec->set_all("LEFT","1,1,2,2,3,3,4,4");
}

void naaronder::DoEXIT()
{

}

void naaronder::Update(const float& dt)
{
	if (this->atimer.get_ticks()  > this->timeout)
			{
				int arand = (rand()%2)+1;
					 if (arand == 1)
					{
						this->fsm->TransitionTo("naarlinksonder");
					}
					else
					{
						this->fsm->TransitionTo("stop");
					}

			}
}

void naarlinks::DoENTER()
{
	this->fsm->dircont->x = -5;
	this->fsm->dircont->y = 0;
	this->fsm->animec->startani();
	this->fsm->animes->startani();
	this->fsm->animes->set_all("LEFT","1,1,2,2,3,3,4,4");
	this->fsm->animec->set_all("LEFT","1,1,2,2,3,3,4,4");
}

void naarlinks::DoEXIT()
{

}

void naarlinks::Update(const float& dt)
{
	if (this->atimer.get_ticks()  > this->timeout)
			{
				int arand = (rand()%3)+1;

					if (arand == 1)
					{
						this->fsm->TransitionTo("naarlinksonder");
					}
					else if (arand == 2)
					{
						this->fsm->TransitionTo("naarlinksboven");
					}
					else
					{
						this->fsm->TransitionTo("stop");
					}
			}
}

void naarlinksboven::DoENTER()
{
	this->fsm->dircont->x = -5;
	this->fsm->dircont->y = -5;
	this->fsm->animec->startani();
	this->fsm->animes->startani();
	 this->fsm->animes->set_all("LEFT","1,1,2,2,3,3,4,4");
	 this->fsm->animec->set_all("LEFT","1,1,2,2,3,3,4,4");
}

void naarlinksboven::DoEXIT()
{

}

void naarlinksboven::Update(const float& dt)
{
	if (this->atimer.get_ticks()  > this->timeout)
			{
				int arand = (rand()%2)+1;

					if (arand == 1)
					{
						this->fsm->TransitionTo("naarlinks");
					}
					else
					{
						this->fsm->TransitionTo("naarboven");
					}

			}
}

void naarlinksonder::DoENTER()
{
	this->fsm->dircont->x = -5;
	this->fsm->dircont->y = 5;
	this->fsm->animec->startani();
	this->fsm->animes->startani();
	 this->fsm->animes->set_all("LEFT","1,1,2,2,3,3,4,4");
	 this->fsm->animec->set_all("LEFT","1,1,2,2,3,3,4,4");
}

void naarlinksonder::DoEXIT()
{

}


void naarlinksonder::Update(const float& dt)
{
	if (this->atimer.get_ticks()  > this->timeout)
			{
				int arand = (rand()%2)+1;

					if (arand == 1)
					{
						this->fsm->TransitionTo("naaronder");
					}
					else
					{
						this->fsm->TransitionTo("naarlinks");
					}

			}
}





void stop::DoENTER()
{
	this->fsm->dircont->x = 0;
	this->fsm->dircont->y = 0;
	this->fsm->animec->stopani();
	this->fsm->animes->stopani();
	//cout << "enter stop" << endl;
	//string tempst = this->fsm->cond->get_com_name();
	if (this->fsm->cond->get_com_name().compare("pop") == 0)
	{

		this->fsm->TransitionTo("popcontroll");
	}
	else
	{
		this->fsm->animes->set_all("LEFT","1,1,2,2,3,3,4,4");
		this->fsm->animec->set_all("LEFT","1,1,2,2,3,3,4,4");
	}
}

void stop::DoEXIT()
{

}

void stop::Update(const float& dt)
{
	if (this->atimer.get_ticks()  > this->timeout)
			{
		string tempst = this->fsm->cond->get_com_name();

			if (tempst.substr(0,3).compare("enm") == 0)
					{
					int arand = (rand()%4)+1;
					if (arand == 1)
					{
						this->fsm->TransitionTo("naarlinksonder");
					}
					else if (arand == 2)
					{
						this->fsm->TransitionTo("naarlinksboven");
					}
					else
					{
						this->fsm->TransitionTo("naarlinks");
					}
					}
					else
					{
						if (tempst.substr(0,3).compare("sta") == 0)
						{
							this->fsm->TransitionTo("stop");
						}

					}
			}
}

void reveit::DoENTER()
{

	//this->fsm->cond->set_c_steer(true);
	this->fsm->cond->plus_health(-1);

	if (this->fsm->dircont->x == 0 && this->fsm->dircont->y == 0)
	{
	if (!this->fsm->cond->get_invincible())
		this->fsm->cond->plus_health(-10);

	}
	this->fsm->dircont->x *= -1;
	this->fsm->dircont->y *= -1;
	if (this->fsm->animec->get_name() == "RIGHT")
	{
		this->fsm->animes->set_all("RPAIN","1,1,1,1,5,5,5,5");
		this->fsm->animec->set_all("RPAIN","1,1,1,1,5,5,5,5");
	}
	else if (this->fsm->animec->get_name() == "LEFT")
	{
		this->fsm->animec->set_all("LPAIN","5,5,6,6,7,8,8,8");
		this->fsm->animes->set_all("LPAIN","5,5,6,6,7,8,8,8");
	}
}

void reveit::DoEXIT()
{
	this->fsm->animec->set_all("LPAIN","1");
	this->fsm->animes->set_all("LPAIN","1");
}

void reveit::Update(const float& dt)
{

	if (this->atimer.get_ticks() > this->timeout)
			{
				if (this->fsm->cond->get_health() <=0)
				{
					this->fsm->TransitionTo("dying");
				}
				this->fsm->TransitionTo("bumprest");

			}
}

void dying::DoENTER()
{
	cout << "sterf enter" << endl;
	//this->fsm->cond->set_health(0);
}

void dying::DoEXIT()
{
	cout << "sterf exit" << endl;
	this->fsm->cond->set_health(0);
}

void dying::Update(const float& dt)
{
	if (this->atimer.get_ticks()  > this->timeout)
	{
		this->fsm->TransitionTo("stop");
	}
}

void muurbump::DoENTER()
{
	this->fsm->dircont->x = 0;
	this->fsm->dircont->y = 0;

	this->fsm->animec->stopani();
	this->fsm->animes->stopani();
}

void muurbump::DoEXIT()
{
}

void muurbump::Update(const float& dt)
{
	if (this->atimer.get_ticks()  > this->timeout)
	{
		string tempst = this->fsm->cond->get_com_name();

		if (tempst.substr(0,3).compare("pop") != 0)
		{
			this->fsm->TransitionTo("dying");
		}
		else
		{
			this->fsm->TransitionTo("reveit");
		}


	}
}

void popcontroll::DoENTER()
{
}

void popcontroll::DoEXIT()
{

}

void popcontroll::Update(const float& dt)
{
	if (this->atimer.get_ticks()  > this->timeout)
	{

	}
}

void party::DoENTER()
{

}

void party::DoEXIT()
{
	//this->fsm->cond->set_win(true);
}

void party::Update(const float& dt)
{
	if (this->atimer.get_ticks()  > this->timeout)
	{

	}
}

void bumprest::DoENTER()
{
	this->fsm->dircont->x = 0;
	this->fsm->dircont->y = 0;
	if (this->fsm->animec->get_name() == "RPAIN")
	{
		//this->fsm->animes->set_all("RIGHT","1,2,3,4,5,6,7,8");
		//this->fsm->animec->set_all("RIGHT","1,2,3,4,5,6,7,8");
	}
	else if (this->fsm->animec->get_name() == "LPAIN")
	{
		 //this->fsm->animes->set_all("LEFT","16,15,14,13,12,11,10,9");
		 //this->fsm->animec->set_all("LEFT","16,15,14,13,12,11,10,9");
	}
}

void bumprest::DoEXIT()
{

}

void bumprest::Update(const float& dt)
{
	if (this->atimer.get_ticks()  > this->timeout)
	{
		{
			string tempst = this->fsm->cond->get_com_name();
			if (!tempst.substr(0,3).compare("pop"))
				this->fsm->TransitionTo("popcontroll");
			else
				this->fsm->TransitionTo("stop");

		}
	}
}

void test1::DoENTER()
{


}

void test1::DoEXIT()
{

}

void test1::Update(const float& dt)
{
	if (this->atimer.get_ticks()  > this->timeout)
	{

		this->fsm->TransitionTo("test2");

	}
}

void test2::DoENTER()
{


}

void test2::DoEXIT()
{

}

void test2::Update(const float& dt)
{
	if (this->atimer.get_ticks()  > this->timeout)
	{

		this->fsm->TransitionTo("test1");

	}
}


