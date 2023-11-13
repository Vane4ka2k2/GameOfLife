#include "GameOfLife.h"

GameOfLife::GameOfLife()
{
	srand(time(0));

	for (int i = 0; i < row; i++)
	{
		vector<int> buf;
		for (int i = 0; i < col; i++)
		{
			buf.push_back(rand() % 2);
		}
		board.push_back(buf);
	}
}

GameOfLife::GameOfLife(int _size)
{
	srand(time(0));
	row = _size;
	col = _size;	

	for (int i = 0; i < row; i++)
	{
		vector<int> buf;
		for (int i = 0; i < col; i++)
		{
			buf.push_back(rand() % 2);
		}
		board.push_back(buf);
	}
}

GameOfLife::GameOfLife(int _row, int _col)
{
	srand(time(0));
	row = _row;
	col = _col;

	for (int i = 0; i < row; i++)
	{
		vector<int> buf;
		for (int i = 0; i < col; i++)
		{
			buf.push_back(rand() % 2);
		}
		board.push_back(buf);
	}
}

GameOfLife::GameOfLife(vector<vector<int>> _board)
{
	row = _board.size();
	col = _board[0].size();

	board = _board;
}

GameOfLife::GameOfLife(string name)
{
	string path = name + ".txt";
	ifstream input(path);
	input >> row >> col;

	for (int i = 0; i < row; i++)
	{
		vector<int> buf;
		for (int j = 0; j < col; j++)
		{
			int value;
			input >> value;
			buf.push_back(value);
		}
		board.push_back(buf);
	}

	input.close();
}

GameOfLife::~GameOfLife()
{

}

void GameOfLife::gameLoop()
{
	while (true)
	{
		system("cls");
		display();
		update();
		Sleep(1000);
	}
}

void GameOfLife::display()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << (board[i][j] == 1 ? '#' : ' ');
		}
		cout << endl;
	}
}

void GameOfLife::update()
{
	vector<vector<int>> newBoard = board;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int neighbors = 0;
			for (int x = -1; x <= 1; x++)
			{
				for (int y = -1; y <= 1; y++)
				{
					int ni = i + x;
					int nj = j + y;

					if (ni >= 0 && ni < row && nj >= 0 && nj < col) {
						neighbors += board[ni][nj];
					}
				}
			}
			neighbors -= board[i][j];

			if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3))
			{
				newBoard[i][j] = 0;
			}
			else if (board[i][j] == 0 && neighbors == 3)
			{
				newBoard[i][j] = 1;
			}
		}
	}

	board = newBoard;
}
