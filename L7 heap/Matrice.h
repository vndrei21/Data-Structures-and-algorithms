#pragma once
#include "utility"



#define NULL_TELEMENT -1
using namespace std;
class Nod;
typedef int TElem;
typedef Nod* Pnod;

typedef Nod* Pnod;

class Nod
{
protected:
    pair<Pnod,Pnod> descendeti;
    pair<TElem , TElem> pozitie;
    TElem value;
public:
    Nod(int i, int j, TElem valoare):pozitie{i,j},value{valoare},descendeti{nullptr, nullptr}{};
    Pnod get_stang()
    {
        return descendeti.first;
    }
    Pnod get_drept()
    {
        return descendeti.second;
    }
    TElem get_value()
    {
        return value;
    }
    void set_value(TElem val)
    {
        value = val;
    }
    int get_linie()
    {
        return pozitie.first;
    }
    int get_coloana()
    {
        return pozitie.second;
    }
    void set_stang(Pnod P)
    {
        descendeti.first = P;
    }
    void set_drept(Pnod P)
    {
        descendeti.second = P;
    }
};

class Matrice{
    friend class Nod;
private:
	/* aici e reprezentarea */
    Pnod radacina;
    int linie;
    int coloane;
    Pnod adauga_rec(Pnod p,int i, int j,TElem e);
    void adauga(int i, int j, TElem e);
    Pnod cauta(int i, int j) const;
    Pnod cauta_rec(Pnod prim,int i, int j) const;
    void dealoca_rec(Pnod p);
    bool valid(int i, int j) const;
    void stergere(int i, int j);
    Pnod sterege_rec(Pnod p, int i, int j);
    bool relatie_stergere(int i, int j, int x, int y);
    Pnod minim(Pnod p);

public:

	//constructor
	//se arunca exceptie daca nrLinii<=0 sau nrColoane<=0
	Matrice(int nrLinii, int nrColoane);

    bool relatie(int i, int j, int x, int y)const;


    void show_matrice();





	//destructor
	~Matrice();

	//returnare element de pe o linie si o coloana
	//se arunca exceptie daca (i,j) nu e pozitie valida in Matrice
	//indicii se considera incepand de la 0
	TElem element(int i, int j) const;


	// returnare numar linii
	int nrLinii() const;

	// returnare numar coloane
	int nrColoane() const;

    int valoareMaxima()const;

	// modificare element de pe o linie si o coloana si returnarea vechii valori
	// se arunca exceptie daca (i,j) nu e o pozitie valida in Matrice
	TElem modifica(int i, int j, TElem);
    int diferențaMaxMin();

};







