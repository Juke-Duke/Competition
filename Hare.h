#ifndef HARE_H_
#define HARE_H_

class Hare
{
private:
	int* pattern;
	int patternLength;
	int position;

public:
	Hare();
	Hare(int* pattern, int patternLength, int position);
	~Hare();
	int* getPattern() const;
	int getPatternLength() const;
	int getPosition() const;
	void move();
	void setPosition(int newPosition); // Manually sets position when we leave the boundary of the given pattern
};
#endif