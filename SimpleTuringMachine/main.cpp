#include <array>
#include <vector>
#include <utility>

#include "simple_turing_machine.hpp"
#include "double_turing_machine.h"

int main()
{
	using std::array;
	using std::vector;
	double_turing_machine machine{};
	vector<int> input = {1,1,0,1,0,0};
	while (!machine.is_stopped())
	{
		auto pos = machine.position();
		auto out = machine.read_input(input[pos]);
		if ((pos + 1) >= input.size())
			break;
		input[pos] = out;
	}
	return 0;
}