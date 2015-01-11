#ifndef HOMOMORPHISM_H
#define HOMOMORPHISM_H

/**
 * A homomorphism is a map between two groups that preserves the algebraic structure.
 * For two Abelian groups X,Y the set Hom(X,Y) is itself a group.
 */
template <typename X, typename Y>
class Homomorphism : public virtual Group<Homomorphism<X,Y> > {
public:
    virtual ~Homomorphism(){}

    //typedef Group<Homomorphism<X,Y> > Hom; //in c++11 we can replace this with alias declaration
	using Hom = Group < Homomorphism<X, Y> > ;

    /** The actual homomorphism itself. X --> Y */
    virtual typename Group<Y>::Ptr of(const typename Group<X>::Ptr x) const = 0;

    typename Group<Y>::Ptr operator()(const typename Group<X>::Ptr x) const {
        return of(x);
    }
};

/**
 * For a Ring R and two R-modules X and Y,
 * a Module Homomorphism is an 'R-linear' group homomorphism.
 * For two R-modules the set R-Hom(X,Y) is itself an R-module.
*/
template <typename R, typename X, typename Y>
class ModuleHomomorphism : public virtual Homomorphism<X, Y >, public virtual Module<R, ModuleHomomorphism<R, X, Y> > {
public:
    virtual ~ModuleHomomorphism(){}

    typedef typename Group<Homomorphism<X,Y> >::Ptr  Ptr;
};

#endif // HOMOMORPHISM_H
