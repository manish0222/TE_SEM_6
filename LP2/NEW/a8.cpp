#include <iostream>
#include <bits/stdc++.h>
#include <cstdlib> 
using namespace std;

vector<string> symptoms = {"Fever", "Cough", "Headache", "Sore throat"};

unordered_map<string, vector<string>> diseases = {
    {"Common Cold", {"Fever", "Cough", "Headache", "Sore throat"}},
    {"Flu", {"Fever", "Cough", "Headache"}},
    {"Strep Throat", {"Fever", "Sore throat"}},
    {"Migraine", {"Headache"}}
};

unordered_map<string, vector<string>> medicines = {
    {"Common Cold", {"Acetaminophen", "Ibuprofen", "Cough syrup"}},
    {"Flu", {"Antiviral medication", "Acetaminophen", "Cough syrup"}},
    {"Strep Throat", {"Antibiotics", "Pain relievers", "Throat lozenges"}},
    {"Migraine", {"Sumatriptan", "Ibuprofen", "Acetaminophen"}}
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
    
    for (const string& symptom : user_symptoms) {
        for (auto& disease_entry : diseases) {
            const string& disease = disease_entry.first;
            const vector<string>& causes = disease_entry.second;
            if (find(causes.begin(), causes.end(), symptom) != causes.end()) {
                possible_diseases.insert(disease);
            }
        }
    }
    
    if (!possible_diseases.empty()) {
        cout << "Possible diseases:" << endl;
        for (const string& disease_name : possible_diseases) {
            cout << "- " << disease_name << " ";
        }cout<<endl;
        
        cout << "Recommended medicines:" << endl;
        for (const string& disease_name : possible_diseases) {
            cout << disease_name << ": ";
            const vector<string>& recommended_medicines = medicines[disease_name];
            int t=(rand())%3;
            // for (const string& medicine : recommended_medicines) {
            //     cout << "- " << medicine << endl;
            // }
            cout << "- " << recommended_medicines[t]<<" ";
            cout << endl;
        }
    } else {
        cout << "No matching diseases found." << endl;
    }
}

int main() {
    diagnose();
    return 0;
}