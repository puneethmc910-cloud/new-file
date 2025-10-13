#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n =5;
    int arr[n]={1,23,0,-2,2};
      cout<<"\n before oder:";
    for(int k=0;k<n;k++)
    {
        cout<<"\n array elemt "<<k<<" : "<<arr[k];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            
            while(arr[i]<arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }
    }
    cout<<"\n after oder:";
    for(int k=0;k<n;k++)
    {
        cout<<"\n array elemt "<<k<<" : "<<arr[k];
    }
    

    return 0;
}