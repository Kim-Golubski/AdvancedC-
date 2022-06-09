#include "die.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

void Die::roll()
{
    roll_value = rand() % 6 + 1;
}




