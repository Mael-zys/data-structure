#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int findi(int *a,int k,int l,int r)
{
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a[mid]==k) return mid;
        else if(a[mid]>a[r])
        {
            if(a[mid]>k&&a[r]<=k) l=mid+1;
            else r=mid-1;
        }
        else
        {
            if(a[mid]<k&&a[l]>=k) r=mid-1;
            else l=mid+1;
        }
    }
    return -1;
}

int findmax(int *a, int l,int r)
{
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(a[mid]>a[r]) r=mid;
        else l=mid+1;
    }
    return r;
}



int main()
{
    int n,i,temp;
    cin>>n;
    getchar();
    int a[50];
    for(i=0;i<n;i++)
    {
        int j=0;
        while(cin>>temp)
        {
            a[j++]=temp;
            if (cin.get() == '\n') break;
        }
        int m=findmax(a,0,j-1),t;
        while(cin>>t)
        {
            int o=findi(a,t,0,j-1);
            if (o==-1) cout<<-1<<endl;
            else cout<<(o-m+j)%j<<endl;
            if(cin.get()=='\n') break;
        }
        //cout<<a[0]<<" "<<a[1];
    }
}
