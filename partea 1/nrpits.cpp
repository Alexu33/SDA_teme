#include <bits/stdc++.h>
using namespace std;

ifstream f("nrpits.in");
ofstream g("nrpits.out");


stack<int> s;



///
/// Structura de date folosita: stack. Am folosit stack pentru a simula gropile. Daca intalneam o valoare mai mare, ea devenea noul capat.
/// Complexitate: O(n). Iau fiecare valoare doar.
///
/// am inserat de la inceput primul element. Dupa pentru fiecare element nou care devine capat:
/// - daca am deja cel putin 2 elemente, atunci e o secventa (el e al 3lea) => incremenetez nr de secvente.
/// - scot capatul vechi
/// ma opresc cand nu mai e niciun element sau nu mai e niciun element <= decat el, dupa care il adaug la final.
///
///



int main()
{
    //s.push(1e9);
    int n,x,nr;
    nr = 0;
    f >> n >> x;
    s.push(x);
    for(int i=1;i<n;i++)
    {
        f >> x;
        while(x > s.top())
        {
            if(s.size() >= 2)
                nr++;
            s.pop();
            if(s.empty())
                break;
        }
        s.push(x);
    }
    //cout << nr;
    g << nr;


}
