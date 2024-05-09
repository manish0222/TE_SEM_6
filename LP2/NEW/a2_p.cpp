#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    vector<vector<int>> board;
    int f,g,h;
    Node(vector<vector<int>> b,int g,int h){
        this->board=b;
        this->g=g;
        this->h=h;
        this->f=this->g+this->h;
    }
};
//print the node
void printNode(Node* node){
    cout<<endl;
    for(auto i:node->board){
        for(auto j : i){
            cout<<j<<" ";
        }cout<<endl;
    }
    cout<<"F "<<node->f<<" G "<<node->g<<" H "<<node->h<<endl;
}
//string 
string getString(Node* node){
    string s="";
    for(auto i:node->board){
        for(auto j : i){
            s+=(to_string(j));
        }
    }
    return s;
}
int getH(vector<vector<int>> node, vector<vector<int>> goal){
    int h=0;
    for(int i=0;i<node.size();i++){
        for(int j=0;j<node.size();j++){
            if(node[i][j]!=0 and node[i][j]!=goal[i][j]) j++;
        }
    }
    return h;
}
vector<Node*> getNeighbour(Node* node,vector<vector<int>> goal){
    vector<Node*> neighbours;
    int dx[]={-1,1,0,0};
    int dy[]={0,0,1,-1};
    int bx=0,by=0;
    for(int i=0;i<node->board.size();i++){
        for(int j=0;j<node->board.size();j++){
            if(node->board[i][j]==0){
                bx=i;by=j;break;
            }
        }
    }
    for(int i=0;i<4;i++){
        int newX = bx+dx[i];
        int newY = by+dy[i];
        if(newX>=0 and newX<=2 and newY<3 and newY>=0){
            vector<vector<int>> new_board=node->board;
            swap(new_board[bx][by],new_board[newX][newY]);
            neighbours.push_back(new Node(new_board,node->g+1,getH(new_board,goal)));
        } 
    }
    return neighbours;
}
bool isgoal(vector<vector<int>> node, vector<vector<int>> goal){
    return node==goal;
}
void solve(vector<vector<int>> node, vector<vector<int>> goal){
    Node* sn=new Node(node,0,getH(node,goal));
    priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>> pq;
    pq.push({sn->f,sn});
    map<Node*,bool> visit;
    while(!pq.empty()){
        auto tp=pq.top();
        pq.pop();
        Node* curr=tp.second;
        printNode(curr);
        if(isgoal(curr->board,goal)){
            cout<<"Goal reached "<<curr->g<<endl;
            return;
        }

        visit[curr]=1;
        vector<Node*> neighbour=getNeighbour(curr,goal);
        for(auto neib:neighbour){
            cout<<getString(neib)<<" ";
             cout<<"F "<<neib->f<<" G "<<neib->g<<" H "<<neib->h<<endl;
             if(!visit[neib]){
                pq.push({neib->f,neib});
             }
        }
        cout<<endl;
    }

    cout<<"NO solution exists";
}
int main(){
    Node *start=new Node({{1,2,3},{0,4,6},{7,5,8}},0,0);
    Node *end=new Node({{1,2,3},{4,5,6},{7,8,0}},0,0);
    solve(start->board,end->board);
    return 0;
}
/*
#include <bits/stdc++.h>
#include <string>
using namespace std;
class Node{
public:
    vector<vector<int>> board;
    int f,g,h;
    Node(vector<vector<int>> b,int g,int h){
        board=b;
        this->g=g;
        this->h=h;
        this->f=this->g+this->h;
    }
};
string tostring(Node* node){
    string s="";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            s+=(to_string(node->board[i][j]));
        }
    }
    return s;
}
void print(Node* node){
    cout<<endl;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<node->board[i][j]<<" ";
        }cout<<endl;
    }
    cout<<"F "<<node->f<<" G "<<node->g<<" H "<<node->h<<endl;
}
bool isgoal(vector<vector<int>> node,vector<vector<int>> g){
    return node==g;
}
int getH(vector<vector<int>> nb,vector<vector<int>> goal){
    int h=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(nb[i][j]!=0 and nb[i][j]!=goal[i][j]) h++;
        }
    }
    return h;
}
vector<Node*> getNeigbours(Node* node,vector<vector<int>> goal){
    int bx,by;
    vector<Node*> arr;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(node->board[i][j]==0){
                bx=i;
                by=j;
                break;
            }
        }
    }
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    for(int i=0;i<4;i++){
        int nx=bx+dx[i];
        int ny=by+dy[i];//imp
        if(nx>=0 && ny>=0 && nx<3 && ny<3){
            vector<vector<int>> nb=node->board;
            swap(nb[bx][by],nb[nx][ny]);
            arr.push_back(new Node(nb,node->g+1,getH(nb,goal)));
        }
    }
    return arr;
}

void solve(vector<vector<int>> board,vector<vector<int>> goal){
    Node* start=new Node(board,0,getH(board,goal));
    priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>> p;
    map<Node*,bool> visit;
    p.push({start->f,start});//imp
    while(p.empty()==false){
        Node* tp=p.top().second;
        p.pop();
        print(tp);//imp
        if(isgoal(tp->board,goal)){
            cout<<"Done \n";
            return;
        }
        visit[tp]=1;  //imp
        vector<Node*> neigh=getNeigbours(tp,goal);
        for(auto neib:neigh){
            cout<<tostring(neib)<<" ";
            cout<<"F "<<neib->f<<" G "<<neib->g<<" H "<<neib->h<<endl;
            if(!visit[neib]){
                p.push({neib->f,neib});  //imp
            }
        }
    }
    cout<<"No sol ";
    return;
}
int main() {
    Node *start=new Node({{1,2,3},{4,6,0},{7,5,8}},0,0);
    Node *end=new Node({{1,2,3},{4,5,6},{0,7,8}},0,0);
    solve(start->board,end->board);
    return 0;
}
*/