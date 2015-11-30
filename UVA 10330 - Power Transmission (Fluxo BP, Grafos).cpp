#include <iostream>
#include <string.h>

#define INF 0x3f3f3f3f
#define NVM 1006
using namespace std;

int C[NVM][NVM], F[NVM][NVM], M[NVM], CAP[NVM], PR[NVM],CC[NVM][NVM], FC[NVM][NVM], n, m;
bool V[NVM];
struct nof{int v; int p; int ma;};
int B,D,cont;
nof Fila[NVM];

void ImprimeC(){
        cout<<"Rede:"<<endl;
        for(int i=1;i<=n;i++) { 
            for(int j=1;j<=n;j++) { 
                if (C[i][j] > 0) cout << i << " " << j << "  "<<C[i][j]<<endl;
            }        
        }     
}
void ImprimeF(){
        cout<<"Fluxo:"<<endl;
        for(int i=1;i<=n;i++) { 
            for(int j=1;j<=n;j++) { 
                if (F[i][j] > 0) cout << i << " " << j << "  "<<F[i][j]<<endl;
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



void CriaRede(){
     int i,m,temp1,temp2,temp3;
	
	
	cin >> m;
	//cout << "m = " << m << endl;
	
	/*for(i=1;i<=(n/2)-1;i++){
		//C[i*2][(i*2)-1] = CAP[i];
		
		C[i*2][(i*2)+1] = CAP[i];
	}*/
	
     for(i=1;i<=m;i++){
     	cin >> temp1 >> temp2 >> temp3;
     	
     	
     	
     //	C[(temp1*2)-1][temp2*2] = temp3;
     	C[(temp1*2)+1][(temp2*2)] = temp3;
     }
     
     
     int temp;
     cin>>B; cin>>D;
     for(i=1;i<=B;i++){
     	cin >> temp;
     	//C[n-1][temp*2] = CAP[temp];
     	C[1][temp*2] = CAP[temp];
     }
     
     for(i=1;i<=D;i++){
     	cin >> temp;
     	
     	C[(temp*2)+1][n] = CAP[temp];
     //	cout << endl;
     //	cout << CAP[temp*2] << endl;
     	//C[(temp*2)-1][n] = CAP[temp];
     }
     
    // cout << "B = " << B << endl;
    // cout << "D = " << D << endl;
     
}

int main() {
    int fmax,i;
    
   	//fonte = 1
   	//sumidouro = 2
   	
   	//mesas = 3 até (2+mesas)
   	//times = (3+mesas) até (2+mesas+times)
    
    while(cin>>n) {
        memset(C, 0, sizeof(C)); 
        memset(F, 0, sizeof(F));
        memset(V, 0, sizeof(V)); 
        memset(PR, 0, sizeof(PR));
        memset(CAP, 0, sizeof(CAP));
        memset(M, 0, sizeof(M));
        
        
        for(i=1;i<=n;i++){
        	cin >> CAP[i];
        	C[i*2][(i*2)+1] = CAP[i];
        }
        
        
        n*=2;
        n+=2;
        
        //cout << "n = " << n << endl;
        
        CriaRede();
        
       // ImprimeC();
        

  
           fmax = 0;
           while(int fm = MFBFS()) {
               fmax += fm;
           }

        
        
        //ImprimeF();
        cout << fmax << endl;
        


		
    }
}
