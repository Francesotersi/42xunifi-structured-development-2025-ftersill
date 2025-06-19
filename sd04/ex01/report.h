#ifndef REPORT_H
#define REPORT_H

#include "expenses.h"

void generate_summary(ExpenseTracker *tracker);
CategorySummary* get_category_breakdown(ExpenseTracker *tracker, int *count);

#endif