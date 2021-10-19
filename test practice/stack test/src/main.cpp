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

class AnagramObj
{
    public:
        string input;
        int swapIndex;
        AnagramObj(string input, int swapIndex){
            this->input = input;
            this->swapIndex = swapIndex;
        }
};


//----------------------List all anagrams-----------------------//
/*
 *An anagram of a string is just a
 *permutation of the string. You must write a function that produces all anagrams
 *of the input string in a list. The order does not matter. For example, if the
 *input string was “abc”, the function should output a list containing the following
 *strings: abc, acb, bac, bca, cab, cba
 *
 */

void listAllAnagramsStack(string thisInput){
    
    stack<AnagramObj>recurStack;
    recurStack.push(AnagramObj(thisInput,0));

    while(!recurStack.empty()){
        AnagramObj stackTop = recurStack.top();
        recurStack.pop();
        
        if(stackTop.swapIndex<stackTop.input.length()-1){
        
            for(int i=stackTop.swapIndex; i<stackTop.input.length(); i++){
                string newString = stackTop.input;
                
                //swap newString[swapIndex] and newString[i]
                char temp = newString[stackTop.swapIndex];
                newString[stackTop.swapIndex] = newString[i];
                newString[i] = temp;
                
                recurStack.push(AnagramObj(newString,stackTop.swapIndex+1));
            }
        }else{
            cout<<stackTop.input<<endl;
            continue;
        }
    
    }
}



void listAllAnagramsRecursive(string input, int swapIndex){
    //while the swap index is 
    if(swapIndex<input.length()-1){
    
        for(int i=swapIndex; i<input.length(); i++){
            string newString = input;
            
            //swap newString[swapIndex] and newString[i]
            char temp = newString[swapIndex];
            newString[swapIndex] = newString[i];
            newString[i] = temp;
                
            listAllAnagramsRecursive(newString,swapIndex+1);
        }
    }else{
        cout<<input<<endl;
    }
}

void listAllAnagramsRecursive(string input){
    listAllAnagramsRecursive(input,0);
}


//----------------------language-----------------------//
/*
You will see a lot about languages when you study Computational Models. Just think of the input string
1
as a set of characters Σ (formally called an alphabet). The language generated
by Σ is the set of all strings comprising of characters (symbols) in Σ. This
function generates a list of all strings in the language, whose length is at most
k. Note that empty string is also part of the language. The order of the list
does not matter. For example, if the input is “abc” and k = 2, then the output
list has the following strings: (the empty string), a, b, c, aa, bb, cc, ab, ac, ba,
bc, ca, cb. You can assume that input does not have repeated characters.
*/
void languageRecursive(string input, int k, string curSubString){
    if(curSubString.length()==k){
        cout<<curSubString<<" ";
        return;
    }

    cout<<curSubString<<" ";
    for(int i=0; i<input.length(); i++){
        languageRecursive(input, k, curSubString+input[i]);
    }
}

void languageRecursive(string input, int k){
    languageRecursive(input,k,"");
}


class languageStackObj{
    public:
        string curSubString;
        languageStackObj(string curSubString){
            this->curSubString = curSubString;
        }
};

void languageStack(string input, int k){
    stack<class languageStackObj>recurStack;
    recurStack.push(languageStackObj(""));

    while(recurStack.empty()==false){
        languageStackObj stackTop = recurStack.top();
        recurStack.pop();

        if(stackTop.curSubString.length()==k){
            cout<<stackTop.curSubString<<" ";
            continue;
        }

        cout<<stackTop.curSubString<<" ";
        for(int i=0; i<input.length(); i++){
            recurStack.push(languageStackObj(stackTop.curSubString+input[i]));
        }
    
    }
}


