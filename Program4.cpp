// Doubly Circular Link List
#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
}NODE, *PNODE;

class DoublyCL
{
    private:
        PNODE first;
        PNODE last;
        int Count;

    public:
        DoublyCL();
        void InsertFirst(int no);
        void Display();
        int CountNode();
        void InsertLast(int no);
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(int no,int ipos);
        void DeleteAtPos(int ipos);
};

DoublyCL::DoublyCL()
{
    first = NULL;
    last = NULL;
    Count = 0;
}

void DoublyCL::InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;   
    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last=newn;
    }
    else
    {
        newn -> next = first;
        first -> prev = newn;
        first = newn;
       
    }
    last -> next = first;
    first -> prev = last;
    Count++;
}
void DoublyCL::InsertLast(int no)
{
    PNODE newn = NULL;

    newn = new NODE;   
    newn->data = no;
    newn->next = NULL;
    newn -> prev = NULL;

    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last=newn;
    }
    else
    {
       newn -> prev = last;
       last -> next = newn;
       last = newn;
       
    }
    last -> next = first;
    first -> prev = last;
    Count++;
}
void DoublyCL::Display()
{
    cout<<" \n Elements of the linked list are :"<<"\n";
    
    if((first != NULL) && (last != NULL))
    {
        do
        {
           cout<<"| "<<first -> data<<"| <=> ";
           first = first -> next;
        } 
        while (first != last -> next);          
    }
}
int DoublyCL::CountNode()
{
    int i = 0;

    if((first != NULL) && (last != NULL))
    {
        do
        {
            i++;
           first = first -> next;
        } 
        while (first != last -> next);        
    }
    return i;
}
void DoublyCL::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if( first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last -> next;
        first -> prev = last;
        last -> next = first;
    }
}
void DoublyCL::DeleteLast()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if( first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last -> prev;
        delete last -> next;
        first -> prev = last;
        last -> next = first;
    }
}
void DoublyCL::InsertAtPos(int no,int ipos)
{
    if((ipos < 1) || (ipos > Count+1))
    {
        return;
    }
     
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        PNODE newn = new NODE;
        newn->data = no;
        newn->next = NULL;
        newn -> prev = NULL;

        PNODE temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        temp -> next = newn;
        newn -> prev = temp;

        Count++;
    }
}
void DoublyCL::DeleteAtPos(int ipos)
{
    
    if((ipos < 1) || (ipos > Count))
    {
        return;
    }
     
    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {
        PNODE newn = new NODE;
        newn->next = NULL;
        newn -> prev = NULL;

        PNODE temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }
        
        Count--;
    }
}
int main()
{
    DoublyCL obj;

    obj.InsertFirst(101);
    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    cout<<"\n No. of nodes: "<<obj.CountNode();

    obj.DeleteFirst();
    obj.Display();
    cout<<"\n No. of nodes: "<<obj.CountNode();

    obj.DeleteLast();
    obj.Display();
    cout<<"\n No. of nodes: "<<obj.CountNode();

    obj.InsertAtPos(3,41);
    obj.Display();
    cout<<"\n No. of nodes: "<<obj.CountNode();

    return 0;
}