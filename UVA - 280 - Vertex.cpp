#include<iostream>
#include<string.h>

using namespace std;
const int NVM=1001;
typedef struct no{int v;  int d;};

// Declarações para o grafo
int n, m, cpre, pre[NVM], E[NVM][NVM], DM[NVM][NVM];

int Inv[NVM],Invq[NVM];

//Outras declarações
int i, j, u, w, f, r;
no  Q[NVM];

void Inicializa(int n){   
    memset(pre, 0, sizeof(pre));
	f = r = cpre = 0;
}
void BL(int u, int v){
	no t;
	//pre[v] = ++cpre;
	r = 1; f = 1; Q[1].v = v;  Q[1].d = 0; 
	while(f != 0){
		t = Q[f];
		for(int w=1; w<=n; w++)
			if((E[w][t.v] == 1) && (pre[w] == 0)){
				r++; Q[r].v = w;  Q[r].d = t.d+1; pre[w] = ++cpre;
				DM[u][w] = t.d+1;
			}
		if(f == r) f = 0;
		else       f++;
	}
}

int main(){   
	 int j; int temp, temp2;
	 int vezes;
	 bool primeiro=true;
	 
	 while(cin >> vezes, vezes){
         n = vezes;
	     Inicializa(n);
	     
	     memset(DM, 0, sizeof(DM));
	     memset(E, 0, sizeof(E)); 
	     memset(Inv, 0, sizeof(Inv));
	     memset(Invq, 0, sizeof(Invq));
	     
	     
	     while(cin >> temp,temp){
	     	while(cin >> temp2, temp2) E[temp2][temp] = 1;
	     }
		
		int num;
		cin >> num;
		for (i=0;i<num;i++){
			cin >> temp;
			Inv[i] = temp;
		}
        
	    for(i=1; i<=n; i++){
		    if(pre[i] == 0)
			    BL(i,i);
			    Inicializa(n);
       }
	    
	    
	    
        for(i=0; i<num; i++){
                for (j=1;j<=n;j++)
		    		if(!DM[Inv[i]][j]){
		    			Invq[i]++;
		    		}
        }
		
		/*
		for(i=1; i<=n; i++){
                for (j=1;j<=n;j++) 
		    cout<<DM[i][j]<<" "; cout << endl;			   } 
*/
		
		for(i=0; i<num; i++){
				cout << Invq[i];
                for (j=1;j<=n;j++)
		    		if(!DM[Inv[i]][j]){
		    			cout << " " << j;
		    		}
		    	cout <<endl;
        }
	 }
        
        
		    		
	return 0;
}




