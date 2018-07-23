/*
 * This file holds global constants, data types, and their associated helper
 * functions for the game of battleship.
 */
#ifndef ___GAME_SPECS___
#define ___GAME_SPECS___

#include <string>
using namespace std;

// Put new code here.
enum Tile
{
	WATER,
	AIRCRAFT_CARRIER,
	BATTLESHIP,
	SUBMARINE,
	DESTROYER,
	PATROL_BOAT,
	MISS,
	AIRCRAFT_CARRIER_HIT,
	BATTLESHIP_HIT,
	SUBMARINE_HIT,
	DESTROYER_HIT,
	PATROL_BOAT_HIT
};

const int BOARD_LENGTH = 10;
const int SHIP_SIZE[] = {0, 5, 4, 3, 3, 2};

char tileToSymbol(Tile tile)
{
	switch (tile)
	{
		case 0:
			return '.';
		case 1:
			return 'A';
		case 2:
			return 'B';
		case 3:
			return 'S';
		case 4:
			return 'D';
		case 5:
			return 'P';
		case 6:
			return '~';
		case 7:
			return 'a';
		case 8:
			return 'b';
		case 9:
			return 's';
		case 10:
			return 'd';
		case 11:
			return 'p';
		default:
			printf("Error");
			return ' ';
	}
}

string shipToString(Tile tile)
{
	switch (tile)
	{
		case 1:
		case 7:
			return "Aircraft Carrier";
		case 2:
		case 8:
			return "Battleship";
		case 3:
		case 9:
			return "SUBMARINE";
		case 4:
		case 10:
			return "Destroyer";
		case 5:
		case 11:
			return "Patrol Boat";
		default:
			return "Error";
	}
}

#endif
