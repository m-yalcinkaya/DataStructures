
#include <iostream>

using namespace std;

struct node{
    struct node* ptr;
    int data;
};


void push(struct node*& head, int data){
    
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp -> data = data;
    temp -> ptr = head;
    head = temp;
    
}


void pop(struct node*& head){
    if(head->ptr == NULL) cout << "There is not item in stack" << endl;
    else{
        struct node* temp = head;
        head = head->ptr;
        temp->ptr = NULL;
        free(temp);
    }
    
}

void traversel(struct node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head -> ptr;
    }    
}

int main()
{
    struct node* head = NULL;
    push(head, 10);
    push(head, 78);
    push(head, 19);
    push(head, 32);
    push(head, 45);
    pop(head);
    pop(head);
    
    traversel(head);

    return 0;
}
