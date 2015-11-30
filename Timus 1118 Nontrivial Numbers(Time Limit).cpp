#include <iostream>
using namespace std;


int main() {
	int n,soma,m,i,resp;
	double menor,temp;
	bool primeiro=true;
	
	cin >> n >> m;
	
	while(n<=m){
		soma=0;
		
		if(n==1) soma =1;
		else for(i=1;i<n;i++)
				if(n%i == 0) soma+=i;
		
	//	cout << soma << " " << n << " " << (double)((double)soma/(double)n) << endl;
		
		temp = (double)((double)soma/(double)n);
		if(primeiro) {menor=temp; resp = n; primeiro=false;}
		else if (temp<menor) {menor = temp; resp = n;}
		
		n++;
	}
	
	cout << resp << endl;
	
	return 0;
}