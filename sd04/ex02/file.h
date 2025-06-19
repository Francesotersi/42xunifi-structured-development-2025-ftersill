#ifndef FILE_IO_H
#define FILE_IO_H

#include "contact.h"

int load_contacts(const char *filename, ContactBook *book);
int save_contacts(const char *filename, ContactBook *book);
void free_contacts(ContactBook *book);

#endif