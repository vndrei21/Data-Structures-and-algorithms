#include "Iterator.h"
#include "DO.h"
#include <exception>
using namespace std;




//best case = worst case = overall case =θ(1)
DO::DO(Relatie r) {
	/* de adaugat */
    prim = nullptr;
    rel = r;
}

//adauga o pereche (cheie, valoare) in dictionar
//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
//daca nu exista cheia, adauga perechea si returneaza null

//best case:θ(n) worst case:θ(n^2) overall case:θ(n^2)
TValoare DO::adauga(TCheie c, TValoare v) {
	/* de adaugat */


    TValoare val = NULL_TVALOARE;
    TValoare rez = cauta(c);
    if(rez!=NULL_TVALOARE)
    {
        pointer_nod p = prim;
        while(p!= nullptr) {
            if (p->dict.first == c)
            {
                val = p->dict.second;
                p->dict.second = v;
                return val;
            }
            p = p->urmator();
        }
    }
    TElem d;
    d.first = c;
    d.second = v;
    pointer_nod n = new Nod(d, nullptr);
    n->adress_urmator = prim;
    prim = n;
    pointer_nod p = prim;
    /* while(p->adress_urmator != nullptr && !rel(prim->dict.first,p->dict.first))
    {
           p->dict = p->adress_urmator->dict;
           p = p->urmator();
    }*/
    while(p!= nullptr)
    {
        pointer_nod k = prim;
        while(k->adress_urmator != nullptr)
        {
            if(!rel(k->dict.first,k->urmator()->dict.first))
                swap(k->dict,k->urmator()->dict);
            k = k->adress_urmator;
        }
        p = p->urmator();
    }

	return val;
}

//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null

//best case = worst case = overall case = θ(n)
TValoare DO::cauta(TCheie c) const {
	/* de adaugat */
    pointer_nod p = prim;
    while(p!= nullptr)
    {
        if(p->dict.first == c)
            return p->dict.second;
        p = p->urmator();
    }
	return NULL_TVALOARE;	
}

//sterge o cheie si returneaza valoarea asociata (daca exista) sau null


//best case:θ(n) worst case:θ(n) overall case:θ(n)
TValoare DO::sterge(TCheie c) {
	/* de adaugat */
    TValoare rez;
    if(this->prim == nullptr)
        return NULL_TVALOARE;
    rez = NULL_TVALOARE;
    pointer_nod p = this->prim;
    pointer_nod penultim = new Nod(p->dict, nullptr);
    while(p != nullptr)
    {
        if(p->dict.first == c)
        {
            penultim->adress_urmator = p->adress_urmator;
            rez = p->dict.second;
            break;
        }
        penultim = p;
        p = p->urmator();
    }
    if(p == prim)
        prim = p->adress_urmator;

   if(rez != NULL_TVALOARE)
   {
       delete p;
       delete penultim;
   }

    return rez;
}

//returneaza numarul de perechi (cheie, valoare) din dictionar
//best case = worst case = overall case = θ(n)
int DO::dim() const {
	/* de adaugat */
    int size = 0;
    pointer_nod p = prim;
    while(p!= nullptr)
    {
        size++;
        p = p->urmator();
    }
	return size;
}

//verifica daca dictionarul e vid
// best case = worst case = overall case = θ(n)
bool DO::vid() const {
    return prim == nullptr;
	/* de adaugat */
}

Iterator DO::iterator() const {
	return  Iterator(*this);
}

//best case = worst case = overall case = θ(n)
DO::~DO() {
	/* de adaugat */
    pointer_nod p  = this->prim;
    while(p!= nullptr)
    {
        pointer_nod dealoc = p;
        p = p->urmator();
        delete  dealoc;
    }
}
//complexity:best case:θ(n*m) worst case:θ(n*m) overall case:θ(n*m)
int DO::adaugaInexistente(DO &d) {
    pointer_nod p = d.prim;
    int k = 0;
    while(p!= nullptr)
    {
        if(cauta(p->element().first) == -1)
        {
            adauga(p->element().first,p->element().second);
            k++;
        }
        p = p->urmator();
    }
    return k;
}

//best case = worst case = overall case =θ(1)
Nod::Nod(TElem el, pointer_nod p) {
    dict = el;
    adress_urmator =p;
}


TElem Nod::element() {
    return dict;
}

pointer_nod Nod::urmator() {
    return adress_urmator;
}

