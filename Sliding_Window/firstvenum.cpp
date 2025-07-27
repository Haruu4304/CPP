/*
Problem statement - 
first negative number in every window size of k.
return 0 if no negative number is present in that window size.
*/

#include<bits/stdc++.h>
using namespace std;

void FirstNegativeNumber(vector<int> &v, int n, int k) {
    int i=0,j=0;
    list<int> negative;
    while(j < n){
        if(v[j] < 0){
            negative.push_back(v[j]);
        }
        if(j-i+1 < k){
            j++;
        }else if(j-i+1 == k){
            if(negative.size() == 0){
                cout << "0";
            }else{
                cout << negative.front() << endl;
                if(v[i] == negative.front()){
                    negative.pop_front();
                }
            }   
            i++;
            j++;
        }
    }
}


int main(){
    vector<int> v;
    int n, k;
    cin >> n >> k;
    cout << "now enter the elements of the array" << endl;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    FirstNegativeNumber(v, n, k);
}