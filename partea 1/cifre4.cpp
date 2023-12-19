#include <bits/stdc++.h>
using namespace std;


ifstream f("cifre4.in");
ofstream g("cifre4.out");


queue<long long> coada;
vector<int> resturi;
const int MAX_REST = 6000001;



int cifre[] = {2, 3, 5 ,7};
int t, n, p;
long long actual, nou;
int i;


///
/// Structura de date folosita: queue. Mereu iau cea mai mica valoare pe care o inserez.
/// Complexitate: O(T * M) , M = nr de elemente de care am nevoie pt a ajunse la raspuns ( 5^(nr_cifre_raspuns) + 5^(nr_cifre_raspuns - 1) + .... + 5  daca are raspuns, altfel nitel mai mult )
///
/// incep in coada cu 2,3,5,7 si dupa aceea voi genera numerele care deriva din cel curent + ultima cifra 2,3,5,7. Le inserez adaug in ordinea asta in coada ca mereu valoarea cea mai mica sa fie prima
/// ma folosesc si cu un vector de resturi pentru a stii daca am mai intalnit restul respectiv, sa nu intru in ciclu infinit. Daca nu mai am alte resturi pe care le pot intalni si nu am ajuns la solutie, atunci nu exista
/// altfel generez in continuu numerele pana gasesc.
///

long long rezolvare(int n, int p)
{

    /// INIT
    coada = queue<long long>();
    resturi = vector<int>();
    resturi.reserve(MAX_REST);
    for(i=1;i<=MAX_REST;i++)
        resturi.push_back(0);


    for(auto& cifra : cifre)
        coada.push(cifra);

    resturi[2] = resturi[3] = resturi[5] = resturi[7] = 1;


    while(!coada.empty())
    {
        actual = coada.front();
        coada.pop();

        if(actual % p == n)
            return actual;


        /// ADAUGARE NR NOI
        for(auto& cifra : cifre)
        {
            nou = actual*10 + cifra;
            if(resturi[nou % p] == 0)
            {
                resturi[nou % p] = 1;
                coada.push(nou);
            }
        }

    }

    return -1;
}


int main()
{
    f >> t;

    for(int j=1; j<= t;j++)
    {
        f >> n >> p;
        //cout << rezolvare(n,p) << endl;
        g << rezolvare(n,p) << endl;
    }


}

