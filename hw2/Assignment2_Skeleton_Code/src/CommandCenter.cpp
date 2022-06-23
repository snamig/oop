//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname: NAMIG SAMADOV
//---Student Number: 150190912
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
//-------------Do Not Add Change Header Include Paths-------------//
#include "CommandCenter.h"
#include "Robot.h"
#include <iostream>
using namespace std;
/*
****************
BEGIN: CREW CLASS FUNCTION DECLARATIONS
****************
*/

// Crew::Crew(int maxExplorers, int maxMiners, int explorerCrewSize, int minerCrewSize)
// {
//   this->crewMaintenanceCost = 0;
//   this->crewManufactureCost = 0;

//   if (this->maxExplorers < 1 || this->maxExplorers > 5)
//     this->maxExplorers = 2;
//   else
//     this->maxExplorers = maxExplorers;

//   if (this->maxMiners < 1 || this->maxMiners > 5)
//     this->maxMiners = 2;
//   else
//     this->maxMiners = maxMiners;

//   if (this->explorerCrewSize > maxExplorers || this->explorerCrewSize < 0)
//     this->explorerCrewSize = this->maxExplorers;
//   else
//     this->explorerCrewSize = explorerCrewSize;

//   if (this->minerCrewSize > maxMiners || this->minerCrewSize < 0)
//     this->minerCrewSize = this->maxMiners;
//   else
//     this->minerCrewSize = minerCrewSize;

//   this->ExplorerCrew = new Explorer *[this->explorerCrewSize];
//   for (int i = 0; i < this->explorerCrewSize; i++)
//   {
//     // this->ExplorerCrew[i] = (Explorer *)this->manufactureRobot("explorer");
//     this->ExplorerCrew[i] = static_cast<Explorer *>(this->manufactureRobot("explorer"));
//   }

//   this->MinerCrew = new Miner *[this->minerCrewSize];
//   for (int i = 0; i < this->minerCrewSize; i++)
//   {
//     this->MinerCrew[i] = static_cast<Miner *>(this->manufactureRobot("miner"));
//   }
// }

// void Crew::showInfo() const
// {
//   cout << "explorerCrew Size:" << explorerCrewSize << endl;
//   cout << "minerCrew Size:" << minerCrewSize << endl;
//   for (int i = 0; i < explorerCrewSize; i++)
//   {
//     this->ExplorerCrew[i]->showInfo();
//   }
//   for (int i = 0; i < minerCrewSize; i++)
//   {
//     this->MinerCrew[i]->showInfo();
//   }
//   cout << "Total manufacture cost: " << crewManufactureCost << endl;
//   cout << "Total maintenance cost: " << crewMaintenanceCost << endl;
// }

// int Crew::getCrewManufactureCost() const
// {
//   return this->crewManufactureCost;
// }

// void Crew::setCrewMaintenanceCost(float crewMaintenanceCost)
// {
//   this->crewMaintenanceCost = crewMaintenanceCost;
// }

// float Crew::getCrewMaintenanceCost() const
// {
//   return this->crewMaintenanceCost;
// }

// int Crew::getExplorerCrewSize() const
// {
//   return this->explorerCrewSize;
// }

// int Crew::getMinerCrewSize() const
// {
//   return this->minerCrewSize;
// }

// void Crew::operator+=(Robot *r)
// {
//   string type = r->getName();
//   string shortType = "";

//   if (type == "explorer")
//   {
//     shortType = "exp";
//   }
//   else if (type == "miner")
//   {
//     shortType = "mnr";
//   }

//   bool add = false;

//   if (shortType == "exp")
//   {
//     if (this->maxExplorers > this->explorerCrewSize)
//     {
//       add = true;
//       this->ExplorerCrew[explorerCrewSize] = static_cast<Explorer *>(r);
//       this->explorerCrewSize++;
//     }
//   }
//   else if (shortType == "mnr")
//   {
//     if (this->maxMiners > this->minerCrewSize)
//     {
//       add = true;
//       this->MinerCrew[minerCrewSize] = static_cast<Miner *>(r);
//       this->minerCrewSize++;
//     }
//   }

//   if (add == false)
//   {
//     cout << "This robot cannot be added, check maximum size of the crew" << endl;
//     Crew::crewManufactureCost -= r->getManufactureCost();
//     delete r;
//   }
// }

// void Crew::operator-=(string robotName)
// {
//   string shortType = "";

//   if (robotName == "explorer")
//   {
//     shortType = "exp";
//   }
//   else if (robotName == "miner")
//   {
//     shortType = "mnr";
//   }

