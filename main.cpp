#include "GameOfLife.h"

void menu()
{
	cout << "Выберите режим:\n";
	cout << "1. Квадратное поле размера 10 x 10 заполненное случайными значениями\n";
	cout << "2. Квадратное поле размера n x n заполненное случайными значениями\n";
	cout << "3. Поле размера m x n заполненное случайными значениями\n";
	cout << "4. Поле считанное с файла board.txt\n";
	int value = 1;
	cin >> value;

	if (value == 1)
	{
		GameOfLife game;
		game.gameLoop();
	}
	else if (value == 2)
	{
		int size;
		cout << "Введите размер поля: "; cin >> size;
		GameOfLife game(size);
		game.gameLoop();
	}
	else if (value == 3)
	{
		int row, col;
		cout << "Введите кол-во строк: "; cin >> row;
		cout << "Введите кол-во столбцов: "; cin >> col;
		GameOfLife game(row, col);
		game.gameLoop();
	}
	else if (value == 4)
	{
		GameOfLife game("board");
		game.gameLoop();
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	menu();

	return 0;
}