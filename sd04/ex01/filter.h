#ifndef FILTER_H
#define FILTER_H

#include "expenses.h"

void filter_by_category(ExpenseTracker *tracker, const char *query);
void filter_by_date_range(ExpenseTracker *tracker, const char *start_date, const char *end_date);

#endif