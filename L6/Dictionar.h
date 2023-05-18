#pragma once


#define NULL_TVALOARE -1
#define MAX 10
typedef int TCheie;
typedef int TValoare;

class IteratorDictionar;

#include <utility>
#include <cmath>

typedef std::pair<TCheie,TValoare> TElem;
class Nod;
typedef Nod* PNod;

class Nod
{
private:
    TElem elem;
    PNod Urm;
public:
    friend class Dictionar;















































































































































































































    friend class IteratorDictionar;
   //PNod()=default;
    Nod(TElem e, PNod u):elem{e},Urm{u}{};

};

class Dictionar {
	friend class IteratorDictionar;
    friend class Nod;
	private:
	/* aici e reprezentarea */
    PNod* elems;
    int cap;
    int len;


	public:

	// constructorul implicit al dictionarului
	Dictionar();

	// adauga o pereche (cheie, valoare) in dictionar	
	//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
	// daca nu exista cheia, adauga perechea si returneaza null: NULL_TVALOARE
	TValoare adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null: NULL_TVALOARE
	TValoare cauta(TCheie c) const;

	//sterge o cheie si returneaza valoarea asociata (daca exista) sau null: NULL_TVALOARE
	TValoare sterge(TCheie c);

	//returneaza numarul de perechi (cheie, valoare) din dictionar 
	int dim() const;

	//verifica daca dictionarul e vid 
	bool vid() const;

	// se returneaza iterator pe dictionar
	IteratorDictionar iterator() const;


	// destructorul dictionarului	
	~Dictionar();

    const int hash_function(TCheie c) const {
        return abs(c) % cap;
    }

};


