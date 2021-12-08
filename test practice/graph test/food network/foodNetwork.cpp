

#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include <utility>
#include <vector>
using namespace std;

#define pb push_back
#define mp make_pair
#define rr return 0
#define ll long long
typedef pair<int,int> pii;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define judge(expression){ if(expression){ cout<<"YES\n"; }else{ cout<<"NO\n"; } }
#define getLetters(s,vec){for(int i=0; i< (int)s.length(); i++){  if(s[i]>='a' && s[i]<='z') vec.pb(s[i]);}}
#define getDigits(s,vec){for(int i=0; i< (int)s.length(); i++){  if(s[i]>='0' && s[i]<='9') vec.pb(s[i]-'0');}}
#define printVec(vec){cout<<"["; for(int i=0; i<(int)vec.size();i++){ cout<<vec[i]<<", "; } cout<<"]";}
#define printPairs(vec){cout<<"["; for(pair<int,int> n:nums){  cout<<"("<<n.first<<", "<<n.second<<")";}cout<<"]\n";}
#define prtset(n) {cout<<"["; for(auto i:n) cout<<i<<" "; cout<<"]\n";}

/*14. Biologists often construct a food network of species in an ecosystem. The
vertices represent species, and a directed edge (u, v) means species u eats
species v. An apex species is one that is not eaten by another species.
Suppose you are give a list of all possible “eating” relationships (so a list
of “u eats v”). Determine all apex species.*/


void q14(string listOfRelations){
    vector<string>animals;
    set<string>isEaten;

    istringstream listOfRelationsISS(listOfRelations);
    string animal1, middle, animal2;
    while(listOfRelationsISS>>animal1>>middle>>animal2){
        animals.pb(animal1);
        animals.pb(animal2);

        isEaten.insert(animal2);
    }
    
    cout<<"Apex Preditors: ";

    for(string cur : animals){
        if(isEaten.find(cur) == isEaten.end()){
            //not found, so is apex
            cout<<cur<<" ";
        }
    }


