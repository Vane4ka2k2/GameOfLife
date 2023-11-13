#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

class GameOfLife
{
public:
	GameOfLife();
	GameOfLife(int _size);
	GameOfLife(int _row, int _col);
	GameOfLife(vector<vector<int>> _board);
	GameOfLife(string name);
	~GameOfLife();

	void gameLoop();

private:
	int row = 10;
	int col = 10;
	vector<vector<int>> board;

	void display();
	void update();
};