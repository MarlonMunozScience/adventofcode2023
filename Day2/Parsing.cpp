#include "Parsing.h"
#include <iostream>
#include <string>
#include <vector>
#include <array>



void hello_world() {
	std::cout << "hello world" << std::endl;
}

Cubes parse_string(std::string s, std::string delimiter) {

	// Vector to hold relevant information
	std::vector<std::string> info;

	size_t pos = 0;
	std::string token;

	// Split by delimiter " ", put inside of 
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		s.erase(0, pos + delimiter.length());
		info.push_back(token);
	}

	// Handle the last part of the string
	if (!s.empty()) {
		info.push_back(s);
	}

	// Check each element of the array
	// If starts w G, that gives us game ID
	// If starts w R, G, B, then previous value is amount of cubes



	// Going through each line of the array
	// auto& line is good for going through vectors, but I want access to the index
	// Luckly vector::size does this for me

	int vector_size = info.size();
	int game_id = 0; // Stores ID of game for adding later
	int red_max = 0; // Stores max number of red cubes seen
	int green_max = 0; // Stores max number of green cubes seen
	int blue_max = 0; // stores max number of blue cubes seen


	for (int i = 0; i < vector_size; i++){
		// Check if first element starts w G for Game ID
		if (info[i].at(0) == 'G') {
			game_id = std::stoi(info[i + 1]);
			
		}

		// Check if first element in line starts w r for red cubes
		if (info[i].at(0) == 'r' && i > 0) { // gets rid of edge case where i = 0
			if (red_max < (std::stoi(info[i - 1]))) {
				red_max = std::stoi(info[i - 1]) ;
				
			}
		}

		// Check if first element in line starts w g for green cubes
		if (info[i].at(0) == 'g' && i > 0) { // gets rid of edge case where i = 0
			
			if (green_max < (std::stoi(info[i - 1]))) {

				green_max = std::stoi(info[i - 1]) ;
				
			}
		}

		// Check if first element in line starts w b for blue cubes
		if (info[i].at(0) == 'b' && i > 0) { // gets rid of edge case where i = 0
			if (blue_max < (std::stoi(info[i - 1]))) {
				blue_max = std::stoi(info[i - 1]);
				
			}
		}
	}
	Cubes max = {game_id, red_max, green_max, blue_max };
	return max;

}

