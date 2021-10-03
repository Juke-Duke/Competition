#ifndef COMPETITION_H_
#define COMPETITION_H_
#include "Hare.h"
#include "Tortoise.h"
#include "Road.h"

class Competition
{
private:
    Hare* har;
    Tortoise* tor;
    Road* rd;

public:
    Competition();
    Competition(Hare* rabbit, Tortoise* tor, int length);
    ~Competition();
    void start(); //TODO: shall we put const after
        //this method, that is, are we going to modify
        //data members of current object?
};
#endif