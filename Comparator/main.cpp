/*
Comparator - it is used to define your custom sorting algorithm - 
in inbuilt sort func - what it says : 
should_i_swap - agar karna hai toh tum mujhe false return kar do agar nahi karna hai toh
    tum mujhe true return kar do 
*/

#include<bits/stdc++.h>
using namespace std;

//this is comparator -
bool should_i_swap(pair<int , int> a , pair<int, int>b){
    if(a.first != b.first){
        // if(a.first > b.first){
        //     return false;               this is very confusing right
        // }return true;

        return a.first < b.first;
    }else{
        // if(a.second < b.second){
        //     return false;
        // }return true;

        return a.second > b.second;
    }
}

int main(){
    int n;
    cin >> n;
    vector<pair<int, int >> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i].first >> a[i].second;
    }

    //basic sorting algo
    // for(int i=0; i<n; i++){
    //     for(int j=i+1; j<n; j++){
    //         if(should_i_swap(a[i],a[j])){
    //             swap(a[i] , a[j]);
    //         }
    //     }
    // }

    //we can use the our sort inbuilt function also
    //we have already learn that sort take 2 parameter but here we can also pass comparator as 3rd eleme
    
    sort(a.begin(), a.end() , should_i_swap);

    cout << "Displaying the result" << endl;
    for(int i=0; i<n; i++){
        cout << a[i].first << " " << a[i].second << endl;
    }
}