//
//  main.cpp
//  gen_tree
//
//  Created by Apple on 04.12.15.
//  Copyright © 2015 Apple. All rights reserved.
//

#include<iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;
#define pb push_back
#define mp make_pair

class Graph{
    int V;
    list<int> *adj;
    void func1(int v, bool used[]);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
    void BFS(int v);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].pb(w);
}
void Graph::func1(int v, bool used[])
{
    used[v] = true;
    cout<<v<<" ";
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!used[*i])
            func1(*i, used);
}
void Graph::DFS(int v)
{
    bool *used = new bool[V];
    for (int i = 0; i < V; i++)
        used[i] = false;
    func1(v, used);
}

void Graph::BFS(int s)
{
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    
    list<int> queue;
    
    visited[s] = true;
    queue.push_back(s);
    
    list<int>::iterator i;
    
    while(!queue.empty())
    {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        
        for(i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if(!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
    Graph g(10);
    string str;
    vector<pair<string, int> > children;
    int n, i = 0, j = 1, count = 0;
    cout<<"Vertex: ";
    cin>>n;
    while (n != 0){
        cout<<"Father: ";
        string s;
        cin>>s;
        if (count<1)
            children.pb(mp(s, 0));
        cout<<"Sons: ";
        while (str != "End"){
            cin>>str;
            if (str != "End"){
                children.pb(mp(str, j));
                g.addEdge(i, j);
                j++;
            }
            else i++;
        }
        str = "";
        n--;
        count++;
    }
    cout<<endl;
    cout<<"DFS \n";
    g.DFS(0);
    cout<<endl;
    cout<<"BFS \n";
    g.BFS(0);
    return 0;
}