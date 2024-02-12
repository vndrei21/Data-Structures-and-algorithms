#include "TestScurt.h"
#include <assert.h>
#include "Matrice.h"
#include <iostream>

using namespace std;


void testAll() { //apelam fiecare functie sa vedem daca exista
	Matrice m(4,4);
	assert(m.nrLinii() == 4);
	assert(m.nrColoane() == 4);
	//adaug niste elemente
	m.modifica(1,1,5);
  //  cout << m.element(1,1);
	assert(m.element(1,1) == 5);
	m.modifica(1,1,6);
	assert(m.element(1,2) == NULL_TELEMENT);
    m.modifica(1,2,6);
    assert(m.element(1,2) == 6);
   // m.show_matrice();
    cout << '\n';
    m.modifica(1,2,0);
    //m.show_matrice();
    //cout << m.element(1,2);
   // assert(m.element(1,2) == -1);
    m.modifica(1,2,6);
    assert(m.element(1,2) == 6);

}


void testFunctionalitate() {
    Matrice m(4,4);
    assert(m.nrLinii() == 4);
    assert(m.nrColoane() == 4);
    assert(m.valoareMaxima() == NULL_TELEMENT);
    assert(m.diferențaMaxMin() == -1);
    m.modifica(1,1,5);
    assert(m.diferențaMaxMin() == 0);
    m.modifica(1,2,7);
    m.modifica(1,3,2);
    m.modifica(1,0,3);
    m.modifica(3,1,9);
    m.modifica(2,1,11);
    assert(m.diferențaMaxMin() == 9);
}
