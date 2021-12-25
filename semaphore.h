int WRITE = 1;
int MUTEX = 1;

void wait(int& S) {
    while(S == 0);
    S --;
}

void signal(int& S) {
    S ++;
}
