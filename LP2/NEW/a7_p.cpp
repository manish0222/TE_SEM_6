#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
class CB{
public:
    map<string,map<string,string>> mp;
    CB(){
        //remember all comma separated
        mp["camera"]= {{"size", "36 MP"}, {"price", "$500"},{"camera","A device to click photo"}};
        mp["mobile"]= {{"size", "128 MB"}, {"price", "$800"},{"mobile","A device to talk to people"}};
        mp["cc"]={{"context","NONE"}};
    }
    void chat(string userinput){
        cout<<"CHATBOT : ";
        for(auto pair:mp){
            if(userinput.find(pair.first)!=string::npos){
                mp["cc"]=pair.second;
                mp["cc"]["context"] = pair.first; //assign context
                if(userinput.find("size")!=string::npos){
                    cout<<"size of "<<pair.first<<" "<<pair.second.at("size")<<endl;
                }
                else if(userinput.find("price")!=string::npos){
                    cout<<"size of "<<pair.first<<" "<<pair.second.at("price")<<endl;
                }
                else if(userinput.find(pair.first)!=string::npos){
                    cout<<pair.second.at(pair.first)<<endl;
                }
                else cout<<"DIDNOT GET IT "<<endl;
                return; 
            }
        }
        if(mp["cc"]["context"]!="NONE"){
                string ans=mp["cc"]["context"];
                if(userinput.find("size")!=string::npos){
                    cout<<"size of "<<ans<<" "<<mp["cc"]["size"]<<endl;
                }
                else if(userinput.find("price")!=string::npos){
                    cout<<"size of "<<ans<<" "<<mp["cc"]["price"]<<endl;
                }
                else if(userinput.find(ans)!=string::npos){
                    cout<<mp["cc"][ans]<<endl;
                }
                else cout<<"DIDNOT GET IT "<<endl;
        }
        else cout<<"DIDNOT GET IT "<<endl;
    }
};
int main() {
    string input;
    CB obj;
    while(true){
        cout<<"USER: ";
        getline(cin,input);
        if(input=="bye"){ cout<<"THANKS \n";break;};
        obj.chat(input);
    }
    return 0;
}