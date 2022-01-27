// In this program the adjacency matrix is a array of vectors

// also try to solve the same problem using topological sorting


// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    // Function to check if a palindrome pair exists
    
    
     bool palindrome(string s1,string s2){



       cout<<"Chcek Plaindrome:"<<s1<<" "<<s2;
         string s=s1+s2;
         int i=0,j=s.length()-1;
         while(i!=j && i<j){
             if(s[i]!=s[j]){
                 return false;
             }
             i++;j--;
         }

         return true;
     }
    bool palindromepair(int N, string arr[]) {
        // code here
        map<char,vector<int>>starting;
        map<char,vector<int>>ending;
        for(int i=0;i<N;i++){
             starting[arr[i][0]].push_back(i);
             int l=arr[i].length();
             ending[arr[i][l-1]].push_back(i);
        }

       for(auto i=starting.begin();i!= starting.end();i++){
     cout<<i->first<<":";
     for(int j=0;j<i->second.size();j++){
       cout<<i->second[j]<<" ";
     }
     cout<<endl;
       }
  cout<<"***"<<endl;
       for(auto i=ending.begin();i!= ending.end();i++){
     cout<<i->first<<":";
     for(int j=0;j<i->second.size();j++){
       cout<<i->second[j]<<" ";
     }
     cout<<endl;
       }


        for(auto it=starting.begin();it!=starting.end();it++){
            
            for(int i=0;i<it->second.size();i++){
                for(int j=0;j<ending[it->first].size();j++){
                  if (palindrome(arr[it->second[i]],arr[ending[it->first][j]]))return true;
                }
            }
        }
       return false; 
    }

};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        string arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.palindromepair(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
