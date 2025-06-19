#ifndef EXPENSE_H
#define EXPENSE_H

#define MAX_EXPENSES 1000
#define MAX_LINE_LENGTH 256
#define DATE_LENGTH 11 // YYYY-MM-DD + null terminator

typedef struct {
    char date[DATE_LENGTH];
    double amount;
    char *category;
    char *description;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

typedef struct {
    char *category;
    double total;
    double percentage;
} CategorySummary;

#endif