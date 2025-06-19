#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "contact.h"

void add_contact(ContactBook *book);
void update_contact(ContactBook *book);
void delete_contact(ContactBook *book);
void list_contacts(ContactBook *book);
void search_contacts(ContactBook *book);

#endif