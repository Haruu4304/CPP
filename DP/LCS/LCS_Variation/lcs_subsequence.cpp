/*
This is exactly same as LCS Questions-
just the small difference is that ke waha pe hume length return karna tha aur yaha pe hume string 
*/

#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> t;

//print the LCS 
string PrintLCS(string a , string b , int m , int n){
    int i = m;
    int j = n;
    string s = "";

    while(i>0 && j>0){//dono mai sey koi empty nahi hota tab tk loop chalavo
        if(a[i-1] == b[j-1]){
            s.push_back(a[i-1]);
            i--;
            j--;
        }else{
            if(t[i][j-1] > t[i-1][j]){
                j--;
            }else{
                i--;
            }
        }
    }
    reverse(s.begin() , s.end());
    return s;
}

void LCS(string a , string b , int m , int n){
    vector<char> result;
    //fill the middle values - 
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(a[i-1] == b[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
            }else{
                t[i][j] = max(t[i][j-1] , 
                                t[i-1][j]);
            }
        }
    }
}

int main(){
    string a = "acbcf";
    string b = "abcdaf";
    int m = a.size();
    int n = b.size();
    t.assign(m+1 , vector<int>(n+1 , 0));

    LCS(a , b , m , n);

    cout << "Result : "<< PrintLCS(a , b , m , n);
}