//----------------------stretch-----------------------//
/*
 A stretch of the input string is
generated by repeating each character in order up to k times (and at least once).
For input string “abc” and k = 2, the output list should have: abc, aabc, abbc,
abcc, aabbc, aabcc, abbcc, aabbcc. (Again, the order does not matter.)
*/
void stretchRecursive(int k, string str1, string str2){
    //once str1 is empty, that means str2 is complete
    if(str1.length()==0){
        cout<<str1<<"  "<<str2<<endl;
        return;
    }
    
    //rip off the first char of str1 so that we can append it to str2 later
    char taken = str1[0];   
    str1 = str1.substr(1,str1.length());
    
    //create branches in the recursive function for each repetition
    //EX. ab abb abbb for k=3
    for(int i=0; i<k; i++){
        str2+=taken;
        stretchRecursive(k, str1, str2);
    }
}

void stretchRecursive(string input, int amount){
    stretchRecursive(amount,input,"");
}



class StretchStackObj{
    public:
        string str1;
        string str2;
        StretchStackObj(string str1, string str2){
            this->str1 = str1;
            this->str2 = str2;
        }
};

void stretchStack(string input, int k){
    stack<class StretchStackObj>recurStack;
    recurStack.push(StretchStackObj(input,""));
    
    while(!recurStack.empty()){
        StretchStackObj stackTop = recurStack.top();
        recurStack.pop();

        if(stackTop.str1.length()==0){
            cout<<stackTop.str1<<"  "<<stackTop.str2<<endl;
            continue;
        }

        char taken = stackTop.str1[0];   

        stackTop.str1 = stackTop.str1.substr(1,stackTop.str1.length());
        
        
        for(int i=0; i<k; i++){
            stackTop.str2+=taken;
            recurStack.push(StretchStackObj(stackTop.str1, stackTop.str2));
        }
    
    }
}


//----------------------bubbling-----------------------//
/*
 A bubbling of the input string
is generated as follows. Iterate over every index (except the last index) of the
string: in the ith iteration, you can swap the ith and (i + 1)th characters. (You
can also choose to not swap.) Any sequence of such swaps leads to a string,
called a bubbling of the original string. For example, suppose the input string
is “abc”. Here are the bubblings: abc, acb, bac, bca. (These were achieved,
respectively, by: no swaps at all, no swap and swap, swap and no swap, swap
and swap.) The order of the output does not matter.
*/
void bubblingRecursive(string str1, string str2){
    //once str1 is empty, that means str2 is complete
    if(str1.length()==0){
        cout<<str2<<endl;
        return;
    }
    
    //rip off the first char of str1 so that we can append it to str2 later
    char taken = str1[str1.length()-1];   
    str1.pop_back();
    
    bubblingRecursive(str1, str2+taken);

    //only create the second branch if str2 isn't empty or else you will get
    //""+a and a+"" which creates the same output
    if(str2.length()>0){
        bubblingRecursive(str1, taken+str2);
    }
}

void bubblingRecursive(string input){
    bubblingRecursive(input,"");
}



class BubblingStackObj{
    public:
        string str1;
        string str2;
        BubblingStackObj(string str1, string str2){
            this->str1 = str1;
            this->str2 = str2;
        }
};

void bubblingStack(string input){
    stack<class BubblingStackObj>recurStack;
    recurStack.push(BubblingStackObj(input, ""));
    
    while(!recurStack.empty()){
        BubblingStackObj stackTop = recurStack.top();
        recurStack.pop();

        //once str1 is empty, that means str2 is complete
        if(stackTop.str1.length()==0){
            cout<<stackTop.str2<<endl;
            continue;
        }
        
        //rip off the first char of str1 so that we can append it to str2 later
        char taken = stackTop.str1[stackTop.str1.length()-1];   
        stackTop.str1.pop_back();
        
        //only create the second branch if str2 isn't empty or else you will get
        //""+a and a+"" which creates the same output
        recurStack.push(BubblingStackObj(stackTop.str1, stackTop.str2+taken));
        if(stackTop.str2.length()>0){
            bubblingRecursive(stackTop.str1, taken+stackTop.str2);
        }
        
    }
}


int main() {
   bubblingRecursive("abc");
   cout<<endl;
   bubblingStack("abc");
   cout<<endl;
  return 0;
}
