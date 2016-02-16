#include "connect4_engine.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	char line[256];
	int num_rows = 8;
	int length_to_win = 4;
	
	if(argc == 3) {
		num_rows = atoi(argv[1]);
		if(num_rows < 3) {
			printf("Error, minimum board size for rows/cols is 3. Exiting.\n");
			exit(1);
		}
		length_to_win = atoi(argv[2]);
		if(length_to_win > num_rows) {
            printf("Error, the length to win cannot be greater than the number of rows/cols. Exiting.\n");
            exit(1);
        }
	} else if(argc == 2) {
		num_rows = atoi(argv[2]);
		if(num_rows < 3) {
			printf("Error, minimum board size for rows/cols is 3. Exiting.\n");
			exit(1);
		}			
	} else {
        printf("Warning! No arguments found or too many arguments. Loading default settings.\n");
    }

	int board[num_rows][num_rows];
	printf("Creating a connect 4 board of size %d x %d. To win a length of %d is required\n", num_rows, num_rows, length_to_win);
	
	init_board(num_rows, num_rows, board);
	int players = 2;
	while(1) {
		print_board(num_rows, num_rows, board);
		int is_winner = -1;
		int is_full = -1;
		
		int was_placed = 0; // if it is 1, that means a token was placed successfully
		printf("It is player %d's turn.\n", players % 2);
		printf("Please enter a column number between %d and %d to place a token in.\n", 0, num_rows -1);

		int column;
		fgets(line, sizeof(line), stdin);
		sscanf(line, "%d", &column);

		was_placed = place_token(players % 2, column, num_rows, num_rows, board);
		is_winner = winner(num_rows, num_rows, length_to_win, board);
		is_full = is_board_full(num_rows, num_rows, board);

		if(is_winner != -1) { // check to see if there is a winner first
			printf("\n\n\n");
			printf("Player %d has won!\n", is_winner);
			print_board(num_rows, num_rows, board);
			exit(1);
		}

		if(is_full != -1) { // check to see if the board is full, resulting in a tie
			printf("\n\n\n");
			printf("Tie game!\n");
			print_board(num_rows, num_rows, board);
			exit(1);
		}
		
		if(was_placed) { // token was successfully placed, no winner, no tie
            printf("Successfully placed a token in column %d\n", column);
			players++; // goes to the next player
		}

		


	}
}

