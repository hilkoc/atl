#include "../include/DefaultNumberFactoryImpl.h"
#include "../include/ComplexNumber.h"
#include "../include/Vector.h"


//implementation of DefaultNumberFactoryImpl

Complex::Ptr DefaultNumberFactoryImpl::createComplex(real_type realVal , real_type imagVal ) const {
    return Complex::Ptr(new ComplexNumber(realVal, imagVal));
}

Group<Real>::Ptr DefaultNumberFactoryImpl::createReal(real_type value ) const {
    return Group<Real>::Ptr(new RealNumber(value));
}


AbstractVector<Real>::ModulePtr DefaultNumberFactoryImpl::createRealVector3(real_type x0, real_type x1, real_type x2) const {
    int const n = AbstractVector<Real>::getDimension();
    AbstractVector<Real>::RingPtr* entries = new AbstractVector<Real>::RingPtr[n];
    entries[0] = AbstractVector<Real>::RingPtr(new RealNumber(x0));
    entries[1] = AbstractVector<Real>::RingPtr(new RealNumber(x1));
    entries[2] = AbstractVector<Real>::RingPtr(new RealNumber(x2));
    AbstractVector<Real>::ModulePtr result(new vec::Vector<Real>(entries));
    delete[] entries;
    return result;
 }

NumberFactory::DualPtr DefaultNumberFactoryImpl::createDualVector(const AbstractVector<Real>::ModulePtr vectr) const {
    NumberFactory::DualPtr result;
    return result;
}