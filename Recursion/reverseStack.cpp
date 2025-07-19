#include<bits/stdc++.h>
using namespace std;

void insert(stack<int> &ss, int temp){
    if(ss.empty()){
        ss.push(temp);
        return;
    }

    int value = ss.top();
    ss.pop();
    insert(ss, temp);
    ss.push(value);
}

void reverseStack(stack<int> &ss){
    if(ss.size() == 1){
        return;
    }

    int temp = ss.top();
    ss.pop();
    reverseStack(ss);
    insert(ss, temp);
}

int main(){
    stack<int> ss;
    int n;
    cin >> n;
    vector<int> arr(n);
    
    // Read input normally
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // Push in reverse order so 1 is on top and 5 is on bottom
    for(int i = n - 1; i >= 0; i--){
        ss.push(arr[i]);
    }

    reverseStack(ss);

    cout << "after reversing a stack - "<< endl;
    while(!ss.empty()){
        cout << ss.top() << endl;
        ss.pop();
    }
}