//   int i = 0; // index for the crew
//   if (shortType == "exp")
//   {
//     if (this->explorerCrewSize != 1)
//     {
//       while (this->ExplorerCrew[i]->getName() != robotName)
//       {
//         i++;
//       }
//       delete this->ExplorerCrew[i];
//       for (int j = i + 1; j < this->explorerCrewSize; j++)
//       {
//         this->ExplorerCrew[j - 1] = this->ExplorerCrew[j];
//       }
//       this->explorerCrewSize--;
//       this->ExplorerCrew[explorerCrewSize] = NULL;
//     }
//   }
//   else if (shortType == "mnr")
//   {
//     if (this->minerCrewSize != 1)
//     {
//       while (this->MinerCrew[i]->getName() != robotName)
//       {
//         i++;
//       }
//       delete this->MinerCrew[i];
//       for (int j = i + 1; j < this->minerCrewSize; j++)
//       {
//         this->MinerCrew[j - 1] = this->MinerCrew[j];
//       }
//       this->minerCrewSize--;
//       this->MinerCrew[minerCrewSize] = NULL;
//     }
//   }
//   cout << robotName << ": Goodbye" << endl;
// }

// Robot *Crew::manufactureRobot(string robotType)
// {
//   int dur = (rand() % 5) + 1;
//   float spd;
//   bool initialMove = true;

//   while (robotType != "explorer" && robotType != "miner")
//   {
//     if (robotType == "null")
//     {
//       initialMove = false;
//     }
//     cout << "Type:";
//     cin >> robotType;
//   }
//   if (robotType == "explorer")
//   {
//     spd = (float)rand() / (float)RAND_MAX;
//     spd += 1.5;
//     crewManufactureCost += 3000;
//     Explorer *newExplorer = new Explorer(robotType, spd, dur);
//     newExplorer->setCanMove(initialMove);
//     return newExplorer;
//   }
//   else
//   {
//     spd = (float)rand() / ((float)RAND_MAX);
//     spd /= 2.0;
//     spd += 1.0;
//     crewManufactureCost += 5000;
//     Miner *newMiner = new Miner(robotType, spd, dur);
//     newMiner->setCanMove(initialMove);
//     return newMiner;
//   }
// }

// void Crew::initMovement()
// {
//   for (int i = 0; i < this->explorerCrewSize; i++)
//   {
//     this->ExplorerCrew[i]->setCanMove(true);
//   }
//   for (int i = 0; i < this->minerCrewSize; i++)
//   {
//     this->MinerCrew[i]->setCanMove(true);
//   }
// }

// void Crew::updateDurability()
// {
//   cout << "Explorer durability updated" << endl;
//   for (int i = 0; i < this->explorerCrewSize; i++)
//   {
//     if (this->ExplorerCrew[i]->getExploredArea() > 0)
//     {
//       this->ExplorerCrew[i]->setDurability((this->ExplorerCrew[i]->getDurability()) - 1);
//       if (this->ExplorerCrew[i]->getDurability() == 0)
//       {
//         cout << "Durability of " << this->ExplorerCrew[i]->getName() << " = 0" << endl;
//         operator-=(ExplorerCrew[i]->getName());
//       }
//     }
//   }
//   cout << "Miner durability updated" << endl;
//   for (int i = 0; i < this->minerCrewSize; i++)
//   {
//     if (this->MinerCrew[i]->getGatheredSelenium() > 0)
//     {
//       this->MinerCrew[i]->setDurability((this->MinerCrew[i]->getDurability()) - 1);
//       if (this->MinerCrew[i]->getDurability() != 0)
//       {
//         cout << "Durability of " << this->MinerCrew[i]->getName() << " = 0" << endl;
//         operator-=(MinerCrew[i]->getName());
//       }
//     }
//   }
// }

// Crew::~Crew()
// {
//   for (int i = 0; i < this->explorerCrewSize; i++)
//   {
//     delete this->ExplorerCrew[i];
//   }
//   delete[] this->ExplorerCrew;
//   for (int i = 0; i < this->minerCrewSize; i++)
//   {
//     delete this->MinerCrew[i];
//   }
//   delete[] this->MinerCrew;
// }

