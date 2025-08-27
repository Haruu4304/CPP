#include<bits/stdc++.h>
using namespace std;

int areaOfMaxDiagonal(vector<vector<int>> dimensions){
    double maxDiagonal = 0;   // should be double
    int maxArea = 0;

    for(int i=0; i<dimensions.size(); i++){
        int length = dimensions[i][0];
        int width = dimensions[i][1];
        double diagonal = sqrt((length*length) + (width*width));
        int area = length * width;

        if(diagonal > maxDiagonal){
            maxDiagonal = diagonal;
            maxArea = area;
        }else if(fabs(diagonal - maxDiagonal) < 1e-9){ // compare doubles safely
            maxArea = max(maxArea, area);
        }
    }
    return maxArea;
}

int main(){
    vector<vector<int>> dimensions = {{10,3} , {5,9} , {8,3}};
    cout << areaOfMaxDiagonal(dimensions);
}