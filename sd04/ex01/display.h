#ifndef DISPLAY_H
#define DISPLAY_H

#include "expenses.h"

void display_welcome(void);
void display_menu(void);
void display_summary(ExpenseTracker *tracker);
void display_error(const char *message);
char* get_user_input(const char *prompt);
char* get_valid_date(const char *prompt);

#endif