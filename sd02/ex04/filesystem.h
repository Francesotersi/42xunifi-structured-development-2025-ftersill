#ifndef FILESYSTEM_H
# define FILESYSTEM_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef enum {FT_FILE, FT_FOLDER} FSNodeType;

typedef struct FSNode 
{
	FSNodeType type;
	char *name;
	int size;
	struct FSNode *first_child;
	struct FSNode *next_sibling;
}   FSNode;

FSNode *create_file(const char *name, int size);
FSNode *create_folder(const char *name);
void add_child(FSNode *parent, FSNode *child);
FSNode *get_children(const FSNode *parent);
FSNode *get_sibling(const FSNode *node);

#endif