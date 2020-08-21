#include "header.h"

/*
Function: worldBoard()
Date Created: 3/6/2020
Description: This function is the constructor for the class worldBoard and will generate
a random board once the class is intialized
Input Parameters: void
Returns: void
*/
worldBoard::worldBoard()
{
	int maxPits = 0, maxGold = 1, numPits = 0, gold = 0, maxPlayer = 1, maxWumpus = 1, player = 0, wumpus = 0, row = 0, col = 0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			board[i][j].occupied = false; //Sets cells to occupied FALSE
			board[i][j].symbol = '-'; //Sets the cells' symbol to '-'
		}
	}

	maxPits = (rand() % 6) + 5; //generates a random number between 5 and 10
	row = getRandInt(); //generates a random location in the board
	col = getRandInt();

	while (numPits < maxPits || gold < maxGold || player < maxPlayer || wumpus < maxWumpus)
	{
		if (board[row][col].occupied == true)
		{
			row = getRandInt(); //gets a new location on the board if the location is already occupied
			col = getRandInt();
		}
		else if (numPits < maxPits) //Makes sure to place down the number of pits on the board based on the number randomly generated
		{
			board[row][col].occupied = true;
			board[row][col].symbol = 'P';
			numPits++;
		}
		else if (gold < maxGold) //Makes sure to place down only one gold and labels the spot as occupied
		{
			board[row][col].occupied = true;
			board[row][col].symbol = 'G';
			gold++;
		}
		else if (player < maxPlayer) //Makes sure to place down one user and labels that the spot is occupied
		{
			board[row][col].occupied = true;
			board[row][col].symbol = 'U';
			user.row = row; //adds location of user to user location
			user.col = col;
			player++;
		}
		else if (wumpus < maxWumpus) //Makes sure to place down the Wumpus and labels that spot as occupied
		{
			board[row][col].occupied = true;
			board[row][col].symbol = 'W';
			enemy.row = row; //adds location of wumpus to enemy location
			enemy.col = col;
			wumpus++;
		}
	}
}

/*
Function: displayEntireWorld()
Date Created: 3/6/2020
Description: This function will display the entire board and the symbols that each
cell represents
Input Parameters: void
Returns: void
*/
void worldBoard::displayEntireWorld()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << " " << board[i][j].symbol << " "; //Prints out the symbol of each cell
		}
		cout << endl;
	}
}

/*
Function: displayVisibleWorld()
Date Created: 3/6/2020
Description: This function will display the cells adjacent and diagonal to the user and
show the rest of the cells as unknown ( ~ )
Input Parameters: void
Returns: void
*/
void worldBoard::displayVisibleWorld()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if ((i >= user.row - 1 && i <= user.row + 1) && (j >= user.col - 1 && j <= user.col + 1))
			{
				cout << " " << board[i][j].symbol << " "; //Prints out the symbol of the cell
			}
			else
			{
				cout << " ~ "; //Every other cell will be printed out as unknown
			}
		}
		cout << endl;
	}
}

/*
Function: moveUp()
Date Created: 3/6/2020
Description: This function will move the user up one cell if the user does not go out of bounds
Input Parameters: void
Returns: Will check if the user has found the gold or has died
*/
void worldBoard::moveUp()
{
	board[user.row][user.col].occupied = false; //Resetting the cell
	board[user.row][user.col].symbol = '-';
	user.row--;	//Moves the user's location up
	if (haveIWon() || amIAlive())
	{
		board[user.row][user.col].occupied = true; //Updating the cell
		board[user.row][user.col].symbol = 'U';
		score += 5;
	}
	else
	{
		board[user.row][user.col].occupied = false; //Updating the cell
		board[user.row][user.col].symbol = 'X';
		alive = false;
	}
}

/*
Function: moveDown()
Date Created: 3/6/2020
Description: This function will move the user up one cell if the user does not go out of bounds
Input Parameters: void
Returns: Will check if the user has found the gold or has died
*/
void worldBoard::moveDown()
{
	board[user.row][user.col].occupied = false; //Resetting the cell
	board[user.row][user.col].symbol = '-';
	user.row++; //Moves the user's location down
	if (haveIWon() || amIAlive())
	{
		board[user.row][user.col].occupied = true;
		board[user.row][user.col].symbol = 'U';
		score += 5;
	}
	else
	{
		board[user.row][user.col].occupied = false; //Updating the cell
		board[user.row][user.col].symbol = 'X';
		alive = false;
	}
}

/*
Function: moveRight()
Date Created: 3/6/2020
Description: This function will move the user up one cell if the user does not go out of bounds
Input Parameters: void
Returns: Will check if the user has found the gold or has died
*/
void worldBoard::moveRight()
{
	board[user.row][user.col].occupied = false; //Resetting the cell
	board[user.row][user.col].symbol = '-';
	user.col++; //Moves the user's location right
	if (haveIWon() || amIAlive())
	{
		board[user.row][user.col].occupied = true;
		board[user.row][user.col].symbol = 'U';
		score += 5;
	}
	else
	{
		board[user.row][user.col].occupied = false; //Updating the cell
		board[user.row][user.col].symbol = 'X';
		alive = false;
	}
}

