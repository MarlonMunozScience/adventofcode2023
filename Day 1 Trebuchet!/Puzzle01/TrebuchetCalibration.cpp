// TrebuchetCalibration.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Day 1 of advent calender https://adventofcode.com/2023/day/1
// This includes part 1 and 2 of the problems.

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

// Decodes the puzzle to get the calibration values
int decode(std::string line) {
	
	int num_1 = -1; //temp 
	int num_2 = -1;
	// going through each element in string
	for (char& c : line) {
		// we only want to check on digits

		//std::cout << line << std::endl;
		if (isdigit(c)) {
			
			// If num_1 is -1, first digit will be set 
			if (num_1 == -1) {
				num_1 = c - '0'; // Correctly converts char into int
				
			}
			else {
				num_2 = c - '0';			
			}
		}
	}
	// for the case where there is only 1 number per line, ]
	if (num_2 == -1) {
		num_2 = num_1;
	}


	int return_num = num_1 * 10 + num_2;

	//for debug
	//std::cout << line << '\n' << return_num << std::endl;

	return return_num;
}

// Reads in each value of the vector, finds the first and last number, and adds it to a sum,
int sum_calibration(std::vector<std::string> input_values) {
	int sum = 0;
	

	// indexing through each element in the vector
	for (auto& line : input_values) {
		int num = decode(line);
		sum = sum + num;
	}

	return sum;

}

// C++ doesn't have dictionaries :c
std::map<std::string, int> createNumberMap() {
	return {
		{"zero", 0},
		{"one", 1},
		{"two", 2},
		{"three", 3},
		{"four", 4},
		{"five", 5},
		{"six", 6},
		{"seven", 7},
		{"eight", 8},
		{"nine", 9}
	};

}

int decode_2(std::string line) {
	int num_1 = -1; //temp 
	int num_2 = -1;
	int index_1 = 0;
	int index_2 = 0;
	int counter = 0;

	auto nummap = createNumberMap();

	// We can use a similar loop to find the number, but now we need their index.
	// going through each element in string
	for (char& c : line) {
		// we only want to check on digits

		//std::cout << line << std::endl;
		if (isdigit(c)) {

			// If num_1 is -1, first digit will be set 
			if (num_1 == -1) {
				num_1 = c - '0'; // Correctly converts char into int
				index_1 = counter;
			}
			else {
				num_2 = c - '0';
				index_2 = counter;
			}
		}
		counter++;
	}
	// for the case where there is only 1 number per line, ]
	if (num_2 == -1) {
		num_2 = num_1;
		index_2 = index_1;
	}

	// Now we can find the first and last numbers in the strings
	// List of spelled out numbers
	std::set<std::string> spelledNumbers = { "zero", "one", "two", "three", "four",
											"five", "six", "seven", "eight", "nine" };


	// check for spelled numbers
	// Looks for the provided strings and updates the first and last digits.
	auto searchAndUpdate = [&](std::string_view sv, int value) {

		// Search from the front of the line
		size_t iPosFirst = line.find(sv);
		if (iPosFirst != std::string::npos && iPosFirst < index_1) {
			num_1 = value;
			index_1 = iPosFirst;
		}

		// Search from the back of the current line
		size_t iPosLast = line.rfind(sv);
		if (iPosLast != std::string::npos && iPosLast > index_2) {
			num_2 = value;
			index_2 = iPosLast;
		}
	};

	// Search for each textual digit
	searchAndUpdate("one", 1);
	searchAndUpdate("two", 2);
	searchAndUpdate("three", 3);
	searchAndUpdate("four", 4);
	searchAndUpdate("five", 5);
	searchAndUpdate("six", 6);
	searchAndUpdate("seven", 7);
	searchAndUpdate("eight", 8);
	searchAndUpdate("nine", 9);

	int num_return =  num_1 * 10 + num_2;
	return num_return;
}

// Finds the calibration value for part 2 of the puzzle
// This is repetivie, but its fine its christmas :D
int sum_calibration_2(std::vector<std::string> input_array) {
	int sum = 0;

	

	// indexing through each element in the vector
	for (auto& line : input_array) {
		int num = decode_2(line);
		sum = sum + num;
	}

	return sum;
}
int main()
{
	std::string input_file = "input/puzzle_inputs.txt";

	std::vector<std::string> puzzle_array = read_input(input_file);
	
	std::cout << "Calibration value is: " << sum_calibration(puzzle_array) << std::endl;
	
	std::cout << "New calibration value is: " << sum_calibration_2(puzzle_array) << std::endl;

	return 0;
}

