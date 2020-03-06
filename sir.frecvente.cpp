/* Se considera sirul de numere naturale x= 1,2,2,3,3,3,4,4,4,4,...(fiecare numar natural nenul apare, in ordine, de un numar de ori egal cu
elınsusi
a) Se da un numar natural nenuln.Sa sescrie un program care afiseaza primii n termeni al sirului x
b) Se da un numar natural nenuln. Sa se scrie un program care afiseaza ın timp constant (care nu depinde de n) al n-lea termen al sirului x.
c) Se da un numar natural nenuln si n numere naturale nenule y1,...,yn.Sa se scrie un program care verifica(afisand ”DA”, respectiv ”NU”) daca exista o permutare a termenilor y1,...,yn care sa fie identica cu primii n termeni ai sirului x.
d) Dati o solutie ın timp liniar (ın functie de n) cerintei de la punctul c). */

#include <iostream>
#include <math.h>


using namespace std;

int main()
{
    int n;
    cout << "Da-ti-l pe n: "; cin>>n;

    int aux=n;
    int j=1,i=1;
    int x[50];

 for(int k = 1 ; k < 50 ; k++) // initializam un vector de frecventa pentru x cu 0
        x[k] = 0;

    while(aux){         //a) generarea sirului x
            i=1;
        while(i<=j){
            cout<<j;
            x[j]++;     //salvam numarul de aparitii ale unui numar din x
               i++;
               aux--;
               if(aux==0)
                break;
                  }
               j++;
    }

    cout << endl;


    float r;

    r=(-1+sqrt(1+8*n))/2;
    int auxr=r;
    if(r!=int(auxr))        //b) afisarea al
     r=auxr+1;
    cout<< r << endl;

    cout << endl;

    int y[100],auxy;

    for(int i = 1 ; i<=n ; i++) //initializam un vector de frecventa pentru y cu 0
        y[i]=0;


    for(int i = 1 ; i<=n ; i++){    //salvam numarul de aparitii a fiecarui numar introdus de la tastatura in vectorul de frecventa y

        cout << "pentru i = " << i << endl;
        cin>>auxy;
        y[auxy]++;
    }

    cout << endl;

    for(int i=1 ; i<=r ; i++){
        cout << i << " de "<<y[i]<< " ori " << endl;
    }

    int ok=1;

    cout << endl;

    for ( int i=1; i<= r ;i ++)  //cum r depinde de n , avem o solutie liniara
    {

        if(y[i]!=x[i]){   // comparam numarul de aparitii ale numerelor din y cu cele din x
        ok=0;
        break;
        }
    }
    if(ok==1)
    cout<< "DA! " << endl;
    else
    cout << "NU!" << endl;



return 0;
}
