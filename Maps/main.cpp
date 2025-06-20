// maps in cpp of stl 
// it is a data structure which is used to store the value in a form of key and value pair.
// here the key are remain unique, and by using these keys we can perform different operations over the data/
// values.
// map it is used to create mapping between the value.
// so the normal map it is used to stroe the elements in a ascending order based on the keys it uses red 
// black tree.
// but the unordered map are used to store the elements as they are given.
// every element of map is pair.
// it is a pair of key and value.
// map it is non-contigenous order.

//how it is actually works ? in behind
// jab hum koi naya element ya pair daalne ka try karte hai toh woh humsha compare hota hai uske existing pairs ke sath
// for ex., hum log abhi 9 daal rahe hai toh woh pehle compare hoga 1, 3 and 5 and 4 ke sath aur
// uske sahi jagah pe jaake baith jayega

// ab agar mera jo map hai woh string type ka hai - map<string,string> m;
// aisa hai toh yaha jo tc hai O(log(n)) ye change ho jayega kyuki hum log yaha pe ek string ko compare 
// karte hai isliye
// toh string ke waqt tc -> s.size() * log(n)


#include <bits/stdc++.h>
using namespace std;

void printMap(map<int,string> m){
    cout << "Size of map : " << m.size() << endl;
    for(auto &value : m){
        cout << value.first << " " << value.second << endl; //tc -> O(log(n))
    }
}

int main(){
    map<int,string> m;
    m[1] = "abc"; //tc -> O(log(n)) here n is current size of map
    m[5] = "cdc";
    m[3] = "acd";
    //another method to insert the map
    m.insert({4, "afg"});
    printMap(m);

    //some functions on map -
    //map.find() -> it is used to find the value of given key.
    //it returns one iterator -
    //if any value is not present on that index/key 
    // then it simply returns m.end()
    auto it = m.find(3); //tc -> O(log(n))
    if(it == m.end()){
        cout << "The given key is not present in map" << endl;
    }else{
        cout << it->first << " " << it->second << endl;
    }

    //2nd function - erase:
    //erase -> it is used to erase the value.
    // tc -> O(log(n))
    //it takes 2 types of input - i) directly key and ii)iterator input
    //first method using key 
    m.erase(3); 
    //using iterator - 
    auto it = m.find(5);
    if(it != m.end()){
        m.erase(it); //log(n)
    }

    m.clear(); // it works in all container
    printMap(m);

    printMap(m);
}