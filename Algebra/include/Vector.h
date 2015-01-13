#ifndef VECTORTEMPLATE_H_
#define VECTORTEMPLATE_H_
#include <iostream>
#include <array>

namespace vec {

/**
 * Assume that T is a Ring.
 */
template<typename T, int D=3>
class VectorImpl : public FreeModule<T,D> {

public:
    typedef typename FreeModule<T,D>::ModulePtr ModulePtr;
    typedef typename FreeModule<T,D>::RingPtr RingPtr;

protected:
    //stupid we need to redefine dim or use the longer FreeModule<T,D>::dim instead
    static int const dim = FreeModule<T,D>::dim;
    // Could also use std::array<RingPtr> instead
    RingPtr entries[dim];


    void copyEntries(const RingPtr rhsentries[dim]) {
        for(int i=0; i<dim; ++i) {
            entries[i] = rhsentries[i];
        }
    }
public:
	virtual ~VectorImpl();
	VectorImpl() {
    //entries hold garbage now
    }

    // EQUIVALENT Vector(const T* array) {
	VectorImpl(const RingPtr array[dim]) {
        copyEntries(array);
    }

    //copy contructor
	VectorImpl(const Vector<T, D>& rhs) {
        entries = new T[dim];
        std::cout << "vec copy constructor" << std::endl;
        copyEntries(rhs.entries);
    }
    //assignment operator
	VectorImpl& operator= (const VectorImpl<T, D>& rhs) {
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
    // prototypes for FreeModule<R,D>
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
