#include <iostream>
#include <string>
#include <map>

using namespace std;

// Function to get response from the chatbot
string getResponse(const string& userQuery) {
    // Define some basic responses
    map<string, string> responses = {
        {"hi", "Hello! How can I assist you today?"},
        {"how are you", "I'm just a chatbot, but thanks for asking! How can I help you?"},
        {"bye", "Goodbye! Have a great day!"},
        {"screen", "The screen warranty is only 6 months."},
        {"battery", "The battery warranty is 1 year."},
        {"camera", "The camera warranty is 6 months."},
        {"ram", "The RAM warranty is 1 year."},
        {"sim", "The SIM card warranty is not provided."}
    };

    // Check if user query exists in responses
    auto it = responses.find(userQuery);
    if (it != responses.end()) {
        return it->second;
    } else {
        // Check if the user query contains specific keywords
        if (userQuery.find("screen") != string::npos) {
            return "The screen warranty is only 6 months.";
        } else if (userQuery.find("battery") != string::npos) {
            return "The battery warranty is 1 year.";
        } else if (userQuery.find("camera") != string::npos) {
            return "The camera warranty is 6 months.";
        } else if (userQuery.find("ram") != string::npos) {
            return "The RAM warranty is 1 year.";
        } else if (userQuery.find("sim") != string::npos) {
            return "The SIM card warranty is not provided.";
        } else {
            return "Sorry, I didn't understand your query. Could you please rephrase?";
        }
    }
}

int main() {
    cout << "Welcome to Customer Care Chatbot" << endl;
    cout << "You can start chatting. Type 'bye' to exit." << endl;

    string userQuery;
    while (true) {
        cout << "User: ";
        getline(cin, userQuery);

        if (userQuery == "bye") {
            cout << "Chatbot: Goodbye! Have a great day!" << endl;
            break;
        }

        string response = getResponse(userQuery);
        cout << "Chatbot: " << response << endl;
    }

    return 0;
}

