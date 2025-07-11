/*
if ( open bracket came then push inside the stack and if ) closing bracket came then pop from the stack 
this is our logic.
*/

#include<bits/stdc++.h>
using namespace std;

unordered_map<char, int> symbols = {{'(' , -1}, {'[',-2},{'{',-3},{')' , 1}, {']',2},{'}',3}};
string isBalanced(string s){
    stack<char> st;
    for(char bracket : s){
        if(symbols[bracket] < 0){
            st.push(bracket);
        }else{
            if(st.empty()){
                return "No";
            }
            char top = st.top();
            st.pop();
            if(symbols[top] + symbols[bracket] !=0){
                return "No";
            }
        }
    }
    if(st.empty()){
        return "Yes";
    }else{
        return "No";
    }
}


int main(){
    int t;
    cin >> t;
    while(t--){
        string x;
        cin >> x;
        string value = isBalanced(x);
        cout << value << endl;
    }
}