#ifndef LINEARALGEBRA_H
#define LINEARALGEBRA_H

#include "Algebra.h"

/**
 * A free module of finite rank D over a Ring R.
 */
template<typename R, int D >
class FreeModule : public virtual Module < R, FreeModule<R, D> > {
protected:
    static int const dim = D;
public:
	virtual ~FreeModule(){}
	typedef FreeModule<R, D> type;
	typedef typename Module<R, FreeModule<R, D> >::ModulePtr ModulePtr;
	typedef typename Module<R, FreeModule<R, D> >::RingPtr   RingPtr;

    static int const getDimension() {
        return dim;
    }

    // prototypes for Group<M>
    virtual bool equals(const ModulePtr rhs) const = 0;
    virtual ModulePtr plus(const ModulePtr rhs) const = 0;
    virtual ModulePtr minus(const ModulePtr rhs) const = 0;
    // prototypes for Module<R,M>
    virtual ModulePtr scalarTimes(const RingPtr rhs) const = 0;

    //prototypes for FreeModule
    /** Return the coordinate at given index*/
    virtual RingPtr get(int const index) const = 0;

    virtual std::ostream& toCout(std::ostream &out) const = 0;


    RingPtr operator[](int const index) const {
        return get(index);
    }

    friend std::ostream&  operator<<(std::ostream& out, ModulePtr const rhs) {
        return out << *rhs;
    }
	friend std::ostream&  operator<< (std::ostream& out, FreeModule const & rhs) {
        return rhs.toCout(out);
    }
};


/**
* A vector space is a free module over a field.
* F a field, D the dimension.
*/
template < typename F, int D >
using Vector = FreeModule < F, D >;

#endif // LINEARALGEBRA_H
