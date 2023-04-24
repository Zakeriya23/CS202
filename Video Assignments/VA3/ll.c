#include <stdio.h>
#include <stdlib.h>

// gcc -Wall -g -o ll ll.c
// ./ll
//valgrind ./ll  Memory Leaks

typedef struct node_s {
    int key;
    struct node_s *next;
}node_t;

typedef struct llist{
    node_t * first;
    node_t * last;
}llist;

node_t * new_node(int);
void add_node(llist *, int);
void walk_list(llist *); //Display
void free_list(llist *); //free

int main(void){

    llist list = {NULL,NULL};

    add_node(&list, 1);
    add_node(&list, 2);
    add_node(&list, 3);
    add_node(&list, 4);
    add_node(&list, 5);

    walk_list(&list);
    free_list(&list);

    return EXIT_SUCCESS;
}

void add_node(llist * list, int key){

    node_t *node = new_node(key);
    
    if(list->first == NULL){
        list->first= list->last= node;
    }
    else{
        list->last = list->last->next = node;
        //list->last->next = node
        //list->last = node;
    }
}
node_t * new_node(int key){
    node_t * node = malloc(sizeof(node_t));

    node->key=key;
    node -> next = NULL;
    
    return node;
}
void walk_list(llist *list){
    node_t * current = list->first;
    while(current){
        printf("node: %p    key:%d\n", (void*) current, current->key);
        current = current -> next;
    }
    
}
void free_list(llist *list){
    node_t * current = list->first;
    while(current){
       node_t * temp = current->next;
       free(current);
       current = temp;
    }
    
}

