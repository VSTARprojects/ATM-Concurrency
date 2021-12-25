#include <bits/stdc++.h>
using namespace std;

string read() {
    ifstream sharedFile;
    try {
        sharedFile.open("data.txt", ios :: in);
        if(!sharedFile) throw "Couldn't open the file";
    } catch(string message) {
         cerr << message << endl;
    }
    string data;
    sharedFile >> data;
    sharedFile.close();
    return data;
}

void write(){
    ofstream sharedFile;
    try{
        sharedFile.open("data.txt", ios :: out);
        if(!sharedFile) throw "Couldn't open the file";
    } catch(string message) {
        cerr << message << endl;
    }
    string data;
    cout << "Enter the initial balance:";
    cin >> data;
    sharedFile << data;
    sharedFile.close();
    cout << "Initial Balance: " << data << endl;
}

void withdraw() {
    int balance = stoi(read());

    ofstream sharedFile;
    try{
        sharedFile.open("data.txt", ios :: out);
        if(!sharedFile) throw "Couldn't open the file";
    } catch(string message) {
        cerr << message << endl;
    }
    int amount;
    cout << "Enter the amount to be withdrawn:";
    cin >> amount;

    

    if(amount > balance) {
        cerr << "Insuffient Balance" << endl;
        return;
    }

    balance -= amount;

    sharedFile << to_string(balance);
    sharedFile.close();
    cout << "Balance Remaining: " << balance << endl;
}

void deposit() {
    int balance = stoi(read());
    ofstream sharedFile;
    try{
        sharedFile.open("data.txt", ios :: out);
        if(!sharedFile) throw "Couldn't open the file";
    } catch(string message) {
        cerr << message << endl;
    }
    int amount;
    cout << "Enter the amount to be deposited:";
    cin >> amount;

    balance += amount;

    sharedFile << to_string(balance);
    sharedFile.close();
    cout << "Balance Remaining: " << balance << endl;
}