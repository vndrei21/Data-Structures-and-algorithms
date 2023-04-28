#include "Colectie.h"
#include "IteratorColectie.h"
#include <exception>
#include <iostream>

using namespace std;


Colectie::Colectie() {
	/* de adaugat */
    capacitate = 10;
    len = 0;
    elems = new TElem[capacitate];
    urm = new int[capacitate];
    prim=-1;
    for(int i = 0; i < capacitate ; ++i)
        urm[i] = i + 1;
    prim_liber = 0;
}


void Colectie::adauga(TElem elem) {
	/* de adaugat */
    if(len == capacitate)
        redim();
    len ++;
    int i = prim_liber;
    prim_liber=urm[prim_liber];
    elems[i] = elem;
    urm[i] = prim;
    prim = i;
}


bool Colectie::sterge(TElem elem) {
	/* de adaugat */
    int iterator = this->prim;
    if(dim() == 0)
        return false;

    if(this->elems[this->prim] == elem) {
        int new_prim = this->urm[this->prim];
        this->urm[this->prim] = prim_liber;
        prim_liber = this->prim;
        this->prim = new_prim;
        this->len--;
        return true;
    }
    else
    while(this->urm[iterator] != -1)
    {
        if(this->elems[this->urm[iterator]] == elem)
        {
            int new_liber = urm[iterator];
            this->urm[iterator] = this->urm[urm[iterator]];
            this->urm[new_liber] = this->prim_liber;
            this->prim_liber = new_liber;
            this->len--;
            return true;
        }
        iterator = this->urm[iterator];
    }
	return false;
}

bool Colectie::cauta(TElem elem) const {
	/* de adaugat */
    int iterator = prim;
    while(iterator != -1)
    {
        if(elems[iterator] == elem)
            return true;
        iterator = urm[iterator];
    }
	return false;
}

int Colectie::nrAparitii(TElem elem) const {
	/* de adaugat */
    int iterator = prim;
    int contor =0;
    while(iterator != -1)
    {
        if(elems[iterator] == elem)
            contor++;
        iterator = urm[iterator];
    }
	return contor;
}


int Colectie::dim() const {
	/* de adaugat */
	return len;
}


bool Colectie::vida() const {
	/* de adaugat */
	return prim == -1;
}

IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}


Colectie::~Colectie() {
    delete [] elems;
    delete [] urm;
	/* de adaugat */
}

void Colectie::redim() {
    TElem * new_elems = new TElem [this->capacitate*2];
    int* new_urm = new TElem [this->capacitate*2];
    for(int i = 0 ; i <this->capacitate; ++i)
        new_elems[i] = this->elems[i];
    for(int i = 0; i < this->capacitate * 2; ++i)
        new_urm[i] = i + 1;
    for(int i = 0; i < this->capacitate ; ++i)
        new_urm[i] = this->urm[i];
    this->capacitate = this->capacitate*2;
    prim_liber = len;
        delete [] elems;
    delete [] urm;
    this->elems = new_elems;
    this->urm = new_urm;
}

void Colectie::afisare() {

    int iterator = prim;
    while(iterator != -1) {
        cout << iterator << " " << elems[iterator] << " " << urm[iterator] << endl;
        iterator = urm[iterator];
    }

}


