#include "Matrice.h"

#include <exception>
#include <iostream>

using namespace std;


//best case:θ(1) worst case:θ(1) overall case:θ(1)
Matrice::Matrice(int m, int n) {
	/* de adaugat */
    if(m <= 0 || n <= 0)
        throw std::exception();
    else{
    linie = m;
    coloane = n;
    radacina= nullptr;

    }
}


//best case:θ(1) worst case:θ(1) overall case:θ(1)

int Matrice::nrLinii() const{
	/* de adaugat */
	return linie;
}

//best case:θ(1) worst case:θ(1) overall case:θ(1)

int Matrice::nrColoane() const{
	/* de adaugat */
	return coloane;
}

//best case:θ(1) worst case:θ(h) overall case:O(h)

TElem Matrice::element(int i, int j) const{
	/* de adaugat */
    auto c = cauta(i,j);
    if(c == nullptr)
        return NULL_TELEMENT;
	return c->get_value();
}


//best case:θ(1) worst case:θ(h) overall case:O(h)
TElem Matrice::modifica(int i, int j, TElem e) {
	/* de adaugat */
   // cout << "am intrat\n";
    if(!valid(i,j))
        throw std::exception();
    //cout << "am trecut\n";
    auto n = cauta(i,j);
    if(n == nullptr)
    {
        if(e == 0)
            return NULL_TELEMENT;
            adauga(i, j, e);
        return NULL_TELEMENT;
    }else {
        auto a = n->get_value();
            if(e == 0) {
             stergere(i,j);
            }
            else
                n->set_value(e);
           // stergere(n);
            return a;

    }
}
//best case:θ(1) worst case:θ(Log2 n) overall case:O(Log2 n)
Pnod Matrice::cauta(int i, int j) const {
    return cauta_rec(radacina,i, j);
}
//best case:θ(h) worst case:θ(h) overall case:theta(h)
Pnod Matrice::cauta_rec(Pnod p,int i, int j) const {
    Pnod a;
    if (p == nullptr)
        return nullptr;
        /*else
            if (p->get_linie() == i && p->get_coloana() == j)
            return p;
            else {
            auto a= cauta_rec(p->get_stang(), i, j);
            auto b=   cauta_rec(p->get_drept(), i, j);
        if(a != nullptr)
            return a;
        else
            return b;
            }*/
    else if (p->get_linie() == i && p->get_coloana() == j)
        return p;
    else {
        if (relatie(p->get_linie(), p->get_coloana(), i, j))
             a = cauta_rec(p->get_stang(), i, j);
        else
             a = cauta_rec(p->get_drept(), i, j);

    }
    return a;

}
//best case:θ(1) worst case:θ(1) overall case:θ(1)

bool Matrice::valid(int i, int j) const {
    if(i < 0 || i >= linie)
        return false;
    if(j < 0 || j >= coloane)
        return false;
    return true;
}

//best case:θ(h) worst case:θ(h) overall case:O(h)
void Matrice::adauga(int i, int j, TElem e) {
    radacina = adauga_rec(radacina, i, j, e);

}
//best case:θ(h) worst case:θ(h) overall case:θ(h)

Pnod Matrice::adauga_rec(Pnod p, int i, int j, TElem e) {
        if(p == nullptr)
        {
           // cout << "ADAUGA\n";
            p = new Nod{i,j,e};
        } else
        {
            if(relatie(p->get_linie(),p->get_coloana(),i, j))
                p->set_stang(adauga_rec(p->get_stang(),i,j,e));
            else
                p->set_drept(adauga_rec(p->get_drept(),i,j,e));
        }
    return p;


}
//best case:θ(Log 2 n) worst case:θ(Log2 n) overall case:θ(Log2 n)

void Matrice::dealoca_rec(Pnod p) {
    if (p != nullptr) {
        dealoca_rec(p->get_stang());
        dealoca_rec(p->get_drept());
        delete p;
    }
}
//best case:θ(Log 2 n) worst case:θ(Log2 n) overall case:θ(Log2 n)
Matrice::~Matrice() {
    dealoca_rec(radacina);
}
//best case:θ(1) worst case:θ(n^2*Log2 n) overall case:θ(Log2 n)