Crew::Crew(int maxExplorers, int maxMiners, int explorerCrewSize, int minerCrewSize)
{
  if (5 < maxExplorers || 1 > maxExplorers)
  {
    this->maxExplorers = 2;
  }
  else
  {
    this->maxExplorers = maxExplorers;
  }
  if (5 < maxMiners || 1 > maxMiners)
  {
    this->maxMiners = 2;
  }
  else
  {
    this->maxMiners = maxMiners;
  }
  if (explorerCrewSize < 0 || explorerCrewSize > maxExplorers)
  {
    this->explorerCrewSize = this->maxExplorers;
  }
  else
  {
    this->explorerCrewSize = explorerCrewSize;
  }
  if (minerCrewSize < 0 || minerCrewSize > maxMiners)
  {
    this->minerCrewSize = this->maxMiners;
  }
  else
  {
    this->minerCrewSize = minerCrewSize;
  }
  this->crewMaintenanceCost = 0;
  this->crewManufactureCost = 0;
  this->ExplorerCrew = new Explorer *[this->explorerCrewSize];
  this->MinerCrew = new Miner *[this->minerCrewSize];
  for (int i = 0; i < this->explorerCrewSize; i++)
  {
    this->ExplorerCrew[i] = (Explorer *)this->manufactureRobot("explorer");
  }
  for (int i = 0; i < this->minerCrewSize; i++)
  {
    this->MinerCrew[i] = (Miner *)this->manufactureRobot("miner");
  }
};
Crew::~Crew()
{
  for (int i = 0; i < this->explorerCrewSize; i++)
  {
    delete this->ExplorerCrew[i];
  }
  delete[] this->ExplorerCrew;
  for (int i = 0; i < this->minerCrewSize; i++)
  {
    delete this->MinerCrew[i];
  }
  delete[] this->MinerCrew;
}
Robot *Crew::manufactureRobot(string type)
{
  int generatedDurability = (rand() % 5) + 1;
  float generatedSpeed;
  bool initialMove = true;
  while (type != "explorer" && type != "miner")
  {
    if (type == "NULL")
    {
      initialMove = false;
    }
    cout << "Type:";
    cin >> type;
  }
  if (type == "explorer")
  {
    generatedSpeed = (float)rand() / (float)RAND_MAX;
    generatedSpeed += 1.5;
    crewManufactureCost += 3000;
    Explorer *newExplorer = new Explorer(type, generatedSpeed, generatedDurability);
    newExplorer->setCanMove(initialMove);
    return newExplorer;
  }
  else
  {
    generatedSpeed = (float)rand() / ((float)RAND_MAX);
    generatedSpeed /= 2.0;
    generatedSpeed += 1.0;
    crewManufactureCost += 5000;
    Miner *newMiner = new Miner(type, generatedSpeed, generatedDurability);
    newMiner->setCanMove(initialMove);
    return newMiner;
  }
};
void Crew::initMovement()
{
  for (int i = 0; i < minerCrewSize; i++)
  {
    this->MinerCrew[i]->setCanMove(true);
  }
  for (int i = 0; i < explorerCrewSize; i++)
  {
    this->ExplorerCrew[i]->setCanMove(true);
  }
};
void Crew::updateDurability()
{
  cout << "Explorer durability is being updated" << endl;
  for (int i = 0; i < explorerCrewSize; i++)
  {
    if (this->ExplorerCrew[i]->getExploredArea() > 0)
    {
      int durability = this->ExplorerCrew[i]->getDurability();
      this->ExplorerCrew[i]->setDurability(durability - 1);
      if (durability == 0)
      {
        cout << this->ExplorerCrew[i]->getName() << "'s durability=0" << endl;
        this->operator-=(ExplorerCrew[i]->getName());
      }
    }
  }
  cout << "Miner durability is being updated" << endl;
  for (int i = 0; i < minerCrewSize; i++)
  {
    if (this->MinerCrew[i]->getGatheredSelenium() > 0)
    {
      int durability = this->MinerCrew[i]->getDurability();
      this->MinerCrew[i]->setDurability(durability - 1);
      if (durability != 0)
      {
        cout << this->MinerCrew[i]->getName() << "'s durability=0" << endl;
        this->operator-=(MinerCrew[i]->getName());
      }
    }
  }
};

void Crew::operator+=(Robot *robot)
{
  string robotType = "";
  bool canBeAdded = false;
  for (int i = 0; i < 3; i++)
  {
    robotType.push_back(robot->getName()[i]);
  }
  if (robotType == "exp")
  {
    if (this->maxExplorers > this->explorerCrewSize)
    {
      canBeAdded = true;
      this->ExplorerCrew[explorerCrewSize] = (Explorer *)robot;
      this->explorerCrewSize++;
    }
  }
  else
  {
    if (this->maxMiners > this->minerCrewSize)
    {
      canBeAdded = true;
      this->MinerCrew[minerCrewSize] = (Miner *)robot;
      this->minerCrewSize++;
    }
  }
  if (!canBeAdded)
  {
    cout << "This robot cannot be added, check maximum size of the crew" << endl;
    Crew::crewManufactureCost -= robot->getManufactureCost();
    delete robot;
  }
};

