#include "shooter.h"

Roll* Shooter::throw_die(Die& one, Die& two)
{
    Roll* roll = new Roll(one, two);
    roll->roll_die();
    rolls.push_back(roll);
    return roll;
}

std::ostream& operator<<(std::ostream& out, const Shooter& s)
{
    for(auto& element:s.rolls)
    {
        out<<element->roll_value()<<"\n";
    }
    return out;
}

Shooter::~Shooter()
{
    for(int i=0; i<rolls.size(); i++)
    {
        delete(rolls)[i];
    }
}