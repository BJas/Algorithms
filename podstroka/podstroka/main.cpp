//
//  main.cpp
//  podstroka
//
//  Created by Apple on 26.10.15.
//  Copyright © 2015 Apple. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;
int p[50001];
void prefix(string str, string t)
{
    p[0] = -1;
    int x;
    for(int i=1; i<str.length(); i++)
    {
        x = p[i-1];
        while(str[x+1] != str[i] && x >= 0)
        {
            x = p[x];
        
        }
        if(str[x+1] == str[i])
            x++;
        
        
        p[i] = x;
    }
    
    for(int i=0; i<str.length(); i++)
    {
        if(p[i]+1 == t.length())
            cout<<i-2*t.length()<<" "; //i-(t.length-1)-(t.length+1)
    }
}

int main(){
    string s, t;
    cin>>s>>t;
    string str = t+"$"+s;
    prefix(str, t);
    
    return 0;
}
