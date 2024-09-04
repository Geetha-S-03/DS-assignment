#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


int findMiddle(struct Node* head) {
    struct Node* s = head;
    struct Node* f= head;
    
    while (f != NULL && f->next != NULL) {
        s = s->next;
        f = f->next->next;
    }
    
    return s->data;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    struct Node* last = *head_ref;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}


int main() {
    struct Node* head = NULL;
    

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);
    
    printf("Middle node: %d\n", findMiddle(head)); 


    append(&head, 6);
    
    printf("Middle node: %d\n", findMiddle(head)); 
    
    return 0;
}
