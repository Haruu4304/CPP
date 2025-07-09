/*Given N strings, print unique strings in lexigraphical order 
N <= 10^5
S <= 10000
*/

#include<bits/stdc++.h>
using namespace std;

void printSet(set<string> &s){
    for(auto string : s){
        cout << string << endl;
    }
}

int main(){
    set<string> s;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        string x;
        cin >> x;
        s.insert(x);
    }

    printSet(s);
}