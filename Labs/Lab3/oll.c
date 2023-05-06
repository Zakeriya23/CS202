//Zakeriya Muhumed || CS201 || Lab 3 

//Librays
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>

//compile & debug
/*  gcc -Wall -g -o oll oll.c
    ./oll
    valgrind ./oll 
*/
#define MAX_LINE_LEN 1000

//Data structure
typedef struct node_s {
    char *str;
    struct node_s *prev;
    struct node_s *next;
} node_t;

typedef struct llist_s {
    node_t *first;
    node_t *last;
} llist_t;

//Function Prototypes
node_t *new_node(char *);
void insert_node(llist_t *, char *);
void walk_forward(llist_t *);
void walk_reverse(llist_t *);
void free_list(llist_t *);

node_t * new_node(char *str){
    // 1. Allocate a new node
    // 2. Assign values to all of its data members.
    //Check
    // allocated a new node and assigned values to its data members.
    // alocate and assign before these statements.
    // 3. return the new node

    node_t * node = malloc(sizeof(node_t));
    node->str=strdup(str);
    node -> next = NULL;
    node->prev = NULL;

    
    assert(node != NULL);
    assert(node->next == NULL);
    assert(node->prev == NULL);
    assert(node->str != str);
    
    return node;
}

void insert_node(llist_t *list, char *str){
    // 1. Allocate a new node by calling new_node()
    // 2. Insert the new node into the ordered linked list at the correct location

    node_t * node = new_node(str);
    node_t * current = list->first;
    node_t * prev = NULL;

    if(list->first == NULL){
        list-> first = list-> last = node;
        return;
    }
    while(current && strcmp(str, current->str)> 0){
        prev =current;
        current = current -> next;
    }
    if(prev){
        node -> next = current;
        node -> prev = prev;
        prev -> next = node;
        if(current){
            current ->prev = node;
        }
        else{
            list->last= node;
        }
    }
    else{
        node->next = current;
        current -> prev = node;
        list -> first = node;
    }

}

void walk_forward(llist_t *list){

    // 1. Print "--- forward ---\n"
    // 2. Walk forward through the list printing the string for each
    //    node in the list. These should all be in increasing order.
    // 3. Print a newline

    printf("--- forward ---\n");
    
    node_t * current = list ->first;
    while(current){
        printf("%s\n",current->str);
        current = current -> next;
    }
    
    printf("\n");

}

void walk_reverse(llist_t *list){
    // 1. Print "--- reverse ---\n"
     // 2. Walk backward through the list printing the string for each
    //    node in the list. These should all be in decreasing order.
     // 3. Print a newline
    printf("--- reverse ---\n");
   
    node_t * current = list ->last;
    while(current){
        printf("%s\n",current->str);
        current = current -> prev;
    }
   
    printf("\n");

}

void free_list(llist_t *list){
    // 1. walk through the list and free all allocated memory
    node_t *current = list->first;
    while(current){
        node_t * temp= current->next;
        free(current->str);
        free(current);
        current= temp;
    }
    list->first = NULL;
    list->last =NULL;

    /*
    assert(list->first == NULL);
    assert(list->last == NULL);
    */
}


//main(int argc, char *argv[])
int main(void){
    llist_t list = {NULL, NULL};

//#define TESTING
#ifdef TESTING
    // Testing
    // you can insert nodes into the ordered linked list correctly.
    // It does NOT read any input from stdin.
    
    insert_node(&list, "y");
    insert_node(&list, "b");
    insert_node(&list, "x");
    insert_node(&list, "a");
    insert_node(&list, "c");
    insert_node(&list, "z");

    assert(strcmp(list.first->str, "a") == 0);
    assert(strcmp(list.first->next->str, "b") == 0);
    assert(strcmp(list.first->next->next->str, "c") == 0);
    assert(strcmp(list.first->next->next->next->str, "x") == 0);
    
    assert(strcmp(list.last->str, "z") == 0);
    assert(strcmp(list.last->prev->str, "y") == 0);
    assert(strcmp(list.last->prev->prev->str, "x") == 0);
    assert(strcmp(list.last->prev->prev->prev->str, "c") == 0);
#else // TESTING
    char buf[MAX_LINE_LEN] = {0};
    while(scanf("%s", buf)!=EOF){
        insert_node(&list,buf);
    }

#endif // TESTING

    // 2. Walk forward through the list, by calling walk_forward()
    // 3. Walk backward through the list, by calling walk_reverse()
    // 4. Free all allocated memory, by calling free_list()
    walk_forward(&list);
    walk_reverse(&list);
    free_list(&list);
    
    // After you've freed all the memory, these will make sure the
    // first and last pointers are set to NULL.
    assert(list.first == NULL);
    assert(list.last == NULL);

    return EXIT_SUCCESS;
}
