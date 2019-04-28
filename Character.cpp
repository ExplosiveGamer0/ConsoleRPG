#include "Character.h"


using namespace std;

Character::Character()
{
	this->xPos = 0.0;
	this->yPos = 0.0;
	
	this->name = "";
	this->level = 0;
	this->exp = 0;
	this->expNext = 0;
	this->health = 0;
	this->hpMax = 0;
	this->stamina = 0;
	this->staminaMax = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defence = 0;

	this->strength = 0;
	this->vitality = 0;
	this->dexterity = 0;
	this->intelligence = 0;

	this->statPoints = 0;
	this->skillPoints = 0;
}

Character::Character(string name, int level, int exp, int strength, int vitality, int deterity, int intelligence, int health, int stamina, int statPoints)
{
	this->name = name;
	this->level = level;
	this->exp = exp;
	this->expNext = 0;

	this->strength = strength;
	this->vitality = vitality;
	this->dexterity = dexterity;
	this->intelligence = intelligence;

	this->health = health;
	this->hpMax = 0;
	this->stamina = stamina;
	this->staminaMax = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defence = 0;

	this->statPoints = statPoints;

	this->updateStats();
}

Character::~Character()
{

}

//Functions
void Character::initialize(const string name)
{
	this->xPos = 0.0;
	this->yPos = 0.0;

	this->name = name;
	this->level = 1;
	this->exp = 0;

	this->strength = 5;
	this->vitality = 5;
	this->dexterity = 5;
	this->intelligence = 5;

	this->statPoints = 0;

	this->updateStats();
}

void Character::printStats() const
{
	cout << "= Character Sheet =" << endl;
	cout << "= Name: " << this->name << endl;
	cout << "= Level: " << this-level << endl;
	cout << "= Exp: " << this->exp << endl;
	cout << "= Exp to next level: " << this->expNext << endl;
	cout << setw(10) << setfill('=') << endl;
	cout << "= Strength: " << this->strength << endl;
	cout << "= Vitality: " << this->vitality << endl;
	cout << "= Dexterity: " << this->dexterity << endl;
	cout << "= Intelligence: " << this->intelligence << endl;
	cout << setw(10) << setfill('=') << endl;
	cout << "= HP: " << this->health << " / " << this->hpMax << endl;
	cout << "= Stamina: " << this->stamina << " / " << this->staminaMax << endl;
	cout << "= Damage: " << this->damageMin << " - " << this->damageMax << endl;
	cout << "= Defense: " << this->defence << endl;
}

string Character::getAsString() const
{
	return name + " "
		+ to_string(level) + " "
		+ to_string(exp) + " "
		+ to_string(strength) + " "
		+ to_string(vitality) + " "
		+ to_string(dexterity) + " "
		+ to_string(intelligence) + " "
		+ to_string(health) + " "
		+ to_string(stamina) + " "
		+ to_string(statPoints) + " ";
}

void Character::levelUp() 
{
	if (this->exp >= this->expNext)
	{
		this->exp -= this->expNext;
		this->level++;
		this->expNext = static_cast<int>((50 / 3) * ((pow(level, 3)
			- 6 * pow(level, 2))
			+ 17 * level - 12)) + 100;

		this->statPoints++;

		this->updateStats();

		cout << "You are now level " << this->level << "!" << "\n\n";
	}
	else
	{
		cout << "Not enough Exp!" << "\n\n";
	}
}

void Character::updateStats()
{
	{
		this->expNext = static_cast<int>(
			(50 / 3) * ((pow(level, 3)
				- 6 * pow(level, 2))
				+ 17 * level - 12)) + 100;

		this->hpMax = (this->vitality * 5) + (this->strength) + this->level * 5;
		this->staminaMax = this->vitality + (this->strength / 2) + (this->dexterity / 3);
		this->stamina = this->staminaMax;
		this->damageMin = this->strength;
		this->damageMax = this->strength + 2;
		this->defence = this->dexterity + (this->intelligence / 2);

		this->health = this->hpMax;
	}
}
