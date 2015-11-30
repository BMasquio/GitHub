#include <iostream>
#include <queue>
using namespace std;

typedef struct jogada{
	bool B[100];
	bool P[100];
	int score;
}jogada;

typedef struct comb{
	int a,b,c,score;
}comb;


int main() {
	int n,i,j,maximo,caso;

	
	caso=0;
	
	while(cin >> n, n){
		maximo = -1;
		queue<jogada> fila;
		jogada jogo1,jogo2;
		comb poss[90];
		
		
		for(i=1;i<10;i++){
			jogo1.B[i] = false;
		}
		jogo1.score = 0;
		
				
		for(i=0;i<n;i++){
			cin >> poss[i].a;
			cin >> poss[i].b;
			cin >> poss[i].c;
			cin >> poss[i].score;
			jogo1.P[i] = false;
		}
		
		fila.push(jogo1);
		
		while(!fila.empty()){
			jogo1 = fila.front();
			fila.pop();
			
			for(i=0;i<n;i++){
				if(!jogo1.B[poss[i].a] && !jogo1.B[poss[i].b] && !jogo1.B[poss[i].c] && !jogo1.P[i]){
					jogo1.P[i] = true;
					jogo2 = jogo1;
					jogo2.score += poss[i].score;
					jogo2.B[poss[i].a] = true;
					jogo2.B[poss[i].b] = true;
					jogo2.B[poss[i].c] = true;
					
					bool todos = true;
					for(j=1; j<10; j++) if(!jogo2.B[j]) {todos = false; break;}
					if(todos){
						if (jogo2.score > maximo) maximo = jogo2.score;
					}else fila.push(jogo2);
				}
			}
		}
		
		cout << "Case " << ++caso << ": " << maximo << endl;
	}
	
	return 0;
}