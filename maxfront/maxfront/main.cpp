
#include <iostream>
using namespace std;
int main(){
    int n, a[1000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    
    int x = a[0], ind = 0;
    for(int i=1; i<n; i++)
    {
        if(x < a[i])
        {
            x = a[i];
            ind = i;
        }
    }
    
    int temp = a[0];
    a[0] = a[ind];
    a[ind] = temp;
    
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
