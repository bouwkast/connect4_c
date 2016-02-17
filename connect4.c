#include "connect4_engine.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int num_rows = 8;
    int length_to_win = 4;
    if (argc == 3) {
        if (is_number(argv[1]))
            num_rows = atoi(argv[1]);
        else {
            crash_and_burn();
        }
        if (num_rows < 3) {
            printf(YELLOW"Error, minimum board size for rows/cols is 3. Exiting.\n"RESET);
            exit(1);
        } else if (num_rows > 100) {
            printf(YELLOW"Error, the board size cannot be greater than 100. Exiting.\n"RESET);
            exit(1);
        }
        if (is_number(argv[2]))
            length_to_win = atoi(argv[2]);
        else {
            crash_and_burn();
        }
        if (length_to_win > num_rows) {
            printf(YELLOW"Error, the length to win cannot be greater than the number of rows/cols. Exiting.\n"RESET);
            exit(1);
        }
    } else if (argc == 2) {
        if (is_number(argv[1]))
            num_rows = atoi(argv[1]);
        else {
            crash_and_burn();
        }
        if (num_rows < 3) {
            printf(YELLOW"Error, minimum board size for rows/cols is 3. Exiting.\n"RESET);
            exit(1);
        }
        if (length_to_win > num_rows)
            length_to_win = num_rows;
    } else {
        printf("Warning! Too many arguments. Loading default settings.\n");
    }

    int board[num_rows][num_rows];
    printf("Creating a Connect FOUR board of size "
                   RED "%d" RESET " x "
                   RED "%d" RESET ". To win a length of"
                   RED" %d" RESET " is required\n\n\n", num_rows, num_rows, length_to_win);

    init_board(num_rows, num_rows, board);
    int players = 2;
    int column = -1;
    while (1) {

        print_board(num_rows, num_rows, board, column);
        printf("Board size is" RED " %d x %d " RESET "and ;a length of "RED "%d " RESET "is required to win.\n", num_rows, num_rows, length_to_win);
        int is_winner = -1;
        int is_full = -1;

        int was_placed = 0; // if it is 1, that means a token was placed successfully
        printf("\nIt is player %d's turn.\n", players % 2);
        printf("Please enter a column number between %d and %d to place a token in.\n", 0, num_rows - 1);


        char input[256];
        scanf("%s", input);
        if (is_number(input)) {
            column = atoi(input);
        } else {
            printf(YELLOW "\n\nWarning, please enter integers only for the column you wish to place a token into.\n\n" RESET);
            column = -1; // so it won't place a token in the previously selected column
        }

        was_placed = place_token(players % 2, column, num_rows, num_rows, board); // check to see if a token was placed
        is_winner = winner(num_rows, num_rows, length_to_win, board); // check to see if there is a winner
        is_full = is_board_full(num_rows, num_rows, board); // check to see if the board is full - stalemate

        if (is_winner != -1) { // check to see if there is a winner first
            printf("\n\n\n");
            printf("Player %d has won!\n", is_winner);
            print_board(num_rows, num_rows, board, column);
            exit(1);
        }

        if (is_full != -1) { // check to see if the board is full, resulting in a tie
            printf("\n\n\n");
            printf("Tie game!\n");
            print_board(num_rows, num_rows, board, column);
            exit(1);
        }

        if (was_placed) { // token was successfully placed, no winner, no tie
            printf(GREEN"\n\nSuccessfully" RESET " placed a token in column " GREEN "%d\n\n" RESET, column);
            players++; // goes to the next player
        }


    }
}

