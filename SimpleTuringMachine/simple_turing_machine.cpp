#include "simple_turing_machine.hpp"

simple_turing_machine::simple_turing_machine(int intitial_state)
	: state_(intitial_state)
{
}

int simple_turing_machine::read_input(int input)
{
	if (is_stopped())
		return input;

	if (state_ == 0)
	{
		if (input == 0)
		{
			return 0;
		}
		else if (input == 1)
		{
			state_ = 1;
			return 1;
		}
	}
	else if (state_ == 1)
	{
		if (input == 0)
		{
			state_ = 0;
			stopped_ = true;
			return 1;
		}
		else if (input == 1)
		{
			return 1;
		}
	}
	
	return 0;
}

bool simple_turing_machine::is_stopped()
{
	return stopped_;
}
