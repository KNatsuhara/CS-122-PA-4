#include "header.h"

/**********************************************************
Programmer: Koji Natsuhara
Class: CptS 122, Spring 2020, Lab Section 3
Programming Assignment: Programming Assignment 4: Hunt the Wumpus Game
Date: March 6, 2020
Description: This program will be written in C++ and implement classes and define constructors
and destructurs. It will properly utilize public and private variables/functions. This program will
also apply basic file operations and file streams as well as implement overloaded functions.
**********************************************************/

int main()
{
	ofstream output;
	output.open("GameScores.txt"); //Opening file
	srand(time(0));
	cout << "===========HUNT THE WUMPUS GAME==========\n";
	worldBoard world;
	world.setName();
	while (world.getAlive())
	{
		world.showPlayer();
		world.getAction();
		system("PAUSE");
		system("CLS");
	}
	output << world; //Prints Nickname and the player's score
	output.close(); //Closing file
	return 0;
}