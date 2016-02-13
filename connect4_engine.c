#include <stdio.h>
#include "connect4_engine.h"

#define EMPTY -1

int place_token(int player, int column, int num_rows, int num_columns, int board[num_rows][num_columns]) {
	if(column >= num_columns || column < 0) {
		printf("Couldn't place token on board because column is not within the boundaries\n");
		return 0;
	}
	for(int row = num_rows - 1; row > -1; --rows) { // have to go up each row to find resting point of token
		// Start looking from the bottom and go up until we find an EMPTY cell
		if(board[row][column] == EMPTY) {
			board[row][column] = player;
			return 1; // successfully placed a token
		}

		if(row == 0) { // reached the top and haven't been able to place token anywhere
			printf("That column is full, please select a different column.\n");
			return 0; // wasn't able to place a token	
		}
		
	}
	// if it gets here, a token wasn't successfully placed
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
	int winner = -1;
	int count = 0;
	int iterate = length_to_win - 1;
	bool game_is_over = false; // assume game isn't over yet, look for a win though
	for(int row = 0; row < num_rows; ++row) {
		for(int col = 0; col < num_columns; ++col) {
			if(row + (length_to_win - 1) < num_rows) { // row boundary checking
				if(col - (length_to_win - 1) > -1) { // col boundary checking
					// at this point there could be an up-left diagonal win
					int player = board[row][col];
					if(player != EMPTY) { // check to make sure cell isn't empty
						count++; // one token, now look for others up/left or down/right
						int start_row = row + 1;
						int start_col = col - 1;
						iterate = length_to_win - 1; // num times to check
						bool cont = true; // should we continue to check or not
						while(iterate >= 0 && countinue) {
							if(player == array[start_row][start_col]) {
								count++;
								++start_row;
								++start_col;
								--iterate;	
							} else {
								cont = false;
							}
						}
						if(cont) { // if we found a diagonal win return winner
							return player;
						}
					}
				}
			}
		}
	}	
}
