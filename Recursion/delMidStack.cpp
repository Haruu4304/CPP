/*
Delete an middle element from stack - 
*/

#include<bits/stdc++.h>
using namespace std;

//recursive call - 
void DelMidElement(stack<int> &ss, int k){
    //base condition - 
    if(k == 1){
        ss.pop();
        return;
    }

    //hypothesis - 
    int temp = ss.top();
    ss.pop();
    DelMidElement(ss, k-1);
    
    //induction method - 
    ss.push(temp);
    return;
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
    int k = 0;
    k = ss.size()/2 + 1;
    DelMidElement(ss,k);

    cout << "Result after deleting a middle element - " << endl;
    while(!ss.empty()){
        cout << ss.top() << endl;
        ss.pop();
    }
}