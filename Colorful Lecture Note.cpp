#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
    char a[1000];
    int num[3];
    char color[3];
    gets(a);
    int r=0,b=0,y=0,n=0,coun=0;
    for(int i=0;i<strlen(a);i++)
    {
        if (a[i]==' ') continue;
        int flag=0;
        if(a[i]=='<')
        {
            int j;
            if(n!=0)
            {
                if(color[n-1]=='r')r+=coun;
                if(color[n-1]=='y')y+=coun;
                if(color[n-1]=='b')b+=coun;
                //cout<<r<<' '<<y<<' '<<b<<endl;
                coun=0;
            }
            if(a[i+1]=='/')n--;
            else {color[n]=a[i+1];n=n+1;}
            for(j=i+1;a[j]!='>';j++);
            i=j+1;
        }
        if(n!=0)coun++;
    }
    cout<<r<<' '<<y<<' '<<b<<endl;
    return 0;
}

