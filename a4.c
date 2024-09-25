#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

void open_window(Node **head, int window_num) {
    
    //create node and add to the beginning
    Node *ptr = malloc(sizeof(Node));
    ptr->data = window_num; //assign pointer struct data to window num 
    ptr->next = *head; //assign next field to head pointer

    *head = ptr; //head is now pointing to first element
}

void close_window(Node **head, int window_num) {
    //close the window given in the input
    Node *current = *head;
    Node *previous = *head;

    if (*head == NULL) {
        exit (0);
    }
    else if(window_num == (*head)->data){
        *head = current->next;
        free(current);
        current = NULL;
    }
    else {
        //runs until current is at node to delete and previous is one before
        while (current->data != window_num){ 
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        
        free(current);
        current = NULL;
    }  
}

void switch_window(Node **head, int window_num){
    //bring chosen window_num to the front and delete former position
    close_window(head, window_num);
    open_window(head, window_num);
}

void print_front (Node *head){
    printf("%d\n", head->data);
}
void print_list (Node *head) {
    while (head != NULL) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {

    char action[10]; //enough to hold all commands
    int window_num; //number associated with window
    Node *head = NULL; //initalizing head

    while(1) {
        int returned = scanf("%s %d", &action, &window_num);

        if (returned == EOF) {
            break;
        }

        if (strcmp(action, "open") == 0) {
            open_window(&head, window_num);
        }
        if (strcmp(action, "close") == 0) {
            close_window(&head, window_num);
        }
        if (strcmp(action, "switch") == 0) {
            switch_window(&head, window_num);
        }
        
        //print element at the front of the linked list
        if (head == NULL) {
            exit (0);
        }
        else{
            print_front(head); 
        }

    }

    return 0;
}