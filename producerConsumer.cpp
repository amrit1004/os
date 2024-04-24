#include<iostream>
#include<algorithm>
using namespace std;
int mutex = 1 ,full = 0 , empty = 4;
int wait(int &s){
    while(s<=0){
        return --s;
    }
}
int signal (int &s){
    return ++s;
}
void producer(){
    empty = wait(empty);
    mutex = wait(mutex);
    cout << "Item Produced\n";
    mutex = signal(mutex);
    full = signal(full);
}   
void consumer(){
    full = wait(full);
    mutex = wait(mutex);
    cout << "Item consumed\n";
    mutex = signal(mutex);
    empty = signal(empty);
}   

int main(){
    producer();
    producer();
    producer();
    producer();
    producer();
    producer();
    consumer();
}