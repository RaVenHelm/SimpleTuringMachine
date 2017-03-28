#ifndef _DOUBLE_TURING_MACHINE_
#define _DOUBLE_TURING_MACHINE_

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include "turing_machine.hpp"

class double_turing_machine :
	public turing_machine
{
public:
	enum direction
	{
		STOP,
		LEFT,
		RIGHT
	};
private:
	int state_ = 0;
	
	direction direction_;

	int delegate_0(int input);
	int delegate_1(int input);
	int delegate_2(int input);
	int delegate_3(int input);
	int delegate_4(int input);
	int delegate_5(int input);
public:
	double_turing_machine();
	virtual ~double_turing_machine() {}

	virtual int read_input(int input) override;
	virtual bool is_stopped() override;

	int set_state(int new_state) { return state_ = new_state; }
	direction set_direction(direction new_dir) { return direction_ = new_dir; }
};

#endif // !_DOUBLE_TURING_MACHINE_