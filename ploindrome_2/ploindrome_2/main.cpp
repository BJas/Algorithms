#include <iostream>
#include <stack>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;
long long k, k1, d2[200000], d1[200000];
long long l=0, r = -1, l1 = 0, r1 = -1;
long long func(string s){
    long long n = s.length();
    long long sum1 = 0;
    long long sum  = 0;
    for(long long i = 0; i < n; i++){
        if(i > r)
            k = 0;
        else
            k = min(d2[l + r - i + 1], r - i + 1);
        
        while(i + k < n && i - k - 1 >= 0 && s[i+k] == s[i - k - 1])
            k++;
        d2[i] = k;
        
        sum = sum + d2[i];
        
        if(i + k - 1 > r)
        {
            l = i - k;
            r = i + k - 1;
        }
        
        
        if(i > r1)
            k1 = 1;
        else
            k1 = min(d1[l1 + r1 - i], r1 - i);
        
        while(0 <= i-k1 && i+k1 < n && s[i - k1] == s[i + k1])
            k1++;
        d1[i] = k1;
        
        sum1 = sum1 + d1[i];
        if(i + k1 - 1 > r1)
        {
            r1 = i + k1 - 1;
            l1 = i - k1 + 1;
        }
    }
    return sum1+sum;
}
int main()
{
    string str;
    cin>>str;
    
    cout<<func(str);
    return 0;
}