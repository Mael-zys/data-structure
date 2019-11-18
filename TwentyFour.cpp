#include "TwentyFour.h"

int TwentyFour::GetNums()
{
	cout << "Please enter four numbers (1 to 10):";
	// TO COMPLETE
	cin >> num[0] >> num[1] >> num[2] >> num[3];
	return 0;
}

int TwentyFour::Ope(int n,int x, int y)
{
   double result;
    switch(n)
    {
        case 1: result=x+y;break;
        case 2: result=x-y;break;
        case 3: result=x*y;break;
        case 4: result=x/y;break;
    }
    return result;
}

int a,b,c,d,i,j,k;
int TwentyFour::SearchOp()
{
	// TO COMPLETE
	// By the way, you do not need to cram all code just in this function;
	// you can well define some new functions and invoke those functions in a well organized way

	// Type 1 operation: ((num[0] op[0] num[1]) op[1] num[2]) op[2] num[3]
	// TO COMPLETE
	// If a solution exists, return 0;

	for (a=0;a<4;a++)
    {
        for (b=0;b<4;b++)
        {
            if (b!=a)
            {
                for (c=0;c<4;c++)
                {
                    if(c!=b&&c!=a)
                    {
                        for(d=0;d<4;d++)
                        {
                            if (d!=a && d!=b && d!=c)
                            {
                                for (i=1;i<5;i++)
                                {
                                    for (j=1;j<5;j++)
                                    {
                                        for (k=1;k<5;k++)
                                        {
                                            if (TwentyFour::Ope(k,TwentyFour::Ope(j,TwentyFour::Ope(i,num[a],num[b]),num[c]),num[d])==24)
                                                return 1;
                                            if (TwentyFour::Ope(j,TwentyFour::Ope(i,num[a],num[b]),TwentyFour::Ope(k,num[c],num[d]))==24)
                                                return 2;
                                        }
                                    }

                                }



                            }
                        }
                    }
                }
            }
        }


    }

	// Type 2 operation: (num[0] op[0] num[1]) op[1] (num[2] op[2] num[3])
	// TO COMPLETE
	// If a solution exists, return 0;

	return 0;
}

int TwentyFour::ShowResult()
{
	int aaa=SearchOp();
	if (aaa==0){
		cout << "No solution exists for " << num[0] << " " << num[1] << " " << num[2] << " " << num[3] << "!" << endl;
		return 1;
	}
	else {if (aaa==1)
    {
        cout << "((("<<num[a];
        switch(i)
        {
            case 1: cout<<"+"<<num[b]<<")";
            case 2: cout<<"-"<<num[b]<<")";
            case 3: cout<<"*"<<num[b]<<")";
            case 4: cout<<"/"<<num[b]<<")";
        }
        switch(j)
        {
            case 1: cout<<"+"<<num[c]<<")";
            case 2: cout<<"-"<<num[c]<<")";
            case 3: cout<<"*"<<num[c]<<")";
            case 4: cout<<"/"<<num[c]<<")";
        }
        switch(k)
        {
            case 1: cout<<"+"<<num[d]<<")";
            case 2: cout<<"-"<<num[d]<<")";
            case 3: cout<<"*"<<num[d]<<")";
            case 4: cout<<"/"<<num[d]<<")";
        }
        cout<<endl;
    }
    else
    {
           cout << "(("<<num[a];
        switch(i)
        {
            case 1: cout<<"+"<<num[b]<<")";
            case 2: cout<<"-"<<num[b]<<")";
            case 3: cout<<"*"<<num[b]<<")";
            case 4: cout<<"/"<<num[b]<<")";
        }
        switch(j)
        {
            case 1: cout<<"+"<<"("<<num[c];
            case 2: cout<<"-"<<"("<<num[c];
            case 3: cout<<"*"<<"("<<num[c];
            case 4: cout<<"/"<<"("<<num[c];
        }
        switch(k)
        {
            case 1: cout<<"+"<<num[d]<<"))";
            case 2: cout<<"-"<<num[d]<<"))";
            case 3: cout<<"*"<<num[d]<<"))";
            case 4: cout<<"/"<<num[d]<<"))";
        }
        cout<<endl;
    }
	}


	// Otherwise, print the solution
	// TO COMPLETE

	return 0;
}