void Crew::operator-=(string name)
{
  string robotType = "";
  for (int i = 0; i < 3; i++)
  {
    robotType.push_back(name[i]);
  }

  int index = 0;
  if (robotType == "exp")
  {
    if (this->explorerCrewSize != 1)
    {
      while (this->ExplorerCrew[index]->getName() != name)
      {
        index++;
      }
      delete this->ExplorerCrew[index];
      for (int i = index + 1; i < this->explorerCrewSize; i++)
      {
        this->ExplorerCrew[i - 1] = this->ExplorerCrew[i];
      }
      this->explorerCrewSize--;
      this->ExplorerCrew[explorerCrewSize] = NULL;
    }
  }
  else
  {
    if (this->minerCrewSize != 1)
    {
      while (this->MinerCrew[index]->getName() != name)
      {
        index++;
      }
      delete this->MinerCrew[index];
      for (int i = index + 1; i < this->minerCrewSize; i++)
      {
        this->MinerCrew[i - 1] = this->MinerCrew[i];
      }
      this->minerCrewSize--;
      this->MinerCrew[minerCrewSize] = NULL;
    }
  }
  cout << name << ": Goodbye" << endl;
};

void Crew::showInfo() const
{
  cout << "explorerCrew Size:" << explorerCrewSize << endl;
  cout << "minerCrew Size:" << minerCrewSize << endl;
  for (int i = 0; i < explorerCrewSize; i++)
  {
    this->ExplorerCrew[i]->showInfo();
  }
  for (int i = 0; i < minerCrewSize; i++)
  {
    this->MinerCrew[i]->showInfo();
  }
  cout << "Total manufacture cost: " << crewManufactureCost << endl;
  cout << "Total maintenance cost: " << crewMaintenanceCost << endl;
}

/*
****************
END: CREW CLASS FUNCTION DECLARATIONS
****************
*/

/*
****************
BEGIN: COMMANDCENTER CLASS FUNCTION DECLARATIONS
****************
*/

CommandCenter::CommandCenter(int neededSelenium, int searchArea, int seleniumWorth) : neededSelenium(neededSelenium), searchArea(searchArea), seleniumWorth(seleniumWorth)
{
  this->turnCount = 1;
  this->profit = 0;
}

bool CommandCenter::isGameEnded() const
{
  if (Explorer::totalExploredArea != this->searchArea)
  {
    return false;
  }
  else
  {
    cout << "Area has been fully explored." << endl;
    cout << "Aim: " << this->neededSelenium << " selenium." << endl;
    cout << "Collected: " << Miner::totalGatheredSelenium << endl;
    if (this->profit >= 0 && Miner::totalGatheredSelenium >= this->neededSelenium)
    {
      cout << "Congrats!" << endl;
      return true;
    }
    else
    {
      cout << "Mission Failed!" << endl;
      return true;
    }
  }
}

void CommandCenter::showInfo() const
{
  cout << "Current turn: " << this->turnCount << endl;
  cout << "Aim: " << this->neededSelenium << " selenium" << endl;
  cout << "Collected: " << Miner::totalGatheredSelenium << endl;
  cout << "Total Search Area: " << this->searchArea << endl;
  cout << "Explored Area:" << Explorer::totalExploredArea << endl;
  cout << "Currently, there are " << Explorer::totalNumberOfSeleniumArea << " area/s that include selenium" << endl;
  if (Explorer::totalNumberOfSeleniumArea > 0)
  {
    cout << "Mine these areas if miners have not finished their turn! If you cannot cope with mining, you can always add new miners!" << endl;
  }
}

void CommandCenter::operator++()
{
  this->turnCount++;
}

void CommandCenter::calculateProfit(const Crew &crew)
{
  // profit: revenues - expenses
  // revenues: seleniumWorth * totalGatheredSelenium
  // expenses: crew.meintenance + crew.manufactureCost
  this->profit = (this->seleniumWorth * Miner::totalGatheredSelenium) - (crew.getCrewMaintenanceCost() + crew.getCrewManifactureCost());
  cout << "Profit: " << this->profit << endl;
  cout << "Expenses: " << crew.getCrewMaintenanceCost() + crew.getCrewManifactureCost() << endl;
  cout << "Selenium revenue: " << this->seleniumWorth * Miner::totalGatheredSelenium << endl;
}

/*
****************
END: COMMANDCENTER CLASS FUNCTION DECLARATIONS
****************
*/