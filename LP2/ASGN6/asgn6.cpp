#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

vector<string> symptoms = {"Fever", "Cough", "Headache", "Sore throat"};

unordered_map<string, vector<string>> diseases = {
    {"Common Cold", {"Fever", "Cough", "Headache", "Sore throat"}},
    {"Flu", {"Fever", "Cough", "Headache"}},
    {"Strep Throat", {"Fever", "Sore throat"}},
    {"Migraine", {"Headache"}}
};

vector<string> get_user_input() {
    vector<string> user_symptoms;
    for (const string& symptom : symptoms) {
        char response;
        cout << "Do you have " << symptom << "? (y/n): ";
        cin >> response;
        if (response == 'y' || response == 'Y') {
            user_symptoms.push_back(symptom);
        }
    }
    return user_symptoms;
}

void diagnose() {
    vector<string> user_symptoms = get_user_input();
    set<string> possible_diseases;
    
    for(int i=0;i<user_symptoms.size();i++){
        string symptom=user_symptoms[i];
        for(auto i:diseases){
            string d=i.first;
            vector<string> cause=i.second;
            if(find(cause.begin(),cause.end(),symptom)!=cause.end()){
                possible_diseases.insert(d);
            }
        }
    }
    // for (const auto& disease : diseases) {
    //     const string& disease_name = disease.first;
    //     const vector<string>& symptoms = disease.second;
    //     for (const string& symptom : symptoms) {
    //         if (find(user_symptoms.begin(), user_symptoms.end(), symptom) != user_symptoms.end()) {
    //             possible_diseases.push_back(disease_name);
    //             break;
    //         }
    //     }
    // }

    if (!possible_diseases.empty()) {
        cout << "Possible diseases:" << endl;
        for (const string& disease_name : possible_diseases) {
            cout << "- " << disease_name << endl;
        }
    } else {
        cout << "No matching diseases found." << endl;
    }
}

int main() {
    diagnose();
    return 0;
}
