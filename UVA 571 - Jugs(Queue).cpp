#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

bool M[1010][1010];

typedef struct item{
	int a,b;
	string str;
}item;


int main() {
	item i1,i2;
	
	int A,B,N;
	
	
	
	while(cin >> A >> B >> N){
		queue<item> fila;
		
		memset (M,false,sizeof(M));
		i1.a=0;
		i1.b=0;
		i1.str="";
		fila.push(i1);
		
		while(!fila.empty()){
			i1 = fila.front();
			fila.pop();
			
		//	cout << i1.a << " " << i1.b << endl;
			
			if(M[i1.a][i1.b]) continue;
			else M[i1.a][i1.b] = true;
			
			if((i1.a == N) || (i1.b == N)){
				i1.str += "success\n";
				break;
			}
			
			//enche A
			i2=i1;
			i2.a=A;
			i2.str+="fill A\n";
			fila.push(i2);
			
			//enche B
			i2=i1;
			i2.b=B;
			i2.str+="fill B\n";
			fila.push(i2);
			
			//A no B
			i2 = i1;
			i2.b = i2.b+i2.a;
			i2.a = 0;
			
			if(i2.b > B){
				i2.a = i2.b - B;
				i2.b = B;
			}
			
			i2.str+="pour A B\n";
			fila.push(i2);
			
			
			//B no A
			i2 = i1;
			i2.a = i2.a+i2.b;
			i2.b = 0;
			
			if(i2.a > A){
				i2.b = i2.a - A;
				i2.a = A;
			}
			
			i2.str+="pour B A\n";
			fila.push(i2);
			
			
			//esvazia A
			i2=i1;
			i2.a=0;
			i2.str+="empty A\n";
			fila.push(i2);			
			
			//esvazia B
			i2=i1;
			i2.b=0;
			i2.str+="empty B\n";
			fila.push(i2);
		}
		
		cout << i1.str;
		
	}
	
	
	return 0;
}