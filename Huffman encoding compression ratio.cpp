#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

typedef struct node
{
    int fois;
    int letter;
    int leng;
    node*l=NULL;
    node*r=NULL;
}node;
node d[50];//用来存各个字母的个数
node e[100];//哈夫曼树

//用最小堆来做
void swapp(node *sor,int h,int t)
{
    node temp=sor[h];
    sor[h]=sor[t];
    sor[t]=temp;
}
void shiftdown(node*sor,int n,int h)
{
    int i,t;
    while(2*h+1<n)
    {
        if(2*h+2<n&&sor[2*h+2].fois<sor[2*h+1].fois)t=2*h+2;
        else t=2*h+1;
        if(sor[h].fois<sor[t].fois)return;
        swapp(sor,h,t);
        h=t;
    }
}
void in(node*sor,int &n,node *e,int m)
{

    sor[n]=e[m];
    int k=n;
    n++;
    while(k>0)
    {
        int s=(k-1)/2;
        if(sor[k].fois<sor[s].fois) swapp(sor,s,k);
        else return;
    }
}
void re(node *sor,node *j,int &n,int &m)
{
    j[m++]=sor[0];
    swapp(sor,0,n-1);
    n--;
    shiftdown(sor,n,0);
}
void buildheap(node* sor,int n)
{
    int i;
    for(i=(n-1)/2;i>=0;i--) shiftdown(sor,n,i);
}

//建立新结点时把下面的叶节点的code长度加一
void add(node* e)
{
    if(e==NULL) return;
    if(e->l==NULL) {e->leng++;}
    add(e->l);
    add(e->r);
}
//算code总长度
void fin(node *e,int &aaa)
{
    if(e==NULL) return;
    if(e->l==NULL)
        {
            int b=e->fois,c=e->leng;
            aaa=aaa+b*c;
        }
    fin(e->l,aaa);
    fin(e->r,aaa);
}

int main()
{
    char s[100];
    while(cin >> s)
    {
        if (strcmp(s, "END") == 0) break;
        int l=strlen(s),i,k,n=0,m=0;
        //初始化
        for(i=0;i<50;i++) {d[i].fois=0;d[i].leng=0;}
        //算各个字母的个数
        for(i=0;i<l;i++)
        {
            int con=0;
            for(k=0;k<n;k++)
            {
                if(s[i]==d[k].letter) {d[k].fois++;con=1;break;}
            }
            if(con==0)
                {d[n].letter=s[i];d[n++].fois=1;}
        }
        node sor[50];//用来排序
        for(i=0;i<50;i++) sor[i]=d[i];
        buildheap(sor,n);
        while(n>1)
        {
            re(sor,e,n,m);
            re(sor,e,n,m);
            e[m].fois=e[m-2].fois+e[m-1].fois;
            e[m].l=&e[m-1];
            e[m].r=&e[m-2];
            add(&e[m]);
            in(sor,n,e,m);
            m++;
        }
        int aaa=0;
        fin(&e[m-1],aaa);
        cout<<8*l<<' ';
        cout<<aaa<<' ';
        printf("%.1f\n",8*l*1.0/(aaa*1.0));
    }
    return 0;
}
