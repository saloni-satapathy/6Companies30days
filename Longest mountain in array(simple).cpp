
//Complex method
#include<bits/stdc++.h>
 using namespace std;
  int MountainLength(int arr[],int n){
       int result=0;
         int n=arr.size();
        for(int i=1;i<n;i++){
            int count=1;
          int flag=0;
          int j=i;
          // increasing
           while(j<n && arr[j]>arr[j-1]){
             count++;
             j++;

           }
          //decreasing
          while(i!=j && j<n && arr[j]<arr[j-1]){
            count++;
            j++;
            flag=1;
          }
          //calculating the mountain
          if(i!=j && flag && count>2){
                result= max(result,count);
              j--;
          }
          
          
          i=j;
        }
        
    
     return result;
  }

  int main(){
    int n;
    cin>>n; 
    int arr[n];
     for(int i=0;i<n;i++){
       cin>>arr[i];
     }
     cout<<endl;
     cout<<MountainLength(arr,n);
  }
