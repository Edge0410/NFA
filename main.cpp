#include <bits/stdc++.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
#define NMAX 1000

int nrNoduri, nrMuchii, nodIntrare, nrNoduriIesire, nrTeste, lungimeTest;
bool gasitSol = 0;

vector<vector<pair<int, char>>> listaAdiacenta(1000);
vector<int> noduriIesire;
vector<int> solCurenta; /// stiva ce contine traseul urmat

void valid(int Nod) /// functie ce imi verifica daca nodul pe care ma aflu este nod de iesire
{
    for(int i=0; i<nrNoduriIesire; i++)
        if(noduriIesire[i] == Nod)
        {
            gasitSol = 1;
            fout<<"DA"<<'\n'<<"Traseu: ";
            for(int j=0; j<solCurenta.size(); j++)
                fout<<solCurenta[j]<<" ";
            fout<<'\n';
        }
}

void DFS(int Nod, char * Letters)
{
    solCurenta.push_back(Nod); /// adaug nodul curent in traseu
    if(*Letters == NULL && gasitSol == 0)
    {
        valid(Nod); /// daca am terminat cuvantul verific daca nodul actual e nod de iesire
    }
    else
    {
        for(int i=0; i<listaAdiacenta[Nod].size(); i++)
        {
            if(listaAdiacenta[Nod][i].second == *Letters) /// parcurg toate muchiile care pleaca din nodul curent
                DFS(listaAdiacenta[Nod][i].first, Letters+1);
        }
    }
    solCurenta.pop_back();
}

int main()
{
    int nodFirst, nodSecond, nodIesire;
    char Letter;
    char testString[1000];

    fin>>nrNoduri>>nrMuchii;
    for(int i=0; i<nrMuchii; i++)
    {
        fin>>nodFirst>>nodSecond; /// citesc fiecare muchie si o adaug in lista de adiacenta
        fin>>Letter;
        listaAdiacenta[nodFirst].push_back(make_pair(nodSecond, Letter));
    }
    fin>>nodIntrare; /// citesc nodul de intrare
    fin>>nrNoduriIesire;
    for(int i=0; i<nrNoduriIesire; i++)
    {
        fin>>nodIesire; /// citesc nodurile de iesire si le adaug intr-o lista
        noduriIesire.push_back(nodIesire);
    }
    fin>>nrTeste;
    fin.get();
    for(int i=0; i<nrTeste; i++)
    {
        fin.getline(testString, 1000); /// iau fiecare test in parte si apelez DFS
        gasitSol = 0;
        DFS(nodIntrare, testString);
        if(gasitSol == 0)
            fout<<"NU\n";
    }
    return 0;
}
