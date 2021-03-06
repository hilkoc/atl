#ifndef DEFAULTNUMBERFACTORYIMPL_H
#define DEFAULTNUMBERFACTORYIMPL_H

#include "Export.h"
#include "NumberFactory.h"

class DefaultNumberFactoryImpl : public NumberFactory {
private:
	//prohibit allocation on the heap
	void * operator new   (size_t);
	void * operator new[] (size_t);
	// void   operator delete   (void *); //gives linking errors
	void   operator delete[] (void*);
public:
	virtual ~DefaultNumberFactoryImpl() = default; //not supported in VS
	DefaultNumberFactoryImpl() = default; //not supported in VS

    virtual API_EXPORT Field<Complex>::Ptr createComplex(real_type realVal = 0, real_type imagVal =  0) const ;
    virtual API_EXPORT Field<Real>::Ptr createReal(real_type value = 0) const ;

    virtual API_EXPORT Vector<Real,3>::ModulePtr createRealVector3(real_type x0=0, real_type x1=0, real_type x2=0) const;

    virtual API_EXPORT DualPtr createDualVector(const Vector<Real,3>::ModulePtr vectr) const;
};

#endif // DEFAULTNUMBERFACTORYIMPL_H
