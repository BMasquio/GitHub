/*Neste programa voc� vai implementar a solu��o para o problema 
  UVA 11045 (y T-shirt suits me). A entrada � a seguinte:
  primeira linha: nc = n�m. de camisetas de cada tipo
  segunda linha: np = nu. de pessoas
  as np linhas seguintes cont�m 2 numeros de 1 a 6,
  indicando, respectivamente, XXL, XL, L, M, S, XS.
1. Programe o procedimento CriaRede para modelar a rede(preencher C).
*/
#include <iostream>
#include <string.h>
#define INF 0x3f3f3f3f
#define NVM 1006
using namespace std;

int C[NVM][NVM], F[NVM][NVM], PR[NVM][3], n, m, nc, np;
bool V[NVM];

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
     int i;
     
     //sumidouro n=8
     //fonte n=7
     
     for (i=1;i<=6;i++){
         C[7][i] = nc;
     }
     
     for(i=9; i<=n; i++){
          C[PR[i-8][1]] [i] = 1;
          C[PR[i-8][2]] [i] = 1;
          C[i][8] = 1;    
     }    
     
     
      
     //implementar aqui
      
}

int main() {
    int fmax,t,po[3];
    string s[2];
    
    cin >> t;
    
    while(t--) {
		cin>>nc;    
		nc/=6;
        cin >> np;   n=8+np;
        
        memset(C, 0, sizeof(C));  memset(F, 0, sizeof(F));  memset(V, 0, sizeof(V)); 
       // cout<<"As duas preferencias (1=XXL 2=XL, 3=L, 4=M 5=S 6=XS):"<<endl;      
        
        
        memset(PR, 0, sizeof(PR));
        
        for(int i=1;i<=np;i++){
            cin >> s[0] >> s[1];
            
            for(int kl=0;kl<2;kl++){
            	if(s[kl] == "XXL") po[kl]=1;
            	if(s[kl] == "XL") po[kl]=2;
            	if(s[kl] == "L") po[kl]=3;
            	if(s[kl] == "M") po[kl]=4;
            	if(s[kl] == "S") po[kl]=5;
            	if(s[kl] == "XS") po[kl]=6;
            }
            
	        PR[i][1] = po[0];
	        PR[i][2] = po[1];
        
        }
        CriaRede(); 
        fmax = 0;
        while(int fm = MF(7, 8, INF)) {
            fmax += fm;
            memset(V, 0, sizeof(V));
            //Imprime();
        }
        
       // ImprimeF();
        
        if(fmax == np) cout << "YES";
        else cout << "NO";
        
        cout << endl;
    }
}
