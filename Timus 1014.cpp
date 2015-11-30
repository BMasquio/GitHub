#include <iostream> 
#include <cstdlib> 
#include <math.h> 
#include <stdio.h> 

using namespace std;

int f[20];
bool b;

int main(){ 
   int i,n;
   b=false;
   
   cin >> n;
   
   if (n==0){
   	cout << 10;
   	return 0;
   }
   if (n==1){
   	cout << 1;
   	return 0;
   }
   
   
   for(i=0;i<10;i++){
   		f[i]=0;
   }
   
   for(i=9;i>1;i--){
   		while(!(n%i)){
   			f[i]++;
   			n/=i;
   		}
   }
   
 
   
   if(n==1){
   for(i=2;i<10;i++){
   		while(f[i]){
   			f[i]--;
   			cout << i;
   			b=true;
   		}
   }
   }
   
	if (!b) cout << -1;
	
    return 0; 
} 