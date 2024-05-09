#include <iostream>
#include <string>
#include <map>

using namespace std;

class CustomerServiceChatbot {
private:
    map<string, map<string, string>> context; // Map to store context

public:
    CustomerServiceChatbot() {
        // Initialize context with default values
        context["camera"] = {{"size", "36 MP"}, {"price", "$500"},{"camera","A device to click photo"}};
        context["screen"] = {{"size", "6.5 inches"}, {"price", "$200"},{"screen","A screen for displaying content"}};
        context["sim"] = {{"size", "Nano-SIM"}, {"price", "$20"},{"sim","A subscriber identity module (SIM) for network connectivity"}};
        context["ram"] = {{"size", "8 GB"}, {"price", "$100"},{"ram","Random access memory (RAM) for running applications"}};
        context["memory"] = {{"size", "128 GB"}, {"price", "$50"},{"memory","Internal storage memory for storing data and apps"}};
        context["battery"] = {{"size", "4000 mAh"}, {"price", "$80"},{"battery","A rechargeable battery for powering the device"}};
        context["current_context"] = {{"context", "None"}}; // Initialize current context to None
    }
    void handleUserInput(const string& userInput) {  

        // Check if user input contains a keyword from context
        for (const auto& pair : context) {
            if (userInput.find(pair.first) != string::npos) {
                // Update current context
                context["current_context"] = pair.second;
                context["current_context"]["context"]= pair.first;
                // Provide response based on context
                cout << "Chatbot: ";
                if (userInput.find("size") != string::npos) {
                    cout << "Size of " << pair.first << " is " << pair.second.at("size") << "." << endl;
                } else if (userInput.find("price") != string::npos) {
                    cout << "Price of " << pair.first << " is " << pair.second.at("price") << "." << endl;
                } else if (userInput.find(pair.first) != string::npos) {
                    cout << pair.second.at(pair.first) << endl;
                }
                 else {
                    cout << "I'm sorry, I didn't understand your query. Could you please rephrase?" << endl;
                }
                return;
            }
        }

        // If no context matches, use previously stored context
                // If no context matches, use previously stored context
        if (context["current_context"]["context"] != "None") {
            cout << "Chatbot: ";
            if (userInput.find("size") != string::npos) {
                auto it = context["current_context"].find("size");
                if (it != context["current_context"].end()) {
                    cout << "Size of " << context["current_context"]["context"] << " is " 
                         << it->second << "." << endl;
                } else {
                    cout << "Size information not available." << endl;
                }
            } else if (userInput.find("price") != string::npos) {
                auto it = context["current_context"].find("price");
                if (it != context["current_context"].end()) {
                    cout << "Price of " << context["current_context"]["context"] << " is " 
                         << it->second << "." << endl;
                } else {
                    cout << "Price information not available." << endl;
                }
            } else if (userInput.find(context["current_context"]["context"]) != string::npos) {
                auto it = context["current_context"].find(context["current_context"]["context"]);
                if (it != context["current_context"].end()) {
                    cout << it->second << endl;
                } else {
                    cout << "Information not available." << endl;
                }
            } else {
                cout << "I'm sorry, I didn't understand your query. Could you please rephrase?" << endl;
            }
        } else {
            cout << "Chatbot: I'm sorry, I didn't understand your query. Could you please provide more context?" << endl;
        }
    }
};

int main() {
    CustomerServiceChatbot chatbot;

    cout << "Welcome to Customer Service Chatbot" << endl;
    cout << "You can start chatting. Type 'bye' to exit." << endl;

    string userInput;
    while (true) {
        cout << "User: ";
        getline(cin, userInput);

        if (userInput == "bye") {
            cout << "Chatbot: Goodbye! Have a great day!" << endl;
            break;
        }

        chatbot.handleUserInput(userInput);
    }

    return 0;
}
/*
// Online C++ compiler to run C++ program online
#include <map>
#include <iostream>
#include <string>
using namespace std;
class CB{
public:
    map<string,map<string,string>> mp;
    CB(){
        mp["mobile"]={{"price","50$"},{"size","128gb"},{"mobile","talking material"}};
        mp["camera"]={{"price","30$"},{"size","32gb"},{"camera","Capture photo"}};
        mp["currcont"]={{"context","NONE"}};
    }
    void chat(const string &input){
        for(const auto& pair : mp){
            if(input.find(pair.first) != std::string::npos){
                mp["currcont"]=pair.second;
                mp["currcont"]["context"]=pair.first;
                cout<<"chatbot: ";
                if(input.find("price")!=string::npos){
                    cout<<"price of "<<pair.first<<" is "<<pair.second.at("price")<<endl;
                }
                else if(input.find("size")!=string::npos){
                    cout<<"size of "<<pair.first<<" is "<<pair.second.at("size")<<endl;
                }
                else if(input.find(pair.first)!=string::npos){
                    cout<<pair.second.at(pair.first)<<endl;
                }
                else cout<<"CY rephrase"<<endl;
                return;
            }
            
        }
        if(mp["currcont"]["context"]!="NONE"){
            if(input.find("price")!=string::npos){
                    cout<<"price of "<<mp["currcont"]["context"]<<" is "<<mp["currcont"]["price"]<<endl;
                }
                else if(input.find("size")!=string::npos){
                    cout<<"size of "<<mp["currcont"]["context"]<<" is "<<mp["currcont"]["size"]<<endl;
                }
                else if(input.find(mp["currcont"]["context"])!=string::npos){
                    cout<<mp["currcont"][mp["currcont"]["context"]]<<endl;
                }
                else cout<<"CY rephrase"<<endl;
        }
        else cout<<"CY rephrase"<<endl;
    }
};
int main() {
    string input;
    CB obj;
    while(true){
        cout<<"USER: ";
        getline(cin,input);
        if(input=="bye"){ cout<<"THAKS \n";break;};
        obj.chat(input);
    }

    return 0;
}
*/