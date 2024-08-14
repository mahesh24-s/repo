//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data<<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 

  Node* addOne(Node *head,int& carry) 
    {
        if(head->next==NULL)
        {
            int total=head->data+carry;
            head->data=total%10;
            carry=total/10;
            return head;
        }
        addOne(head->next,carry);
        int total=head->data+carry;
        head->data=total%10;
            carry=total/10;
            return head;
    }

int main() 
{ 
   Node* head=new Node(-1);
   Node* last=head;
   int n=4;
   while(n--)
   {
    int num;
    cout<<"enter number:";
    cin>>num;
    Node* temp=new Node(num);
    last->next=temp;
    last=temp;
   }
   Node* temp=head;
   head=head->next;
   temp->next=NULL;
   delete temp;
int carry=1;
   head=addOne(head,carry);
   if(carry)
   {
    Node * temp=new Node(carry);
    temp->next=head;
    head=temp;
   }
   printList(head);
    return 0; 
} 

// } Driver Code Ends