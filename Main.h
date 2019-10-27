class Grid {
public:
	bool gElements[GRID_LENGTH][GRID_LENGTH];
	bool gStatusElem[GRID_LENGTH][GRID_LENGTH];

	Grid() {
		loadGrid();
	}
	void loadGrid();
	void showGrid();
	void showFullGrid();
	int getClosestBombs(int index1, int index2);
	bool inRange(int x, int y);
	bool isWin();
};

void Grid::loadGrid()
{
	for (int i = 0; i < GRID_LENGTH; i++)
	{
		for (int ii = 0; ii < GRID_LENGTH; ii++)
		{
			this->gStatusElem[i][ii] = false;
			this->gElements[i][ii] = (rand() % 100 > DIFFICULTY * 11) ? false : true;
		}
	}
}

void Grid::showGrid()
{
	for (int i = 0; i < GRID_LENGTH; i++)
	{
		for (int ii = 0; ii < GRID_LENGTH; ii++)
		{
			if (this->gStatusElem[i][ii]) cout << this->getClosestBombs(i, ii);
			else cout << "-";
		}
		cout << endl;
	}
}

void Grid::showFullGrid()
{
	for (int i = 0; i < GRID_LENGTH; i++)
	{
		for (int ii = 0; ii < GRID_LENGTH; ii++)
		{
			if (this->gElements[i][ii]) cout << "B";
			else cout << this->getClosestBombs(i, ii);
		}
		cout << endl;
	}
}

bool Grid::inRange(int x, int y)
{
	return (x >= 0 && x < GRID_LENGTH && y >= 0 && y < GRID_LENGTH);
}

bool Grid::isWin()
{
	for (int i = 0; i < GRID_LENGTH; i++)
	{
		for (int ii = 0; ii < GRID_LENGTH; ii++)
		{
			if (!this->gElements[i][ii] && !this->gStatusElem[i][ii]) return false;
		}
	}
	return true;
}

int Grid::getClosestBombs(int index1, int index2)
{
	int count = 0;
	int temp[8][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };
	for (int i = 0; i < 8; i++) if (this->inRange(index1 + temp[i][0], index2 + temp[i][1])) {
		if (this->gElements[temp[i][0] + index1][temp[i][1] + index2]) count++;
		else {
			if (i < 4) this->gStatusElem[temp[i][0] + index1][temp[i][1] + index2] = true;
		}
	}
	return count;
}