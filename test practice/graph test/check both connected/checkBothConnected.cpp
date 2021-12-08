#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include <utility>
#include <vector>


#include "SnakesAndLadders.h"
#include "foodNetwork.h"

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




/*17. You are given a directed, unweighted graph G representing the power
grid, as an adjacency list. Each vertex is a power station, and an edge
(u, v) means that power goes from u to v. A source vertex denotes a
power generator. A sink vertex denotes a power supplier, typically to a
neighborhood. Your job is to understand the robustness of the power grid,
under failure of a power station s. (Note that this may not be a source,
it could be some internal vertex.) If s fails, it stops transmitting power to
any of the outneighbors. This could potentially result in some sink node t
not receiving power at all, representing a power failure in a neighborhood.
Thus, a sink node t will not receive power if every path from every source
to t passes through the power station s. Design an algorithm that given
2
G and a vertex s, determines all the sink vertices t (if any) that stop
receiving power when s fails.*/

//A sink node is a node such that no edge emerges out of it.


void q18(){
    
}
