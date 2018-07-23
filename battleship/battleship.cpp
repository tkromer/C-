/**
 * Player plays battleship against an AI controlled opponent.
 *
 * Required files: enemyAI.h, gameSpecs.h
 *
 * By Tim Kromer
 */
// Include standard headers
#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <string>

using namespace std;

// Include custom headers
#include "gameSpecs.h"
#include "enemyAI.h"

/**
 * Displays random battleship coordinates in quick succession to make the
 * illusion that the computer/enemy is thinking about which coordinate to shoot
 * at.
 *
 * After the function returns the last random coordinate is still on the screen,
 * but the cursor is back up so that it can be overwritten with something new.
 */
void randomCoordinatesAnimation();

/**
 * Clears the board and sets each tile to given tile, defualt is water
 * @param board The board to be clear
 * @param tile Tile to be written into board, default is water
 */
void wipeBoard(Tile board[][BOARD_LENGTH], Tile tile = WATER);

/**
 * Prints the player and AI boards to the screen
 * @param enemyBoard  Enemy's board to be displayed
 * @param playerBoard Player's board to be displayed
 * @param showAll defaults to false, allows player to see enemy board when true
 */
void displayBoards(const Tile enemyBoard[][BOARD_LENGTH],
	const Tile playerBoard[][BOARD_LENGTH], bool showAll = false);

/**
 * Places ship of a given size horizontally on the board at given location
 * @param  tile     Indicates the type of ship being placed
 * @param  shipSize length of the ship
 * @param  yCoord   the row the ship starts on
 * @param  xCoord   the column the ship starts on
 * @param  board    The board that the ship is placed on
 * @return          True if ship was succesfully placed, false for Invalid
 * starting coordinates
 */
bool placeShipHorizontally(Tile tile, int shipSize, int yCoord, int xCoord,
	Tile board[][BOARD_LENGTH]);

/**
 * Places ship of a given size vertically on the board at given location
 * @param  tile     Indicates the type of ship being placed
 * @param  shipSize length of the ship
 * @param  yCoord   the row the ship starts on
 * @param  xCoord   the column the ship starts on
 * @param  board    The board that the ship is placed on
 * @return          True if ship was succesfully placed, false for Invalid
 * starting coordinates
 */
bool placeShipVertically(Tile tile, int shipSize, int yCoord, int xCoord,
	Tile board[][BOARD_LENGTH]);

/**
 * Places ships in random locations on the board
 * @param board Game board ships are to be placed on
 */
void placeShipRandomly(Tile board[][BOARD_LENGTH]);

/**
 * Places the player's ships on the board and allows them to approve layout
 * @param playerBoard Board ships are placed on
 */
void placePlayersShip(Tile playerBoard [][BOARD_LENGTH]);

/**
 * Allows player to make shots. Outputs error message for invalid shot
 * @param  enemyBoard Game board the player is shooting at
 * @param  enemyHits tracks the number of hits left for the ships
 * @return           Returns message based on the result of the shot
 */
string playersTurn(Tile enemyBoard[][BOARD_LENGTH], int enemyHits[]);

/**
 * Determines if player has lost
 * @param  ships array holding the fleet's remaining hits
 * @return       true if player is out of hits, false if not
 */
bool isAllZeroes(int ships[]);

int main ()
{
	Tile playerBoard[BOARD_LENGTH][BOARD_LENGTH]; // Player's game board
	Tile enemyBoard[BOARD_LENGTH][BOARD_LENGTH]; // Enemy game board
	int playerHits[6]; // Tracks the number of hits the player has
	int enemyHits[6]; // Tracks the number of hits the enemy has
	string enemyMessage, playerMessage; // Messages played with shot results
	bool firstTurn = true; // Don't run segments on first loop;
	// Seeds the randomizer for ship placement
	unsigned int seed = static_cast<unsigned int>(time(NULL));
	srand(seed);

	//randomCoordinatesAnimation();

	// Tracks number of hits left on each ship
	for (int index = 0; index < 6; ++index)
	{
		playerHits[index] = SHIP_SIZE[index];
		enemyHits[index] = SHIP_SIZE[index];
	}

	// Sets all tiles to water
	wipeBoard(enemyBoard);

	placePlayersShip(playerBoard); // Allows player to choose ship locations
	placeShipRandomly(enemyBoard); // randomly places enemy ships
	cout << string(21, '\n'); // clears the screen

	do
	{
		displayBoards(enemyBoard, playerBoard);

		// Wont disply shot messages before first turn
		if (!firstTurn)
		{
			// Displays the results of the player's shot
			cout << "Your shot: " << playerMessage;

			// // Displays the results of the enemy's shot
			cout << "Enemy shot: ";
			randomCoordinatesAnimation();
			cout << enemyMessage << endl;
		}
		else
		{
			firstTurn = false;
		}

		// Lets the player take a shot
		playerMessage = playersTurn(enemyBoard, enemyHits);

		// check if the last shot took out the last enemy ship
		if (isAllZeroes(enemyHits))
		{
			cout << string(21, '\n');
			break; // Ends the loop if enemy loses
		}

		// Enemy takes a random shot
		enemyMessage = EnemyAI::enemyTurn(playerBoard, playerHits);

		cout << string(21, '\n');

	}
	while (!isAllZeroes(playerHits)); // Loops until player is out of ships

	cout << string(20, '\n');

	if (isAllZeroes(playerHits))
	{
		cout << "You Lose" << endl << endl;
	}
	else
	{
		cout << "You Win!!!" << endl << endl;
	}
	// Prints final board with enemy ship locations
	displayBoards(enemyBoard, playerBoard, true);

	return 0;
}

