#pragma once

#include <iostream>

class Game {
public: 
	// Init variables
	char matrix[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	bool isWin = false;
	bool isDraw = false;
	char player = 'Y';
	int position, x, y, k = 0, moves = 0;

	// Init functions
	void drawBoard();
	void input();
	void togglePlayer();
	void checkWin();
};
