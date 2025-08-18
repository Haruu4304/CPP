/*
24 game problem - Recursion + backtracking 
*/

#include<bits/stdc++.h>
using namespace std;

double eps = 0.1; //epsilion value

bool solve(vector<double> &cards){
    if(cards.size() == 1){
        return abs(cards[0] - 24) <= eps; //return true we got 24 so some of matching of 24
    }

    //pick only 2 values at a time for operations
    for(int i=0; i<cards.size(); i++){
        for(int j=0; j<cards.size(); j++){
            if(i == j){ //if you are getting the same value then just ignore itt
                continue;
            }
            vector<double> temp;
            for(int k=0; k<cards.size(); k++){
                if(k != i && k != j){
                    temp.push_back(cards[k]); //remaining elements which are not selected - 
                }
            }

            double a = cards[i];
            double b = cards[j];

            vector<double> possibleval = {a+b, a-b, b-a , a*b};
            if(abs(b) > 0.0){
                possibleval.push_back(a/b);
            }
            if(abs(a) > 0.0){ 
                possibleval.push_back(b/a);
            }

            for(double val : possibleval){ 
                temp.push_back(val);//Do
                if(solve(temp) == true){ //explore
                    return true;
                }else{
                    temp.pop_back(); //undo
                }
            }
        }
    }

    return false;
}

bool judgePoint24(vector<int>& cards){
    vector<double> nums;
    for(int i=0; i<cards.size(); i++){
        nums.push_back(1.0 * cards[i]); //1.0 becuase to convert tha int to double
    }

    return solve(nums); //recusion function call
}

int main(){
    vector<int> cards = {8,1,4,7};

    cout << "Result : "  << judgePoint24(cards) << endl;
}