//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname: NAMIG SAMADOV
//---Student Number: 150190912
//--------------------------//

#include <iostream>
#include "Robot.h"
using namespace std;
class Crew
{
	friend class CommandCenter;

private:
	int maxExplorers;
	int maxMiners;
	int crewManufactureCost;	 // getter needed
	float crewMaintenanceCost; // setter and getter needed
	int explorerCrewSize;			 // getter needed
	int minerCrewSize;				 // getter needed
	Explorer **ExplorerCrew;
	Miner **MinerCrew;

public:
	// Crew(int, int, int, int);

	// void showInfo() const;

	// int getCrewManufactureCost() const;

	// void setCrewMaintenanceCost(float);
	// float getCrewMaintenanceCost() const;

	// int getExplorerCrewSize() const;

	// int getMinerCrewSize() const;

	// Explorer **getExplorers() const { return ExplorerCrew; };
	// Miner **getMiners() const { return MinerCrew; };

	// void operator+=(Robot *);
	// void operator-=(string);

	// Robot *manufactureRobot(string = "null");
	// void initMovement();
	// void updateDurability();

	// ~Crew();

	Crew(int, int, int, int);
	~Crew();
	Robot *manufactureRobot(string = "NULL");
	void initMovement();
	void updateDurability();
	void operator+=(Robot *);
	void operator-=(string);
	void showInfo() const;
	Miner **getMiners() const { return MinerCrew; };
	Explorer **getExplorers() const { return ExplorerCrew; };
	float getCrewMaintenanceCost() const { return crewMaintenanceCost; };
	void setCrewMaintenanceCost(float cost) { crewMaintenanceCost = cost; };
	int getCrewManifactureCost() const { return crewManufactureCost; };
	int getExplorerCrewSize() const { return explorerCrewSize; };
	int getMinerCrewSize() const { return minerCrewSize; };
};

class CommandCenter
{
private:
	const int neededSelenium;
	const float searchArea;
	const int seleniumWorth;
	int turnCount;
	float totalCrewMaintenanceCost;
	float profit;

public:
	CommandCenter(const int, const int, const int);
	bool isGameEnded() const;
	void showInfo() const;
	void operator++();
	void calculateProfit(const Crew &);
};
