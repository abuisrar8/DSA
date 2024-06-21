#include<istream>

using namespace std;

int sumOfSquareOfDigit(int in)
{
    int sum =0;
    while(in>0)
    {
        int rem = in% 10;
        sum += rem*rem;
        in/=10;
    }
}
class Node
{
public:
    int data;
    Node* next;

};

void happpyNo(Node* head)
{
    
    Node* slow =head;
    Node* fast =head;


}