void randomCoordinatesAnimation()
{
	// Variables to hold random coordinates to print
	int colNumber;
	char rowLetter;

	cout << left; // left align columns

	// Repeatedly output a random coordinate, then wait, then backup to overwrite
	// The pauses increase in time exponentially until it is >= 160 msecs
	for (int msecs = 10; msecs < 160; msecs = static_cast<int>(msecs * 1.1))
	{
		// Get random numbers
		rowLetter = rand() % BOARD_LENGTH + 'A';
		colNumber = rand() % (BOARD_LENGTH) + 1;

		// Output numbers
		cout << rowLetter << setw(2) << colNumber << flush;

		// Wait the alloted time
		this_thread::sleep_for(chrono::milliseconds(msecs));

		// Backup for next output.
		cout << "\b\b\b";
	}

	cout << right; // reset alignment back to the default
}

void wipeBoard(Tile board[][BOARD_LENGTH], Tile tile)
{
	// Sets board to given tile
	for (int rowIndex = 0; rowIndex < BOARD_LENGTH; ++rowIndex)
	{
		for (int colIndex = 0; colIndex < BOARD_LENGTH; ++colIndex)
		{
			board[rowIndex][colIndex] = tile;
		}
	}
}

void displayBoards(const Tile enemyBoard[][BOARD_LENGTH],
	const Tile playerBoard[][BOARD_LENGTH], bool showAll)
{
	char rowLetter = 'A'; // Labels for the rows
	int colNumber; // Column numbers prited at top of boards
	int colIndex; // index for counting columns
	int rowIndex; // index for counting rows

	cout << " Enemy's Board    "
		<< "        Your Board" << endl << "  ";

	// Prints enemy column numbers
	for (colNumber = 1; colNumber <= BOARD_LENGTH; ++colNumber)
	{
		cout << setw(2) << colNumber;
	}

	cout << "    ";

	// Prints plyer's column numbers
	for (colNumber = 1; colNumber <= BOARD_LENGTH; ++colNumber)
	{
		cout << setw(2) << colNumber;
	}

	cout << endl;

	for (rowIndex = 0; rowIndex < BOARD_LENGTH; ++ rowIndex)
	{
		cout << setw(2) << rowLetter;
		// Prints enemy board
		for (colIndex = 0; colIndex < BOARD_LENGTH; ++colIndex)
		{
			// Changes the output if the player is allowed to see the
			// opponents board
			if (showAll)
			{
				cout << setw(2)
					<< tileToSymbol(enemyBoard[rowIndex][colIndex]);
			}

			// Prints hidden board when showAll is false
			else
			{
				if (enemyBoard[rowIndex][colIndex] == MISS)
				{
					cout << setw(2) << "o";
				}
				else if
					(enemyBoard[rowIndex][colIndex] >= 7 &&
					enemyBoard[rowIndex][colIndex] <= 11)
				{
					cout << setw(2) << "x";
				}
				else
				{
					cout << setw(2) << ".";
				}
			}
		}
		cout << "  " << setw(2) << rowLetter;

		// Prints player's board
		for (colIndex = 0; colIndex < BOARD_LENGTH; ++colIndex)
		{
			cout << setw(2) << tileToSymbol(playerBoard[rowIndex][colIndex]);
		}

		cout << endl;
		++rowLetter;
	}
}

bool placeShipHorizontally(Tile tile, int shipSize, int yCoord, int xCoord,
	Tile board[][BOARD_LENGTH])
{
	int index;

	// Checks that ship will fit on the board
	if (xCoord < 0 || xCoord > BOARD_LENGTH ||
		xCoord + shipSize > BOARD_LENGTH ||
		yCoord < 0 || yCoord > BOARD_LENGTH)
	{
		return false;
	}

	// Check for other ships in location
	for (index = 0; index < shipSize; ++index)
	{
		if (board[yCoord][xCoord + index] != WATER)
		{
			return false;
		}
	}

	// Places the ship in the array
	for (index = 0; index < shipSize; ++index)
	{
		board[yCoord][xCoord + index] = tile;
	}

	return true;
}

