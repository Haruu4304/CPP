/*
Porblem statement - 
Sort a Stack - 
*/

#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &ss, int temp){
    //base cond.
    if(ss.size() == 0 || ss.top() < temp){
        ss.push(temp);
        return;
    }

    //hypothesis - 
    int value = ss.top();
    ss.pop();
    insert(ss, temp);

    //induction - 
    ss.push(value);

    return;
}

//recursive call - 
void sortStack(stack<int> &ss){
    //base condition - 
    if(ss.size() == 1){
        return;
    }

    //hypothesis - 
    int value = ss.top();
    ss.pop();
    sortStack(ss);

    //induction - 
    insert(ss, value);
}


int main(){
    stack<int> ss;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int value;
        cin >> value;
        ss.push(value);
    }

    sortStack(ss);

    cout << "Result after sorting the stack - " << endl;
    while(!ss.empty()){
        cout << ss.top() << endl;
        ss.pop();
    }
}