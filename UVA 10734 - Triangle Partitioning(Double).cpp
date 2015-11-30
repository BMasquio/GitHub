//Anderson Zudio
//Bruno Masquio
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <algorithm>
#define inf 1001000
#define PI acos(-1)
#define QZERO 0.0001

using namespace std;

vector<vector<double> > triangulos;
int n, resp;

bool semelhantes(vector <double> triangulo1, vector<double> triangulo2){
    return ( (fabs(triangulo1[0]/triangulo2[0] - triangulo1[1]/triangulo2[1]) < QZERO) &&
            (fabs(triangulo1[1]/triangulo2[1] - triangulo1[2]/triangulo2[2]) < QZERO) &&
            (fabs(triangulo1[2]/triangulo2[2] - triangulo1[0]/triangulo2[0]) < QZERO) );
}

void corte(vector <double> triangulo){
    bool equivalencia;
    sort(triangulo.begin(), triangulo.end(), [](double a, double b)->bool{ return a < b;});
    double altura = sqrt((2*triangulo.at(0)*triangulo.at(0) + 2*triangulo.at(1)*triangulo.at(1) - triangulo.at(2)*triangulo.at(2))/4);

    vector<double> trianguloA(3), trianguloB(3);
    trianguloA[0] = trianguloB[0] = altura;
    trianguloA[1] = trianguloB[1] = triangulo.at(2)/2;
    trianguloA[2] = triangulo.at(0); trianguloB[2] = triangulo.at(1);
    sort(trianguloA.begin(), trianguloA.end(), [](double a, double b)->bool{ return a < b;});
    sort(trianguloB.begin(), trianguloB.end(), [](double a, double b)->bool{ return a < b;});

    equivalencia = false;
    for(auto i = triangulos.begin(); i != triangulos.end(); i++){
            if(semelhantes(trianguloA, *i)){
                equivalencia = true;
                break;
            }
    }
    if(!equivalencia){
        triangulos.push_back(trianguloA);
        //cout << trianguloA.at(0) << " " << trianguloA.at(1) << " " << trianguloA.at(2) << " " << endl;
        //cin >> n;
        resp++;
        corte(trianguloA);
    }

    equivalencia = false;
    for(auto i = triangulos.begin(); i != triangulos.end(); i++){
            if(semelhantes(trianguloB, *i)){
                equivalencia = true;
                break;
            }
    }
    if(!equivalencia){
        triangulos.push_back(trianguloB);
        //cout << trianguloB.at(0) << " " << trianguloB.at(1) << " " << trianguloB.at(2) << " " << endl;
        //cin >> n;
        resp++;
        corte(trianguloB);
    }
}

int main(){
    cin >> n;
    for(int t = 1; t <= n; t++){
        triangulos.clear();
        vector<double> triangulo(3);
        for(int i = 0; i < 3; i++)
            cin >> triangulo[i];

        resp = 0;
        corte(triangulo);
        cout << "Triangle " << t << ": " << resp << endl;
    }
    return 0;
}
