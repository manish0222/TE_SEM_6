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