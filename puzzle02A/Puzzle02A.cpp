// Puzzle02A.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Plan:
// Use struct to define each showing of bag
// Use parsing to convert input into struct
// Compare struct at end 

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
struct Cubes
{
	int id = 0;
	int red = 0;
	int green = 0;
	int blue = 0;
};

std::vector<std::string> read_input(std::string input) {

	//reading in the file
	std::ifstream fin(input);

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

// Goes through each element of the input array and parses it to create a cube struct for each
// Returns a vector of all of the structs
/*
std::vector<Cubes> cubeArray(std::vector<std::string> puzzleInput) {

	// Vector that will hold all the cubes
	std::vector<Cubes> cubeVector;

	std::string delimiter = " ";

	// Going through each line of the array
	for (auto& line : puzzleInput) {
		
	}
	
}
*/

int main()
{
	hello_world();
	/*
		// Grabs input from puzzle
	std::string input_file = "input/puzzle_inputs.txt";

	// Converts input into vectors
	std::vector<std::string> puzzle_array = read_input(input_file);



	// Reads through each line of the vector, and creates a vector full of structs of type bag*/
}

