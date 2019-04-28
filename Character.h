#pragma once

#include<string>
#include<iostream>
#include <iomanip>

using namespace std;

class Character
{
public:
	Character();
	Character(string name, int level, int exp, int strength, int vitality, int dexterity, int intelligence, int health, int stamina, int statPoints);
	virtual ~Character();

	//Functions
	void initialize(const string name);
	void printStats() const;
	string getAsString() const;
	void levelUp();
	void updateStats();
		
	//Accessors
	inline const double& getX() const { return this->xPos; }
	inline const double& getY() const { return this->yPos;  }
	inline const string& getName() const { return this->name; }
	inline const int& getLevel() const { return this->level; }
	inline const int& getExp() const { return this->exp; }
	inline const int& getExpNext() const { return this->expNext; }
	inline const int& getHealth() const { return this->health; }
	inline const int& getHPMax() const { return this->hpMax; }
	inline const int& getStamina() const { return this->stamina; }
	inline const int& getDamageMin() const { return this->damageMin; }
	inline const int& getDamageMax() const { return this->damageMax; }
	inline const int& getDefense() const { return this->defence; }

	//Modifier

private:
	double xPos;
	double yPos;

	string name;
	int level;
	int exp;
	int expNext;
	int health;
	int hpMax;
	int stamina;
	int staminaMax;
	int damageMin;
	int damageMax;
	int defence;

	int strength;
	int vitality;
	int dexterity;
	int intelligence;

	int statPoints;
	int skillPoints;
};