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

	//std::string TEST_STRING = "Game 1: 4 red, 3 blue; 6 blue, 5 green; 10 blue, 10 green, 1 red; 10 green, 4 red, 6 blue";

	// Maximums of reds, greens, and blues for each game
	int red_max = 12;
	int green_max = 13;
	int blue_max = 14;

	int game_id_sum = 0; // Keeping track of game ids that pass
	
	//std::string line = "Game 71: 6 red; 3 green, 9 blue, 18 red; 19 blue, 14 red; 11 blue, 18 red, 5 green"; 
	//td::string line = "Game 29: 1 blue, 3 green; 5 green; 3 green";
	// Loop through each string in the vector, find the max and compare them. If they are reasonable, add game id to max
	for (auto& line : puzzle_array) {
		
		// Find maxes and convert to Cube
		Cubes maxes = parse_string_max(line, " ");

		// Compare that all maxes are less than given maximums
		if (maxes.red > red_max || maxes.green > green_max || maxes.blue > blue_max){
		}
		else
		{
			game_id_sum = game_id_sum + maxes.id;
		}
	}
	std::cout << "Max Game IDs are " << game_id_sum << std::endl;

	// Reads through each line of the vector, and creates a vector full of structs of type bag
}

