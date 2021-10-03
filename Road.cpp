#include "Road.h"

Road::Road() 
{
    length = 70;
    blocks = new char[length];
    clear();
}

Road::Road(int length) 
{
    if (length <= 0)
        this->length = 70;
    else
        this->length = length;

    blocks = new char[this->length];
    clear();
}

Road::~Road() 
{
    delete[] blocks;
    blocks = nullptr;
}

void Road::clear() 
{
    for (int i = 0; i < length; i++)
        blocks[i] = ' ';
}

void Road::mark(int pos, char ch)
{
    blocks[pos] = ch;
}

int Road::getLastBlock() const
{
    return length - 1;
}

char* Road::toString() const
{
    return blocks;
}