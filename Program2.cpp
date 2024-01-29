// Singly Circular Link List
#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node *next;
}NODE, *PNODE;

class SinglyCL
{
    private:
        PNODE first;
        PNODE last;
        int Count;

    public:
        SinglyCL();
        void InsertFirst(int no);
        void Display();
        void InsertLast(int no);
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(int no,int ipos);
        void DeleteAtPos(int ipos);
};

SinglyCL::SinglyCL()
{
    first = NULL;
    last = NULL;
    Count = 0;
}
void SinglyCL::InsertFirst(int no)
{
    PNODE newn = NULL;

    newn = new NODE;   
    newn->data = no;
    newn->next = NULL;


    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last=newn;
    }
    else
    {
        newn -> next = first;
        first = newn;
       
    }
    last -> next = first;
    Count++;
}
void SinglyCL::InsertLast(int no)
{
    PNODE newn = NULL;
    
    newn = new NODE;   
    newn->data = no;
    newn->next = NULL;


    if((first == NULL) && (last == NULL))
    {
        first = newn;
        last=newn;
    }
    else
    {
        last -> next = newn;
        last = newn;
        last -> next = first;
       
    }
    Count++;
}
void SinglyCL::Display()
{
    
     PNODE temp = first;

    cout<<"Elements of the linked list are :"<<"\n";
    
    if((first != NULL) && (last != NULL))
    {
        do
        {
           cout<<"| "<<first -> data<<"| -> ";
           first = first -> next;
        } 
        while (first != last -> next);
               
    }
}
int SinglyCL::CountNode()
{
    int Cnt = 0;

    if((first != NULL) && (last != NULL))
    {
        do
        {
            Cnt++;
           first = first -> next;
        } 
        while (first != last -> next);        
    }
    return Cnt;
}
void SinglyCL::DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;
        delete last -> next;
        last -> next = first;
    }
}
void SinglyCL::DeleteLast()
{
    PNODE temp = first;

    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        while(temp->next != last)
        {
            temp = temp -> next;
        }
        delete last;
        last = temp;
        last -> next = first;
    }
}
void SinglyCL::InsertAtPos(int no,int ipos)
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

        PNODE temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;

        Count++;
    }
}
void SinglyCL::DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > Count))
    {
        return;
    }
     
    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Count+1)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }

        PNODE targatednode = temp->next;
        temp->next = temp->next->next;
        delete targatednode;

        Count--;
    }
}

int main()
{
    SinglyCL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);
    obj.Display();
    cout<<"No. of nodes : \n"<<obj.CountNode();

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.Display();
    cout<<"No. of nodes : \n"<<obj.CountNode();

    obj.InsertAtPos(31,3);
    obj.Display();
    cout<<"No. of nodes\n : "<<obj.CountNode();

    obj.DeleteAtPos(3);
    obj.Display();
    cout<<"No. of nodes\n : "<<obj.CountNode();

    obj.DeleteFirst();
    obj.Display();
    cout<<"No. of nodes : \n"<<obj.CountNode();

    obj.DeleteLast();
    obj.Display();
    cout<<"No. of nodes : \n"<<obj.CountNode();

    return 0;
}