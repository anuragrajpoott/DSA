#include<iostream>
#include<unordered_map>
using namespace std;

int main(){

    unordered_map<string,int> m;


    //one way
    pair<string,int> p = make_pair("babbar",1);
    m.insert(p);
    
    //two way
    pair<string,int> p2("love",2);
    m.insert(p2);

    //three way
    m["mera"] = 3; //creates new entry

    m["mera"]= 4;  //updates existing entry


    //searching
    cout<<m["mera"]<<endl; //finds corresponding if not creates

    cout<<m.at("love")<<endl; //finds entry at love

    cout<<m["null"]<<endl; //this creates since not there

    cout<<m.at("null")<<endl; //thus this is an error

    //size
    cout<<m.size()<<endl;

    //check existance or count
    cout<<m.count("love")<<endl;

    //delete
    cout<<m.erase("love")<<endl;

    //display
    //one way
    for(auto i: m){
        cout<<i.first<<"->"<<i.second<<endl;
    }
    //two way
    unordered_map<string,int> :: iterator i = m.begin();
    while(i!=m.end()){
        cout<<i->first<<"->"<<i->second<<endl;
        i++;
    }
}