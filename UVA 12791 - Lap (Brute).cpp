#include <iostream>
#include <math.h>


using namespace std;

int main() {
	int x,y;
	
	while(cin >> x >> y){
		cout << ceil((double)x/(double)(y-x))+1 << endl;
	}
	
	return 0;
}