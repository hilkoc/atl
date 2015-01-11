#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include "Algebra.h"

#define REAL_TYPE double

typedef REAL_TYPE real_type;

class Complex : public virtual Field<Complex> {
public:
    virtual ~Complex(){}
    virtual bool equals(const Ptr rhs) const = 0;
    virtual Ptr plus(const Ptr rhs) const = 0;
    virtual Ptr minus(const Ptr rhs) const = 0;
    virtual Ptr minus() const = 0;

    virtual Ptr times(const Ptr rhs) const = 0;
    virtual Ptr divide(const Ptr rhs) const = 0; //may throw if rhs is not invertible

    virtual real_type getReal() const = 0;
    virtual real_type getImaginary() const = 0;

    friend std::ostream&  operator<<(std::ostream& out, Complex const & rhs) {
        return out << rhs.getReal() << " +  i " << rhs.getImaginary();
    }
    friend std::ostream&  operator<<(std::ostream& out, Complex::Ptr const rhs) {
        return out << *rhs;
    }
};


class Real : public Complex , public virtual Field<Real>
{
public:
    virtual ~Real(){}
    typedef Field<Complex>::Ptr ComplexPtr;
    typedef Field<Real>::Ptr RealPtr;

    virtual bool equals(const ComplexPtr rhs) const = 0;
    virtual ComplexPtr plus(const ComplexPtr rhs) const = 0;
    virtual ComplexPtr minus(const ComplexPtr rhs) const = 0;
    virtual ComplexPtr minus() const = 0;

    virtual bool equals(const RealPtr rhs) const = 0;
    virtual RealPtr plus(const RealPtr rhs) const = 0;
    virtual RealPtr minus(const RealPtr rhs) const = 0;
    //virtual RealPtr minus() const = 0; //cannot be overloaded

    virtual ComplexPtr times(const ComplexPtr rhs) const = 0;
    virtual ComplexPtr divide(const ComplexPtr rhs) const = 0; //may throw if rhs is not invertible
    virtual RealPtr times(const RealPtr rhs) const = 0;
    virtual RealPtr divide(const RealPtr rhs) const = 0; //may throw if rhs is not invertible

	/** Overload scalarTimes function from the Module interface.
	 * This is necessary, otherwise there is ambiguity on the return types
	*/
	virtual RealPtr scalarTimes(const RealPtr rhs) const { return this->times(rhs); }

    friend std::ostream&  operator<<(std::ostream& out, Real const & rhs) {
        return out << rhs.getReal() ;
    }
    friend std::ostream&  operator<<(std::ostream& out, RealPtr const rhs) {
        return out << *rhs;
    }
};

#endif // COMPLEX_H
