/*
Simple Basic Recusion problems - 
*/

#include<bits/stdc++.h>
using namespace std;

/*
1. print 1 to n with recursion - 
*/

// int print(int n){
//     if(n == 1){
//         return 0;
//     }
//     print(n-1);
//     cout << n << endl;
// }

/*
2. print n to 1 with recursion - 
*/

// int print(int n){
//     if(n==1){     //base condition
//         return 0;
//     }
//        cout << n << endl;
//     print(n-1);
// }

/*
3. factorial with recursion - 
bc = if(n==1)
hypothesis -> fact(n) * fact(n-1);
induction -> cout << n
*/

int fact(int n){
    if(n==0 || n==1){
        return 1;
    }
    return n * fact(n-1);
}

int main(){
    int n;
    cin >> n;
    int value = fact(n);
    cout << "Result" << endl;
    cout << value << endl;
    return 0;
}