//Anderson Zudio
//AC 28/07/2014
#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>
#include <string.h>
#define INF 0x3f3f3f3f
#define QZERO 0.00000001
#define NVM 1006
#include <stdlib.h>
using namespace std;

struct nof{int v; int p; int ma;};

int C[NVM][NVM], CC[NVM][NVM], F[NVM][NVM], FC[NVM][NVM], n, m, ct, ct2, N1[3000], N2[3000];
bool V[NVM];  nof Fila[NVM];

void Imprime(){
        cout<<"Fluxo:"<<endl;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if (F[i][j] > 0) cout << i << " " << j << "  "<<F[i][j]<<endl;
            }
        }
}
void ImprimeC(){
        cout<<"Rede:"<<endl;
        for(int i=2;i<=ct;i++) {
            for(int j=ct+1;j<=ct2+ct+1;j++) {
                if (CC[i][j] > 0) cout << N1[i] << " " << N2[j] << "  "<<CC[i][j]<<endl;
            }
        }
        
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if (CC[i][j] > 0) cout << i << " " << j << "  "<<CC[i][j]<<endl;
            }
        }
}
int MFBFS(){
    int i, j, f, r, p, s, fm;
    memset(V, 0, sizeof(V));
    f=r=1;   Fila[1].v=1; Fila[1].p=0;  Fila[1].ma=INF; V[1]=true;
    while(f<=r){
        s=Fila[f].v;
        for(int i=1; i<=n; i++) if (!V[i]){
            if (C[s][i] > 0){
                V[i]=true;
                Fila[++r].v=i;  Fila[r].p=f;  Fila[r].ma=min(Fila[f].ma,C[s][i]);
                if (i==n) {f=r; break;}
            }
        }
        f++;
    }
    if (Fila[r].v==n){
        j=r;  i=Fila[j].v;  p=Fila[j].p;  s=Fila[p].v;  fm=Fila[r].ma;
        while (i != 1){
            C[s][i] -= fm;  C[i][s] += fm;
            F[s][i] += fm;  F[i][s] -= fm;
            j=p;  i=Fila[j].v;  p=Fila[j].p;
            if (i != 1) s= Fila[p].v;
        }
        return fm;
    }
    return 0;
}

double dist(pair <double, double> p, pair <double, double> q){
    return ((p.first-q.first)*(p.first-q.first)) + ((p.second-q.second)*(p.second-q.second));
}

int main() {
	
    int fmax;
    int mt,u,nv,nva,cp,ck;
    int t,i,j,N, M, S, V, qtd=0;
	
	cin >> t;

    while(t--){
    	memset(CC,0,sizeof(C));
    	memset(FC,0,sizeof(F));
    	memset(N1,0,sizeof(N1));
    	memset(N2,0,sizeof(N2));
    	
    	cin>> ct;
    	
    //	cout << ct << endl;
    	
    	for(i=2;i<=ct+1;i++){
    		cin >> N1[i];
    //		cout << N1[i];
    	}
    	
    	cin >> ct2;
    	for(i=ct+2;i<=ct2+ct+1;i++){
    		cin >> N2[i];
    //		cout << N2[i];
    	}
    	
    	
    	
    	n= ct+ct2+2;
    	
    	//vertices de 1 até (ct+ct2+2)
    	for(i=2;i<=ct+1;i++){
    		CC[1][i] = 1;
    		
    		for (j=ct+2;j<=ct2+ct+1;j++){
    			if (N1[i] && N2[j]) {if(N2[j]%N1[i]==0) {CC[i][j]=1;}}
    			else if(/*!N1[i] && */!N2[j]) CC[i][j] = 1;
    		}
    		
    	}
    	
    	for (j=ct+2;j<=ct2+ct+1;j++) CC[j][ct+ct2+2] = 1;
    	
    //	ImprimeC();
    	
       nv=20;
       nva=nv;
       while(nva--){
		   for (int i=1; i<=n; i++) for (int j=1; j<=n; j++){
               C[i][j]=CC[i][j];   F[i][j]=FC[i][j];
           }
           fmax = 0;
           while(int fm = MFBFS()) {
               fmax += fm;
           }
           
       }
       cout << "Case " << ++qtd << ": " <<  fmax << endl;
    }
}
