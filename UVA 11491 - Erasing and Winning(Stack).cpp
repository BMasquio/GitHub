#include <iostream>
#include <stack>
#include <vector>
#include <string.h>

using namespace std;

int main() {
	int N,D;
	string s1;
	
	int i;
	
	while(cin >> N >> D, N || D){
		stack<int> pilha;
		int tamanho,pos,tirados=0;
		tamanho = N-D;
		
		cin >> s1;
		
		
		pilha.push(10);
		
		for(i=0;i<N;i++){
			
			//cout << s1[i] << endl;
			
			while((pilha.top() < s1[i]-'0') && (tirados < D)){
				tirados++;
				pilha.pop();
			}
			
			if(pilha.size() < tamanho+1){ pilha.push(s1[i]-'0');}
			else tirados++;
			
		//	cout << tamanho << endl;
		//	cout << s1[i] << " " << tirados << endl;
			
		}
		
		
		
		
		
		vector<int> temp;
		while(pilha.size() > 1){
			temp.push_back(pilha.top());
			pilha.pop();
		}
		
		for(i=temp.size()-1;i>=0;i--){
			cout << temp[i];
		}
		cout << endl;
	}
	
	return 0;
}