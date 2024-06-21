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

void sum(Node** head)
{
    
    Node* temp = new Node ;
    while( temp->next != NULL && (temp)->data/10 > 0 )
    {
        temp->data =(temp->data+1)%10;
        temp = temp->next;
    }
    if(temp->data/10>0 )
    {
        temp->data =(temp->data+1)%10;
        push(&(*head),1);
    }
    else{
        temp->data =(temp->data+1)%10;

    }

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
    int input;
    cin>>input;
    Node *head = NULL;

    while(input>0)
    {
        push(&head,input%10);
        input /= 10;
    }
    sum(&head);
    display(&head);
    return 0;

}