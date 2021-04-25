#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <random>
using namespace std;

class Bug
{
    string type = "default name";
    int id = 0;
    pair<int, int> position = {0, 0};
    int direction = 0;
    int size = 0;
    bool alive = true;
    vector<pair<int, int>> path;
    string getDirectionName()
    {
        switch (direction)
        {
        case North:
            return "North";
        case East:
            return "East";
        case South:
            return "South";
        case West:
            return "West";
        }
    }
    void dead() { this->alive = false; }

public:
    Bug(string type, int id, pair<int, int> pos, int direction, int size)
        : type(type), id(id), position(pos), direction(direction), size(size)
    {
    }
    enum Directions
    {
        North = 1,
        East,
        South,
        West
    };

    Bug() {}

    string getType() const { return type; }
    int getID() const { return id; }
    pair<int, int> getPosition() const { return position; }
    int getXPos() const { return position.first; }
    int getYPos() const { return position.second; }
    int getDirection() const { return direction; }
    int getSize() const { return size; }
    bool isAlive() const { return alive; }
    vector<pair<int, int>> getPath() const { return path; }
    virtual int getHopLength() const = 0;

    virtual void print(ostream &out)
    {

        string dir;
        dir = getDirectionName();
        out << endl
            << id << " " << type << " "
            << "(" << position.first << "," << position.second << ") " << size << " " << dir << " ";
    }
    friend ostream &operator<<(ostream &out, Bug &b)
    {
        b.print(out);
        return out;
    }
    bool isWayBlocked();
    void changeDirection();
    void fight(Bug &b2);
    virtual void move() = 0;
    virtual ~Bug()
    {
        cout << "destructure bug \n";
    }
};
