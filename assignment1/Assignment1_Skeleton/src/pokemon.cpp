//--- 2021-2022 Summer Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname: NAMIG SAMADOV
//---Student Number: 150190912
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "../include/pokemon.h"

using namespace std;

//-------------You Can Add Your Functions Down Below-------------//

// Class pokemon starts here

// I have just followed the instructions on the pdf here

pokemon::pokemon()
{
  this->name = "Pikachu";
  this->hpValue = 100;
  this->atkValue = 20;
}

pokemon::pokemon(string &name, int attack_value)
{
  setName(name);
  this->hpValue = 100;
  setAtkValue(attack_value);
}

pokemon::pokemon(const pokemon &pocketMonster)
{
  this->name = pocketMonster.name;
  this->atkValue = pocketMonster.atkValue;
  this->hpValue = pocketMonster.hpValue;
}

void pokemon::setName(string &name)
{
  this->name = name;
}

string pokemon::getName()
{
  return this->name;
}

void pokemon::setHpValue(int &hpVal)
{
  this->hpValue = hpVal;
}

int pokemon::getHpValue()
{
  return this->hpValue;
}

void pokemon::setAtkValue(int &atkVal)
{
  this->atkValue = atkVal;
}

int pokemon::getAtkValue()
{
  return this->atkValue;
}

// Class pokemon ends here

// Class pokedex starts here

pokedex::pokedex()
{
  this->value = 0;
}

void pokedex::updatePokedex(pokemon &newPokemon)
{
  int i = 0;
  for (int i = 0; i < value; i++)
  {
    if (pokedexArray[i].name == newPokemon.name)
    {
      i = 1;
    }
  }
  if (i == 0)
  {
    pokedexArray[value - 1] = newPokemon;
  }
}

void pokedex::printPokedex()
{
  for (int i = 0; i < value; i++)
  {
    cout << pokedexArray[i].getName() << endl;
  }
}

void pokedex::increaseVal()
{
  value += 1;
}

// Class pokedex ends here

// Class player starts here

player::player()
{
  this->name = "Pikachu";
  this->pokemonNumber = 0;
  this->pokeballNumber = 10;
  this->badgeNumber = 0;
}

player::player(string name, string &pocketmonster)
{
  this->name = name;
  this->pokemonNumber = 0;
  this->pokeballNumber = 10;
  this->badgeNumber = 0;
  this->playerPokemon = pokemon(pocketmonster, 20); // My pokemon with attack value 20
}

int player::showBadgeNumber()
{
  return this->badgeNumber;
}
int player::showPokeballNumber()
{
  return this->pokeballNumber;
}
int player::showPokemonNumber()
{
  return this->pokemonNumber;
}
pokemon player::getPlayerPokemon()
{
  return this->playerPokemon;
}
void player::battleWon()
{
  player::pokeballNumber += 3;
  player::badgeNumber++;
  playerPokedex.increaseVal();
}
void player::catchPokemon()
{
  player::pokemonNumber++;
  player::pokeballNumber--;
  playerPokedex.increaseVal();
}

// Class player ends here

// Class enemy starts here

enemy::enemy()
{
  this->name = "Pikachu";
}

enemy::enemy(string &name, string &pocketMonster)
{
  this->name = name;
  enemyPokemon = pokemon(pocketMonster, 10); // enemy pokemon with attack value 10
}

pokemon enemy::getPokemon()
{
  return this->enemyPokemon;
}
string enemy::getName()
{
  return this->name;
}

// Class enemy ends here
