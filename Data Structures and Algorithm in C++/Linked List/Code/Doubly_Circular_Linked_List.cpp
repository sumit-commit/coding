#include <iostream>
using namespace std;

class node{
    public:
    
    int data;
    node* next;
    node* prev;

    node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

};


class ll{
    
    public:
    
    node* head ;
    node* tail ;
 
    int length = 0; 
    
    
    //Traversing all list elements 
    void traverse(){
     
        if(head == NULL)
        {
          cout<<"List is Empty nothing to traverse\n";
        }
        else
        {
        cout<<"Final Linked List : \n";
        node* ptr = head;
        while(ptr->next!=head)
        {
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
        cout<<ptr->data;
        cout<<endl;
    }
    }
    
    //insert at first position

    void insertatfirst(int val)
    {
        
        node* new_node = new node(val);
        
        if(head == NULL)
        {
        
            head = new_node;
            tail = new_node;
            head->prev = tail;
            tail->next = head;
            
        }
        else
        {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
            head->prev = tail;
            tail->next = head;
        }
        length++;
    }

    //insert at some position
    void insertatpos(int pos, int val)
    {   
        if(pos<2)
        {
           insertatfirst(val);
        }
        else if(pos>length)
        {
            insertatlast(val);
        }
        else
        {
            node* temp = head;
            node* new_node = new node(val);
            while(pos>2)
            {
                temp = temp->next;
                pos--;
            }
            
            
            new_node->next = temp->next;
            temp->next->prev = new_node;
            temp->next = new_node;
            new_node->prev = temp;
            
            length++;
        }
    }
    
    //insert at last position
    void insertatlast(int val)
    {
        
        node* new_node = new node(val);
        
        if(head == NULL)
        {
            head = new_node;
            tail = new_node;
            head->prev = tail;
            tail->next = head;
            
        }
        else
        {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
            head->prev = tail;
            tail->next = head;
        }
        length++;
    }
    
    // delete from first position
    
    void deletefromfirst()s
    {

        if(head == NULL)
        {
            cout<<"List is already empty nothing to delete\n";
        }

        else if(head == tail)
        {
            cout<<head->data<<" deleted from first position\n";
            head = NULL;
            tail = NULL;
            length--;
        }
        else
        {
            cout<<head->data<<" deleted from first position\n";
            head = head->next;
            head->prev = tail;
            tail->next = head;
            length--;
        }
        
    }
    
    
    // delete from last position
    
    void deletefromlast()
    {

        if(head == NULL)
        {
            cout<<"List is already empty nothing to delete\n";
        }

        else if(head == tail)
        {
            cout<<head->data<<"deleted from last position\n";
            head = NULL;
            tail = NULL;
            length--;
        }
        else
        {
            
            tail = tail->prev;
            head->prev = tail;
            tail->next = head;
            length--;
        }
        
    }

     // delete from some position
    
    void deletefrompos(int pos)
    {
        if(pos<2)
        {
           deletefromfirst();
        }

        else if(pos>=length)
        {
            deletefromlast();
        }
        else
        {
            
            node* ptr = head;
            
            while(pos>2)
            {
                ptr = ptr->next;
                pos--;
            }
            
            cout<<ptr->next->data<<" deleted from some position\n";
            ptr->next = ptr->next->next;
            ptr->next->next->prev = ptr;
            length--;
        }
    }


};



int main(){
    ll o;
    o.deletefromfirst();
    o.traverse();
    o.insertatfirst(6);
    o.traverse();
    o.insertatfirst(5);
    o.traverse();
    o.insertatlast(7);
    o.traverse();
    o.insertatlast(9);
    o.traverse();
    o.insertatpos(4,8);
    o.traverse();
    o.insertatfirst(4);
    o.traverse();
    o.insertatpos(9,10);
    o.traverse();
    o.deletefromlast();
    o.traverse();
    o.insertatpos(0,2);
    o.traverse();
    o.deletefrompos(5);
    o.traverse();
    o.deletefromfirst();
    o.traverse();
    o.insertatpos(1,1);
    o.traverse();
    o.insertatpos(3,3);
    o.traverse();
    return 0;
}


