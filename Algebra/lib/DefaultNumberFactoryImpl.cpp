#include "../include/DefaultNumberFactoryImpl.h"
#include "../include/ComplexNumber.h"
#include "../include/Vector.h"


//implementation of DefaultNumberFactoryImpl

Field<Complex>::Ptr DefaultNumberFactoryImpl::createComplex(real_type realVal , real_type imagVal ) const {
    return Field<Complex>::Ptr(new ComplexNumber(realVal, imagVal));
}

Field<Real>::Ptr DefaultNumberFactoryImpl::createReal(real_type value ) const {
    return Field<Real>::Ptr(new RealNumber(value));
}


Vector<Real,3>::ModulePtr DefaultNumberFactoryImpl::createRealVector3(real_type x0, real_type x1, real_type x2) const {
    int const n = Vector<Real,3>::getDimension();
    Vector<Real,3>::RingPtr* entries = new Vector<Real,3>::RingPtr[n];
    entries[0] = Vector<Real,3>::RingPtr(new RealNumber(x0));
    entries[1] = Vector<Real,3>::RingPtr(new RealNumber(x1));
    entries[2] = Vector<Real,3>::RingPtr(new RealNumber(x2));
    Vector<Real,3>::ModulePtr result(new vec::VectorImpl<Real,3>(entries));
    delete[] entries;
    return result;
 }

NumberFactory::DualPtr DefaultNumberFactoryImpl::createDualVector(const Vector<Real,3>::ModulePtr vectr) const {
    NumberFactory::DualPtr result;
    return result;
}