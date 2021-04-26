#include "Bug.h"

bool Bug::isWayBlocked()
{
	int predictedYPos;
	int predictedXPos;
	while (true)
	{
		if (this->getDirection() == Directions(North)) // Move North
		{
			predictedYPos = getYPos() - this->getHopLength();
			if (predictedYPos >= 0)
			{
				path.push_back({position});
				position = {getXPos(), predictedYPos};
				path.push_back({position});
				return false;
			}
		}
		else if (this->getDirection() == Directions(East)) // Move East
		{
			predictedXPos = getXPos() + this->getHopLength();
			if (predictedXPos < 10)
			{
				path.push_back({position});
				position = {predictedXPos, getYPos()};
				path.push_back({position});
				return false;
			}
		}
		else if (this->getDirection() == Directions(South)) // Move South
		{
			predictedYPos = getYPos() + this->getHopLength();
			if (predictedYPos < 10)
			{
				path.push_back({position});
				position = {getXPos(), predictedYPos};
				path.push_back({position});
				return false;
			}
		}
		else if (this->getDirection() == Directions(West)) // Move West
		{
			predictedXPos = getXPos() - this->getHopLength();
			if (predictedXPos >= 0)
			{
				path.push_back({position});
				position = {predictedXPos, getYPos()};
				path.push_back({position});
				return false;
			}
		}
		changeDirection();
	}
}

void Bug::changeDirection()
{
	int oldDirection;
	do
	{
		oldDirection = direction;
		random_device dev;
		mt19937 rng(dev());
		uniform_int_distribution<mt19937::result_type> dist6(1, 4); // distribution in range [1, 4]
		direction = dist6(rng);
	} while (oldDirection == direction);
}

void Bug::fight(Bug &b2)
{
	if (this->getSize() > b2.getSize())
	{
		b2.dead();
		this->size += b2.size;
	}
	else if (this->getSize() < b2.getSize())
	{
		this->dead();
		b2.size += this->size;
	}
	else
	{
		random_device dev;
		mt19937 rng(dev());
		uniform_int_distribution<mt19937::result_type> dist6(1, 2);
		if (dist6(rng) == 1)
		{
			this->dead();
			b2.size += this->size;
		}
		else
		{
			b2.dead();
			this->size += b2.size;
		}
	}
}