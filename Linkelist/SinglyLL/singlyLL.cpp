#include<iostream>
#include<stdlib.h>

using namespace std;
class Node
{
public:
    int data;
    Node* next;

};

void push(Node** head, int new_data)
{
    Node * new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;

    if(*head == NULL)
    {
        *head = new_node;
        return;
    }
        
    
    Node *temp = *head;
    while(temp->next != NULL)
        temp = temp->next;
    
    temp->next = new_node;
    
    return;

}

void atFirst(Node** head,int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;

    if((*head) == NULL)
    {
        
        new_node->next = NULL;
        *head = new_node;
        return;
    }

    new_node->next = (*head);
    (*head) = new_node;
    return;
}

void delNode(Node** head, int del_data)
{
    if(*head == NULL) 
    {
        cout<<"empty LL ";
        return;
    }
    Node *temp = *head;
    if((*head)->data == del_data)
    {
        (*head) = (*head)->next;
        free(temp);
        return;
    }
    
    while(temp->next->data != del_data) temp=temp->next;
    
    if(temp->next->next == NULL)
    {
        free(temp->next);
        temp->next=NULL;
        return;
    }
    
    temp->next = temp->next->next;
    free(temp->next);
    return;
    

}

void atBtw(Node** head, int prev_data, int next_data, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;

    Node *prev_node = (*head);
    while(prev_node->data != prev_data) prev_node = prev_node->next;
    
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    
    return;

}

void display(Node **head)
{
    if (*head == NULL) cout<<"Enpty LL";
    Node *temp = *head;
    while((temp) != NULL)
    {
        cout<<(temp)->data;
        temp = (temp)->next;
    }
    

    return;
}



int main()
{
    Node *head = NULL;
    
    int flag = 1;
    int x;
    p:{ 
        cin>>x;
        push(&head,x);
        cout<<"n? (1/0 :)";
        cin>>x;
        if(x) goto p;
    }
    display(&head);
    cout<<endl<<" at end : ";
    cin>>x;
    push(&head,x);
    display(&head);
    cout<<endl<<"at begin : ";
    cin>>x;
    atFirst(&head,x);
    display(&head);
    cout<<endl<<" in bwt : \n";
    int y;
    cout<<"1: ";
    cin>>x;
    cout<<" 2: ";
    cin>>y;
    cout<<" data :";
    int d;
    cin>>d;
    atBtw(&head,x,y,d);
    display(&head);
    cout<<endl<<"del :";
    cin>>x;
    delNode(&head,x);
    display(&head);


    return 0;
}