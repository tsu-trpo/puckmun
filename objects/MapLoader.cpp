#include "objects/MapLoader.h"

#include <cinttypes>
#include <iostream>

#include "errors/BasicMapLoader-errors.h"
#include "error.h"

const string MapSignature = "basic_puckmun_map";
const uint64_t VersionMajor = 0;
const uint64_t VersionMinor = 1;

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
	}
	return Block::Space;
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
	}
	throw std::logic_error(ERR_HEADER "unexpected wall type");
}

Map basic_load_map(const string& filename)
{
	std::fstream map_file (filename);

	string header;
	map_file >> header;
	if (header != MapSignature)
	{
		throw FiletypeError("Incorrect header of file " + filename);
	}

	uint64_t version_major, version_minor;
	char separator;
	map_file >> version_major >> separator >> version_minor;
	if (separator != '.')
	{
		throw FiletypeError("Incorrect header of file " + filename);
	}
	if (version_major > VersionMajor)
	{
		throw FiletypeError("Incompatible version of file " + filename +
			" - has major version " + std::to_string(version_major) +
			", while loader has version " + std::to_string(VersionMajor));
	}

	uint64_t width, height;
	map_file >> width >> height;
	if (width == 0 || height == 0)
	{
		throw IllFormedMapError("Too thin map in file " + filename);
	}
	Map map (static_cast<Coordinate>(width), static_cast<Coordinate>(height));

	char current;
	// считываем конец строки с размерами
	map_file.get(current);
	for (uint64_t y = 0; y < height; ++y)
	{
		for (uint64_t x = 0; x < width; ++x)
		{
			map_file.get(current);
			if (current == '\n')
			{
				throw IllFormedMapError("Unexpected newline in file " + filename +
					" on coordinates " + std::to_string(x) + ":" +
					std::to_string(y));
			}
			map.change_block(x, y, char_to_block(current));
		}
		map_file.get(current);
		if (current != '\n')
		{
			throw IllFormedMapError("Unexpected non-newline in file " + filename +
					" on coordinates " + std::to_string(width + 1) + ":" +
					std::to_string(y));
		}
	}

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
