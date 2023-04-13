#include "Iterator.h"
#include "DO.h"

using namespace std;

//best case = worst case = overall case =θ(1)
Iterator::Iterator(const DO& d) : dict(d){
	/* de adaugat */
    curent = d.prim;

}
//best case = worst case = overall case =θ(1)
void Iterator::prim(){
	/* de adaugat */
    curent  = dict.prim;
}
//best case = worst case = overall case =θ(1)
void Iterator::urmator(){
    if(!valid())
        throw std ::invalid_argument("Iteratorul nu este valid");
    curent = curent->urmator();
	/* de adaugat */
}
//best case = worst case = overall case =θ(1)
bool Iterator::valid() const{
	/* de adaugat */
	return curent != nullptr;
}
//best case = worst case = overall case =θ(1)
TElem Iterator::element() const{
	/* de adaugat */
    if(valid())
        return pair<TCheie,TValoare>(curent->element().first,curent->element().second);
    //return pair <TCheie, TValoare>  (-1, -1);
        throw std ::invalid_argument("Iteratorul nu este valid");
}


