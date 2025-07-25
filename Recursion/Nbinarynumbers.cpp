/*
Question - 
Print N binary numbers having more 1's than 0's using prefix - 
condition - 
1's >= 0's
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int ones, int zeros, int n, string op){
    if(n == 0){
        cout << op << endl;
        return;
    }

    string op1 = op;
    op1.push_back('1');
    solve(ones + 1, zeros , n-1, op1);

    if(ones > zeros){
        string op2 = op;
        op2.push_back('0');
        solve(ones, zeros+1, n-1 , op2);
    }
    return;
}


int main(){
    int N;
    cin >> N;
    int ones = 0;
    int zeros = 0;
    string op = "";
    solve(ones, zeros , N , op);
}