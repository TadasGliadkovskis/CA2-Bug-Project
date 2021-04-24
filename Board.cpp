#include "Board.h"
#include <iostream>
#include <fstream>
#include <sstream>

void Board::initialiseBugBoard()
{
      cout << "Reading bugs.txt file " << endl;
      string line;
      ifstream stream("bugs.txt");

      if (stream.good())
      {
            while (getline(stream, line))
            {
                  setUpBugVector(line);
            }
            stream.close();
      }
      else
      {
            cout << "Unable to open file, or file is empty" << endl;
      }
}

void Board::setUpBugVector(string bugInfo)
{
      stringstream stream(bugInfo);
      string bugType;
      int bugID, xPos, yPos, direction, size;
      Bug *bugPtr = nullptr;
      try
      {
            string str;
            getline(stream, bugType, ';');

            getline(stream, str, ';');
            bugID = stoi(str);

            getline(stream, str, ';');
            xPos = stoi(str);

            getline(stream, str, ';');
            yPos = stoi(str);

            getline(stream, str, ';');
            direction = stoi(str);

            getline(stream, str, ';');
            size = stoi(str);

            if (bugType == "C")
            {
                  bugPtr = new Crawler(bugID, {xPos, yPos}, direction, size);
            }
            else
            {
                  getline(stream, str, ';');
                  int hopLength = stoi(str);
                  bugPtr = new Hopper(bugID, {xPos, yPos}, direction, size, hopLength);
            }
            bugs.push_back(bugPtr);
      }
      catch (const std::exception &e)
      {
            cout << "ERROR " << endl;
      }
}

void Board::displayAllBugs()
{
      for (Bug *b : bugs)
      {
            cout << *b;
      }
}

void Board::findBugByID()
{
      int bugID;
      bool bugFound = false;
      cout << endl
           << "Enter in a bug id number: ";
      while (true)
      {
            cin >> bugID;
            if (!cin)
            {
                  cout << "Please enter in a number: ";
                  cin.clear();
                  cin.ignore(numeric_limits<streamsize>::max(), '\n');
                  continue;
            }
            break;
      }
      for (Bug *b : bugs)
      {
            if (b->getID() == bugID)
            {
                  cout << *b << endl;
                  bugFound = true;
                  break;
            }
      }
      if (!bugFound)
            cout << "Bug " << bugID << " not found" << endl;
}

void Board::tapBoard()
{
      for (Bug *b : bugs)
      {
            b->move();
      }
}

void Board::displayHistoryAllBugs()
{
      for (Bug *b : bugs)
      {
            cout << b->getID() << " " << b->getType() << " Path: ";
            for (pair<int, int> &loc : b->getPath())
            {
                  cout << "(" << loc.first << "," << loc.second << "),";
            }
            string health = b->isAlive() ? "Alive!" : "Dead";
            cout << " " << health << endl;
      }
}

void Board::exit()
{
      ofstream outputFile("bugs_life_history.out");
      if (outputFile.is_open())
      {
            string bugInfo;
            for (Bug *b : bugs)
            {

                  bugInfo = to_string(b->getID()) + " " + b->getType() + " Path: ";
                  for (pair<int, int> &loc : b->getPath())
                  {
                        bugInfo += "(" + to_string(loc.first) + ',' + to_string(loc.second) + "),";
                  }
                  string health = b->isAlive() ? "Alive!" : "Dead";
                  outputFile << bugInfo << " " << health << endl;
            }
            outputFile.close();
      }
      else
      {
            cout << "Unable to open file" << endl;
      }
}

void Board::displayAllCells()
{
      bool empty = true;
      for (int x = 0; x < 10; x++)
      {
            for (int y = 0; y < 10; y++)
            {
                  cout << "(" << x << "," << y << "): ";
                  for (Bug *b : bugs)
                  {
                        if (b->getXPos() == x && b->getYPos() == y)
                        {
                              cout << b->getType() << " " << b->getID() << ", ";
                              empty = false;
                        }
                  }
                  if (empty)
                  {
                        cout << "Empty";
                  }
                  empty = true;
                  cout << endl;
            }
      }
}

Board::~Board()
{
      cout << "Desturction";
}