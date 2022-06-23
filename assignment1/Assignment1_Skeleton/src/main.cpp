//--- 2021-2022 Summer Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Namig & Surname: NAMIG SAMADOV
//---Student Number: 150190912
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <fstream>

#include "../include/pokemon.h"

using namespace std;

//-------------Do Not Change These Global Variables-------------//
int NAME_COUNTER = 0;           // Use this to keep track of the enemy names
int POK_COUNTER = 0;            // Use this to keep track of the pokemon names
int PLAYER_POKEMON_ATTACK = 20; // You don't have to use this variable but its here if you need it
int ENEMY_POKEMON_ATTACK = 10;  // You don't have to use this variable but its here if you need it
//--------------------------------------------------------------//

//---If Necessary Add Your Global Variables Here---//
//
//
//
//-------------------------------------------------//

//-------------Do Not Change These Function Definitions-------------//
string *readEnemyNames(const char *);
string *readPokemonNames(const char *);
player characterCreate(string, int);
void mainMenu();
void fightEnemy(player *, string *, string *);
void catchPokemon(player *, string *);
//------------------------------------------------------------------//

//---If Necessary Add Your Function Definitions Here---//
//
int getSize(const char *);
//
//-----------------------------------------------------//

//-------------Do Not Change This Function-------------//
int main(int argc, char *argv[])
{
    system("clear");

    //---Creating Enemy and Pokemon Name Arrays---//
    string *enemyNames = readEnemyNames(argv[1]);
    string *pokemonNames = readPokemonNames(argv[2]);

    string playerName;
    int pokemonChoice;

    cout << "Welcome to the Pokemon Game! \n"
         << endl;
    cout << "Please enter your name: ";
    cin >> playerName;
    cout << "Please choose one of these pokemons as your pokemon: \n1- Bulbasaur \n2- Charmender \n3- Squirtle \nChoice: ";
    cin >> pokemonChoice;

    //---Character Creation--//
    player newPlayer = characterCreate(playerName, pokemonChoice);

    int menuChoice;

    while (true)
    {
        mainMenu();
        cin >> menuChoice;

        switch (menuChoice)
        {
        case 1:
            fightEnemy(&newPlayer, enemyNames, pokemonNames);
            break;
        case 2:
            catchPokemon(&newPlayer, pokemonNames);
            break;
        case 3:
            cout << newPlayer.showPokemonNumber() << endl;
            break;
        case 4:
            cout << newPlayer.showPokeballNumber() << endl;
            break;
        case 5:
            cout << newPlayer.showBadgeNumber() << endl;
            break;
        case 6:
            cout << endl;
            cout << "------- Pokedex -------" << endl;
            newPlayer.playerPokedex.printPokedex();
            break;
        case 7:
            //---Deletes Dynamic Arrays From Memory and Exits---//
            delete[] enemyNames;
            delete[] pokemonNames;
            return EXIT_SUCCESS;
            break;

        default:
            cout << "Please enter a valid number!!!" << endl;
            break;
        }
    }
    return EXIT_FAILURE;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
// As we need to get the size of the arrays twice I have seperated this as
// different function
int getSize(const char *argv)
{
    int arr_size;
    ifstream infile(argv);
    if (infile.is_open())
    {
        string str;
        int count = 0;
        while (infile >> str)
        {
            if (count == 0)
            {
                arr_size = stoi(str);
            }
            count++;
        }
    }
    infile.close();
    return arr_size;
}

string *readEnemyNames(const char *argv)
{
    int enemy_arr_size = getSize(argv);

    // First we got the array size then we were able
    // to create new dynamic array with given size

    string *enemy_arr = new string[enemy_arr_size];

    ifstream inFile(argv);
    if (inFile.is_open())
    {

        string str;
        int count = 0;
        while (inFile >> str)
        {

            if (count > 0)
            {
                enemy_arr[count - 1] = str;
            }
            count++;
        }
    }

    inFile.close();

    return enemy_arr;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string *readPokemonNames(const char *argv)
{
    int poke_arr_size = getSize(argv);

    ifstream inFile(argv);

    string *pokemon_arr = new string[poke_arr_size];
    if (inFile.is_open())
    {

        string str;
        int count = 0;
        while (inFile >> str)
        {

            if (count > 0)
            {
                pokemon_arr[count - 1] = str;
            }
            count++;
        }
    }

    inFile.close();

    return pokemon_arr;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
player characterCreate(string playerName, int pokemonChoice)
{

    string pokemon;

    switch (pokemonChoice)
    {
    case 1:
        pokemon = "Bulbasaur";
        break;
    case 2:
        pokemon = "Charmender";
        break;
    case 3:
        pokemon = "Squirtle";
        break;

    default:
        cout << "Please enter a valid number!!!" << endl;
        break;
    }

    player newPlayer(playerName, pokemon);

    return newPlayer;
};
//--------------------------------------------//

//-------------Do Not Change This Function-------------//
void mainMenu()
{
    cout << endl;
    cout << "-------- Menu --------" << endl;
    cout << "1. Fight for a badge" << endl;
    cout << "2. Catch a Pokemon" << endl;
    cout << "3. Number of Pokemons" << endl;
    cout << "4. Number of Pokeballs " << endl;
    cout << "5. Number of Badges" << endl;
    cout << "6. Pokedex" << endl;
    cout << "7. Exit" << endl;
    cout << endl;
    cout << "Choice: ";
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
void fightEnemy(player *newPlayer, string *enemyNames, string *pokemonNames)
{

    bool end = true;

    enemy myEnemy(enemyNames[NAME_COUNTER], pokemonNames[POK_COUNTER]);
    pokemon enemyPokemon = myEnemy.getPokemon();

    int hpValEnemy = enemyPokemon.getHpValue();
    int hpValPlayer = hpValEnemy;

    cout << "You encounter with " << enemyNames[NAME_COUNTER]
         << " and his/hers pokemon " << pokemonNames[POK_COUNTER] << endl;

    cout << pokemonNames[POK_COUNTER] << " Health: "
         << hpValEnemy << " Attack: "
         << ENEMY_POKEMON_ATTACK << endl;
    while (end)
    {
        if (hpValEnemy <= 0)
        {
            cout << "You Won!" << endl;
            newPlayer->battleWon();
            newPlayer->playerPokedex.updatePokedex(enemyPokemon);
            end = false;
        }
        else
        {

            int ch;
            cout << "1- Fight" << endl
                 << "2- Runaway" << endl
                 << "Choice: " << endl;

            cin >> ch;

            switch (ch)
            {
            case 1:
                hpValEnemy -= PLAYER_POKEMON_ATTACK;
                hpValPlayer -= ENEMY_POKEMON_ATTACK;
                break;

            case 2:
                end = false;
                break;

            default:
                cout << "Please enter a valid number!!!" << endl;

                break;
            }
            cout << "Your Pokemons Health: " << hpValPlayer << endl
                 << enemyNames[NAME_COUNTER] << " Pokemons Health: " << hpValEnemy << endl;
        }
    }

    NAME_COUNTER++;
    POK_COUNTER++;
};
//--------------------------------------------//

//-------------Code This Function-------------//
void catchPokemon(player *newPlayer, string *pokemonNames)
{
    pokemon newPoke = pokemon(pokemonNames[POK_COUNTER], 10);

    cout << "You encounter with " << pokemonNames[POK_COUNTER]
         << " Health: " << newPoke.getHpValue()
         << " Attack: " << newPoke.getAtkValue()
         << endl
         << endl;
    cout << "1- Catch" << endl
         << "2- Runaway" << endl
         << "Choice: ";
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
    case 2:
        newPlayer->catchPokemon();
        newPlayer->playerPokedex.updatePokedex(newPoke);
        cout << "You catch " << pokemonNames[POK_COUNTER];

        break;

    default:
        cout << "Please enter a valid number!!!" << endl;

        break;
    }
    POK_COUNTER++;
};
//--------------------------------------------//
