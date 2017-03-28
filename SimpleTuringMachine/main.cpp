#include <array>
#include <vector>
#include <utility>

#include "simple_turing_machine.hpp"

int main()
{
	using std::array;
	using std::vector;
	simple_turing_machine machine{0};
	vector<int> input = {0,0,0,0,1,1,1,1,0,0,0,0};
	auto output = vector<int>{};
	for (auto i : input)
	{
		output.push_back(machine.read_input(i));
	}
	return 0;
}