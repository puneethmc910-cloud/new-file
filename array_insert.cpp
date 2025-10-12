#include<iostream>
using namespace std;
int main()
{
    int n=6;
    int arr[n]={1,2,3,4,5};
    int pos;
    int num;
    cout<<"before adding num:";
    for(int i=0;i<n;i++)
    {
        cout<<"\narray elemet "<<i<<" : "<<arr[i];
    }
    cout<<"\nenter the number inserted to array:";
    cin>>num;
    cout<<"\nenter the position(1-7):";
    cin>>pos;
    for(int i=n-1;i>=pos-1;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos-1]=num;
    n++;
    cout<<"\n after adding num:";
    for(int i=0;i<n;i++)
    {
        cout<<"\narray elemet "<<i<<" : "<<arr[i];
    }
    return 0;
}