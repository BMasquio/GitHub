#include <iostream>
#include <string.h>
using namespace std;

int main() {
	string s;
	int m,i;
	cin >> m;
	
	bool o,n,e;
	
	while(m--){
		cin >> s;
		if(s.length() == 5) cout << 3 << endl;
		else{
			o=false;
			n=false;
			e=false;
			for(i=0;i<s.length();i++){
				if(s[i] == 'o') o=true;
				if(s[i] == 'n') n=true;
				if(s[i] == 'e') e=true;
			}
			
			if((o&&n) || (o&&e) || (n&&e)) cout << 1 << endl;
			else cout << 2 << endl;
		}
	}
	
	return 0;
}