#pragma once

#include"Character.h"
#include<iostream>
#include<ctime>
#include<string>
#include<iomanip>
#include"Functions.h"

using namespace std;

class Game
{
private:
	int choice;
	bool playing;

	// Character related
	Character character;

public:
	Game();
	virtual ~Game();

	//Operators

	//Functions
	void initGame();
	void mainMenu();

	//Accessors
	inline bool getPlaying() const {
		return this->playing;
	}

	//Modifiers

};

