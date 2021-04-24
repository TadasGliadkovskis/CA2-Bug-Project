#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"
class Board
{
	int height;
	int width;
	vector<Bug *> bugs;
	void setUpBugVector(string bugInfo);

public:
	Board() {}
	void initialiseBugBoard();
	void displayAllBugs();
	void findBugByID();
	void tapBoard();
	void displayHistoryAllBugs();
	void exit();
	void displayAllCells();
	~Board();
};
