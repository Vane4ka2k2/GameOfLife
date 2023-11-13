#include "GameOfLife.h"

void menu()
{
	cout << "�������� �����:\n";
	cout << "1. ���������� ���� ������� 10 x 10 ����������� ���������� ����������\n";
	cout << "2. ���������� ���� ������� n x n ����������� ���������� ����������\n";
	cout << "3. ���� ������� m x n ����������� ���������� ����������\n";
	cout << "4. ���� ��������� � ����� board.txt\n";
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
		cout << "������� ������ ����: "; cin >> size;
		GameOfLife game(size);
		game.gameLoop();
	}
	else if (value == 3)
	{
		int row, col;
		cout << "������� ���-�� �����: "; cin >> row;
		cout << "������� ���-�� ��������: "; cin >> col;
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