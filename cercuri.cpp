/*Se  dauncercuri  de  razer1,r2,...,rn.   Aceste  cercuri  sunt  “impachetate” intr-un  dreptunghi  astfel:
toatecercurile sunt tangente la baza dreptunghiului, cercurile sunt aranjate in ordinea initiala (cel mai din stanga fiindcercul de raza r1, cel mai din dreapta cercul de razarn), iar cercurile consecutive (de raze ri si respectiv ri+1)sunt tangente.
Sa se scrie un program care calculeazalatimea minima a dreptunghiului in care incap cercurile.Rezultatul se va afisa cu trei zecimale exacte.Spre exemplu, daca n=3, r1=2, r2=1 si r3=2, atunci rezultatul care trebuie afisat este 9.656 */

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
    int n;
    cout << "Dati numarul de cercuri n: ";
    cin >> n;
    cout << endl;
    cout << "Dati lungimile razelor celor n cercuri: " << endl;
    double aux,r1,r2,segment,latimea_dreptunghi=0;

    cout << "r1 : "; cin >> r1; cout << endl;
    cout << "r2 : "; cin >> r2; cout << endl;

    latimea_dreptunghi = latimea_dreptunghi + r1;

    latimea_dreptunghi = latimea_dreptunghi + 2*(sqrt(r1*r2));



    for(int i = 3; i <= n; i++){
        aux = r2;
        cout << "r" << i <<" : "; cin >> r2; cout << endl;
        r1=aux;
        segment = 2*(sqrt(r1*r2));
        latimea_dreptunghi = latimea_dreptunghi + segment;
        }
    latimea_dreptunghi = latimea_dreptunghi + r2;

    cout << "Latimea minima a dreptunghiului este: " << setprecision(4) << latimea_dreptunghi << endl;


return 0;
}
