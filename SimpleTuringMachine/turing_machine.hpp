#ifndef _TURING_MACHINE_HPP_
#define _TURING_MACHINE_HPP_

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

struct turing_machine
{
	virtual int read_input(int input) = 0;
	virtual bool is_stopped() = 0;
};

#endif // _TURING_MACHINE_HPP_
