typedef struct node {
	void* data;
	struct node* link;
} Node;

typedef struct _list {
	int count;
	Node *first;
} List;

void insert_node(List *mylist, void* data, int (*compareFn)(void*, void*));
void print_l(List mylist, void (*print_data)(void*));
