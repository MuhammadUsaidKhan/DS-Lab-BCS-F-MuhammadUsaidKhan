#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
};

class LinkedList{
    public:
        Node * first;
        Node *last;
        LinkedList(){
            first = NULL;
            last = NULL;
        }
        LinkedList(int A[], int n);
        ~LinkedList();
        void Display();
        void Insert(int index, int x);
        int Delete(int index);
        int Length();
        void Reverse(Node *f);
        bool isPalindrome();
};
LinkedList::LinkedList(int A[], int n){
    Node *t;
    int i=0;
    first = new Node;
    first->data = A[0];
    last = first;
    last->next=NULL;
    for(i=1; i<n; i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
LinkedList::~LinkedList(){
    Node *p = first;
    while(first){
        first = first->next;
        delete p;
        p = first;
    }
}
void LinkedList::Display(){
    Node *p = first;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int LinkedList::Length(){
    int count = 0;
    Node *p = first;
    while(p!=NULL){
        count++;
        p = p->next;
    }
    return count;
}
void LinkedList::Insert(int index, int x){
    Node *p = first;
    Node *t;
    if(index<0 || index>Length()){
        return;
    }
    t=new Node;
    t->data = x;
    t->next = NULL;
    if(index==0){
        t->next = first;
        first = t;
    }
    else if(index>0){
        for(int i=0; i<index-1; i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}
int LinkedList::Delete(int index){
    Node *p, *q=NULL;
    int x=0;
    if(index<0 || index>Length()){
        return -1;
    }
    if(index==1){
        p = first;
        first = first->next;
        x=p->data;
        delete p;
    }
    else{
        p = first;
        for(int i=0; i<index-1; i++){
            q=p;
            p=p->next;
        }
        q->next = p->next;
        x=p->data;
        delete p;
    }
    return x;
}
void LinkedList::Reverse(Node* f){
    Node *p =first;
    Node *q =NULL;
    Node *r = NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first = q;
}
bool LinkedList::isPalindrome(){
    Node *p =first;
    Node* q;
    char array1[Length()];
    char array2[Length()];
    if(first->next==NULL){
        return true;
    }
    else{
        while(p!=NULL){
            int i=0;
            array1[i] = p->data;
            p=p->next;
            i++;
        }
        Reverse(first);
        q = first;
        while(q!=NULL){
            int j=0;
            array2[j] = q->data;
            q=q->next;
            j++;
        }
        for(int i=0; i<Length(); i++){
        if(array1[i]!=array2[i]){
            return false;
            }
        }
    }
    return true;
}
LinkedList mergeSortedLists(LinkedList &l1, LinkedList &l2){
    Node* p= l1.first;
    Node* q= l2.first;
    Node *third=NULL;
    Node *last =NULL;
    if(p->data<q->data){
        third = p;
        last = p;
        p=p->next;
        last->next=NULL;
    }
    else{
        third = q;
        last = q;
        q=q->next;
        last->next = NULL;
    }
    while(p!=NULL && q!=NULL){
        if(p->data<q->data){
            last->next = p;
            last = p;
            p=p->next;
            last->next = NULL;
        }
        else{            
            last->next=q;            
            last=q;            
            q=q->next;            
            last->next=NULL;
        }

    }
    if(p!=NULL){
        last->next = p;
    }
    else{
        last->next = q;
    }
    
    LinkedList merged;
    merged.first= third;
    return merged;
}
int main() {
    int A[]={0,15,25,35,40};
    LinkedList l1(A,5);
    int B[]={10,20,30,45,50,60};
    LinkedList l2(B,6);
    LinkedList merged = mergeSortedLists(l1, l2);
    cout<<"Merged Sorted List is: "<<endl;
    merged.Display();
    return 0;
}
