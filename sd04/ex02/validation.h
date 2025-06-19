#ifndef VALIDATION_H
#define VALIDATION_H

#include "contact.h"

int is_valid_id(int id, ContactBook *book);
int is_valid_name(const char *name);
int is_valid_phone(const char *phone);
int is_valid_email(const char *email);
int is_valid_city(const char *city);
void trim_whitespace(char *str);

#endif