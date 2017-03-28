#ifndef _SIMPLE_TURING_MACHINE_HPP_
#define _SIMPLE_TURING_MACHINE_HPP_

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#include "turing_machine.hpp"

class simple_turing_machine
	: turing_machine
{
	int state_ = 0;
	bool stopped_ = false;
public:
	simple_turing_machine(int intitial_state);
	virtual ~simple_turing_machine(){}

	virtual int read_input(int input) override;
	virtual bool is_stopped() override;
};

#endif // !_SIMPLE_TURING_MACHINE_HPP_