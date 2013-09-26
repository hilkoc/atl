#ifndef VECTORTEMPLATE_H_
#define VECTORTEMPLATE_H_
#include <iostream>
#include <array>

namespace vec {

/*We must assume that T is a Ring, so has type Module<T>::Ring*/
template<typename T, int D=3>
class Vector : public AbstractVector<T,D> {

public:
    typedef typename AbstractVector<T,D>::ModulePtr ModulePtr;
    typedef typename AbstractVector<T,D>::RingPtr RingPtr;

protected:
    //stupid we need to redefine dim or use the longer AbstractVector<T,D>::dim instead
    static int const dim = AbstractVector<T,D>::dim;
    // Could also use std::array<RingPtr> instead
    RingPtr entries[dim];


    void copyEntries(const RingPtr rhsentries[dim]) {
        for(int i=0; i<dim; ++i) {
            entries[i] = rhsentries[i];
        }
    }
public:
    virtual ~Vector();
    Vector() {
    //entries hold garbage now
    }

    // EQUIVALENT Vector(const T* array) {
    Vector(const RingPtr array[dim]) {
        copyEntries(array);
    }

    //copy contructor
    Vector(const Vector<T,D>& rhs) {
        entries = new T[dim];
        std::cout << "vec copy constructor" << std::endl;
        copyEntries(rhs.entries);
    }
    //assignment operator
    Vector& operator= (const Vector<T,D>& rhs) {
        std::cout << "vec assignment operator" << std::endl;
        if(this == &rhs) {
            return *this;
        }
        copyEntries(rhs.entries);
        return *this;
    }
//  //NOT POSSIBLE in this version
//	Vector(const std::initializer_list<T>& il): dim(3) {
//		entries = new T[dim];
//	}

    // prototypes for Group<M>
    virtual bool equals(const ModulePtr rhs) const;
    virtual ModulePtr plus(const ModulePtr rhs) const;
    virtual ModulePtr minus(const ModulePtr rhs) const;
    // prototypes for Module<R,M>
    virtual ModulePtr scalarTimes(const RingPtr rhs) const;
    // prototypes for AbstractVector<R,D>
    virtual RingPtr get(int const index) const {
        return entries[index];
    }

    virtual std::ostream& toCout(std::ostream &out) const;

};

/*
 * The implementation of this template class is part of this header file.
 * The include below is purely cosmetic, but necessary.
 * http://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
 */
#include "Vector.hpp"

}//vec::

#endif /* VECTORTEMPLATE_H_ */
