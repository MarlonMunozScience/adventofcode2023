// Puzzle02B.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctype.h>
#include <map> //for map
#include <regex>
#include <set>
#include <algorithm>
#include <string_view>


#include "Parsing.h"

std::vector<std::string> read_input(std::string input) {

	//reading in the file
	std::ifstream fin(input);

	//Error handling
	if (!fin) {
		std::cerr << "Unable to open file: " << input << std::endl;
		return {}; // Return an empty vector or handle the error as needed
	}
	// defining the vector to push the strings into
	std::vector<std::string> input_arrays;

	// input -> temp -> vector
	std::string temp;

	//populating the vector
	while (std::getline(fin, temp)) {
		input_arrays.push_back(temp);
	}

	return input_arrays;
}


int main()
{
	// Grabs input from puzzle
	std::string input_file = "input/puzzle_input.txt";

	// Converts input into vectors
	std::vector<std::string> puzzle_array = read_input(input_file);

	// Housekeeping
	int power = 0; // Holds power calcuklationm
	int power_sum = 0; // Sum of power calc

	// Loop through each line of the vector
	for (auto& line : puzzle_array) {
		// Find maxes and convert to Cube
		Cubes maxes = parse_string_max(line, " ");

		power = maxes.red * maxes.blue * maxes.green;

		power_sum = power_sum + power;
		// find the power of 
	}

	std::cout << power_sum << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
