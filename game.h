#ifndef c_project_game_h
#define c_project_game_h

int get_severity_range(int severity_in);
int generate_game_matrix(int severity, int *round_count);
int check_game_result();
char get_symbol(int severity);
int check_game_result(char game_matrix[3][3]);
void calculate_money_won(int bet, int row_won_count, int *money_won, int *account, int severity_in);

#endif
