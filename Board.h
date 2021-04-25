#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"
class Board
{
	vector<Bug *> bugs;
	void setUpBugVector(string bugInfo);
	void fight();

public:
	Board() {}
	void initialiseBugBoard();
	void displayAllBugs();
	void findBugByID();
	void tapBoard();
	void tapBoardX();
	void displayHistoryAllBugs();
	void exit();
	void displayAllCells();
	~Board();
};
