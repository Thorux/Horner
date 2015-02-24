/*
 * poly_roots.cpp
 *
 *  Created on: 09/02/2015
 *      Author: Anders
 */
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
 
using namespace std;
 
#define Xmax 10
 
void Poly (int X[Xmax+1], int x)
{
        int i;
 
        cout << "Insert constant: ";
        cin >> X[0];
 
        for (i=x ; i>0 ; i--) {
        cout << "Insert variable x^" << i << ": ";
        cin >> X[i];
        }
}
void ShowPoly (int X[Xmax], int x)
{
        cout << X[x] << "x^" << x;
        for(int i=x-1; i>0; i--){
        if (X[i]>1){
        cout << "+" << X[i] << "x^" << i;
        }
        else if (X[i]<0){
        cout << X[i] << "x^" << i;
        }
        else if (X[i]==1){
        cout << "+" << X[i] << "x";
        }
        else {
        cout << "";
        }
}
        if (X[0]>0){
        cout << "+" << X[0];
        }
        else if (X[0]<0){
        cout << X[0];
        }
        else{
        cout <<"";
        }
}
void CorPoly (int X[Xmax])
{
        int P, a, c;
        char p, h;
        do {
        cout << "What element would you like to change?\n";
        cout << "A: Constant or B: polynomial value? ";
        cin >> p;
 
        if (p == 'A' | p == 'a') {
        cout << "New constant value: ";
        cin >> c;
        X[0] = c;
        }
        else if (p == 'B' | p == 'b'){
        cout << "Polynomial value x^: ";
        cin >> a;
 
        cout << "New element value: ";
        cin >> P;
        X[a] = P;
        }
 
        cout << "Want to change other values? \nY/N";
        cin >> h;
        } while (h == 'Y' | h == 'y');
}
 
void Horner(int n, int X[Xmax+1], double x, double fx, double dx)
{
        int k;
        double b[Xmax+1], c[Xmax];
 
        b[0] = X[0];
        for (k = 1; k <= n; k++){
                b[k] = X[k] + x * b[k-1];
        }
/*
        c[0] = b[0];
        for (k = 1; k < n; k++){
                c[k] = b[k] + x * c[k-1];
        }*/
        fx = b[n];
        //dx = c[n-1];
 
}
int main(){
        int X[Xmax], x, n, fx, dx;
        char j;
 
        cout <<"Insert the rank of the polynomial:\n";
        cout <<"X: ";
        cin >> x;
 
        cout <<"Insert your polynomial-values: \n";
        Poly(X,x);
        ShowPoly(X,x);
 
        cout <<"\n\nWant to change values? \nY/N: ";
        cin >> j;
 
        if (j == 'Y' | j == 'y'){
        CorPoly(X);
 
        ShowPoly(X,x);
        }
 
 
        cout << "\n\nInsert your function value. \nX = ";
        cin >> n;
 
        Horner(n, X, x, fx, dx);
 
 
        cout << fx << "\n"; //<< dx;
 
        return 0;
}