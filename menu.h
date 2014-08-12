#ifndef c_project_menu_h
#define c_project_menu_h

void welcome_menu();
void transaction_menu();
int severity_select();
int make_transaction();
void make_bet(int *account, int *bet);
void print_result(int row_won_count, int bet, int money_won);

#endif
