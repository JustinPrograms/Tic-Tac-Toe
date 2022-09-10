#include <iostream>
#include "Tic Tac Toe.h"


Game game;

int main() {

	// Game loop
	while (!game.isWin) {
		game.togglePlayer();
		game.drawBoard();
		game.input();
		game.checkWin();
	}

	// What happens after game is over and winner/tie declared
	game.drawBoard();
	if (game.isWin && !game.isDraw)
		std::cout << "\nCongratulations player '" << game.player << "' you are the winner!";
	else {
		std::cout << "\nAww! You Tied";

	}
	// Credits ofc
	std::cout << "\n\n-----Credits-----\nGame: Tic Tac Toe\nAuthor: Justin\nGithub: https://github.com/JustinPrograms\n\n\n";
	std::system("pause");

}


void Game::drawBoard() {
	// Drawing the board and updating the board
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}

}

void Game::input() {

	// Getting the field
	std::cout << "Player " << player << " please choose a number on the field: ";
	std::cin >> position;


	// Checks if field has already been played
	x = (position - 1) / 3;
	y = (position - 1) - (x * 3);

	if (matrix[x][y] == 'X' || matrix[x][y] == 'O') {
		std::cout << "This field has already been played! ";
		game.input();
	}


	// Sets the field to the player
	switch (position) {

	case 1:
		matrix[0][0] = player;
		break;

	case 2:
		matrix[0][1] = player;
		break;

	case 3:
		matrix[0][2] = player;
		break;

	case 4:
		matrix[1][0] = player;
		break;

	case 5:
		matrix[1][1] = player;
		break;

	case 6:
		matrix[1][2] = player;
		break;

	case 7:
		matrix[2][0] = player;
		break;

	case 8:
		matrix[2][1] = player;
		break;

	case 9:
		matrix[2][2] = player; 
		break;
	// Checks if the field is outside the matrix eg. 24
	default:
		std::cout << "Invaild field! ";
		game.input();
	}

}

void Game::togglePlayer() {
	// After every turn the player changes
	if (player == 'X') {
		player = 'O';
	}
	else {
		player = 'X';
	}
	std::cout << "-----------------------------------------------\n";
}

void Game::checkWin() {


	// Checks horizontal win
	for (int i = 0; i < 3; i++) {
		if (matrix[i][0] == player && matrix[i][1] == player && matrix[i][2] == player) {
			isWin = true;
		}
	}

	// Checks vertical win
	for (int i = 0; i < 3; i++) {
		if (matrix[0][i] == player && matrix[1][i] == player && matrix[2][i] == player) {
			isWin = true;
		}
	}

	// Checks diagonal win
	k = 0;
	if (matrix[k][k] == player && matrix[k+1][k+1] == player && matrix[k+2][k+2] == player) {
		isWin = true;
		return;
	}

	k++;
	if (matrix[k][k] == player && matrix[k+1][k-1] == player && matrix[k-1][k+1] == player) {
		isWin = true;
	}

	// Checks tie
	moves++;
	if (moves == 9 && !isWin) {
		isWin = true;
		isDraw = true;
	}
}
