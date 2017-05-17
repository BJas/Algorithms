#include <iostream>
#include <stack>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;
int main()
{
    int n;
    cout<<"The number of vertices: ";
    cin>>n;
    int m;
    cout<<"The number of edges: ";
    cin>>m;
    int a, b;
    vector <int> r[1000];
    for(int i=0; i<m; i++)
    {
        cin>>a>>b;
        r[a].push_back(b);
        r[b].push_back(a);
    }
    int x, y;
    cout<<"Vertices: ";
    cin>>x>>y;
    for(int i=0; i<r[x].size(); i++)
    {
        if(r[x][i] == y)
        {
            cout<<"Connected"<<endl;
            break;
        }
        if(i == r[x].size()-1)
            cout<<"Not Connected"<<endl;
    }
    
    cout<<"Input ";
    cin>>x;
    cout<<"The "<<r[x].size()<<endl;
    cout<<"Input ";
    cin>>x;
    for(int i=0; i<r[x].size(); i++)
    {
            if(i == r[x].size()-1)
                cout<<r[x][i];
            else
            cout<<r[x][i]<<", ";
        
    }
    cout<<endl;
    cout<<"Inputs ";
    cin>>x>>y;
    
    bool q = true;
    for(int i=0; i<r[x].size(); i++)
    {
        for(int j=0; j<r[y].size(); j++)
        {
            if(r[x][i] == r[y][j])
            {
                cout<<r[x][i]<<" ";
                q = false;
            }
        }
    }
    if(q == true)
        cout<<"there is no common vertices";
    return 0;
}