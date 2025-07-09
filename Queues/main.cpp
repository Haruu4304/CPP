/*
Queue it follows fifo order
here operations are done - i)push (enqueue) at the end
                           ii)pop(dequeue) front element
                           iii)front - front element value
if you are trying to remove the element then first element
will be removed first
*/

/* performing queue basic operations - 
Queue overflow - when the queue size is full still trying to push
Queue underflow - when the queue is empty and still tring to pop
*/

#include<bits/stdc++.h>
using namespace std;

void enqueue(queue<string> &q, string x, int size){
    if(q.size() >= size){
        cout << "Queue is Full!!!" << endl;
    }
    q.push(x);
}

void dequeue(queue<string> &q){
    if(q.empty()){
        cout << "Queue is empty!!!" << endl;
    }
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;

}

int main(){
    queue<string> q;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string x;
        cout << "enter the string you want to insert/push in queue" << endl;
        cin >> x;
        enqueue(q, x , n);
    }

    if(!q.empty()){
        cout << q.front() << endl;
    }

    //dequeue - 
    dequeue(q);

    return 0;
}