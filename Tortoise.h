#ifndef TORTOISE_H_
#define TORTOISE_H_

class Tortoise
{
private:
	int* pattern;
	int patternLength;
	int position;

public:
	Tortoise();
	Tortoise(int* pattern, int patternLength, int position);
	~Tortoise();
	int* getPattern() const;
	int getPatternLength() const;
	int getPosition() const;
	void move();
	void setPosition(int newPosition); // Manually sets position when we leave the boundary of the given pattern
};
#endif