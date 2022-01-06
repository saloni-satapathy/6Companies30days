#include<bits/stdc++.h>

using namespace std;

string gcdOfStrings(string str1,string str2){
          if((str1+str2).compare(str2+str1)){
            return "";
        }else if(str1.compare(str2)==0){
            return str1;
        }
        else if(str1.length()>str2.length()){
            return gcdOfStrings(str1.substr(str2.length()),str2);
        }else{
           return gcdOfStrings(str2.substr(str1.length()),str1) ;
        }
        

}

 int main(){
  string str1,str2;
   cin>>str1;
   cin>>str2;
   cout<<endl;
    cout<<gcdOfStrings(str1,str2);    
        
 }