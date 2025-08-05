/*
fruits into basket part 2 
*/

#include<bits/stdc++.h>
using namespace std;

int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets){
    int rem = 0;
    for(int i=0; i<fruits.size(); ++i){
        bool assigned = false;
        for(int j=0; j<baskets.size(); ++j){
            if(fruits[i] <= baskets[j] && baskets[j] != 0){
                //occupied the basket of j
                baskets[j] = 0;
                assigned = true;
                break;
            }
        }

        if(assigned == false){
            rem++;
        }
    }
    return rem;
}

int main(){
    vector<int> fruits = {3,6,1};
    vector<int> baskets = {6,4,7};

    cout << numOfUnplacedFruits(fruits,baskets);
}