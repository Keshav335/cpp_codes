#include<iostream>
using namespace std;


class LinkedListADT{
    private:
    struct node{
        int item;
        node *next;
    };
    node* start;
    
    node *Search(int data){
       node *t;
       if(start == NULL){
        return (NULL);
       }
       t=start;
       while(t!=NULL){
        if(t->item == data){
            return (t);
        }
        t=t->next;
       }
       return (NULL);
    }

    public:
    LinkedListADT(){
        start = NULL;
    }
    int countItems();
    void insertAtStart(int data);
    void insertAtLast(int data);
    void insertAfter(int currentData, int data);
    int searchItem(int data);
    int deleteItemFromStart();
    int deleteItemFromLast();
    int deleteCurrentItem(int currentData);
    void sortList();
    void editItem(int currentData, int newData);
    void viewList();
    int getFirstItem();
    int getLastItem();
    ~LinkedListADT(){
        while(start != NULL){
            deleteItemFromStart();
        }
    }
};

void LinkedListADT::insertAtStart(int data){
    node *n = new node;
    n->item = data;
    n->next = start;
    start = n;
}

void LinkedListADT::insertAtLast(int data){
    node *n = new node;
    n->item = data;
    n->next = NULL;
    if(start == NULL){
        start=n;
    }
    else{
        node *t=start;
        while(t->next != NULL){
            t=t->next;
        }
        t->next=n;
    }
}

void LinkedListADT::insertAfter(int currentData, int data){
    node *t = Search(currentData);
    if(t==NULL){
        cout<<"\nNo Such value exists";
    }
    else{
        node *n=new node;
        n->item = data;
        n->next = t->next;
        t->next = n;
    }
}
    
int LinkedListADT::deleteItemFromStart(){
    if(start == NULL){
        cout<<"\nUnderflow";
        return(0);
    }
    node *r;
    r=start;
    start=start->next;
    delete(r);
    return(1);
}

int LinkedListADT::deleteItemFromLast(){
    if(start == NULL){
        cout<<"\nUnderflow";
        return(0);
    }
    if(start->next == NULL){
        delete(start);
        start = NULL;
        return(1);
    }
    node *t1, *t2;
    t1=start;
    do{
        t2=t1;
        t1=t1->next;
    }while(t1->next!=NULL);
    t2->next=NULL;
    delete(t1);
    return(1);
}

int LinkedListADT::deleteCurrentItem(int currentData){
    node *t=Search(currentData);
    if(t==NULL){
        cout<<"\nItem not found";
        return(0);
    }
    while(t->next!=NULL){
        t->item = t->next->item;
        t = t->next;
    }
    deleteItemFromLast();
    return(1);
}

void LinkedListADT:: editItem(int currentData, int newData){
    node *t = Search(currentData);
    if(t==NULL){
        cout<<"\nItem not found";
    }
    else{
        t->item = newData;
    }
}

int LinkedListADT::countItems(){
    int Count=0;
    node *t;
    t=start;
    while(t!=NULL){
        Count++;
        t=t->next;
    }
    return(Count);
}

int LinkedListADT::getFirstItem(){
    if(start ==NULL){
        cout<<"\nList is empty";
        return(-1);
    }
    return(start->item);
}
    
int LinkedListADT::getLastItem(){
    node* t;
    if(start==NULL){
        cout<<"\nList is empty";
        return(-1);
    }
    t=start;
    while(t->next!=NULL){
        t=t->next;
    }
    return(t->item);
}

void LinkedListADT::viewList(){
    node *t;
    t = start;
    if(start == NULL){
        cout<<"\nList is empty";
    }
    else{
        while(t!=NULL){
            cout<<" "<<t->item;
            t=t->next;
        }
    }
}

int LinkedListADT::searchItem(int data){
    node *t;
    int position=0;
    t=start;
    while(t!=NULL){
        position++;
        if(t->item == data){
            return(position);
        }
        t=t->next;
    }
    return(-1);
}

//sorting: If linked list contain int values ->swaping values is a good option.
// And if values are of object->pointer manipulation is a good choice
//bubble sort: hear we are swaping values
void LinkedListADT::sortList(){
    node* t;
    int r,i,x,n;
    n=countItems();
    for(r=1; r<=n-1; r++){
        t=start;
        for(i=0; i<=n-1-r; i++){
            if(t->item > t->next->item){
                x = t->item;
                t->item = t->next->item;
                t->next->item = x;
            }
            t= t->next;
        }
    }
}

int main(){
    LinkedListADT l1;
    l1.insertAtStart(10);
    l1.insertAtStart(11);
    l1.insertAtStart(12);
    l1.insertAtLast(13);
    l1.insertAfter(12,2);
    cout<<l1.getFirstItem()<<endl;
    cout<<l1.getLastItem()<<endl;
    cout<<l1.countItems()<<endl;
    l1.viewList();
    cout<<endl;
    l1.sortList();
    l1.viewList();
    cout<<endl;
    l1.deleteItemFromStart();
    l1.viewList();
    cout<<endl;
    l1.editItem(10,1);
    l1.viewList();
    return 0;    
}
