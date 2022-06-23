//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname: NAMIG SAMADOV
//---Student Number: 150190912
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
//-------------Do Not Add Change Header Include Paths-------------/

#include <iostream>
using namespace std;
#include "Robot.h"

/*
****************
BEGIN: ROBOT CLASS FUNCTION DECLARATIONS
****************
*/
int Robot::unqID = 1; // Declaring staic int variable unqID
Robot::Robot(string type, float speed, int durability, int manufactureCost, float maintenanceCost) : RobotType(type), manufactureCost(manufactureCost)
{
  string typeType = type == "explorer" ? "exp" : "mnr"; // If type is explorer then type ID is exp, else type ID is mnr
  this->RobotName = typeType + "-" + to_string(unqID);  // Robot name is exp-1, mnr-1, exp-2, mnr-2, ...

  Robot::unqID++; // Incrementing static int variable unqID

  this->speed = speed;
  this->durability = durability;
  this->maintenanceCost = maintenanceCost;
  this->canMove = true;
}

void Robot::showInfo() const
{
  cout << "Name: " << this->RobotName << endl;
  cout << "Type: " << this->RobotType << endl;
  cout << "Speed: " << this->speed << endl;
  cout << "Durability: " << this->durability << endl;
  cout << "MaintenanceCost: " << this->maintenanceCost << endl;
  cout << "Can move: " << this->canMove << endl;
}

Robot Robot::operator=(const Robot &r)
{
  return Robot(r.RobotType, r.speed, r.durability, r.manufactureCost, r.maintenanceCost);
}

float Robot::getSpeed() const
{
  return this->speed;
}

string Robot::getName() const
{
  return this->RobotName;
}

int Robot::getManufactureCost() const
{
  return this->manufactureCost;
}

string Robot::getRobotType() const
{
  return this->RobotType;
}

void Robot::setDurability(int durability)
{
  this->durability = durability;
}

int Robot::getDurability() const
{
  return this->durability;
}

float Robot::getMaintenanceCost() const
{
  return this->maintenanceCost;
}

void Robot::setCanMove(bool canMove)
{
  this->canMove = canMove;
}

bool Robot::getCanMove() const
{
  return this->canMove;
}

/*
****************
END: ROBOT CLASS FUNCTION DECLARATIONS
****************
*/
/*
****************
BEGIN: EXPLORER CLASS FUNCTION DECLARATIONS
****************
*/

int Explorer::totalNumberOfSeleniumArea = 0; // Declaring static int variable totalNumberOfSeleniumArea
float Explorer::totalExploredArea = 0;       // Declaring static float variable totalExploredArea

Explorer::Explorer(string type, float speed, int durability) : Robot(type, speed, durability, 3000, 450.0 / speed)
{
  this->exploredArea = 0;
  this->detectedSelenium = false;
}

void Explorer::showInfo() const
{
  Robot::showInfo();
  cout << "explored area: " << this->exploredArea << endl;
}

Robot Explorer::operator=(const Explorer &r)
{
  return static_cast<Robot>(r);
}

bool Explorer::move() const
{
  return getCanMove();
}

void Explorer::explore()
{
  float randNum = rand() % 101; // Generating random number between 0 and 100
  if (randNum >= 40)
  {
    detectedSelenium = true;
    Explorer::totalNumberOfSeleniumArea++;
  }
  else
  {
    detectedSelenium = false;
  }
  totalExploredArea += 1500;
  exploredArea += 1500;
}

float Explorer::getExploredArea() const
{
  return this->exploredArea;
}

/*
****************
END: EXPLORER CLASS FUNCTION DECLARATIONS
****************
*/

/*
****************
BEGIN: MINER CLASS FUNCTION DECLARATIONS
****************
*/

int Miner::totalGatheredSelenium = 0; // Declaring static int variable totalGatheredSelenium

Miner::Miner(string type, float speed, int durability) : Robot(type, speed, durability, 5000, 750.0 / speed)
{
  this->gatheredSelenium = 0;
}

void Miner::showInfo() const
{
  Robot::showInfo();
  cout << "# of gathered selenium: " << this->gatheredSelenium << endl;
}

Miner Miner::operator=(const Miner &r)
{
  Miner m(r.getRobotType(), r.getSpeed(), r.getDurability()); // Creating new miner object
  m.setGatheredSelenium(r.getGatheredSelenium());             // Setting gathered selenium
  return m;
}

void Miner::mine()
{
  this->gatheredSelenium = 5 * ((rand() % 91) + 10); // Generating random number between 10 and 100 amd multiplying it by 5
  totalGatheredSelenium += this->gatheredSelenium;
  Explorer::totalNumberOfSeleniumArea--;
}

bool Miner::move() const
{

  if (this->getCanMove() && Explorer::totalNumberOfSeleniumArea != 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void Miner::setGatheredSelenium(int gatheredSelenium)
{
  this->gatheredSelenium = gatheredSelenium;
}

int Miner::getGatheredSelenium() const
{
  return this->gatheredSelenium;
}

/*
****************
END: MINER CLASS FUNCTION DECLARATIONS
****************
*/
