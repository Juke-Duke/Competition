#include "Tortoise.h"
#include <cstdlib> //rand
using namespace std; //simplify std::cout by cout, or endl

Tortoise::Tortoise()
{
	patternLength = 10;
	position = 0;
	pattern = new int[patternLength];
	int defaultPattern[] = { 3, 3, 3, 3, 3, -6, -6, 1, 1, 1 };

	for (int i = 0; i < patternLength; i++)
		pattern[i] = defaultPattern[i];
}

Tortoise::Tortoise(int* pattern, int patternLength, int position)
{
	if (patternLength > 0)
	{
		this->patternLength = patternLength;
		this->pattern = new int[this->patternLength];
		for (int i = 0; i < patternLength; i++)
			this->pattern[i] = pattern[i];
	}
	else
	{
		this->patternLength = 10;
		this->pattern = new int[this->patternLength];
		int defaultPattern[] = { 3, 3, 3, 3, 3, -6, -6, 1, 1, 1 };

		for (int i = 0; i < this->patternLength; i++)
			this->pattern[i] = defaultPattern[i];
	}

	this->position = position;
}

Tortoise::~Tortoise()
{
	delete[] pattern;
	pattern = nullptr;
}

int* Tortoise::getPattern() const
{
	return pattern;
}

int Tortoise::getPatternLength() const
{
	return patternLength;
}

int Tortoise::getPosition() const
{
	return position;
}

void Tortoise::move()
{
	int index = rand() % patternLength;
	int steps = pattern[index];
	position += steps;
}

void Tortoise::setPosition(int newPosition)
{
	position = newPosition;
}