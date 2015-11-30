#include <iostream>
using namespace std;

int main() {
	long long n,i1,i2;
	
	cin >> n;
	
	while(n--){
		cin >> i1 >> i2;
		if(i1 < i2) cout << "<" << endl;
		else if(i1 > i2) cout << ">" << endl;
		else cout << "=" << endl;
	}
	
	
	
	return 0;
}