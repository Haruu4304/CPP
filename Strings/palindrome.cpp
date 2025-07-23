#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s){
    int left = 0;
    int right = s.length()-1;
    while(left < right){
        if(s[left] != s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}


int main(){
    string s = "mam";
    cout << checkPalindrome(s) << endl;

}