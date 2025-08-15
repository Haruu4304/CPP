/*
Power of 4 - check karo
*/
#include<bits/stdc++.h>
using namespace std;
//recursive approah -> tc => O(log n)
bool isPowerOfFour(int n){
    if(n <= 0){ //odd condition
        return false;
    }else if(n == 1){ 
        return true;
    }else if(n/4 == 1 && n%4 == 0){ //main logic of 4 
        return true;
    }else if(n%4 != 0){
        return false;
    }else{
        return isPowerOfFour(n/4);
    }
}

//Loop Approact -> tc => O(log n)
//space complexity -> O(1)
bool isPowerOfFourLoop(int n){
    //negative + 0 condition
    if(n <= 0){
        return false;
    }
    while(n % 4 == 0){
        n /= 4;
    }
    return n == 1 ? true : false;
}

int main(){
    int n;
    cin >> n;
    cout << isPowerOfFour(n) << endl;
}