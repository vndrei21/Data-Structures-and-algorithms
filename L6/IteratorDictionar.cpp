#include "IteratorDictionar.h"
#include "Dictionar.h"

using namespace std;

//best case:θ(1) worst case:θ(n) overall case:O(n)

IteratorDictionar::IteratorDictionar(const Dictionar& d) : dict(d){
	/* de adaugat */
    poz = 0;
    deplasare();
}

//best case:θ(1) worst case:θ(n) overall case:O(n)
void IteratorDictionar::prim() {
	/* de adaugat */
    poz = 0;
    deplasare();
}

//best case:θ(1) worst case:θ(n) overall case:O(n)

void IteratorDictionar::urmator() {
	/* de adaugat */
    if(!valid())
        throw("Iterator invalid!");
    curent = curent->Urm;
    if(curent == nullptr)
    {
        poz+=1;
        deplasare();
    }
}

//best case:θ(1) worst case:θ(1) overall case:θ(1)

TElem IteratorDictionar::element() const{
	/* de adaugat */
    if(!valid())
        throw ("iterator invalid");
	return curent->elem;
}

//best case:θ(1) worst case:θ(1) overall case:θ(1)

bool IteratorDictionar::valid() const {
	/* de adaugat */

	return poz < dict.cap;
}

//best case:θ(1) worst case:θ(n) overall case:O(n)
void IteratorDictionar::deplasare() {
    while(dict.cap > poz && dict.elems[poz] == nullptr)
        poz++;
    if( dict.cap > poz)
        curent = dict.elems[poz];
}

