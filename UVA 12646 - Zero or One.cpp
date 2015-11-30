#include <iostream>
using namespace std;

int main() {
	int a,b,c;
	
	while(cin >> a >> b >> c){
	
	
		if((a != b)&&(a != c)) cout << "A";
		else if((b != c)&&(b != a)) cout << "B";
		else if((c != a)&&(c != b)) cout << "C";
		else cout << "*";
		cout << endl;
	}
	
	return 0;
}