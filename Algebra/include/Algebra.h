#ifndef ALGEBRA_H
#define ALGEBRA_H
#include <memory>

/**
 * A Group is a set with an assosiative binary operator, for which there exists a neutral element and every element has an inverse.
 */
template <typename T>
class Group {
public:
    virtual ~Group(){}
    typedef std::shared_ptr<T> Ptr;

    virtual bool equals(const Ptr rhs) const = 0;
    virtual Ptr plus(const Ptr rhs) const = 0;
    virtual Ptr minus(const Ptr rhs) const = 0;
    //virtual Ptr minus() const = 0; //invalid covariant return type
    friend  bool operator==(const Ptr lhs, const Ptr rhs) {
        return lhs->equals(rhs);
    }
    friend  bool operator!=(const Ptr lhs, const Ptr rhs) {
        return !lhs->equals(rhs);
    }
    friend  Ptr operator+(const Ptr lhs, const Ptr rhs) {
        return lhs->plus(rhs);
    }
    friend  Ptr operator-(const Ptr lhs, const Ptr rhs) {
        return lhs->minus(rhs);
    }
    //friend  Ptr operator-(const Ptr lhs) {
    //    return lhs->minus();
    //}
};

/** 
 * A module is an Abelian Group which supports multiplication by a scalar from a Ring R.
 */
template <typename R, typename M = R>
class Module : public virtual Group<M> {
public:
    virtual ~Module(){}
    //g++ doesn't understand that 'Ptr' is Group<T>::Ptr
    typedef typename Group<M>::Ptr ModulePtr;
    typedef typename Group<R>::Ptr  RingPtr;

    virtual ModulePtr scalarTimes(const RingPtr rhs) const = 0;

    friend  ModulePtr operator*(const RingPtr lhs, const ModulePtr rhs) {
        return rhs->scalarTimes(lhs);
    }
};


/** Template specialization to create a Ring.
 *  A Ring is a Group with multiplication.
 *  The function 'scalarTimes' is removed in favour of just 'times'.
 *  Also division is added, but this is only possible if the denominator is invertible.
 */
template <typename R>
class Module<R,R> : public virtual Group<R> {
public:
    virtual ~Module(){}
    typedef Module<R,R> Ring; //in c++11 we can replace this with alias declaration

    //g++ doesn't understand that 'Ptr' is Group<T>::Ptr
    typedef typename Group<R>::Ptr  Ptr;

    /** Removed 'scalarTimes' in favour of just 'times'*/
    virtual Ptr times(const Ptr rhs) const = 0;
    virtual Ptr divide(const Ptr rhs) const = 0; //may throw if rhs is not invertible

    friend  Ptr operator*(const Ptr lhs, const Ptr rhs) {
        return lhs->times(rhs);
    }
    friend  Ptr operator/(const Ptr lhs, const Ptr rhs) { //may throw if rhs is not invertible
        return lhs->divide(rhs);
    }
};

//template <typename R> using Ring = Module<R,R>;

#endif // ALGEBRA_H