int Matrice::valoareMaxima() const {
    TElem maxim = 0;
    if(radacina == nullptr)
        return NULL_TELEMENT;
    for(int i = 0; i < linie; ++i)
        for(int j = 0; j < coloane; ++j)
        {
            auto val = element(i,j);
            if(val > maxim)
                maxim = val;
        }
    return maxim;
}
//best case:θ(1) worst case:θ(H) overall case:0(H)
void Matrice::stergere(int i, int j) {
    sterege_rec(radacina,i,j);

}
//best case:θ(1) worst case:θ(H) overall case:O(H)

Pnod Matrice::sterege_rec(Pnod p, int i, int j) {
    /*Pnod repl = nullptr;
    Pnod temp;
    if(p == nullptr)
        return nullptr;
    else
        if(p->get_stang()!= nullptr && p->get_drept() != nullptr)
        {
             temp = minim(p->get_drept());
            p->set_value(temp->get_value());
            p->set_drept(sterege_rec(minim(p->get_drept())));
            return temp;
        }else
        {
            if(p->get_stang() == nullptr)
                repl = p->get_drept();
            else
                repl = p->get_stang();
        }
    return repl;
*/
    Pnod repl = nullptr;
    Pnod temp;

    if (p == nullptr)
        return nullptr;
    else if (relatie_stergere(p->get_linie(), p->get_coloana(), i, j)) {
        p->set_stang(sterege_rec(p->get_stang(), i, j));
        return p;
    } else if (!relatie(p->get_linie(), p->get_coloana(), i, j)) {
        p->set_drept(sterege_rec(p->get_drept(), i, j));
        return p;
    } else {
        if (p->get_stang() != nullptr && p->get_drept() != nullptr) {
            temp = minim(p->get_drept());
            p->set_value(temp->get_value());
            p->set_drept(sterege_rec(minim(p->get_drept()), i, j));
            return temp;
        } else {
            if (p->get_stang() == nullptr)
                repl = p->get_drept();
            else
                repl = p->get_stang();
        }
    }
    return repl;
}
//best case:θ(n^2) worst case:θ(n^2) overall case:θ(n^2)

Pnod Matrice::minim(Pnod p) {
    int minim = 9999999;
    Pnod min = nullptr;
    for (int i = 0; i < linie; ++i)
        for (int j = 0; j < coloane; ++j) {
            auto a = cauta(i, j);
            if(a == nullptr)
                continue;
            else
                if (minim > a->get_value()) {
                    minim = a->get_value();
                    min = a;
            }

        }
    return min;
}
//best case:θ(1) worst case:θ(1) overall case:θ(1)

bool Matrice::relatie(int i, int j, int x, int y) const {
    if(i >= x)
        return true;
    else if( i == x)
        {
            if( j >= y)
                return true;
            else return false;
        }
    return false;

}
//best case:θ(1) worst case:θ(1) overall case:θ(1)

bool Matrice::relatie_stergere(int i, int j, int x, int y)
{
    if(i == x && j == y)
        return false;

    if(i >= x)
        return true;
    else if( i == x)
    {
    if( j >= y)
        return true;
    else return false;
    }
return false;
}

void Matrice::show_matrice() {
    for (int i = 0; i < linie; ++i)
        for (int j = 0; j < coloane; ++j) {
            auto a = cauta(i, j);
            if (a == nullptr)
                continue;
            else
                cout << a->get_linie() << " " << a->get_coloana() << " " << a->get_value() << '\n';
        }
}

/*
 * subalgoritm diferentaMaxMin
 * daca radacina = NIL atunci
 *      returneaza -1
 *      sfdaca
 *      PNOD a <- minim(radacina);
 *      returneaza valoareMaxima() - a->get_value();
 *      sfarsitsubalgoritm
 *
 */
//best case:θ(1) worst case:θ(n^2) overall case:O(n^2)
int Matrice::diferențaMaxMin() {
    if(radacina == nullptr)
        return -1;
    auto a = minim(radacina);
    return this->valoareMaxima() - a->get_value();

}
