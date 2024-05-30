#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib>
#include <string>
using namespace std;
vector<string> symptoms={"flu","cough","sore-throught","headache"};
map<string,vector<string>> dies={
    {"fever",{"flu","cough","sore throught"}},
    {"migrane",{"headache"}},
    {"strep throught",{"sore-throught","cough"}},
    {"cold",{"flu","cough"}}
};
map<string,vector<string>> meds={
    {"fever",{"paracetomol","antobiotics","crocin"}},
    {"migrane",{"crocin","mig-relief"}},
    {"strep throught",{"coughsyrup","kofol","ORS"}},
    {"cold",{"vicks","coughsyrup"}}
};
vector<string> getsymp(string s){
    vector<string> v;
    for(auto i:symptoms){
        if(s.find(i)!=string::npos){
            v.push_back(i);
        }
    }
    return v;
}
void getmedicine(set<string>& v){
    for(auto i:v){
        vector<string> arr=meds[i];
        int t=(rand()%2);
        cout<<i<<" take "<<arr[t]<<endl; 
    }
}
void solve(string s){
    cout<<"BOT : ";
    vector<string> usymp=getsymp(s);
    set<string> probdie;
    for(auto sym:usymp){
        for(auto i:dies){
            string diesease=i.first;
            vector<string> t=i.second;
            if(find(t.begin(),t.end(),sym)!=t.end()){
                probdie.insert(diesease);
            }
        }
    }
    cout<<"Probable dieseases ";
    for(auto i:probdie) cout<<i<<" ";
    cout<<endl;
    getmedicine(probdie);
}
int main() {
    string s;
    while(1){
        cout<<"USER : ";
        getline(cin,s);
        if(s=="bye" ) break;
        solve(s);
    }
    return 0;
}