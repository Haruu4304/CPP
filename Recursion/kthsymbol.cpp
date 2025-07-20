/*
Kth symbol in grammer using recursion - 
*/

#include<bits/stdc++.h>
using namespace std;

int Kthsymbol(int N, int K){
    //base condition - 
    if(N==1 && K==1){
        return 0;
    }

    int mid = pow(2,N-1)/2;

    if(K <= mid){
        return Kthsymbol(N-1 , K);
    }else{
        return !Kthsymbol(N-1 , K-mid);
    }
}

int main(){
    int N, K;
    cin >> N >> K;
    int result = Kthsymbol(N,K);
    cout << "Result it : " << result << endl;
}