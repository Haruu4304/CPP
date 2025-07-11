/*
Next Greater element - 
using stack we can solve this problem with O(n) tc.
how this 
current element kisi past element ka next greater element ho sakta hai.
*/

#include<bits/stdc++.h>
using namespace std;

//here we are dealing with indices not with values 
vector<int> NGE(vector <int> v){
    stack<int> st;
    vector<int> nge(v.size());
    for(int i=0; i<v.size(); ++i){
        while(!st.empty() && v[i] > v[st.top()]){
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()){
        nge[st.top()] = -1;
        st.pop();
    }
    return nge;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    vector <int> nge = NGE(v);

    for(int i=0; i<n; i++){
        cout << v[i] << " " << (v[nge[i]]) <<endl;
    }
}