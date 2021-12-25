#include <unistd.h>
#include <thread>
#include "readwrite.h"
#include "semaphore.h"
using namespace std;

enum processes {B, W, D};
const int NUM_THREADS = 10;
int processSequence[] = {W, B, B, D, B, W, W, B, D, D};

int readersCount = 0;
void reader() {
    wait(MUTEX);
    readersCount ++;
    if(readersCount == 1) {
        wait(WRITE);
    }

    cout << "BALANCE: " << endl;
    string data = read();
    cout << "Current Balance: " << data << endl;
    cout << endl;

    readersCount --;
    if(readersCount == 0) {
        signal(WRITE);
    }
    signal(MUTEX);
}

void writer() {
    wait(WRITE);
    write();
    cout << endl;
    signal(WRITE);
}

void withdrawer() {
    wait(WRITE);
    cout << "WITHDRAW: " << endl;
    withdraw();
    cout << endl;
    signal(WRITE);
}

void depositer() {
    wait(WRITE);
    cout << "DEPOSIT: " << endl;
    deposit();
    cout << endl;
    signal(WRITE);
}

int main() {

    writer();
    vector<thread> threads;

    try {
        for(int i = 0; i < NUM_THREADS; i++) {
            if(processSequence[i] == B) {
                threads.push_back(thread(reader));
            } else if (processSequence[i] == W){
                threads.push_back(thread(withdrawer));
            } else {
                threads.push_back(thread(depositer));
            }
        }
    } catch(...) {
        cout << "Something went wrong :/" << endl;
    }

    for(auto &th: threads) {
        th.join();
    }
    return 0;
}