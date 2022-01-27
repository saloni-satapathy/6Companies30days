// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    
    void words(int a[],int N,vector<char>keypard[],string res,int index,vector<string>&ans){
         if(index==N){
             ans.push_back(res);
             return;
         }
         int digit=a[index];
         
         for(int i=0;i<keypard[digit].size();i++){
             words(a,N,keypard,res+keypard[digit][i],index+1,ans);
         }
    }
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string>ans;
        vector<char>keypard[]={
            {},{},
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r','s'},
        {'t','u','v'},
        {'w','x','y','z'}};
        string res="";
        words(a,N,keypard,res,0,ans);
        
       return ans; 
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
