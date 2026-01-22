
#include <iostream>

using namespace std;







int main()
{
    int a[10]={1,3,57,54,61,17,8,9,10},m=-1,k=-1;
    int temp;
    for(int i=0;i<10;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    // for(int i=0;i<10;i++)
    // {
        
    //     if(m<a[i])
    //     {   k=m;
    //         m=a[i];
            
    //     }
    // }
    // cout<<m<<" "<<k;
}