/*
Function: moveLeft()
Date Created: 3/6/2020
Description: This function will move the user up one cell if the user does not go out of bounds
Input Parameters: void
Returns: Will check if the user has found the gold or has died
*/
void worldBoard::moveLeft()
{
	board[user.row][user.col].occupied = false; //Resetting the cell
	board[user.row][user.col].symbol = '-';
	user.col--; //Moves the user's location left
	if (haveIWon() || amIAlive())
	{
		board[user.row][user.col].occupied = true;
		board[user.row][user.col].symbol = 'U';
		score += 5;
	}
	else
	{
		board[user.row][user.col].occupied = false; //Updating the cell
		board[user.row][user.col].symbol = 'X';
		alive = false;
	}

}

/*
Function: getChar()
Date Created: 3/6/2020
Description: This function will prompt the user for a character
and will only accept i,k,j,l,v,c,r,q,n
Input Parameters: void
Returns: Will return a character that is accepted by the function from the user
*/
char worldBoard::getChar()
{
	char c = '0';
	int check = 0;
	do
	{
		cout << "What action would you like to perform?: "; //Prompts the user to input a valid character
		cin >> c;
		if (user.row == 0 && (c == 'i' || c == 'I')) //Checks the user's top out-of-bounds limit
		{
			cout << "You cannot go out of bounds!\n";
		}
		else if(user.row == 4 && (c == 'k' || c == 'K')) //Checks the user's bottom out-of-bounds limit
		{
			cout << "You cannot go out of bounds!\n";
		}
		else if (user.col == 0 && (c == 'j' || c == 'J')) //Checks the user's left out-of-bounds limit
		{
			cout << "You cannot go out of bounds!\n";
		}
		else if (user.col == 4 && (c == 'l' || c == 'L')) //Checks the user's right out-of-bounds limit
		{
			cout << "You cannot go out of bounds!\n";
		}
		else if (c == 'i' || c == 'I' || c == 'k' || c == 'K' || c == 'j' || c == 'J' || c == 'l' || c == 'L' || c == 'v' || c == 'V' ||
			c == 'c' || c == 'C' || c == 'r' || c == 'R' || c == 'n' || c == 'N' || c == 'q' || c == 'Q')
		{
			check = 1;
		}
		else
		{
			cout << "You inputted an invalid action!\n";
		}
	} while (check == 0);

	return c;
}

/*
Function: getAction()
Date Created: 3/6/2020
Description: This function take ask the user for a character and then run the character
through a switch statement and then run the option accordingly.
Input Parameters: void
Returns: void
*/
void worldBoard::getAction()
{
	char action = '\0';
	menu();
	action = getChar();
	switch (action)
	{
	case 'i':
	case 'I':
		moveUp(); //moves the user up
		break;
	case'k':
	case'K':
		moveDown(); //moves the user down
		break;
	case 'j':
	case 'J':
		moveLeft(); //moves the user to the left
		break;
	case 'l':
	case 'L':
		moveRight(); //moves the user to the right
		break;
	case 'v':
	case 'V':
		cout << "-----Displaying Visible World-----\n";
		displayVisibleWorld(); //Displays the visible world
		score -= 2;
		break;
	case 'c':
	case 'C':
		cout << "-----Displaying Entire World-----\n";
		displayEntireWorld(); //Displays the entire world
		score -= 5;
		break;
	case 'r':
	case 'R':
		cout << "-----Restarting World-----\n";
		restartWorld(); //Restart World with same player
		break;
	case 'n':
	case 'N':
		cout << "===========HUNT THE WUMPUS GAME==========\n";
		startNewGame();//Restart World with new player
		break;
	case 'q':
	case 'Q':
		cout << "=====Ending the Game======\n";
		endGame(); //End game
		break;
	}
}

/*
Function: amIAlive()
Date Created: 3/6/2020
Description: This function will return true/false based on whether the user is still alive or not
Input Parameters: void
Returns: Boolean true/false
*/
bool worldBoard::amIAlive()
{
	char c = '\0';
	bool alive = true;
	if (board[user.row][user.col].symbol == 'P' || board[user.row][user.col].symbol == 'W') //Checks if the user has walked over a pit or the wumpus
	{
		cout << "You have died!\n";
		cout << "Do you want to try again ";
		c = getYesNo(); //Asks if the user wants to continue
		if (c == 'Y' || c == 'y')
		{
			alive = true;
			restartWorld();
		}
		else
		{
			alive = false;
		}
	}
	return alive;
}

