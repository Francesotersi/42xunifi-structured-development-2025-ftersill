#ifndef FILE_IO_H
#define FILE_IO_H

#include "expenses.h"

int load_expenses(const char *filename, ExpenseTracker *tracker);
void free_expenses(ExpenseTracker *tracker);
int is_valid_date(const char *date);
int is_valid_amount(double amount);

#endif