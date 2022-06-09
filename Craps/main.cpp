#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"
#include <time.h>
#include <iostream>
using std::cout;



int main() 
{
	unsigned seed;
	seed = time(0);
	srand(seed);
	Die die1;
	Die die2;
	Shooter shooter;
	Roll* roll;
	roll = shooter.throw_die(die1, die2);
	ComeOutPhase come_out_phase;

	cout<<"Test your luck at Craps"<<"\n";	

	while((come_out_phase.get_outcome(roll) == RollOutcome::natural) || (come_out_phase.get_outcome(roll) == RollOutcome::craps))
	{
		cout<<"Rolled: "<<roll->roll_value()<<" - Roll Again"<<"\n";
		roll = shooter.throw_die(die1, die2);
	}

	cout<<"Rolled: "<<roll->roll_value()<<" - Start of Point Phase"<<"\n";
	cout<<"Roll until "<<roll->roll_value()<<" or 7 is rolled"<<"\n";

	int point = roll->roll_value();
	PointPhase point_phase (point);

	while((point_phase.get_outcome(roll) == RollOutcome::point) || (point_phase.get_outcome(roll) == RollOutcome::nopoint))
	{
		cout<<"Rolled: "<<roll->roll_value()<<" Roll Again"<<"\n";
		roll = shooter.throw_die(die1, die2);
	}

	cout<<"Luck's over, rolled: "<<roll->roll_value()<<" End of point phase"<<"\n";

	cout<<"Your roll summary:"<<"\n"<<shooter;


	return 0;
}
