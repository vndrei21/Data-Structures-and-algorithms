#include "IteratorColectie.h"
#include "Colectie.h"
using namespace std;

IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
	/* de adaugat */
    curent = col.prim;
}

void IteratorColectie::prim() {
	/* de adaugat */
    curent = col.prim;
}


void IteratorColectie::urmator() {
	/* de adaugat */
    if(!valid())
        throw ("Iterator invalid");
    else
        curent = col.urm[curent];
}



bool IteratorColectie::valid() const {
	/* de adaugat */
    if(curent == -1)
	    return false;
    return true;
}



TElem IteratorColectie::element() const {
	/* de adaugat */
    if(!valid())
        throw("Iterator invalid");
    else
        return col.elems[curent];
}
