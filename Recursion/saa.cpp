/*
Sort an array in recursion - 
*/

#include<bits/stdc++.h>
using namespace std;

//for induction method again we are doing recursion - 
void insert(vector<int> &v , int temp){
    //base condition - 
    if(v.size() == 0 || v[v.size()-1] < temp){
        v.push_back(temp);
        return ;
    }

    //hypothesis
    int val = v[v.size()-1];
    v.pop_back();
    insert(v, temp);

    //induction -
    v.push_back(val);

    return ;
} 


//recursive func call -
void sortVector(vector<int> &v1){
    //base condition -
    if(v1.size() == 1){
        return;
    }

    //hypothesis -
    int temp = v1[v1.size()-1]; 
    v1.pop_back();
    sortVector(v1);

    //induction method - 
    insert(v1, temp);
}


int main(){
    int n;
    cin >> n;
    vector<int> v1(n);
    for(int i=0; i<n; i++){
        cin >> v1[i];
    }

    sortVector(v1);

    //result - 
    for(int value : v1){
        cout << value << endl;
    }
}