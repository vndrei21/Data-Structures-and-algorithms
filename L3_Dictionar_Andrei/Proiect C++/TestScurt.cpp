#include <cassert>
#include "DO.h"
#include "Iterator.h"
#include "TestScurt.h"

//#include <exception>
using namespace std;

bool relatie1(TCheie cheie1, TCheie cheie2) {
    if (cheie1 <= cheie2) {
        return true;
    }
    else {
        return false;
    }
}

void testAll(){
    DO dictOrd = DO(relatie1);
    assert(dictOrd.dim() == 0);
    assert(dictOrd.vid());
    dictOrd.adauga(1,2);
    assert(dictOrd.dim() == 1);
    assert(!dictOrd.vid());
    assert(dictOrd.cauta(1)!=NULL_TVALOARE);
    TValoare v =dictOrd.adauga(1,3);
    assert(v == 2);
    assert(dictOrd.cauta(1) == 3);
    Iterator it = dictOrd.iterator();
    it.prim();
    while (it.valid()){
        TElem e = it.element();
        assert(e.second != NULL_TVALOARE);
        it.urmator();
    }
    assert(dictOrd.sterge(1) == 3);
    //cout << dictOrd.dim();
    assert(dictOrd.vid());
}

void test_functionalitate() {
    DO dictOrd = DO(relatie1);
    dictOrd.adauga(1,2);
    dictOrd.adauga(2,25);
    dictOrd.adauga(3,44);
    dictOrd.adauga(5,128);
    dictOrd.adauga(7,1);
    dictOrd.adauga(10,33);
    DO d = DO(relatie1);
    d.adauga(2,21);
    assert(dictOrd.adaugaInexistente(d) == 0);

    d.adauga(4,21);
    d.adauga(6,81);
    d.adauga(8,13);
    d.adauga(9,91);
    assert(dictOrd.adaugaInexistente(d) == 4);
}

