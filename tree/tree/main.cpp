#include <iostream>
#include <vector>
using namespace std;
class Node{
public:
    Node *parent;
    vector < Node* > children;
    string key;
    Node(){
        parent=NULL;
    }
};
class tree{
public:
    int c;
    bool k;
    Node *root1;
    int index;
    int one,two;
    tree(){
        c=0;
        k=false;
        one=0;
        two=0;
    }
    vector < Node* > root;
    Node* find_index(Node *cur,string key){
        if(cur==NULL){
            return NULL;
        }
        if(cur->key==key){
            return cur;
        }
        else{
            Node *tmp=NULL;
            for(int i=0;i<cur->children.size();i++){
                tmp=find_index(cur->children[i],key);
                if(tmp!=NULL){
                    return tmp;
                }
            }
        }
        return NULL;
    }
    void  add(string father,string son){
        Node *papa;
        if(root.size()==0){
            Node *f=new Node;
            f->key=father;
            root.push_back(f);
        }
        for(int i=0;i<root.size();i++)
        {
            papa=find_index(root[i],father);
            if(papa!=NULL){
                break;
            }
        }
        Node *syn=new Node();
        syn->key=son;
        if(papa==NULL){
            papa=new Node();
            papa->key=father;
            root.push_back(papa);
        }
        for(int i=0;i<root.size();i++){
            if(root[i]->key==syn->key){
                k=true;
                index=i;
                break;
            }
        }
        if(k==false){
            papa->children.push_back(syn);
            syn->parent=papa;
        }
        else{
            papa->children.push_back(root[index]);
            root[index]->parent=papa;
        }
    }
    Node* common(){
        for(int i=0;i<root.size();i++){
            for(int j=0;j<root.size();j++){
                if(find_index(root[i],root[j]->key)!=NULL && i!=j){
                    c++;
                }
            }
            if(c==root.size()-1){
                root1=root[i];
                index=i;
            }
            c=0;
        }
        return root1;
    }
    void print(Node *cur){
        cout<<cur->key<<" ";
        if(cur->children.empty()){
            return;
        }
        for(int i=0;i<cur->children.size();i++){
            print(cur->children[i]);
        }
    }
    void first(string s1,string t1){
        Node *s=find_index(common(),s1);
        Node *t=find_index(common(),t1);
        while(s->parent!=t->parent){
            s->parent=s->parent->parent;
            one++;
            while(t->parent!=NULL){
                t->parent=t->parent->parent;
                two++;
                if(s->parent==t->parent){
                    break;
                }
            }
        }
        cout<<s->parent->key<<endl;
        if(one==0 && two ==0){
            cout<<"They have one common ancestor"<<" "<<s->parent->key<<",he is father of"<<" "<<s1<<" "<<"and father of"<<" "<<t1;
        }
        if(one==0 && two>0){
            cout<<"They have one common ancestor"<<" "<<s->parent->key<<",he is father of"<<" "<<s1<<" "<<"and he is"<<" ";
            if(two==1){
                cout<<"grandfather of"<<" "<<t1;
            }
            else if(two>1){
                cout<<"great-grandfather of"<<" "<<t1;
            }
            
        }
        if(one>0 && two==0){
            cout<<"They have one common ancestor"<<" "<<s->parent->key<<", he is father of"<<" "<<t1<<" "<<"and he is"<<" ";
            if(one==1){
                cout<<"grandfather of"<<" "<<s1;
            }
            else if(one>1){
                cout<<"great-grandfather of"<<" "<<s1;
            }
            
        }
        if(one!=0 && two!=0){
            cout<<"They have one common ancestor"<<" "<<s->parent->key<<",he is"<<" ";
            if(one==1){
                cout<<"grandfather of"<<" "<<s1<<" ";
            }
            else if(one>1){
                cout<<"great-grandfather of"<<" "<<s1<<" ";
            }
            cout<<"and"<<" ";
            if(two==1){
                cout<<"grandfather of"<<" "<<t1;
            }
            else if(two>1){
                cout<<"great-grandfather of"<<" "<<t1;
            }
            
            
        }
        
        
    }
    
    void second(string s){
        Node *cur=find_index(common(),s);
        for(int i=0;i<cur->children.size();i++){
            cout<<cur->children[i]->key<<" ";	
        }	
    }
    void secondforthird(Node *cur){
        for(int i=0;i<cur->children.size();i++){
            cout<<cur->children[i]->key<<" ";	
        }	
    }
    void third(string s){
        Node *cur=find_index(common(),s);
        for(int i=0;i<cur->children.size();i++){
            secondforthird(cur->children[i]);		
        }	
    }
};   

int main(){
    tree *tr=new tree();
    tr->add("Alibek","Ali");
    tr->add("Alibek","Vali");
    tr->add("Ali","IbnAli");
    tr->add("Ivan","Alexey");
    tr->add("Alexey","Alexandr");
    tr->add("Ivan","Alibaba");
    tr->add("Alibaba","Alibek");
    tr->second("Ivan");
    cout<<endl;
    tr->second("Alibek");
    cout<<endl;
    tr->third("Ivan");
    cout<<endl;
    tr->first("Alexandr","Vali");	
    
}
