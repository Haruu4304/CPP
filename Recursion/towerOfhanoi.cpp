/*
Tower of hanoi problem using recursion - 
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int n, int s, int d, int h){
    if(n == 1){
        cout << "Moving plates from source to destination " << endl;
        return;
    }

    solve(n-1, s , h , d);
    cout << "moving n-1 plates from source to helper" << endl;

    cout << "moving 1 plate from source to destination" << endl;

    solve(n-1, h , d , s);
    cout << "moving plates from helper to destination" << endl;
    return;
}


int main(){
    int n; //no of plates
    cin >> n;

    //create 3 tower
    int s = 1;
    int h = 2;
    int d = 3;

    solve(n,s,d,h);
}