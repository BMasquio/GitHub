#include <iostream>
using namespace std;

int main() {
	double Vo=470.312,deltah = 2.13333,mediaH=136.3,mediah=108.7,erroH=0,H,h,g=980,n=1.03821,ho=27.6,derivVo=5.01005,derivh=1.08385;
	int i;
	
	
	
	cout << "n(barra) = " << (Vo*Vo/(2*g*mediah)) << endl;
	
	
	cout << "δ% = "<< 100*(n-1)/n << "%" << endl;
	
	for(i=0;i<10;i++){
		cin >> H;
		erroH += (H-mediaH)*(H-mediaH);
	//	cout << "h" << (i+1) << " = " << (H - ho) << endl;
		h = H - ho;
//		mediaH+=H;
//		mediah+=h;
	}
	
	erroH/=3;
	
	cout << "Erro de H = " << erroH << endl;
	
//	mediah/=10;
//	mediaH/=10;
	
	cout << "Media de H = " << mediaH << endl;
	cout << "Media de h = " << mediah << endl;
	
	derivVo = Vo/(mediah*g);
	derivh = Vo*Vo/(2*g*mediah*mediah);
	
	cout << "Derivada de n em relação a Vo = " << derivVo << endl;
	cout << "Derivada de n em relação a h = " << derivh << endl;
	
	cout << "Delta n = " << (4.30199*derivVo + derivh*deltah) << endl;
	
	return 0;
}