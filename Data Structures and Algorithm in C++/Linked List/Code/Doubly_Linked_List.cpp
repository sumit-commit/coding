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
        while(ptr!=NULL)
        {
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
        cout<<endl;
    }
    }
    
    //insert at first position

    void insertatfirst(int val)
    {
        
        node* new_node = new node(val);
        new_node->prev = NULL;
        
        if(head == NULL)
        {
            new_node->next = NULL;
            head = new_node;
        }
        else
        {
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
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
        new_node->next = NULL;
        
        if(head == NULL)
        {
            new_node->prev = NULL;
            head = new_node;
        }
        else
        {
            node* temp = head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = new_node;
            new_node->prev = temp;
        }
        length++;
    }
    
    // delete from first position
    
    void deletefromfirst()
    {

        if(head == NULL)
        {
            cout<<"List is already empty nothing to delete\n";
        }

        else if(head->next == NULL)
        {
            cout<<head->data<<" deleted from first position\n";
            head = NULL;
            length--;
        }
        else
        {
            cout<<head->data<<" deleted from first position\n";
            head = head->next;
            head->prev = NULL;
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

        else if(head->next == NULL)
        {
            cout<<head->data<<"deleted from last position\n";
            head = NULL;
            length--;
        }
        else
        {
            node* ptr = head;
            while(ptr->next->next!=NULL)
            {
                ptr = ptr->next;
            }
            cout<<ptr->next->data<<" deleted from last position\n";
            ptr->next = NULL;
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


