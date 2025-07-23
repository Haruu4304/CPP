/*
Question - 
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing 
all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include 
letters and numbers.

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
*/
#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s){
    int left = 0;
    int right = s.length()-1;
    while(left < right){
        while(left < right && !isalnum(s[left])){
            left++;
        }
        while(left < right && !isalnum(s[right])){
            right--;
        }

        // comaprre
        if(tolower(s[left]) != tolower(s[right])){
            cout << "false" << endl;
            return false;
        }
        left++;
        right--;
    }
    cout << "true" << endl;
    return true;
}

int main(){
    string s;
    getline(cin, s);

    checkPalindrome(s);
}