/*
Function: haveIWon()
Date Created: 3/6/2020
Description: This function will return true/false based on whether the user has found the gold or not
Input Parameters: void
Returns: Boolean true/false
*/
bool worldBoard::haveIWon()
{
	char c = '\0';
	bool won = false;
	if(board[user.row][user.col].symbol == 'G') //Checks whether the user's location is over the gold location
	{
		cout << "You have found the gold!\n";
		won = true;
		cout << "Do you want to continue ";
		c = getYesNo(); //Asks if the user wants to play another game/continue
		if (c == 'Y' || c == 'y')
		{
			alive = true;
			restartWorld();
		}
		else
		{
			alive = false; //Unorthodox way, but this allows the game to end
		}
	}
	return won;
}

/*
Function: restartWorld()
Date Created: 3/6/2020
Description: This function will restart the entire board and relocate all the pits, gold, wumpus and player
Input Parameters: void
Returns: void
*/
void worldBoard::restartWorld()
{
	int maxPits = 0, maxGold = 1, numPits = 0, gold = 0, maxPlayer = 1, maxWumpus = 1, player = 0, wumpus = 0, row = 0, col = 0;

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			board[i][j].occupied = false; //Sets cells to occupied FALSE
			board[i][j].symbol = '-'; //Sets the cells' symbol to '-'
		}
	}

	maxPits = (rand() % 6) + 5;
	row = getRandInt();
	col = getRandInt();

	while (numPits < maxPits || gold < maxGold || player < maxPlayer || wumpus < maxWumpus)
	{
		if (board[row][col].occupied == true)
		{
			row = getRandInt();
			col = getRandInt();
		}
		else if (numPits < maxPits)
		{
			board[row][col].occupied = true;
			board[row][col].symbol = 'P';
			numPits++;
		}
		else if (gold < maxGold)
		{
			board[row][col].occupied = true;
			board[row][col].symbol = 'G';
			gold++;
		}
		else if (player < maxPlayer)
		{
			board[row][col].occupied = true;
			board[row][col].symbol = 'U';
			user.row = row;
			user.col = col;
			player++;
		}
		else if (wumpus < maxWumpus)
		{
			board[row][col].occupied = true;
			board[row][col].symbol = 'W';
			enemy.row = row;
			enemy.col = col;
			wumpus++;
		}
	}
}

/*
Function: endGame()
Date Created: 3/6/2020
Description: This function will change the private boolean alive variable to false and end the game
Input Parameters: void
Returns: void
*/
void worldBoard::endGame()
{
	alive = false;
	cout << "Game has ended!\n";
}

/*
Function: showPlayer()
Date Created: 3/6/2020
Description: This function will display the entire board as unknown except for the location of the user
Input Parameters: void
Returns: void
*/
void worldBoard::showPlayer()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (board[i][j].symbol == 'U')
			{
				cout << " " << board[i][j].symbol << " ";
			}
			else
			{
				cout << " ~ ";
			}
		}
		cout << endl;
	}
}

/*
Function: showPlayer()
Date Created: 3/6/2020
Description: This function will display the entire board as unknown except for the location of the user
Input Parameters: void
Returns: void
*/
void worldBoard::startNewGame()
{
	setName();
	restartWorld();
}

/*
Function: ofstream& operator << (ofstream& output, const worldBoard& data)
Date Created: 3/6/2020
Description: This function will overload the console out operator and print out the nickname and score of the object class worldBoard and
print it to the GameScores.txt file or whatever output file that the program opens
Input Parameters: void
Returns: void
*/
ofstream& operator << (ofstream& output, const worldBoard& data)
{
	output << data.name << " : " << data.score << endl;
	return output;
}

/*
Function: menu()
Date Created: 3/6/2020
Description: This function will display the menu and the options avaliable to the user
Input Parameters: void
Returns: void
*/
void menu()
{
	cout << "i or I: Move up\n";
	cout << "k or K: Move down\n";
	cout << "j or J: Move left\n";
	cout << "l or L: Move right\n";
	cout << "v or V: Display Visible World\n";
	cout << "c or C: CHEAT Display Entire World\n";
	cout << "r or R: Restart Game\n";
	cout << "n or N: New Game\n";
	cout << "q or Q: End Game\n";
}

/*
Function: getRandInt()
Date Created: 3/6/2020
Description: This function will generate a random number between 0 and 4
Input Parameters: void
Returns: int
*/
int getRandInt()
{
	int num = 0;
	num = rand() % 5;
	return num;
}

/*
Function: getYesNo()
Date Created: 3/6/2020
Description: This function will prompt the user Y/N and accept the characters
Y,y,N,n and return the character
Input Parameters: void
Returns: char
*/
char getYesNo()
{
	char c = '\0';
	int check = 0;
	do
	{
		cout << "(Y/N)?: ";
		cin >> c;
		if (c == 'Y' || c == 'N' || c == 'y' || c == 'n')
		{
			check = 1;
		}
		else
		{
			cout << "Invalid character.\n";
		}
	} while (check == 0);
	return c;
}


