#include "filesystem.h"

FSNode *create_folder(const char *name)
{
	FSNode *folder = (FSNode *)malloc(sizeof(FSNode));
	folder->type = FT_FOLDER;
	folder->name = strdup(name);
	folder->size = 0;
	folder->first_child = 0;
	folder->next_sibling = 0;
	return (folder);
}

FSNode *create_file(const char *name, int size)
{
	FSNode *file = (FSNode *)malloc(sizeof(FSNode));
	file->type = FT_FILE;
	file->name = strdup(name);
	file->size = size;
	file->first_child = 0;
	file->next_sibling = 0;
	return (file);
}

void add_child(FSNode *parent, FSNode *child)
{
	FSNode *temp;
	if (parent->type == FT_FOLDER)
	{
		if (parent->first_child == 0)
			parent->first_child = child;
		else
		{
			temp = parent->first_child;
			while (temp->next_sibling != 0)
				temp = temp->next_sibling;
			temp->next_sibling = child;
		}
	}
}

FSNode *get_children(const FSNode *parent)
{
	if (!parent || parent->type != FT_FOLDER)
		return (0);
	return (parent->first_child);
}

FSNode *get_sibling(const FSNode *node)
{
	if (!node)
		return (0);
	return node->next_sibling;
}

// void print_tree(const FSNode *node, int depth) 
// {
// 	if (!node)
// 		return;
// 	for (int i = 0; i < depth; i++)
// 		printf("  ");
// 	if (node->type == FT_FILE)
// 	{
// 		printf("📄 %s (size: %d)\n", node->name, node->size);
// 	}
// 	else
// 	{
// 		printf("📁 %s\n", node->name);
// 		FSNode *child = node->first_child;
// 		while (child) 
// 		{
// 			print_tree(child, depth + 1);
// 			child = child->next_sibling;
// 		}
// 	}
// }

// int main() 
// {
// 	FSNode *root = create_folder("Root");
// 	FSNode *docs = create_folder("Documents");
// 	FSNode *file1 = create_file("file1.txt", 100);
// 	FSNode *file2 = create_file("file2.txt", 200);
// 	FSNode *snake = create_folder("Snake");
// 	FSNode *otacon = create_file("Otacon.exe", 69420);

// 	add_child(root, docs);
// 	add_child(docs, file1);
// 	add_child(docs, file2);
// 	add_child(docs, snake);
// 	add_child(snake, otacon);

// 	FSNode *first_child = get_children(docs);
// 	printf("Primo figlio di Documents: %s\n", first_child->name);

// 	print_tree(root, 0);
// 	return 0;
// }
