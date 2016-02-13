#ifndef CONNECT_4_
#define CONNECT_4_

int place_token(int player, int column, int num_rows, int num_columns, int board[num_rows][num_columns]);
int winner(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]);
int check_winner(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]);
int horizontal_check(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]);
int vertical_check(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]);
int check_up_right(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]);
int check_up_left(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]);
#endif