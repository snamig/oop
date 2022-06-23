//--- 2021-2022 Summer Object Oriented Programing Assignment 2 ---//
//--------------------------//
//---Name & Surname: NAMIG SAMADOV
//---Student Number: 150190912
//--------------------------//
#include <iostream>
#ifndef _H
#define _H
using namespace std;

class Robot
{
private:
	static int unqID;
	string RobotName;
	const string RobotType;
	float speed;
	int durability;
	const int manufactureCost;
	float maintenanceCost;
	bool canMove;

public:
	Robot(string, float, int, int, float);
	virtual void showInfo() const;
	Robot operator=(const Robot &);

	// void setSpeed(float);
	float getSpeed() const;

	string getName() const;

	// void setManufactureCost(int);
	int getManufactureCost() const;

	// void setRobotType(string);
	string getRobotType() const;

	void setDurability(int);
	int getDurability() const;

	// void setMaintenanceCost(float);
	float getMaintenanceCost() const;

	void setCanMove(bool);
	bool getCanMove() const;

	///////////////////////////
	// void setUnqID() { unqID++; };
};

class Explorer : public Robot
{
	friend class CommandCenter;
	friend class Miner;

private:
	static float totalExploredArea;
	static int totalNumberOfSeleniumArea;
	float exploredArea;
	bool detectedSelenium;

public:
	Explorer(string, float, int);

	// void setExploredArea(float);

	void showInfo() const;

	Robot operator=(const Explorer &);

	bool move() const;

	void explore();

	float getExploredArea() const;
};

class Miner : public Robot
{
	friend class CommandCenter;

private:
	static int totalGatheredSelenium;
	int gatheredSelenium;

public:
	Miner(string, float, int);
	void showInfo() const;
	Miner operator=(const Miner &);
	void mine();
	bool move() const;

	void setGatheredSelenium(int);
	int getGatheredSelenium() const;
};

#endif