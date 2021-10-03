#include "Competition.h"
#include "Hare.h"
#include "Tortoise.h"
#include "Road.h"
#include <cstdlib> //srand
#include <iostream> //use cout
#include <iomanip> //setw
using namespace std; //simplify std::cout by cout, or endl

Competition::Competition()
{
    srand(1); //submit to autograder,
       //otherwise, the game may have different running results,
       //which cannot be checked by scripts.

    //If test in local computer,
    //srand(time(0)); //need to include <ctime> to use time.

    har = new Hare; //create a har with default constructor
        //of Hare class.
        //Same as har = new Hare();
    //If har is not a pointer to Hare, that is,
    //har is not Hare* type,
    //then it is not easy to call a default constructor
    //in two lines:
    //Hare har; //suppose it were in Competition.h
    //har = Hare();

    tor = new Tortoise;
    rd = new Road;
}

Competition::Competition(Hare* har, Tortoise* tor, int length)
{
    srand(1);
    //this->har = har; //not easy to delete data member
         //har, since by this approach,
         //this->har is not created by new 
         //as in default constructor,
         //so in destructor, when we use delete,
         //if har object is created through new,
         //it is ok, but will cause problems if
         //har is not created by new.

    this->har = new Hare(har->getPattern(),
        har->getPatternLength(), har->getPosition());

    //this->tor = tor;
    this->tor = new Tortoise(tor->getPattern(), tor->getPatternLength(), tor->getPosition());

    rd = new Road(length);
}

Competition::~Competition()
{
    delete har;
    har = 0; //avoid dangling pointer problem
    delete tor;
    tor = 0;
    delete rd;
    rd = 0;
}

void Competition::start()
{
    int lastBlock = rd->getLastBlock();
    //rd->getLastBlock() can be rewritten as
    //(*rd).getLastBlock(), () cannot be omitted
    //since . operator has higher precedence than
    //* dereference operator.
    //since Road* rd; so *rd can be thought as
    //an object of Road.
    int round = 1;

    while (har->getPosition() < lastBlock && tor->getPosition() < lastBlock)
    {
        har->move();

        if (har->getPosition() < 0)
            har->setPosition(0);
        else if (har->getPosition() > lastBlock)
            har->setPosition(lastBlock);

        //TODO: Move tor.
        tor->move();

        if (tor->getPosition() < 0)
            tor->setPosition(0);
        else if (tor->getPosition() > lastBlock)
            tor->setPosition(lastBlock);

        rd->mark(har->getPosition(), 'H');
        rd->mark(tor->getPosition(), 'T');

        cout << setw(3) << round << " ";
        cout << rd->toString() << endl;

        if (har->getPosition() == tor->getPosition())
            cout << "Ouch, Tortoise bites Hare." << endl;

        round++;
        rd->mark(har->getPosition(), ' ');
        rd->mark(tor->getPosition(), ' ');
    }

    //TODO: find out the result
    if (har->getPosition() > tor->getPosition()) {
        cout << "Yuck, hare wins." << endl;
    }
    if (tor->getPosition() > har->getPosition()) {
        cout << "Yay!!! tortoise wins!" << endl;
    }
}