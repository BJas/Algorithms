//
//  main.cpp
//  bfs
//
//  Created by Apple on 02.11.15.
//  Copyright © 2015 Apple. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
struct Node{
    string name;
    vector <Node> children;
};

void bfs(Node root){
    cout<<root.name;
    
    vector <Node> v = root.children;
    vector <Node> v1;
    
    while(v.size() != 0)
    {
        v1.clear();
        for(int i=0; i<v.size(); i++)
        {
            cout<<v[i].name;
            for(int j=0; j< v[i].name.length(); j++)
            {
                v1.push_back(v[i].children[j]);
            }
        }
        v.clear();
        v = v1;
    }
}
int main(){
    int n;
    cin>>n;
    int a[1000];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    
    return 0;
}
