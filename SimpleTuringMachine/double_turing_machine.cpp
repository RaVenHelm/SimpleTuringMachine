#include "double_turing_machine.h"

using direction = double_turing_machine::direction;

int double_turing_machine::delegate_0(int input)
{
	if (input == 0)
	{
		direction_ = direction::RIGHT;
		++position_;
	}
	else if (input == 1)
	{
		direction_ = direction::RIGHT;
		state_ = 1;
		++position_;
		return 0;
	}

	return input;
}

int double_turing_machine::delegate_1(int input)
{
	if (input == 0)
	{
		direction_ = direction::LEFT;
		state_ = 2;
		--position_;
		return 1;
	}
	else if (input == 1) {
		direction_ = direction::RIGHT;
		++position_;
	}

	return input;
}

int double_turing_machine::delegate_2(int input)
{
	if (input == 0)
	{
		direction_ = direction::RIGHT;
		state_ = 3;
		++position_;
	}
	else if (input == 1)
	{
		direction_ = direction::RIGHT;
		state_ = 4;
		++position_;
		return 0;
	}
	return input;
}

int double_turing_machine::delegate_3(int input)
{
	if (input == 0)
	{
		direction_ = direction::STOP;
		state_ = 0;
		return 1;
	}
	else if (input == 1)
	{
		direction_ = direction::RIGHT;
		state_ = 4;
		++position_;
		return 0;
	}
	return input;
}

int double_turing_machine::delegate_4(int input)
{
	if (input == 0)
	{
		direction_ = direction::LEFT;
		state_ = 5;
		--position_;
		return 1;
	}
	else if (input == 1)
	{
		direction_ = direction::RIGHT;
		state_ = 4;
		++position_;
	}
	return input;
}

int double_turing_machine::delegate_5(int input)
{
	if (input == 0)
	{
		direction_ = direction::LEFT;
		state_ = 2;
		--position_;
		return 1;
	}
	else if (input == 1)
	{
		direction_ = direction::LEFT;
		state_ = 5;
		++position_;
	}
	return input;
}

double_turing_machine::double_turing_machine()
	: direction_(RIGHT)
{
}

int double_turing_machine::read_input(int input)
{
	if (is_stopped())
		return input;

	switch (state_)
	{
	case 0:
		return delegate_0(input);
	case 1:
		return delegate_1(input);
	case 2:
		return delegate_2(input);
	case 3:
		return delegate_3(input);
	case 4:
		return delegate_4(input);
	case 5:
		return delegate_5(input);
	default:
		return input;
	}
}

bool double_turing_machine::is_stopped()
{
	return direction_ == STOP;
}