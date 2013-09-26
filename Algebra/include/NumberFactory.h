#ifndef NUMBERFACTORY_H
#define NUMBERFACTORY_H

#include "Complex.h"
#include "LinearAlgebra.h"
#include "Homomorphism.h"


class NumberFactory {
public:
    virtual ~NumberFactory(){}

    virtual Complex::Ptr createComplex(real_type realVal = 0, real_type imagVal =  0) const = 0;
    virtual Group<Real>::Ptr createReal(real_type value = 0) const = 0;

    virtual AbstractVector<Real>::ModulePtr createRealVector3(real_type x0=0, real_type x1=0, real_type x2=0) const = 0;

    typedef ModuleHomomorphism<Real, AbstractVector<Real>, Real>::Ptr DualPtr;
    virtual DualPtr createDualVector(const AbstractVector<Real>::ModulePtr vectr) const = 0;
};

#endif // NUMBERFACTORY_H
