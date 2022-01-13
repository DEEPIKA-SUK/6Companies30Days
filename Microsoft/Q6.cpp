#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void func(int a[],int n,map<int,vector<char>> mp,string r,vector<string> &v,int i){
        if(r.length()==n){
            v.push_back(r);
            return;
        }
        for(auto x:mp[a[i]]){
            r+=x;
            func(a,n,mp,r,v,i+1);
            r.pop_back();
        }
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int n)
    {
        //Your code here
        vector<string> v;
        if(n==0)return v;
        map<int,vector<char>> mp;
        mp[2].push_back('a');
        mp[2].push_back('b');
        mp[2].push_back('c');
        mp[3].push_back('d');
        mp[3].push_back('e');
        mp[3].push_back('f');
        mp[4].push_back('g');
        mp[4].push_back('h');
        mp[4].push_back('i');
        mp[5].push_back('j');
        mp[5].push_back('k');
        mp[5].push_back('l');
        mp[6].push_back('m');
        mp[6].push_back('n');
        mp[6].push_back('o');
        mp[7].push_back('p');
        mp[7].push_back('q');
        mp[7].push_back('r');
        mp[7].push_back('s');
        mp[8].push_back('t');
        mp[8].push_back('u');
        mp[8].push_back('v');
        mp[9].push_back('w');
        mp[9].push_back('x');
        mp[9].push_back('y');
        mp[9].push_back('z');
        func(a,n,mp,"",v,0);
        return v;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends