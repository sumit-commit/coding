#include<iostream>
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
        while(ptr->next!=head)
        {
            cout<<ptr->data<<" ";
            ptr = ptr->next;
        }
        cout<<ptr->data<<endl;
    }
    }
    
    //inserting element at first position
    void insertatfirst(int val){
     
       node* ptr =  new node(val);
       if(head == NULL)
       {
        head = ptr ;
        ptr->next = head;
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
     
        if(head == NULL){
            insertatfirst(val);    
        }
        else
        {
        node* ptr =  new node(val);
        node* temp = head;
        
        while(temp->next!=head)
        {
            temp = temp->next;
        }
        
        temp->next= ptr;
        ptr->next = head;
        
        cout<<ptr->data<<" inserted at last\n";
        length++;
        
        }
    }
    
    
    //Deleting element from first position
    void deletefromfirst(){
        
        if(head == NULL)
        {
            cout<<"Linked List is Empty\n";
        }

        else if (head->next == head)
        {
            cout<<head->data<<" deleted from first\n";
            head = NULL;
            length--;
        }

        else
        {
            cout<<head->data<<" deleted from first\n";
            head=head->next;
            length--;
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
    
    
    //Deleting element from last position
    void deletefromlast(){
     
       if(head == NULL)
        {
            cout<<"Linked List is Empty\n";
        }
        else if(head->next == head)
        {
            cout<<head->data<<" deleted from last\n";
            head = NULL;
            length--;
        }
        {
        node* ptr = head;
        
        while(ptr->next->next!=head)
        {
            ptr = ptr->next;
        }
        
        cout<<ptr->next->data<<" deleted from last\n";
        ptr->next = head;
        length--;
        }
    }
    
    
    
   
    
    
};

int main(){
    ll obj;
    obj.insertatfirst(1);
    obj.insertatlast(15);
    obj.insertatlast(6);
    obj.insertatfirst(63);
    obj.insertatfirst(2);
      obj.insertatpos(3,4);
    obj.insertatlast(7);
    obj.deletefromfirst();
      obj.deletefrompos(4);
    obj.insertatfirst(1);
    obj.deletefromlast();
    obj.insertatfirst(0);
    obj.traverse();
    
}