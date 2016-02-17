#ifndef CONNECT_4_
#define CONNECT_4_
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define RED "\x1b[31m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"
#define GREEN "\x1b[32m"

bool is_number(char input[]);
int place_token(int player, int column, int num_rows, int num_columns, int board[num_rows][num_columns]);
int winner(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]);
int check_winner(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]);
int horizontal_check(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]);
int vertical_check(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]);
void print_board(int num_rows, int num_columns, int array[num_rows][num_columns], int prev_col);
int is_board_full(int num_rows, int num_columns, int array[num_rows][num_columns]);
void init_board(int num_rows, int num_columns, int array[num_rows][num_columns]);
int down_right_check(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]);
int down_left_check(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]);
void crash_and_burn();
#endif
