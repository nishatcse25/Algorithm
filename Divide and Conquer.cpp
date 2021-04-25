#include<iostream>
#include<algorithm>

using namespace std;

bool lowest_max(int bottle[],int p,int q,int mid)
{
    int total = 0;
    for (int i=0;i<p;i++)
    {
        total += bottle[i];
        if (total>mid)
        {
            total=0;
            q--;
            i--;
        }
        if (q==0)
        {
            return false;
        }
    }
    return true;
}

int binarysearch(int low,int high,int bottle[],int p,int q)
{
    if (low == high)
    {
        return low;
    }
    int mid = (low+high)/2;
    if (lowest_max(bottle,p,q,mid))
    {
        binarysearch(low,mid,bottle,p,q);
    }
    else
    {
        binarysearch(mid+1,high,bottle,p,q);
    }
}

int main()
{
int p,q;
cin>>p>>q;
int bottle[p],total=0;

for (int i=0;i<p;i++)
{
    cin>>bottle[i];
    total +=bottle[i];
}

int low =1,high =total;
int result =binarysearch(low,high,bottle,p,q);
cout<<result<<endl;
}



