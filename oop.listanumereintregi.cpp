/*  Cerinte comune tuturor temelor:
 implementare in C++ folosind clase
 ATENTIE: functiile pe care le-am numit mai jos metode (fie ca sunt supraincarcari de
operatori, fie altfel de functii), pot fi implementate ca functii prieten in loc de metode ale
claselor respective, daca se considera ca aceasta alegere este mai naturala;
 supraincarcarea operatorilor &lt;&lt; si &gt;&gt; pentru iesiri si intrari de obiecte, dupa indicatiile de
mai jos, astfel incat sa fie permise (si ilustrate in program):
 citirea de la tastatura si dintr-un fisier;
 scrierea pe ecran sau intr-un fisier;
 citirea informațiilor complete a n obiecte, memorarea și afisarea acestora
 Cerinte specifice fiecarei teme:

Tema 1. liste de numere intregi reprezentate ca tablouri unidimensionale:
o metode ale clasei vector de intregi:
- suma tuturor elementelor vectorului;
- gasirea maximului si a pozitiei lui;
- sortarea crescatoare;
- produsul scalar a doi vectori de aceeasi lungime, implementat prin supraincarcarea
operatorului *;
o sa se creeze o clasa matrice de numere intregi, prietena a clasei vector de intregi,
care sa reprezinte matricile de numere intregi, nu neaparat patratice, sub forma
unui vector de elemente de tip clasa vector de numere intregi, privite ca vectori
linie; mai precis, o matrice cu m linii si n coloane va fi reprezentata ca un vector de
m elemente de tip clasa vector, fiecare avand dimensiunea n, elemente care vor
reprezenta liniile matricii; sa se supraincarce operatorii &lt;&lt; si &gt;&gt; si pentru clasa
matrice de intregi, folosind supraincarcarea operatorilor &lt;&lt; si &gt;&gt; pentru clasa
vector de intregi; sa se creeze o metoda pentru adunarea a doua matrici, care sa
supraincarce operatorul +;
o sa se scrie o functie care sa aiba ca parametri o matrice de intregi A cu m linii si n
coloane, un vector de intregi x de dimensiune n privit ca vector coloana, si un
vector de intregi y de dimensiune m privit tot ca vector coloana, si care sa verifice
daca Ax=y, folosind produsul scalar din clasa vector de intregi; */

#include <iostream>
#include <fstream>

using namespace std;

ifstream f("Exemplu.txt");

class Vector{

private:
    int Lungime;
    int Nr_Intregi[100];
public:
    int Suma();
    void Ordoneaza();
    void Gasire_Maxim();
    int Get_Lungime();
    void Set_Lungime(int x=0);
    friend class Matrice;
    friend ifstream& operator>>(ifstream &In_Vect, Vector &Vect_In);
    friend ostream& operator<<(ostream &out, Vector &Vect_Out);
    int operator*(Vector &obj){
    int aux=0;
    for(int i = 0; i < Lungime; i++)
           aux = aux + Nr_Intregi[i]*obj.Nr_Intregi[i];
    return aux;
    }

    Vector operator+(Vector &obj){
    Vector aux;
    aux.Lungime=obj.Lungime;
    for(int i = 0; i<Lungime; i++)
        aux.Nr_Intregi[i]=Nr_Intregi[i]+obj.Nr_Intregi[i];
    return aux;
    }

};

int Vector::Get_Lungime(){
return Lungime;
}

void Vector::Set_Lungime(int x){
this->Lungime=x;
}

void Vector::Gasire_Maxim(){
int Maxim = this->Nr_Intregi[0];
for(int i = 1; i<this->Lungime; i++)
    if(Maxim < this->Nr_Intregi[i])
        Maxim = this->Nr_Intregi[i];
int Pozitie;
for(int i=0;i<this->Lungime;i++)
    if(Maxim == this->Nr_Intregi[i])
        Pozitie = i;
        cout << "Maximul este " << Maxim << " si pozitia pe care se gaseste este " << Pozitie << endl;
}


void Vector::Ordoneaza(){  //Ordonare bubble sort
int aux;
for(int i=0; i<this->Lungime;i++)
    for(int j=i+1; j<this->Lungime;j++)
        if(this->Nr_Intregi[i]>this->Nr_Intregi[j]){
                aux = this->Nr_Intregi[i];
                this->Nr_Intregi[i]= this->Nr_Intregi[j];
                this->Nr_Intregi[j] = aux;
}

}
int Vector::Suma(){  //Suma elementelor unui vector
    int suma=0;

for(int i = 0; i<this->Lungime; i++)
    suma = suma + this->Nr_Intregi[i];

return suma;
}


ifstream& operator >> (ifstream &In_Vect, Vector &Vect_In){ //Citire vector din fisier
    f>>Vect_In.Lungime;

    for(int i = 0;i < Vect_In.Lungime; i++)
        f >> Vect_In.Nr_Intregi[i];
    return In_Vect;
}

ostream& operator << (ostream &out, Vector &Vect_Out){ //Afisare Vector

for(int i = 0; i < Vect_Out.Lungime; i++)
    out << Vect_Out.Nr_Intregi[i] << " ";
return out;
}

class Matrice{
private:
    int NrLinii;
    Vector A[100];
public:

    friend ifstream& operator>>(ifstream &In_Matr, Matrice &Matr_In);
    friend ostream& operator<<(ostream &out, Matrice &Matr_Out);
    friend void test(Matrice A,Vector x,Vector y);
    int Get_NrLinii();
    Matrice operator +(Matrice &matr_obj){ //Adunare Matrice
    Matrice aux;
    aux.NrLinii = matr_obj.NrLinii;
        for(int i=0; i<matr_obj.NrLinii; i++){
                aux.A[i]= A[i] + matr_obj.A[i];
        }

        return aux;
    }
    void test(Matrice A,Vector x,Vector y);


};


ifstream& operator>>(ifstream &In_Matr, Matrice &Matr_In){ //Citire matrice din fisier
f >> Matr_In.NrLinii;
    for(int i=0; i < Matr_In.NrLinii; i++)
        f >> Matr_In.A[i];

return In_Matr;
}

ostream& operator<<(ostream &out_m, Matrice &Matr_Out){ //Afisare matrice
for(int i=0; i<Matr_Out.NrLinii; i++)
    out_m << Matr_Out.A[i] << endl;
return out_m;
}


void Matrice::test(Matrice A,Vector x,Vector y){
            int ok = 1;
            Vector Aux;
            Aux.Lungime = x.Lungime;
            for(int i=0; i < A.NrLinii; i++){
                Aux.Nr_Intregi[i] = A.A[i] * x;
                if(y.Nr_Intregi[i] != Aux.Nr_Intregi[i])
                    ok = 0;
            }
            if(ok)
                cout << "Ecuatia este satisfacuta" << endl;
            else
                cout << "Ecuatia nu este satisfacuta" << endl;

}




int main(){
Vector x,y;
f>>x;
f>>y;
Matrice M,N,P;
f>>M;
cout << M;
cout << endl;

f>>N;
cout << N;
cout << endl;

P = M + N;

cout << P;
cout << endl;

cout << x << endl;
cout << y << endl;
P.test(N,x,y);
return 0;
}
