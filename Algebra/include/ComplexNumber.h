#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

//NEED to add the option: -fPIC to g++
#include <iostream>
#include <stdexcept>
#include "Complex.h"


class ComplexNumber : public virtual Complex {
private:
	const real_type re;
	const real_type im;
public:
    // default destructor
	// ComplexNumber(); covered by default arguemnts
	ComplexNumber(real_type realPart = 0, real_type imPart = 0) : re(realPart), im(imPart) {}
	//default copy constructor   , RealNumber(RealNumber const  & rhs);
	//default assignment operator, RealNumber& operator=(RealNumber const & rhs);
	
	/* Ptr = Complex::Ptr */

	virtual bool equals(const Ptr rhs) const  {
		return re==rhs->getReal() && im == rhs->getImaginary();
	}
	virtual Ptr plus(const Ptr rhs) const {
		return Ptr(new ComplexNumber(re + rhs->getReal(), im + rhs->getImaginary()));
	}
	virtual Ptr minus(const Ptr rhs) const {
		return Ptr(new ComplexNumber(re - rhs->getReal(), im - rhs->getImaginary()));
	}
	virtual Ptr minus() const {
		return Ptr(new ComplexNumber(-re , -im ));
	}

	virtual real_type getReal() const {
		return re;
	}
	virtual real_type getImaginary() const {
		return im;
	}

	Ptr times(const Ptr rhs) const {
		return Ptr(new ComplexNumber(re * rhs->getReal() - im * rhs->getImaginary(), re * rhs->getImaginary() + im * rhs->getReal()) );
	}

	//may throw if rhs is not invertible
	Ptr divide(const Ptr rhs) const {
		if (rhs->getReal() == 0 && rhs->getImaginary() == 0) {
			throw std::invalid_argument("Cannot divide by zero!");
		}
		real_type rhsNorm = rhs->getReal() * rhs->getReal() + rhs->getImaginary() * rhs->getImaginary();
		real_type realPart = re * rhs->getReal() + im * rhs->getImaginary();
		real_type imPart = - re * rhs->getImaginary() + im * rhs->getReal();
		return Ptr( new ComplexNumber(realPart / rhsNorm, imPart/rhsNorm) );
	}

	friend std::ostream&  operator<<(std::ostream& out, ComplexNumber const & rhs) {
		return out << rhs.getReal() << " + i" << rhs.getImaginary();
	}
};


class RealNumber : public virtual Real {
private:
	const real_type re;
public:
    // default destructor
    virtual ~RealNumber(){
        //std::cout << "~Real " << re << std::endl;
    }
	// RealNumber(); covered by default argument
	RealNumber(real_type realValue = 0) : re(realValue) {
        //std::cout << " Real " << re << std::endl;
	}
	//default copy constructor   , RealNumber(RealNumber const  & rhs);
	//default assignment operator, RealNumber& operator=(RealNumber const & rhs);
	virtual real_type getReal() const {
		return re;
	}
	virtual real_type getImaginary() const {
		return real_type(0);
	}

	virtual bool equals(const ComplexPtr rhs) const {
		return re==rhs->getReal() && this->getImaginary() == rhs->getImaginary();
	}
	virtual ComplexPtr plus(const ComplexPtr rhs) const {
		return ComplexPtr(new ComplexNumber(re + rhs->getReal(), this->getImaginary() + rhs->getImaginary()));
	}
	virtual ComplexPtr minus(const ComplexPtr rhs) const {
		return ComplexPtr(new ComplexNumber(re - rhs->getReal(), this->getImaginary() - rhs->getImaginary()));
	}
	virtual ComplexPtr minus() const {
		return ComplexPtr(new RealNumber(-re) );
	}

	virtual bool equals(const RealPtr rhs) const {
		return re==rhs->getReal();
	}
	virtual RealPtr plus(const RealPtr rhs) const {
		return RealPtr(new RealNumber(re + rhs->getReal()));
	}
	virtual RealPtr minus(const RealPtr rhs) const {
		return RealPtr(new RealNumber(re - rhs->getReal()));
	}
	//    virtual RealPtr minus() const {
	//        return RealPtr(new RealNumber(-re) );
	//    }

	RealPtr times(const RealPtr rhs) const {
		return RealPtr(new RealNumber(re * rhs->getReal()));
	}
	//may throw if rhs is not invertible
	RealPtr divide(const RealPtr rhs) const {
		if (rhs->getReal() == 0 ) {
			throw std::invalid_argument("Cannot divide by zero!");
		}
		return RealPtr(new RealNumber(re / rhs->getReal()));
	}

	ComplexPtr times(const ComplexPtr rhs) const {
		return ComplexPtr(new ComplexNumber(re * rhs->getReal(), re * rhs->getImaginary()) );
	}

	//may throw if rhs is not invertible
	ComplexPtr divide(const ComplexPtr rhs) const {
		if (rhs->getReal() == 0 && rhs->getImaginary() == 0) {
			throw std::invalid_argument("Cannot divide by zero!");
		}
		real_type rhsNorm = rhs->getReal() * rhs->getReal() + rhs->getImaginary() * rhs->getImaginary();
		real_type realPart = re * rhs->getReal();
		real_type imPart = - re * rhs->getImaginary();
		return ComplexPtr( new ComplexNumber(realPart / rhsNorm, imPart/rhsNorm) );
	}

	friend std::ostream&  operator<<(std::ostream& out, RealNumber const & rhs) {
		return out << rhs.getReal();
	}
};

#endif // COMPLEXNUMBER_H
