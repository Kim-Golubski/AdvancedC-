#ifndef ROLL_H
#define ROLL_H
#include "die.h"

class Roll : public Die
{
public:
    Roll(Die& one, Die& two) : die1(one), die2(two){}
    void roll_die();
    int roll_value()const{return value;};


private:
    Die& die1;
    Die& die2;
    bool rolled = false;
    int value;

};



#endif