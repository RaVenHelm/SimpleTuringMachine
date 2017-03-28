#include <algorithm>
#include <vector>
#include <iterator>
#include <iostream>
#include <utility>

#include "simple_turing_machine.hpp"

template <typename T>
void print_vector(std::vector<T> const& v)
{
	std::copy(v.begin(), v.end(), std::ostream_iterator<T>(std::cout, ""));
	std::cout << '\n';
}

void println(char const *str)
{
	std::cout << str << '\n';
}

int main()
{
	using std::vector;

	vector<int> input = {0,0,1,1,1,0,0};
	bool stopped = false;
	auto state = 0b000;
	std::size_t position = 0;
	println("Input:");
	print_vector(input);
	while (!stopped)
	{
		auto in = input[position];
		if (state == 0b000)
		{
			if (in == 0)
			{
				state = 0b000;
				input[position++] = 0;
			}
			else
			{
				state = 0b001;
				input[position++] = 0;
			}
		}
		else if (state == 0b001)
		{
			if (in == 0)
			{
				state = 0b010;
				input[position--] = 1;
			}
			else
			{
				state = 0b001;
				input[position++] = 1;
			}
		}
		else if (state == 0b010)
		{
			if (in == 0)
			{
				state = 0b011;
				input[position++] = 0;
			}
			else
			{
				state = 0b100;
				input[position++] = 0;
			}
		}
		else if (state == 0b011)
		{
			if (in == 0)
			{
				state = 0;
				input[position] = 1;
				stopped = true;
			}
			else
			{
				state = 0b011;
				input[position++] = 1;
			}
		}
		else if (state == 0b100)
		{
			if (in == 0)
			{
				state = 0b101;
				input[position--] = 1;
			}
			else
			{
				state = 0b100;
				input[position++] = 1;
			}
		}
		else if (state == 0b101)
		{
			if (in == 0)
			{
				state = 0b010;
				input[position--] = 1;
			}
			else
			{
				state = 0b101;
				input[position--] = 1;
			}
		}
		else
		{
			return -1;
		}
		print_vector(input);
		if (position + 1 > input.size())
		{
			input.push_back(0);
		}
	}
	return 0;
}