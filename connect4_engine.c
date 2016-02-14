#include <stdio.h>
#include "connect4_engine.h"

#define EMPTY -1

void init_board(int num_rows, int num_columns, int array[num_rows][num_columns]) {
	for(int row = 0; row < num_rows; ++row) {
		for(int col = 0; col < num_columns; ++col) {
			array[row][col] = EMPTY;
		}
	}
}

int place_token(int player, int column, int num_rows, int num_columns, int board[num_rows][num_columns]) {
	
	if(column >= num_columns || column < 0) {
		printf("Couldn't place token on board because column is not within the boundaries\n");
		return 0;
	}
	for(int row = num_rows - 1; row > -1; --row) { // have to go up each row to find resting point of token
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
	winner = down_right_check(num_rows, num_columns, length_to_win, array);
	if(winner != -1)
		return winner;
	winner = down_left_check(num_rows, num_columns, length_to_win, array);
	if(winner != -1)
		return winner;
	return winner;
}

int horizontal_check(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]) {
	for(int row = 0; row < num_rows; ++row) {
		int num_tokens = 1;
		for(int col = 0; col < num_columns - 1; ++col) {
			int player = array[row][col];
			if(player != EMPTY) {
				if(array[row][col + 1] == array[row][col]) {
					++num_tokens;
				} else 
					num_tokens = 1;
			} else
				num_tokens = 1;
			
			if(num_tokens == length_to_win) {
				return array[row][col];
			}
		}
	}
	return -1;
}

int vertical_check(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]) {

	for(int col = 0; col < num_columns; ++col) {
		int num_tokens = 1;
		for(int row = 0; row < num_rows-1; ++row) {
			int player = array[row][col];
			if(player != EMPTY) {
				if(array[row + 1][col] == array[row][col]) {
					++num_tokens;
				} else 
					num_tokens = 1;
			} else
				num_tokens = 1;
			
			if(num_tokens == length_to_win) {
				return array[row][col];
			}
		}
	}
	return -1;
}

int down_right_check(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]) {
	for(int row = 0; row < num_rows - 1; ++row) {
		for(int col = 0; col < num_columns- 1; ++col) {
			int num_tokens = 1;
			for(int x = row, y = col; x < num_rows -1 && y < num_columns - 1; ++x, ++y) {
				int player = array[x][y];
				if(player != EMPTY) {
					if(array[x + 1][y + 1] == array[x][y]) {
						++num_tokens;
					} else 
						num_tokens = 1;
				} else
					num_tokens = 1;
				if(num_tokens == length_to_win) {
					return array[x][y];
				}
			}
		}
	}
	return -1;
}

int down_left_check(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]) {
	for(int row = 0; row < num_rows - 1; ++row) {
		for(int col = 0; col < num_columns- 1; ++col) {
			int num_tokens = 1;
			// go down and to the left
			for(int x = row, y = col + 1; x < num_rows -1 && y > 0; ++x, --y) {
				int player = array[x][y];
				if(player != EMPTY) { // check to make sure it isn't empty
					if(array[x + 1][y - 1] == array[x][y]) {
						++num_tokens; 
					} else 
						num_tokens = 1;
				} else
					num_tokens = 1;
				if(num_tokens == length_to_win) {
					return array[x][y];
				}
			}
		}
	}
	return -1;
}



int is_board_full(int num_rows, int num_columns, int array[num_rows][num_columns]) {
	for (int row = 0; row < num_rows; ++row) {
		for(int col = 0; col < num_columns; ++col) {
			if(array[row][col] == EMPTY)
				return -1; // board isn't full	
		}
	}
	return 1; // board is full
}

void print_board(int num_rows, int num_columns, int array[num_rows][num_columns]) {
	for(int row = 0; row < num_rows; ++row) {
		for(int col = 0; col < num_columns; ++col) {
			printf("%d\t", array[row][col]);
		}
		printf("\n");
	}
}


