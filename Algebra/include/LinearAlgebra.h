#ifndef LINEARALGEBRA_H
#define LINEARALGEBRA_H

#include "Algebra.h"

template<typename R, int D=3>
class AbstractVector : public virtual Module<R, AbstractVector<R,D> > {
protected:
    static int const dim = D;
public:
    virtual ~AbstractVector(){}
    typedef AbstractVector<R,D> type;
    typedef typename Module<R, AbstractVector<R,D> >::ModulePtr ModulePtr;
    typedef typename Module<R, AbstractVector<R,D> >::RingPtr   RingPtr;

    static int const getDimension() {
        return dim;
    }

    // prototypes for Group<M>
    virtual bool equals(const ModulePtr rhs) const = 0;
    virtual ModulePtr plus(const ModulePtr rhs) const = 0;
    virtual ModulePtr minus(const ModulePtr rhs) const = 0;
    // prototypes for Module<R,M>
    virtual ModulePtr scalarTimes(const RingPtr rhs) const = 0;

    //prototypes for AbstractVector
    /** Return the coordinate at given index*/
    virtual RingPtr get(int const index) const = 0;

    virtual std::ostream& toCout(std::ostream &out) const = 0;


    RingPtr operator[](int const index) const {
        return get(index);
    }

    friend std::ostream&  operator<<(std::ostream& out, ModulePtr const rhs) {
        return out << *rhs;
    }
    friend std::ostream&  operator<< (std::ostream& out, AbstractVector const & rhs) {
        return rhs.toCout(out);
    }
};

#endif // LINEARALGEBRA_H
