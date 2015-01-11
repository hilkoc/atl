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

	using Ptr = std::shared_ptr < T > ;

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

	using ModulePtr = typename Group<M>::Ptr;
	using RingPtr = typename Group<R>::Ptr;

    virtual ModulePtr scalarTimes(const RingPtr rhs) const = 0;

    friend  ModulePtr operator*(const RingPtr lhs, const ModulePtr rhs) {
        return rhs->scalarTimes(lhs);
    }
};


/** 
 *  A Ring is a Group with multiplication.
 *  It is also an R module over itself.
 *  We also define a division method, but division is only possible if the denominator is invertible.
 */
template <typename R>
class Ring : public virtual Module< R, R > {
public:
    virtual ~Ring(){}

	using Ptr = typename Group<R>::Ptr;
    
    virtual Ptr times(const Ptr rhs) const = 0;
    virtual Ptr divide(const Ptr rhs) const = 0; //may throw if rhs is not invertible

	/** Implement scalarTimes function from the Module interface to ensure it is consistent with times.
	 *  This also ensure that operator* defined in Module:: works as expected.
	 */
	inline virtual ModulePtr scalarTimes(const RingPtr rhs) const {
		return this->times(rhs);
	}

    friend  Ptr operator/(const Ptr lhs, const Ptr rhs) { //may throw if rhs is not invertible
        return lhs->divide(rhs);
    }
};


/**
 * A field is a commutative ring, where every element besides zero has a multiplicative inverse.
 */
template <typename F> using Field = Ring<F>;

#endif // ALGEBRA_H
