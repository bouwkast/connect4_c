#include <stdio.h>
#include "connect4_engine.h"

int player;

int place_token(int player, int column, int num_rows, int num_columns, int board[num_rows][num_columns]) {
	for(int row = 0; row < num_rows; ++rows) {
		if(row == num_rows - 1 && board[row][column] == -1) {
			board[row][column] == player;
			return 1;
		}
		else if(board[row][column] == -1 && row + 1 <= num_rows && board[row+1][column] != -1) {
			board[row][column] == player;
			return 1;
		}
	}
	return 0;
}

int winner(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]) {
	int result = -1;
	
	result = check_winner(num_rows, num_columns, length_to_win, array);
	return result;
}

int check_winner(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]) {
	int winner = -1;
	winner = horizontal_check(num_rows, num_columns, length_to_win, array);
	if(winner != -1)
		return winner;
	winner  = vertical_check(num_rows, num_columns, length_to_win, array);
	if(winner != -1)
		return winner;
	winner = diagonal_check(num_rows, num_columns, length_to_win, array);
	if(winner != -1)
		return winner;
}

int horizontal_check(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]) {
	for(int row = 0; row < num_rows; ++row) {
		for(int col = 0; col < num_columns; ++col) {
			int flag = 1;
			if(col + length_to_win - 1 < num_columns) { // bound checking
				// check from left to right
				int player = board[row][col];
				if(player != -1) {
					for(int i = i; i < length_to_win - 1; ++i) {
						if(board[row][col + i] != player) {
							flag = 0;
						}
					}
				}
			}
			if(flag == 1) {
				return board[row][col];
			}
		}
	}
	return -1;
}

int vertical_check(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]) {

	for(int col = 0; col < num_columns; ++col) {
		for(int row = 0; row < num_rows; ++row) {
			int flag = 1;
			// array[row][col] to go top to bottom
			if(row + length_to_win - 1 < num_rows) {
				// check from top to bottom
				int player = board[row][col];
				if(player != -1) {
					for(int i = 1; i < length_to_win - 1; ++i) {
						if(board[row + i][col] != player) {
							flag = 0;
						}
					}
				}
			}
			if(flag == 1) {
				return board[row][col];
			}
		}
	}
	return -1;
}
int check_up_right(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]) {
	// rows will decrease to go up, columns will increase to go right
	// Need to iterate throughout the entire board normally
	for(int row = 0; row < num_rows; ++row) {
		for(int col = 0; col < num_columns; ++col) {
			int flag = 1;
			if(row - (length_to_win - 1) > -1) { // row bound checking
				if(col + (length_to_win - 1) < num_columns) { // col bound checking
					int player = board[row][col];
					if(player != -1) {
						// go up and to the right to check if there is a win
						for(int row_up = 1; row_up < num_rows - 1; ++row_up) {
							for(int col_right = 1; col_right < num_columns; ++col_right) {
								if(board[row - row_up][col + col_right] != player) {
									flag = 0;
								}
							}
						}
					}	
				}
			}
		}
	}
}

int check_up_left(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]) {
	// rows will increase to go down, columns will decrease to go left
	// need to iterate throughout entire board normally
	for(int row = 0; row < num_rows; ++row) {
		for(int col = 0; col < num_columns; ++col) {
			if(row + (length_to_win - 1) < num_rows) { // row bound checking
				if(col - (length_to_win - 1) > -1) { // col bound checking
					int player = board[row][col];
					if(player != -1) {
						// go down and to the left to see if there is a win
						for(int row_down = 1; row_down < num_rows - 1; ++row_down) {
							for(int col_left = 1; col_left < num_columns; ++col_left) {
								if(board[row + row_down][col - col_left] != player) {
									flag = 0;
								}
							}
						}
					}
				}
			}
		}
	}
}
