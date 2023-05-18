#include "Dictionar.h"
#include <iostream>
#include "IteratorDictionar.h"




//best case:θ(n) worst case:θ(n) overall case:θ(n)
Dictionar::Dictionar() {
    cap=MAX;
    len = 0;
    elems = new PNod[cap];
    for(int i = 0; i < cap; ++i)
    {
        elems[i] = nullptr;
    }
	/* de adaugat */
}

Dictionar::~Dictionar() {
	/* de adaugat */
    delete []elems;
}
//best case:θ(1) worst case:θ(n) overall case:O(n)
TValoare Dictionar::adauga(TCheie c, TValoare v) {
    /* de adaugat */
    int i = hash_function(c);
    auto rez = cauta(c);
        PNod prim = elems[i];
        while (prim != nullptr) {
            if (prim->elem.first == c) {
                prim->elem.second = v;
                return rez;
            }
            prim = prim->Urm;
        }
        TElem e{c, v};
        PNod nod = new Nod{e, nullptr};
        nod->Urm = elems[i];
        elems[i] = nod;
        len++;
        return NULL_TVALOARE;

}




//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
//best case:θ(1) worst case:θ(n) overall case:O(n)
TValoare Dictionar::cauta(TCheie c) const{
	/* de adaugat */
    auto i = hash_function(c);
        PNod prim = elems[i];
        while (prim != nullptr)
        {
            if(prim->elem.first == c)
                return prim->elem.second;
            prim = prim->Urm;
        }

	return NULL_TVALOARE;
}
//best case:θ(1) worst case:θ(n) overall case:O(n)
TValoare Dictionar::sterge(TCheie c){
	/* de adaugat */
        auto rez = cauta(c);
    int i = hash_function(c);
        if(elems[i] == nullptr)
            return NULL_TVALOARE;
        auto prim = elems[i];
        if(prim->elem.first == c)
        {
            PNod sters = prim;
            elems[i] = elems[i]->Urm;
            len--;
            delete sters;
            return rez;

        }
        while(prim->Urm != nullptr)
        {
            if(prim->Urm->elem.first == c)
            {
                PNod sters = prim->Urm;
                prim->Urm = sters->Urm;
                delete sters;
                len--;
                return rez;
            }
            prim = prim->Urm;
        }

	return NULL_TVALOARE;
}

//best case:θ(1) worst case:θ(1) overall case:θ(1)

int Dictionar::dim() const {
	/* de adaugat */
	return len;
}
//best case:θ(1) worst case:θ(1) overall case:θ(1)

bool Dictionar::vid() const{
	/* de adaugat */
	return len == 0;
}

//best case:θ(1) worst case:θ(1) overall case:θ(1)

IteratorDictionar Dictionar::iterator() const {
	return  IteratorDictionar(*this);
}


