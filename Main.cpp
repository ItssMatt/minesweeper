#include <iostream>
#include <stdio.h>
#include <Windows.h>

using std::cout;
using std::endl;
using std::cin;

#define EASY 1
#define MEDIUM 2
#define HARD 3

#define DIFFICULTY HARD
#define GRID_LENGTH 20


#include "Main.h"

int main()
{
	Grid* grid = new Grid();
	grid->showGrid();
	int x, y;
	while (true)
	{
		cout << endl;
		cout << "X: ";
		cin >> x;
		cout << "Y: ";
		cin >> y;
		if (x >= GRID_LENGTH || y >= GRID_LENGTH) continue;
		grid->gStatusElem[x][y] = true;
		if (grid->gElements[x][y] || grid->isWin()) {
			system("cls");
			grid->showFullGrid();
			cout << endl << (!grid->isWin() ? "GAME OVER!" : "YOU WIN!");
			break;
		}
		else grid->showGrid();
		continue;
	}
}