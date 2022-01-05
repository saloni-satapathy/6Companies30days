// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
  string s;
  char c;
  c=src[0];
  int count=0;
 //int i=0;
  for(int i=0;i<src.length();i++){
  if(c==src[i]){
     count++;
  }
  else{
    s+=c;
    s+=to_string(count);
    count=1;
    c=src[i];
  }
  }
     s+=c;
    s+=to_string(count);
    
   
  return s;
}     
 
