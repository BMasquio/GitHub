#include <iostream>
#include <string.h>
#include <stdlib.h>

#define INF 0x3f3f3f3f
#define NVM 1006

#define MODULO(x) ((x)>=0?(x):-(x))

#define ZERO 0.01
using namespace std;

int C[NVM][NVM], F[NVM][NVM], M[NVM], TIME[NVM], PR[NVM], n, nc, np;
bool V[NVM];


typedef struct ponto{
	double x,y;
}ponto;
    int m,goph,s,v;
    ponto G[200], H[200];

double dist;
int times,mesas,cont;

void ImprimeC(){
        cout<<"Rede:"<<endl;
        for(int i=1;i<=n;i++) { 
            for(int j=1;j<=n;j++) { 
                if (C[i][j] > 0) cout << i << " " << j << "  "<<C[i][j]<<endl;
            }        
        }     
}
void ImprimeF(){
	
		//(3+mesas) até (2+mesas+times)
		
        cout<<"Fluxo:"<<endl;
        for(int i=1;i<=n;i++) { 
            for(int j=1;j<=n;j++) { 
                if (F[i][j] > 0) cout << i << " " << j << "  "<<F[i][j]<<endl;
            }        
        }     
}

int MF(int s, int t, int minn) {
    V[s] = true;
    if (s==t) return minn;
    
    for(int i=1; i<=n; i++) {
        if (!V[i] && C[s][i] > 0) {
            if (int fm = MF(i, t, min(minn, C[s][i]))) {
                C[s][i] -= fm;  C[i][s] += fm;
                F[s][i] += fm;  F[i][s] -= fm;                
                return fm;
            }
        }
    }
    return 0;
}

void CriaRede(){
     int i,j;

     //1 fonte
     //2 sumidouro
     //3 até goph+2
     //goph+3 até goph+m+2
     
     //cout << dist*dist << endl;
     for(i=3; i<=goph+2; i++){
     	C[1][i] = 1;
     	for(j=goph+3;j<=goph+m+2;j++){
     //		cout << MODULO(((((G[i].x - H[j].x)*(G[i].x - H[j].x))+((G[i].y - H[j].y)*(G[i].y - H[j].y)))) - (dist*dist)) << endl;
     		if( (dist*dist) - ((((G[i].x - H[j].x)*(G[i].x - H[j].x))+((G[i].y - H[j].y)*(G[i].y - H[j].y)))) > ZERO) C[i][j]=1;
     	}
     }

	for(i=goph+3;i<=goph+m+2;i++) C[i][2] = 1;

}


int main() {
    int fmax,i,j;

   	//fonte = 1
   	//sumidouro = 2
   	
   	//mesas = 3 até (2+mesas)
   	//times = (3+mesas) até (2+mesas+times)
    
    while(cin >> goph >> m >> s >> v){
        memset(C, 0, sizeof(C)); 
        memset(F, 0, sizeof(F));
        memset(V, 0, sizeof(V)); 
        memset(PR, 0, sizeof(PR));
        memset(H, 0, sizeof(H));
        memset(G, 0, sizeof(G));
        fmax=0;
        
        
        n = goph+m+2;
        dist = v*s;
        for(i=3;i<=goph+2;i++) cin >> G[i].x >> G[i].y;
        
        for(i=goph+3;i<=goph+m+2;i++) cin >> H[i].x >> H[i].y;
        
      //  for(i=3;i<=goph+2;i++) cout << G[i].x << " " << G[i].y << endl;
      //  for(i=goph+3;i<=goph+m+2;i++) cout << H[i].x << " " << H[i].y << endl;
        
        
        CriaRede();
        
       // ImprimeC();
        
        while(int fm = MF(1, 2, INF)) {
            fmax += fm;
            memset(V, 0, sizeof(V));
        }
        
      // ImprimeF();
        
        
		cout << goph - fmax << endl;
    }
    
}
