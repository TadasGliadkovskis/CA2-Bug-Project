#pragma once
#include "Bug.h";
#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;
class Hopper : public Bug
{
    int hopLength = 0;

public:
    Hopper(int id, pair<int, int> pos, int direction, int size, int hopLength)
        : Bug("Hopper", id, pos, direction, size)
    {
        this->hopLength = hopLength;
    }
    int getHopLength() const { return hopLength; }
    void print(ostream &out)
    {
        string health = isAlive() ? "Alive" : "Dead";
        Bug::print(out);
        out << hopLength << " " << health << endl;
    }
    friend ostream &operator<<(ostream &out, Hopper &b)
    {
        b.print(out);
        return out;
    }

    Hopper() {}
    void move();
    ~Hopper()
    {
        cout << "Destructure Hopper \n";
    }
};