//--- 2021-2022 Summer Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname: NAMIG SAMADOV
//---Student Number: 150190912
//--------------------------//

#ifndef _H
#define _H

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//-------------Do Not Add Any New Class(es)-------------//

// TODO: 3 constructors -> default -> done
//                      -> Pokemon with default values -> done
//                      -> copy constructor
// Getter -> done

class pokemon
{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
private:
    string name;
    int hpValue;
    int atkValue;
    //
    friend class pokedex;

public:
    pokemon();
    pokemon(string &, const int);
    pokemon(const pokemon &);

    // implemented setter and getter methods
    void setName(string &);
    string getName();

    void setHpValue(int &);
    int getHpValue();

    void setAtkValue(int &);
    int getAtkValue();
};

// TODO: Constructor intialized value as 0
//       Update pokedex -> done
//       print pokedex  -> done

class pokedex
{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
private:
    pokemon pokedexArray[100];
    int value;

public:
    pokedex();
    void updatePokedex(pokemon &);
    void printPokedex();

    void increaseVal();
};

class player
{
private:
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    string name;
    int pokemonNumber;
    int pokeballNumber;
    int badgeNumber;
    pokemon playerPokemon;

public:
    pokedex playerPokedex;
    player();
    player(string, string &);

    int showPokemonNumber();
    int showPokeballNumber();
    int showBadgeNumber();
    pokemon getPlayerPokemon();
    void battleWon();
    void catchPokemon();
};

class enemy
{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
private:
    string name;
    pokemon enemyPokemon;

public:
    enemy();
    enemy(string &, string &);

    pokemon getPokemon();
    string getName();
};

#endif