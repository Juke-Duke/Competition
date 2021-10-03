#ifndef ROAD_H_
#define ROAD_H_

class Road 
{
private:
    char* blocks;
    int length;

public:
    Road();
    Road(int length);
    ~Road();
    void clear();
    void mark(int pos, char ch);
    int getLastBlock() const;
    char* toString() const;
};
#endif