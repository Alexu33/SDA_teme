#include <bits/stdc++.h>
using namespace std;


ifstream f("knumere.in");
ofstream g("knumere.out");

deque<int> dq;

int ans = INT_MAX;
int n,k;
int first, second;
int lungimeOffset0;


///
/// Structura de date utilizata: deque. Am folosit-o pt a putea da manage la capatul din stanga si cel din dreapta al diferentelor.
/// Complexitate: O(n)
///
/// Ideea problemei e ca trebuie sa stergem numerele de la final sau de la inceput, daca stergem din mijloc, diferenta maxima va creste => gresit => practic trb gasit maximul pt fiecare secventa L
///
/// Am calculat fiecare diferenta consecutiva si am pus-o intr-un vector de diferente. Dupa aceea am inceput sa pun in deque fiecare pozitie, incepand sa simulez toate secventele de lungime L (n-k).
/// Daca gaseam o diferenta mai mare, aceasta devenea capatul din dreapta. din deque. Adaug pozitia respectiva in deque. Daca primele pozitii din deque nu se potrivesc pt a avea sir de lungime L
/// cu indicele curent, atunci le scot. Daca indicele curent este cel putin egal cu L, atunci e o secventa de lungime L => verific minimul intre ce am curent si prima pozitie
///


int main()
{
   f >> n >> k;
   f >> first;
   lungimeOffset0 = n-k-2;


   vector<int> diferente;
   diferente.reserve(n-1);



   for(int i=1;i<n;i++)
   {
       f >> second;
       diferente.push_back(second-first);
       first = second;
   }


    for(int i=0; i < n-1; i++)
    {
       while(!dq.empty() && diferente[dq.back()] <= diferente[i])
        dq.pop_back();


       dq.push_back(i);


       while(!dq.empty() && dq.front() < i - lungimeOffset0 )
        dq.pop_front();

       if(i >= lungimeOffset0)
        ans = min(ans, diferente[dq.front()]);
    }

    //cout << ans << endl;
    g << ans << endl;

}
