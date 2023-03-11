
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
        
    }
    else{
        
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
    while(temp->data != data && temp->next != NULL) temp = temp->next;
    if(temp->next == NULL && temp->data != data){
        cout << "The item you wanted to update was not found" << endl;
        return;
    }
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
    if(temp->data == data) cout << "The item you were looking for was found : " << "Node : " << nodeCounter << endl;
    else if(temp->next == NULL) cout << "The item you were looking for was not found" << endl;
    
}

void sortLinkedList(struct node* head){
    
    
    struct node* temp = head;
    struct node* temp2 = head;
    while(true){
        
        int minData = temp->data;
        temp2 = temp;
    
        while(temp->next != NULL){
            temp = temp->next;
            if(temp->data < minData){
                minData = temp->data;
            }
        }
        temp = temp2;
        while(temp -> data != minData) temp = temp->next; 
        int tempData = temp2->data;
        temp2->data = minData;
        temp->data = tempData;
        if(temp2->next != NULL) temp = temp2->next;
        else break;
        
    }
    
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
    addNode(&head, 780);
    addNode(&head, 15);
    addNode(&head, 90);
    addNode(&head, 17);
    addNode(&head, 50);
    addNode(&head, 100);
    deleteNode(&head, 100);
    updateNode(head, 12);
    searchNode(head, 15);
    sortLinkedList(head);
    
    print(head);

    return 0;
}
