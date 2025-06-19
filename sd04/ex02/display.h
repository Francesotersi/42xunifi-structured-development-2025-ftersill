#ifndef DISPLAY_H
#define DISPLAY_H

#include "contact.h"
void display_menu(void);
void display_contact(Contact *contact);
void display_error(const char *message);
void display_success(const char *message);
int get_menu_choice(void);
void get_user_input(const char *prompt, char *buffer, int max_length);

#endif