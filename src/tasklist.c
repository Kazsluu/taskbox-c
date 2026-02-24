#include "../include/tasklist.h"
#include <stdio.h>
#include <stdlib.h>


struct Node *create_node(int id, int done) {
    struct Node *node = malloc(sizeof(struct Node));

    if (node == NULL) {
        return NULL;
    }

    node->task.id = id;
    node->task.done = done;
    node->next = NULL;

    return node;
}

int push_front(struct Node **head, int id, int done) {
    struct Node *new = create_node(id, done);

    if (!new) {
        return 0;
    }
    new->next = *head;
    *head = new;
    return 1;
}

int push_back(struct Node **head, int id, int done) {
    struct Node *new = create_node(id, done);

    if (!new) {
        return 0;
    }
    if (!*head) {
        *head = new;
        return 1;
    }

    struct Node *cur = *head;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = new;
    return 1;

}

struct Node *find_by_id(struct Node *head, int id) {
    struct Node *current = head;

    while (current) {
        if (id == current->task.id) {
            return current;
        }
        current = current -> next; 
    }
    
    return NULL;
}

int delete_by_id(struct Node **head, int id) {
    struct Node *current = *head;
    struct Node *prev = NULL; 

    while (current) {
        if (current->task.id == id) {
            if (prev) {
                prev->next = current->next; 
            } else {
                *head = current->next;
            }
            free(current);
            return 1;         
        }
        prev = current;
        current = current -> next;
    }
    return 0;
}
int toggleDone(struct Node *head, int id) {
    struct Node *toToggle = find_by_id(head, id);

    if (!toToggle) {
        return 0;
    }
    toToggle->task.done = !toToggle->task.done;
    return 1;
}

int mark_done(struct Node *head, int id) {
    struct Node *toDone = find_by_id(head, id);
    if (toDone) {
        toDone -> task.done = 1;
        return 1;
    }
    return 0;
}


void afficherNode(struct Node *node) {
    if (node == NULL) {
        printf("(null)\n");
        return;
    }
    printf("Node id=%d done=%d next=%p\n", node->task.id, node->task.done, (void *)node->next);

}
void print_list(struct Node *head) {
    struct Node *current = head;

    while (current != NULL) {
        afficherNode(current);
        current = current -> next;
    }
}

void free_list(struct Node **head) {
    struct Node *current = *head;

    while (current != NULL) {
        struct Node *next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}


int save_list(const char *filename, struct Node *head) {
    FILE *f = fopen(filename, "w");
    if (!f) {
        return 0;
    }

    for (struct Node *cur = head; cur; cur = cur->next) {
        fprintf(f, "%d %d\n", cur->task.id, cur->task.done);

    }
    fclose(f);
    return 1;
}

int load_list(const char *filename, struct Node **head) {
    FILE *f = fopen(filename, "r");

    if (!f) {
        return 0;
    }
    free_list(head);

    int id, done;
    while (fscanf(f,"%d %d", &id, &done) == 2) {
        if (!push_back(head, id, done)) {
            fclose(f);
            free_list(head);
            return 0;
        }
    }
    fclose(f);
    return 1;
}
void get_stats(struct Node *head, int *total, int *done) {
    *total = 0; 
    *done = 0;
    for (struct Node *cur = head; cur ; cur = cur->next ) {
        (*total)++;
        if (cur->task.done == 1) {
            (*done)++;
        }
    }
}
