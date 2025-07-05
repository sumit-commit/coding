#include <iostream.h>
using namespace std;

class node{
    public:
    
    int data;
    node* next;
    
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

};


class ll{
    
    
    
    node* head ;
    int length = 0;
    
    public:
    ll()
    {
    
    }

    //Traversing all list elements 
    void traverse(){
     
        if(head == NULL)
        {
          cout<<"List is Empty nothing to traverse";
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
    
    //inserting element at first position
    void insertatfirst(int val){
     
        node* ptr =  new node(val);

        if (head == NULL)
        {
            head = ptr;
            ptr->next = NULL;
            
        }
        else
        {
            ptr->next = head;
            head = ptr;
        }
        cout<<ptr->data<<" inserted at first\n";
        length++;

    }
    
    // insert at some position
    void insertatpos(int pos, int val){
        
        if(pos<=1)
        {
            insertatfirst(val);
        }
        else if(pos>length)
        {
            insertatlast(val);
        }
        else
        {
            node* ptr = head;
            node* temp = new node(val);
            cout<<temp->data<<" inserted at "<<pos<<" position\n";
            while(pos>2)
            {
                ptr = ptr->next;
                pos--;
            }
            
            temp->next = ptr->next;
            ptr->next = temp;
            length++;
        }
        
    }
    
    
    
    //inserting element at last position
    void insertatlast(int val){
     
        if(head == NULL)
        {
            insertatfirst(val);    
        }
        else
        {
        node* ptr =  new node(val);
        node* temp = head;
        
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        
        temp->next= ptr;
        ptr->next = NULL;
        
        cout<<ptr->data<<" inserted at last\n";
        length++;
        
        }
    }
    
    // delete from some position
    void deletefrompos(int pos){
        
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
            
            cout<<ptr->next->data<<" Deleted from some position\n";
            ptr->next = ptr->next->next;
            length--;
            
        }
        
    }
    
    
    //Deleting element from first position
    void deletefromfirst(){
        
        
        if(head == NULL)
        {
            cout<<"Linked List is Empty\n";
        }
        else if(head->next == NULL)
        {
            head = NULL;
        }
        else
        {
        cout<<head->data<<" deleted from first\n";
        head=head->next;
        length--;
        }

    }
    
    //Deleting element from last position
    void deletefromlast(){
     
       if(head == NULL)
        {
            cout<<"Linked List is Empty\n";
        }
        else if(head->next == NULL)
        {

            head = NULL;
        }
        else
        {
        node* ptr = head;
        
        while(ptr->next->next!=NULL)
        {
            ptr = ptr->next;
        }
        
        cout<<ptr->next->data<<" deleted from last\n";
        ptr->next = NULL;
        length--;
        }
        
        
}
    
    
    
   
    
    
};

int main(){
    ll obj;

    obj.insertatlast(0);
    obj.insertatlast(1);
    obj.insertatlast(2);
    obj.insertatlast(4);
    obj.insertatlast(7);
    obj.insertatlast(9);
    obj.insertatlast(11);
    obj.insertatlast(14);
    obj.insertatlast(15);
    obj.insertatlast(20);
    obj.traverse();

    // obj.insertatfirst(1);
    // obj.insertatlast(15);
    // obj.insertatlast(6);
    // obj.insertatfirst(63);
    // obj.insertatfirst(2);
    //   obj.insertatpos(3,4);
    // obj.insertatlast(7);
    // obj.deletefromfirst();
    //   obj.deletefrompos(4);
    // obj.insertatfirst(1);
    // obj.deletefromlast();
    // obj.insertatfirst(0);
    // obj.traverse();
    
}