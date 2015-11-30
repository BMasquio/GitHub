#include <iostream>
using namespace std;


int main() {
	
	int t,n,temp1,temp2,cont;
	
	cont = 0;
	cin>>t;
	
	while(t--){
		int sup = 0;
		int inf = 0;
		cin>>n;
		
		bool com = true;
		while(n--){
			temp1 = temp2;
			cin >> temp2;
			if(!com){
				if(temp1 < temp2) sup++;
				else if(temp1 > temp2) inf++;
			}
			com = false;
		}
		
		cout << "Case " << ++cont << ": " << sup << " " << inf << endl;
	}
	
	return 0;
}