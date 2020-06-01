#include <iostream>

using namespace std;

struct Nod
    {
    int Data;
    Nod *Dreapta, *Stanga;
    };



Nod *Rad = NULL;



void SetNode(Nod* &nod,int Valoare)
    {
    Nod *new_nod = new Nod;
    new_nod->Data = Valoare;
    new_nod->Stanga = NULL;
    new_nod->Dreapta = NULL;
    nod = new_nod;
    }



void InsertNode(Nod* &nod, int Valoare)
    {
        if(nod == NULL)
            SetNode(nod,Valoare);
        else if(Valoare <= nod->Data)
            InsertNode(nod->Stanga,Valoare);
        else if(Valoare >= nod->Data)
            InsertNode(nod->Dreapta,Valoare);
    }



void Afisare(Nod* &nod)
    {
        cout << nod->Data << endl;
        if(nod->Stanga != NULL)
            Afisare(nod->Stanga);

        if(nod->Dreapta != NULL)
            Afisare(nod->Dreapta);
    }



Nod *GasesteMin(Nod* &nod)
    {
        if(nod->Stanga != NULL)
            GasesteMin(nod->Stanga);
        else
            return nod;
    }


Nod *GasesteNod(Nod* &nod, int Valoare)
{
    if(Valoare == nod->Data)
        return nod;
    else if(Valoare > nod->Data)
        GasesteNod(nod->Dreapta,Valoare);
    else if(Valoare < nod->Data)
        GasesteNod(nod->Stanga,Valoare);
}

void StergeNod(Nod* &nod,int Valoare)
{

    if(nod->Dreapta == NULL && nod->Stanga == NULL && Valoare == nod->Data)
        nod = NULL;
    else if (nod->Dreapta == NULL && Valoare == nod->Data)
    {
        nod = nod->Stanga;
    }
     else if (nod->Stanga == NULL && Valoare == nod->Data)
    {
        nod = nod->Dreapta;
    }
    else if(Valoare == nod->Data)
    {
        Nod *del_nod = GasesteMin(nod->Dreapta);
        nod->Data = del_nod->Data;
        StergeNod(nod->Dreapta,nod->Data);
    }
    else if(Valoare > nod->Data)
        StergeNod(nod->Dreapta,Valoare);
    else if(Valoare < nod->Data)
        StergeNod(nod->Stanga,Valoare);

}


int main()
{
    InsertNode(Rad,25);
    InsertNode(Rad,15);
    InsertNode(Rad,50);
    InsertNode(Rad,10);
    InsertNode(Rad,22);
    InsertNode(Rad,35);
    InsertNode(Rad,70);
    InsertNode(Rad,4);
    InsertNode(Rad,12);
    InsertNode(Rad,18);
    InsertNode(Rad,24);
    InsertNode(Rad,31);
    InsertNode(Rad,44);
    InsertNode(Rad,66);
    InsertNode(Rad,90);

    Afisare(Rad);
    cout << endl;
    StergeNod(Rad,15);

    Afisare(Rad);
    return 0;
}
