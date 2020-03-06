/* Matrice de numere complexe reprezentate ca tablouri bidimensionale (ca matrici patratice):
o   clasa numar complex sa contina metode pentru: supraincarcarea operatorilor << si
    >>; suma a doua numere complexe, implementata prin supraincarcarea
    operatorului +; produsul a doua numere complexe, implementat prin
    supraincarcarea operatorului *;
o   clasa matrice sa fie prietena a clasei numar complex si sa contina metode pentru:
    supraincarcarea operatorilor << si >>, apelandu-le pe cele din clasa numar
    complex; suma a doua matrici, implementata prin supraincarcarea operatorului +
    si pe baza functiei de supraincarcare a lui + din clasa numar complex; produsul a
    doua matrici, implementat prin supraincarcarea operatorului * si pe baza functiilor
    de supraincarcare ale lui + si * din clasa numar complex; */





#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

using namespace std;

ifstream f ("example.txt");

class NumarComplex{

private:

    float Real;  //partea reala
    float Img;   //parte imaginara
    friend class Matrice;

public:

    NumarComplex(float Set_Real = 0, float Set_Img = 0);




NumarComplex operator + (NumarComplex const &obj_add){  //declarare si definire supraincarcarea operatorului +

    NumarComplex aux;

    aux.Real = Real + obj_add.Real;

    aux.Img = Img + obj_add.Img;


    return aux;
}

NumarComplex operator * (NumarComplex const &obj_times) {  //declarare si definire supraincarcarea operatorului +

    NumarComplex aux;

    aux.Real = (Real*obj_times.Real) - (Img*obj_times.Img);

    aux.Img = (Real*obj_times.Img) + Img*obj_times.Real;

    return aux;

}

friend ostream& operator << (ostream &out_nrcomplex, const NumarComplex &nr_comOut);

friend ifstream& operator >> (ifstream &in_nrcomplex,NumarComplex &nr_comIn);

};



ostream& operator << (ostream &out_nrcomplex, const NumarComplex &nr_comOut){  // supraincarcare operator afisare << pentru numere complexe

out_nrcomplex << nr_comOut.Real << " + " << nr_comOut.Img << "i" << " ";

return out_nrcomplex;

}

ifstream& operator >> (ifstream &in_nrcomplex, NumarComplex &nr_comIn) {  // supraincarcare operator >> pentru citire de numere complexe din fisiere

    f >> nr_comIn.Real;

    f >> nr_comIn.Img;

    return in_nrcomplex;
}


NumarComplex::NumarComplex(float Set_Real, float Set_Img){  //definirea functiei constructorului

Real = Set_Real;

Img = Set_Img;

}



class Matrice{  //clasa matrice


private:

int n;  // dimensiunea matricei

NumarComplex a[3][3];

public:

Matrice(int index_column = 0 ,int index_line = 0 ,float set_real = 0, float set_imag = 0);



Matrice operator + (Matrice const &obj_matr_add){  //declarare si definire supraincarcarea operatorului "+" pentru matrici

    Matrice aux;
    aux.n = obj_matr_add.n;
    for(int i = 0 ; i < obj_matr_add.n ; i++)
        for( int j = 0 ; j < obj_matr_add.n ; j++)
         aux.a[i][j] = a[i][j] + obj_matr_add.a[i][j];

    return aux;
}

Matrice operator * (Matrice const &obj_matr_times) {  //declarare si definire supraincarcarea operatorului "*" pentru matrici

    Matrice aux;

    aux.n = obj_matr_times.n;

    for( int i = 0; i < obj_matr_times.n ; i++){
        for( int j = 0; j < obj_matr_times.n ; j++){
                aux.a[i][j].Real = 0;
                aux.a[i][j].Img = 0;
            for( int k = 0; k < obj_matr_times.n ; k++){
                    aux.a[i][j] = aux.a[i][j] + (a[i][k]*obj_matr_times.a[k][j]);
            }
        }
    }

    return aux;

}


friend ifstream& operator >> (ifstream &in_matrix,Matrice &matr_in);

friend ostream& operator << (ostream &out_matrix, const Matrice &matr_out);

};



ifstream& operator >> (ifstream &in_matrix, Matrice &matr_in){  // citirea din fisier , supraincarcarea operatorului >> pentru matrici

f >> matr_in.n;

for(int i = 0 ; i < matr_in.n ; i++){

    for(int j = 0 ; j < matr_in.n ; j++)

     f >> matr_in.a[i][j];
}


return in_matrix;
}

ostream& operator << (ostream &out_matrix, const Matrice &matr_out){  // afisare matrice, supraincarcarea operatorului << pentru matrici

for(int i = 0 ; i < matr_out.n ; i++){

    for( int j = 0 ; j < matr_out.n ; j++)
        cout << matr_out.a[i][j];

    cout << endl;
}

return out_matrix;
}



Matrice::Matrice(int index_column ,int index_line ,float set_real , float set_imag ){  // constructor matrice


a[index_line][index_column].Real = set_real;

a[index_line][index_column].Img = set_imag;

}


int main(){


Matrice m;

f >> m;

cout << "Matricea m: " << endl;

cout << m << endl;

Matrice p,q;

f >> p;

cout << "Matricea p: " << endl;

cout << p << endl;

q = m * p;

cout << "Matricea q: " << endl;

cout << q << endl;

return 0;
}



