#ifndef HEADER_H
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <string>
#include <fstream>

#define SIZE 5

using namespace std;

struct Location {
	int row;
	int col;
};

struct Cell {
	bool occupied;
	char symbol;
};

class worldBoard {
private:
	Cell board[SIZE][SIZE];
	Location user;
	Location enemy;
	string name;
	int score = 0;
	bool alive = true;
public:
	worldBoard();
	bool getAlive()
	{
		return alive;
	}
	void setScore(int x)
	{
		score += x;
	}
	int getScore()
	{
		return score;
	}
	void setName()
	{
		string tempName;
		cout << "What is your nickname (no spaces)?: ";
		cin >> tempName;
		name = tempName;
	}
	string getName()
	{
		return name;
	}
	void displayEntireWorld();
	void displayVisibleWorld();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	char getChar();
	void getAction();
	bool amIAlive();
	bool haveIWon();
	void restartWorld();
	void endGame();
	void showPlayer();
	void startNewGame();
	friend ofstream& operator << (ofstream& output, const worldBoard& data);
};

void menu();
int getRandInt();
char getYesNo();

#endif