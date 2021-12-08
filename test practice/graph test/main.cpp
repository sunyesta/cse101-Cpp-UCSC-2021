#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include <utility>



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

#define isEqual(v1, v2){ return (v1.size() == v2.size() &&std::equal(v1.begin(), v1.end(), v2.begin()));}



int main(){
    //q13("0 0 22 0 8 0 0 0 0 0 26 0 0 0 0 0 4 0 7 29 9 0 0 0 0 0 1 0 0 0");

}
