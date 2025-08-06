/*
this is optimized version of fruits into basket of the previous one
the previous was O(n^2) tc 
*/

#include<bits/stdc++.h>
using namespace std;

int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets){
    //here we use multiset : because in any case their capacity will be dublicates
    multiset<int> new_baskets;
    for(int val : baskets){
        new_baskets.insert(val);
    }

    
    
    return rem;
}

int main(){
    vector<int> fruits = {4,2,5};
    vector<int> baskets = {3,5,4};

    int result = numOfUnplacedFruits(fruits, baskets);

    cout << "No. of unplaced fruits are : " << result << endl;
}