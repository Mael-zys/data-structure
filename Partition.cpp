#include<iostream>
using namespace std;
template<class T>
class node
{
public:
    T val;
    node* next;
    node(T a, node* n=NULL){val=a;next=n;}
    node(node* n =NULL){ next = n; }
};


template<class T>
class linklist:public node<T>
{
private:
    node<T>*head;
    node<T>*fence;
    node<T>*tail;
    void init();
    void removeall();
public:
    linklist(){init();}
    ~linklist(){removeall();}
    void clearr(){removeall();init(); }
    void pushback(T elem);
    void printall();
    void partitionn(int a);
};

template<class T>
void linklist<T>::partitionn(int a)
{
    fence=head;
    while(fence!=tail&& fence->next->val<a)
        fence=fence->next;
    if(fence==tail) return;
    node<T> *pivot=fence;
    node<T> *tran=fence;
    //fence=fence->next;
    while(fence!=tail &&fence!=NULL)
    {
        if(fence->next->val<a)
        {
            tran=fence->next;
            if(tran==tail)
                tail=fence;
            fence->next=tran->next;
            tran->next=pivot->next;
            pivot->next=tran;
            pivot=pivot->next;
            //cout<<fence->val<<pivot->val<<endl;
        }
        else fence=fence->next;
    }

}

template<class T>
void linklist<T>::printall()
{
    for(fence=head;fence->next!=tail;fence=fence->next)
        cout<<fence->next->val<<" ";
    cout<<fence->next->val<<endl;
}

template<class T>
void linklist<T>::pushback(T elem)
{
    tail->next=new node<T>(elem,NULL);
    tail=tail->next;
}

template<class T>
void linklist<T>::init()
{
    fence=head=tail=new node<T>;
}

template<class T>
void linklist<T>::removeall()
{
    while(head!=NULL)
    {
        fence=head->next;
        delete head;
        head=fence;
    }
}

int main()
{
     int n,i;
     cin>>n;
     for(i=0;i<n;i++)
     {
         linklist<int> ll;
         int num;
         while(cin>>num)
         {
             ll.pushback(num);
             if (cin.get() == '\n') break;
         }
         int a;
         cin>>a;
         ll.partitionn(a);
         ll.printall();
         ll.clearr();
     }
}
