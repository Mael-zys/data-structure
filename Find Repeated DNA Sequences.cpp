#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int hash1(char *a, int l)
{
    int i,slot=0;
    for (i=l;i<l+10;i++)
    {
        slot+=(a[l]+i)%10;
    }
    slot=(slot+99)%99;
    return slot;
}

int hash2(char *a, int l)
{
    int i,slot=0;
    for (i=l;i<l+10;i++)
    {
        slot+=(a[l])%70;
    }
    //slot=slot%10;
    //if(slot==0)slot++;
    cout<<slot<<endl;
    return slot;
}

int compare(char*a, int l1,int l2)
{
    int i;
    for(i=0;i<10;i++)
    {
        if(a[i+l1]==a[i+l2]);
        else return 0;
    }
    return 1;
}

int hashtable(char *a,int l, int *ht)
{
    int slot1=hash1(a,l);
    //cout<<ht[slot1]<<endl;
    if(ht[slot1]==0) {ht[slot1]=l;if(l==0)ht[slot1]=100;return 0;}
    else
    {
        if(compare(a,l,(ht[slot1]%100))==0)
        {
            //int slot2=hash2(a,l);
            int i=1;
            while(ht[(slot1+i)%99]!=0)
            {
                if(((slot1+i)%99)==slot1)
                {
                    cout<<"no place";
                    return 0;
                }
                if(compare(a,l,(ht[(slot1+i)%99]%100))==1) return ht[(slot1+i)%99];
                else i++;
            }
            ht[(slot1+i)%99]=l; return 0;
        }
        else return ht[slot1];

    }

}

int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        char a[50];
        cin>>a;
        int j;
        int ht[100]={0};
        //memset(ht,-1,100);
        cout<<"[";
        int meme[10]={0},l=0;
        for(j=0;j<strlen(a)-9;j++)
        {

            int po=hashtable(a,j,ht);
            //cout<<po<<endl;
            if(po!=0)
            {
                int k,c=0;
                for(k=0;k<l;k++)
                {
                    if(po==meme[k]){c=1;break;}
                }
                if(c==0)meme[l++]=po;
            }
        }
        for(j=0;j<l;j++)
        {
            int k;
            if(j!=0) cout<<",";
            for(k=0;k<10;k++)
                {
                    cout<<a[(100+k+meme[j])%100];
                }
        }
        cout<<"]"<<endl;
    }
}
