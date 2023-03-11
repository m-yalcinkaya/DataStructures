
#include <iostream>

using namespace std;


struct node{
    struct node* next;
    int data;
};

void deleteNode(struct node** head, int data){
    if((*head)->data == data){
        
        struct node* temp = (*head);
        (*head) = (*head)->next;
        temp->next = NULL;
        free(temp);
        
    }else{
        
        struct node* temp = (*head);
        while(temp->next != NULL && temp->next->data != data) temp = temp -> next;
        if(temp->next == NULL) {
            cout << " The item you were looking for was not found  :  " << data << endl;
            return;
        }
        else if(temp->next->data == data){
            if(temp->next->next == NULL){
                free(temp->next);
                temp->next = NULL;
            }
            else{
                struct node* temp2 = temp->next;
                temp->next = temp2->next;
                temp2->next = NULL;
                free(temp2);
            }
        }
        
    }
    
}


void addNode(struct node** head, int data){
    
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp -> data = data;
    
    if((*head) == NULL){
        
        (*head) = temp;
        temp = NULL;
        free(temp);
        
    }
    else{
        
        struct node* iter = (*head);
        while(iter -> next != NULL) iter = iter -> next;
        iter -> next = temp;
        iter = NULL;
        temp = NULL;
        free(temp);
        free(iter);
        
    }
}

void updateNode(struct node* head, int data){
    
    int reguestedData;
    struct node* temp = head;
    while(temp->data != data) temp = temp->next;
    cout << "enter the data you wanted : ";
    cin >> reguestedData;
    temp->data = reguestedData;
    temp = NULL;
    free(temp);
}

void searchNode(struct node* head, int data){
    
    int nodeCounter = 1; 
    struct node* temp = head;
    while(temp->next != NULL && temp->data != data) {
        temp = temp->next;
        nodeCounter++;
    }
    if(temp->next == NULL) cout << "The item you were looking for was not found" << endl;
    else if(temp->data == data) cout << "The item you were looking for was found : " << "Node : " << nodeCounter << endl;
    
}

void print(struct node* head){
    cout << endl;
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
    addNode(&head, 100);
    deleteNode(&head, 110);
    deleteNode(&head, 120);
    updateNode(head, 10);
    updateNode(head, 50);
    searchNode(head,78);
    
    print(head);

    return 0;
}
