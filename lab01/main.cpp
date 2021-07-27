//
//  main.cpp
//  lab01
//
//  Created by Muhammad Suhaib Salarzai on 16/07/2021.
// Student Id: 322322

#include <iostream>

class Node{   //creating class node
public:
    int data;
    Node *next;

};
class LinkedList{
public:

    Node *start;
    Node *PreLoc;
    Node *Loc;
    Node *last;

    LinkedList(){      //constructor

        start = NULL;
        PreLoc= NULL;
        Loc = NULL;
    }

    bool isEmpty(){
        return start == NULL;
    }

    void insertAtFront(int value){
        Node *newnode = new Node();
        newnode->data = value;
        if (isEmpty())
        {
            start = newnode;
            last = newnode;
            
        }
        else
        {
            
            newnode->next = start;
            start = newnode;
        }
}

    void insertAtEnd(int value){
        Node *newnode = new Node();
        if (isEmpty())
        {
            start = newnode;
            last = newnode;
        }
        else{
            newnode->data = value;
            newnode->next = last->next;
            last->next = newnode;
            last = newnode;
        }
    }

    void Print(){

        Node *temp = start;
        if (!isEmpty())
        while (temp != NULL)
        {
           // cout << "test1" << endl;
            std::cout << temp->data << "-->";
            temp = temp->next;
        }
        else{
            std::cout<<"EMPTY List"<<std::endl;
        }
        
        std::cout<<std::endl;
    }
    void search(int value){
        Loc = start;
        PreLoc = NULL;

        while (Loc != NULL && Loc->data < value){
            PreLoc = Loc;
            Loc = Loc->next;
        }
        if (Loc != NULL && Loc->data != value)
            Loc = NULL;
        if (isEmpty()){
            return;
            
        }
    }
    void insertSorted(int value){
        search(value);
        if (Loc != NULL)
            std::cout << "value already exist duplication not allowed" << std::endl;

        else if (Loc == NULL && PreLoc == NULL){
          
            insertAtFront(value);
        }

        else if (Loc == NULL && PreLoc != NULL)
        {
            if (PreLoc == last)
            {
            
                insertAtEnd(value);
            }
            else{
              
                Node *newnode = new Node();
                newnode->data = value;
                newnode->next = PreLoc->next;
                PreLoc->next = newnode;
            }
        }
    }
    void Delete(int value){
        search(value);
        
        if (Loc == NULL){
           
            if (PreLoc == NULL){
                if (Loc == last){
                    start = NULL;
                    last = NULL;
                }
                else
                    start = start->next;
                delete Loc;
            }
        }
        else if (Loc == start){
            start = NULL;
            delete Loc;
            
        }
        
        else if(Loc != NULL){
           
            PreLoc->next = Loc->next;
            delete Loc;
            
        }
    }
   


};
int main()
{
    // New list
    LinkedList list;

    // Append nodes to the list
    list.insertSorted(100);
    list.Print();
    
    list.insertSorted(200);
    list.Print();
   
    list.insertSorted(300);
    list.Print();
 
    list.insertSorted(400);
    list.Print();
 
    list.insertSorted(500);
    list.Print();
    
   
    // Delete nodes from the list
    
    list.Delete(400);
    list.Print();
    list.Delete(300);
    list.Print();
    list.Delete(200);
    list.Print();
    list.Delete(500);
    list.Print();
    list.Delete(100);
    list.Print();
}
