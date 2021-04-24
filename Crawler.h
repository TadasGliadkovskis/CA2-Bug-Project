#pragma once
#include "Bug.h";
#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;
class Crawler : public Bug
{
public:
    Crawler(int id, pair<int, int> pos, int direction, int size)
        : Bug("Crawler", id, pos, direction, size)
    {
    }

    int getHopLength() const { return 1; }
    void print(ostream &out)
    {
        string health = isAlive() ? "Alive" : "Dead";
        Bug::print(out);
        out << health << endl;
    }
    friend ostream &operator<<(ostream &out, Crawler &b)
    {
        b.print(out);
        return out;
    }

    Crawler()
    {
    }
    void move();
    ~Crawler()
    {
        cout << "Destructure crawler \n";
    }
};