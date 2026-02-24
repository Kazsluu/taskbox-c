#ifndef TASKLIST_H
#define TASKLIST_H

struct Task {
    int id;
    int done;
};

struct Node {
    struct Task task;
    struct Node *next;
};

int push_front(struct Node **head, int id, int done);
int push_back(struct Node **head, int id, int done);
int delete_by_id(struct Node **head, int id);
int toggleDone(struct Node *head, int id);
int save_list(const char *filename, struct Node *head);
int load_list(const char *filename, struct Node **head);
void print_list(struct Node *head);
void free_list(struct Node **head);
struct Node *find_by_id(struct Node *head, int id);
void get_stats(struct Node *head, int *total, int *done);

#endif
