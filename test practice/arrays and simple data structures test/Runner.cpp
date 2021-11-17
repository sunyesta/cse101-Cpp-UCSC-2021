#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iterator>
#include <limits>
#include <math.h>
#include <tuple>
#include <locale>
#include <string>
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

#define isEqual(v1, v2){ return (v1.size() == v2.size() &&std::equal(v1.begin(), v1.end(), v2.begin()));}




//HELPERS

vector<vector<int>> generateKsortedArrs(int k, int len){
  vector<vector<int>>Arrs;
  
  cout<<"generated arrays:"<<endl;
  for(int arr=0; arr<k; arr++){
    vector<int>A;
    for(int i=0; i<len; i++){
      A.pb(rand() % 100 + 1);
    }
    
    sort(all(A));
    prtset(A);

    Arrs.pb(A);
  }

  cout<<endl;
  
  return Arrs;
}


//O(A*B)
vector<int> merge2SortedArrs(vector<int>A, vector<int>B){
  int ia=0, ib=0;

  vector<int>AB;
  

  while(ia<A.size() || ib<B.size()){
    
    if(ia>=A.size()){
      AB.pb(B[ib]);
      ib++;
    }else if(ib>=A.size()){
      AB.pb(A[ia]);
      ia++;
    }else if(A[ia]<B[ib]){
      AB.pb(A[ia]);
      ia++;
    }else{
      AB.pb(B[ib]);
      ib++;
    }
  }

  return AB;
}

void performInsert(vector<int>&AB,int i, vector<int>&A, int &ia){
  AB[i]=A[ia];
  ia++;
}

/*
   1. Given an integer x and an array of numbers, find if two numbers in the
array sum up to x. (Or, find the pair of numbers whose sum is closest to
x.)
  */

//running time: O(n^2)


int getDist(pii p, int x){
  return abs(p.first+p.second-x);
}

void ArrQ1(int x, vector<int>arr){
  //store the pair that makes up the closest sum
  pii closest = make_pair(arr[0], arr[1]);
  
  //itterate through all the combos
  for(int i=0; i<arr.size(); i++){
    for(int j=i+1; j<arr.size(); j++){
      pii newPair = make_pair(arr[i], arr[j]);
      
      //if a combo is closer, update `closest`
      if(getDist(newPair,x)<getDist(closest,x)){
        closest = newPair;
      }

    }
  }

}



/*
 2. Given two sorted arrays, find the median of the union of elements.

 https://leetcode.com/problems/median-of-two-sorted-arrays/
  */

//running time: O(A*B)
ll findMedianSortedArrays(vector<int>& A, vector<int>& B){
  //combine arrays
  vector<int>AB = merge2SortedArrs(A, B);//O(A*B)


  
  //if even size return the average of the 2 vals in the middle, else return middle
  if(AB.size()%2==0){
    int first = AB[AB.size()/2 - 1];
    int second =  AB[AB.size()/2];
    return (first+second)/2;
  }else{
    return AB[AB.size()/2];
  }
}


/*
 3. Given two sorted arrays, find the kth smallest element in the union of
elements.
 */

/*
 * 1)
 */
//running time O(A*B)
void arr3(vector<int>& A, vector<int>& B, int k){
  //combine arrays
  vector<int>AB = merge2SortedArrs(A, B);//O(A*B)


  
  cout<<AB[k];
}



/*5. We discussed in class how to merge two sorted array. What about merging
k sorted arrays?*/

vector<int> mergek(vector<vector<int>>arrs){
  vector<int>in(arrs.size()); //the current next index for every array
  
  vector<int>mergedArr;

  while(true){

    //find min next element and insert it to mergedArr
    int min_i=-1;
    
    for(int i=0; i<arrs.size(); i++){
      int curNextIndex = in[i];
      int minNextIndex = in[min_i];
      
      if(curNextIndex>=arrs[i].size()){
        continue;
      }

      if(min_i ==-1 || arrs[i][curNextIndex]<arrs[min_i][minNextIndex]){
        min_i=i;
      }
    }
    
    if(min_i==-1){
      //all arrays have been completley traversed
      break;
    }

    //perform insertion
    mergedArr.pb(arrs[min_i][in[min_i]]);
    in[min_i]++;
  }

  return mergedArr;
  
}


/*6. You have an unsorted array of integers where every integer appears exactly
twice, except one integer that appears once. Find it.*/

int arrQ6(vector<int>A){
  vector<int>count(A.size());

  for(int i=0; i<A.size(); i++){
    count[A[i]]++;
  }
  for(int i=0; i<count.size(); i++){
    if(count[i]==1){
      return i;
    }
  }

  return -1;
}

//TODO
/*7. Given an array, describe an algorithm to identify the contiguous) subarray
with the maximum sum. For example, if the input is [1, −3, 5, −2, 9, −8, −6, 4],
the output should be [5, −2, 9].*/


vector<int> arrQ7(vector<int>arr){
  int maxSoFar = arr[0], maxEndingHere = arr[0];
  int maxSoFarStart = 0, maxSoFarEnd = 0;
  int curStart = 0;

  //itterate over array
  for(int i=0; i<arr.size(); i++){
    
    //if current val is greater than sum, replace the maxEndingHere
    if(maxEndingHere+arr[i]<arr[i]){
      maxEndingHere = arr[i];
      curStart = i;
    }else{
      maxEndingHere += arr[i];
    }
    
    //if current max is greater than total max, update it
    if(maxEndingHere>maxSoFar){
      maxSoFar=maxEndingHere;
      maxSoFarStart=curStart;
      maxSoFarEnd = i;
    }
  }
  
  vector<int>newArr;
  for(int i=maxSoFarStart; i<=maxSoFarEnd; i++){
    newArr.pb(arr[i]);
  }
  
  prtset(newArr);
  cout<<"total = "<<maxSoFar<<endl;

  return newArr;
}

/*8. Given an array A of numbers, for every index i, find the nearest index
j such that A[j] > A[i]. If none exist, report −1. Output these indices
sorted by the corresponding i.*/

//9 sort it?

//10 sort it?
//11 sort and get middle
//12 sort and count
//13 sort and check
//14 try all combos
//15  ?
//16 try all combos and see if any combos have all 3 same
//17 go along the arrays until you find 2 that don't match
//18 get difference of everything and get smallest
//19 check all pts except front and end
//20 same as last but tweaked
//21 have 2 pointer go at different speeds. If 1 ptr = other then loop
//22: https://stackoverflow.com/questions/1536944/detecting-the-start-of-a-loop-in-a-singly-linked-link-list
//23: for every day, check if price ever lowers after. If it does, buy, else don't buy.sell all when price rises
//24: find biggest price increase after stock day
//25: ?
//26: ?
//27 check each one
//28: count them or binary search: https://www.techiedelight.com/find-first-or-last-occurrence-of-a-given-number-sorted-array/
//29: ?
//----------------------------------------------------------

int main() {
  
    
  vector<int>A = {4, 1, 5, 7,3,2,1 };

  arrQ7(A);

  return 0;
}
