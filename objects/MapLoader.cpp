#include "objects/MapLoader.h"

#include <cinttypes>
#include <iostream>

#include "errors/BasicMapLoader-errors.h"

const string MapSignature = "basic_puckmun_map";

Block char_to_block(char c)
{
	switch (c)
	{
		case '#':
			return Block::Wall;
		case '.':
			return Block::Point;
		case '*':
			return Block::BigPoint;
		case ' ':
			return Block::Space;
		default:
			return Block::Space;
	}
}

char block_to_char(Block b)
{
	switch (b)
	{
		case Block::Wall:
			return '#';
		case Block::Point:
			return '.';
		case Block::BigPoint:
			return '*';
		case Block::Space:
			return ' ';
		default:
			throw std::runtime_error("fuck you");
	}
}

Map basic_load_map(const string& filename)
{
	std::fstream map_file (filename);

	string header;
	map_file >> header;
	if (header != MapSignature)
	{
		std::cout << "first header: " << header << std::endl;
		throw FiletypeError("Incorrect header of file " + filename);
	}

	uint64_t version_major, version_minor;
	char separator;
	map_file >> version_major >> separator >> version_minor;
	if (separator != '.')
	{
		std::cout << "secont header: " << separator  << std::endl;
		throw FiletypeError("Incorrect header of file " + filename);
	}

	uint64_t width, height;
	map_file >> width >> height;
	if (width == 0 || height == 0)
	{
		throw IllFormedMapError("Too thin map in file " + filename);
	}
	Map map (static_cast<Coordinate>(height), static_cast<Coordinate>(width));

	char current;
	for (uint64_t y = 0; y < height; ++y)
	{
		for (uint64_t x = 0; x < width; ++x)
		{
			map_file >> current;
			if (current == '\n')
			{
				throw IllFormedMapError("Unexpected newline in file " + filename);
			}
			map.change_block(y, x, char_to_block(current));
			std::cout << current;
		}
		std::cout << std::endl;
//		map_file >> current;
//		if (current != '\n')
//		{
//			throw IllFormedMapError("Unexpected non-newline in file " + filename);
//		}
	}
	std:: cout << "map loaded\n\n\n\n";

	return map;
}


void print_map(const Map& map)
{
	for (Coordinate y = 0; y < map.get_height(); ++y)
	{
		for (Coordinate x = 0; x < map.get_width(); ++x)
		{
			std::cout << block_to_char(map.at(x, y));
		}
		std::cout << std::endl;
	}
}
