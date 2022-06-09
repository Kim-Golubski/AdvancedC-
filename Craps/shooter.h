#ifndef SHOOTER_H
#define SHOOTER_H
#include "roll.h"
#include "die.h"
#include<vector>
#include<iostream>
using std::cout; using std::cin;


class Shooter
{
friend std::ostream& operator<<(std::ostream& out, const Shooter& s);

public:
    Roll* throw_die(Die& one, Die& two);
    ~Shooter();
    
private:
    std::vector<Roll*>rolls;
};

#endif