//Sa se plaseze n regine pe o tabla de sah de dimensiuni n*n astfel incat niciuna dintre regine sa nu se atace


#include <iostream>
#include <stdlib.h>
using namespace std;
int n, nr_sol, coloana[30];

void afisare(){
int i, j;
nr_sol++;
cout << "Solutia nr. : "<< nr_sol << endl;
for( i=0; i<n; i++){
    for(j=0; j<n; j++)
      if(j == coloana[i])
        cout << " * ";
      else
        cout << " # ";
      cout << endl;
                   }
cout << endl; }


void plaseaza_regina(int k){
int i,j,ok;
if (k == n)
    afisare();
    else
        for(i=0;i<n;i++){
           for(ok=1 , j=0 ;j<k;j++)
               if(coloana[j]==i || abs(coloana[j]-i)==(k-j))
                     ok=0;
        if(ok){

        coloana[k]=i;
        plaseaza_regina(k+1);
              }
                        }
                          }
int main()
{
    cout << "Dimensiunea tablei de sah n= ";
    cin >> n;
    plaseaza_regina(0);
    return 0;
}
