#include<stdio.h>
 #include<stdlib.h>

struct Node { 
    int data; 
    struct Node* next; 
};

struct Node* SortedMerge(struct Node* a, struct Node* b);
void push(struct Node** head_ref, int new_data); /
void printList(struct Node *node);

int main(){

    struct Node* res = NULL; 
    struct Node* a = NULL; 
    struct Node* b = NULL; 

    push(&a, 15); 
    push(&a, 10); 
    push(&a, 5); 
    push(&b, 20); 
    push(&b, 3); 
    push(&b, 2); 
    
    res = SortedMerge(a, b); 
    printf("Merged Linked List is:\n"); 
    printList(res);
    return 0; 
}

struct Node* SortedMerge(struct Node* a, struct Node* b){
    
 struct Node* result = NULL;
    
    
    if (a == NULL)  
        return(b); 
    else if (b==NULL)  
        return(a); 
    
    
    if (a->data <= b->data) { 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } else { 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return(result); 
}

void printList(struct Node *node) { 

    while (node!=NULL) 
    { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
}


void push(Node** head_ref, int new_data) {
 
    Node* new_node = (Node*) malloc(sizeof(Node)); 
    new_node->data  = new_data; 
   
    new_node->next = (*head_ref); 
    
    (*head_ref)    = new_node; 
}