bool placeShipVertically(Tile tile, int shipSize, int yCoord, int xCoord,
	Tile board[][BOARD_LENGTH])
{
	int index;

	// Checks that ship will fit on the board
	if (xCoord < 0 || xCoord > BOARD_LENGTH ||
		yCoord + shipSize > BOARD_LENGTH ||
		yCoord < 0 || yCoord > BOARD_LENGTH)
	{
		return false;
	}

	// Check for other ships in location
	for (index = 0; index < shipSize; ++index)
	{
		if (board[yCoord + index][xCoord] != WATER)
		{
			return false;
		}
	}

	// Places the ship in the array
	for (index = 0; index < shipSize; ++index)
	{
		board[yCoord + index][xCoord] = tile;
	}

	return true;
}

void placeShipRandomly(Tile board[][BOARD_LENGTH])
{
	bool result;

	for (Tile ship = AIRCRAFT_CARRIER; ship <= PATROL_BOAT;
	ship = static_cast<Tile>(ship + 1))
	{
		if (rand() % 2) // randomizes vertical or horizontal placement
		{
			do
			{
				result = placeShipVertically(ship, SHIP_SIZE[ship],
					rand() % BOARD_LENGTH, rand() % BOARD_LENGTH, board);
			}
			while(!result); // ends when placeShipVertically returns success
		}
		else
		{
			do
			{
				result = placeShipHorizontally(ship, SHIP_SIZE[ship],
					rand() % BOARD_LENGTH, rand() % BOARD_LENGTH, board);
			}
			while(!result);
			// ends when placeShipHorizontallyertically returns success
		}
	}
}

void placePlayersShip(Tile playerBoard [][BOARD_LENGTH])
{
	char response = 'n';

	do
	{
		cout << string(21, '\n');
		wipeBoard(playerBoard);

		placeShipRandomly(playerBoard);

		displayBoards(playerBoard, playerBoard);

		cout << endl << "Do you want to play this board? (y/n): ";
		cin >> response;
		// Ignores invalid responses
		if (response != 'n' && response != 'N' && response != 'y'
			&& response != 'Y')
		{
			cin.ignore(INT_MAX, '\n') >> response;
		}
	}
	while (response != 'y' && response != 'Y');
	// Randomly places ships until user accepts
}

string playersTurn(Tile enemyBoard[][BOARD_LENGTH], int enemyHits[])
{
	string message;
	char row;
	int rowInt, column;

	do
	{
		cout << endl << "Enter coordinates: ";
		cin >> row >> column;
		cin.clear();

		column -= 1;

		// Make sure coordinates are valid
		if (row >= 'a' && row <= ('a' + BOARD_LENGTH - 1))
		{
			rowInt = row - 'a';
		}
		else if (row >= 'A' && row <= ('A' + BOARD_LENGTH - 1))
		{
			rowInt = row - 'A';
		}

		if (rowInt < 0 || rowInt > BOARD_LENGTH - 1 || column < 0
			|| column > BOARD_LENGTH - 1)
		{
			cout << endl << "Invalid selection" << endl;
		}
		// Check if player has selected the coordinates before
		else if (enemyBoard[rowInt][column] >= MISS &&
			enemyBoard[rowInt][column] <= PATROL_BOAT_HIT)
		{
			cout << endl << "You've already tried there.";
		}

		// Check for hit
		else if (enemyBoard[rowInt][column] >= AIRCRAFT_CARRIER &&
			enemyBoard[rowInt][column] <= PATROL_BOAT)
		{
			enemyHits[enemyBoard[rowInt][column]] -= 1;

			message = row + to_string(column + 1) + " Hit.\n";

			// check if ship is sunk
			if (enemyHits[enemyBoard[rowInt][column]] == 0)
			{
				message += "\tYou sunk the enemy's " +
					shipToString(enemyBoard[rowInt][column]) + "!\n";
			}

			// Changes ship tile to hit tile
			enemyBoard[rowInt][column] =
				static_cast<Tile>(enemyBoard[rowInt][column] + 6);
			return message;
		}
		// check for a miss
		else if (enemyBoard[rowInt][column] == WATER)
		{
			message = row + to_string(column + 1) + " Miss.\n";
			// Chages water tile to miss tile
			enemyBoard[rowInt][column] = MISS;
			return message;
		}
	}
	while (!false);
}

bool isAllZeroes(int ships[])
{
	// If there are any ship tiles that haven't been hit, returns false
	for (int index = 0; index < 6; ++index)
	{
		if (ships [index] > 0)
		{
			return false;
		}
	}
	return true;
}
