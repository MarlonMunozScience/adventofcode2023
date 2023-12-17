#pragma once
#ifndef PARSING
#define PARSING

#include <string>
#include <vector>
#include <array>

struct Cubes
{
	int id = 0;
	int red = 0;
	int green = 0;
	int blue = 0;
};

void hello_world();

Cubes parse_string(std::string s, std::string delimiter);



#endif // FILE_HANDLING_H