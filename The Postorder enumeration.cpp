#include<iostream>
#include<string.h>
using namespace std;

void post(char *a,char *b,int length)
{
    if (length==0)
        return;
    int s;
    for(s=0;s<length;s++)
    {
        if(*(b+s)==*a)
            break;
    }
    post(a+1,b,s);
    post(a+s+1,b+s+1,length-s-1);
    cout<<*a;
    return;
}

int main()
{
    int n,i;
    char a[100],b[100];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        cin>>b;
        char *c=a;
        char *d=b;
        int l=strlen(a);
        post(c,d,l);
        cout<<endl;
    }
    return 0;
}
