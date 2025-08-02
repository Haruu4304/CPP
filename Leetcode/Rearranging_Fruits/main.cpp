/*
You have two fruit baskets containing n fruits each. You are given two 0-indexed integer arrays basket1 
and basket2 representing the cost of fruit in each basket. You want to make both baskets equal. To do so, 
you can use the following operation as many times as you want:

Chose two indices i and j, and swap the ith fruit of basket1 with the jth fruit of basket2.
The cost of the swap is min(basket1[i],basket2[j]).
Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same 
baskets.

Return the minimum cost to make both the baskets equal or -1 if impossible.
*/

#include<bits/stdc++.h>
using namespace std;

int BalanceBasket(vector<int> basket1, vector<int> basket2){
    //step 1 : create 1 map from basket 1 add it and from baskter substract it
    unordered_map<int , int> mp;
    int minElem = INT_MAX;
    for(auto &val : basket1){
        mp[val]++;
        minElem = min(minElem, val); //to get minimum cost
    }
    for(auto &val : basket2){ //here we will got the extra elements present among the both of them
        mp[val]--;
        minElem = min(minElem, val);
    }

    //step 2 : store the result in one vector- 
    vector<int> finalList;
    for(auto &val : mp){
        int cost = val.first;
        int count = val.second;

        if(count == 0){
            continue;
        }

        if(count % 2 != 0){
            return -1;
        }

        for(int c=1; c<=abs(count/2); c++){
            finalList.push_back(count);
        }
    }

    //step 3 : sort the vector
    //sort(begin(finalList), end(finalList)); //no need to sort entire array
    nth_element(begin(finalList), begin(finalList)+finalList.size()/2 , end(finalList));

    long long result = 0;
    for(int i=0; i<finalList.size()/2; ++i){
        result += min(finalList[i] , minElem*2);
    }

    return result;
    
}

int main(){
    vector<int> B1 = {4 , 2 ,2 ,2};
    vector<int> B2 = {1 , 4 ,1 , 2};

    int result = BalanceBasket(B1, B2);
}