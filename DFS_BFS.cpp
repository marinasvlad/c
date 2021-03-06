#include <iostream>
#include <fstream>
using namespace std;

void citire(int Citit[][11], int NrNoduri, int NrMuchii, ifstream &f){
int Nod1, Nod2;

for(int i = 0 ; i < 11; i++)
    for(int j = 0; j < 11; j++)
        Citit[i][j] = 0;


for(int i=0; i < NrMuchii; i++)
    {
    f >> Nod1 >> Nod2;
    Citit[Nod1][0]++;
    Citit[Nod2][0]++;
    Citit[Nod1][Citit[Nod1][0]] = Nod2;
    Citit[Nod2][Citit[Nod2][0]] = Nod1;
    cout << Nod1 << " " << Nod2 << endl;
    }

}

void DFS(int Nod,int Muchie[][11],bool DFS_Vizitat[])
{
        cout << Nod << " ";
        DFS_Vizitat[Nod] = true;
        for(int i = 1; i <= Muchie[Nod][0]; i++)
        {
            int Urmatorul = Muchie[Nod][i];
            if(!DFS_Vizitat[Urmatorul])
            {
                DFS_Vizitat[Urmatorul] = true;
                DFS(Urmatorul,Muchie,DFS_Vizitat);
            }
        }

}

void Push(int Coada[], int &k, int Numar){
    k = k + 1;
    Coada[k] = Numar;
}

void Pop(int Coada[], int &k){
    for(int i = 0; i < k ; i++)
        Coada[i] = Coada[i + 1];
    k = k - 1;
}

int Front(int Coada[]){
return Coada[0];
}

bool IsEmpty(int &k){
if(k == -1)
    return 1;
else return 0;
}

void AfisareCoada(int Coada[],int &k){
for(int i=0;i < k+1; i++)
    cout<<Coada[i]<< " ";
}

void BFS(int Muchii[][11],int Coada[],bool BFS_Vizitat[], int &k){
    int Nod;

while(!IsEmpty(k)){

    Nod = Front(Coada);

    cout << Nod << " ";

    BFS_Vizitat[Nod] = true;

    Pop(Coada,k);

    for (int i=1; i<=Muchii[Nod][0];i++){
        int Urmatorul = Muchii[Nod][i];
        if(!BFS_Vizitat[Urmatorul])
        {
            BFS_Vizitat[Urmatorul] = true;
            Push(Coada,k,Urmatorul);
        }
    }

}

}

int main(){
ifstream f("Exemplu.txt");
int k=-1;
int Coada[100];
bool *D_vizitat = new bool[20];
bool *B_vizitat = new bool[20];
int Muchii[11][11];

int NrNoduri, NrMuchii;

f >> NrNoduri >> NrMuchii;

citire(Muchii,NrNoduri,NrMuchii,f);

cout << "DFS: ";
DFS(3,Muchii,D_vizitat);
Push(Coada,k,3);
cout << endl;
cout << "BFS: ";
BFS(Muchii,Coada,B_vizitat,k);

return 0;
}
