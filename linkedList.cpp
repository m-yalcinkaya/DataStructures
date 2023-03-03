
#include <iostream>

using namespace std;


struct node{
    struct node* next;
    int data;
};


void addNode(struct node** head, int data){
    
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp -> data = data;
    
    if((*head) == NULL){
        (*head) = temp;
        temp = NULL;
        free(temp);
    }else{
        struct node* iter = (*head);
        while(iter -> next != NULL) iter = iter -> next;
        iter -> next = temp;
        iter = NULL;
        temp = NULL;
        free(temp);
        free(iter);
    }
}

void print(struct node* head){
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    struct node* head = NULL;
    addNode(&head, 10);
    addNode(&head, 20);
    addNode(&head, 30);
    addNode(&head, 40);
    addNode(&head, 50);
    
    print(head);

    return 0;
}
