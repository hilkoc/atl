#ifndef MATRIX_H
#define MATRIX_H
#include "VectorTemplate.h"
#include <iostream>

namespace vec {


//template<typename T, int D> std::ostream& operator<<(std::ostream &out, const DualVector<T,D>& rhs);

template<typename T, int D>
class DualVector : public Vector<T,D> {
//	friend std::ostream& operator<< <>(std::ostream &out, const DualVector<T,D>& rhs);
public:
    //it is necessary to re-implement some constructors
    DualVector() {
        //std::cout << "dual default constructor" << std::endl;
    } //automatically calls the constructor in the base class.
//	DualVector(const DualVector<T,D>& rhs){}; //copy contructor, automatically uses base class's
    DualVector(const T initial[Vector<T,D>::dim]) : Vector<T,D>::Vector(initial) {
    } //initialize with array
    DualVector(const Vector<T,D>& rhs) : Vector<T,D>::Vector(rhs) {
    } //initialize with a normal vector

    /*	DualVector<T,D>& operator= (const DualVector<T,D>& rhs){
    		std::cout << "DUAL vec assignment operator" << std::endl;
    		if(this == &rhs){
    			return *this;
    		}
    		Vector<T,D>::copyEntries(rhs.entries);
    		return *this;
    	}
    */
    virtual std::ostream& toCout(std::ostream &out) const {
        out << "(";
        int i;
        for(i=0; i<DualVector<T,D>::dim-1; ++i) {
            out << this->entries[i] << "," ;
        }
        out << this->entries[i] << ")" ;
        return out;
    }

    T mapTo(const Vector<T,D>& vectorIn) {
        T result = 0;
        for(int i=0; i<Vector<T,D>::dim; i++) {
            result = result+ this->entries[i]*vectorIn.entries[i];
        }
        return result;
    }

    T operator() (const Vector<T,D>& rhs) {
        return mapTo(rhs);
    }
};

template<typename T, int rowDim, int colDim>
class Matrix  : public Vector<DualVector<T,rowDim>,colDim> {
private:
    T value;
public:
    //constructors
    //construct a zero matrix
    Matrix() {};

    //array constructor
    Matrix(const DualVector<T,rowDim> initial[colDim]) :  Vector<DualVector<T,rowDim>,colDim>::Vector(initial) {
        //std::cout << "finished matrix array constructor" << std::endl;
    }
    std::string toString() {
        std::string string = "ok";
        return string;
    }
    T getValue();
    void setValue(T value);
};

template class vec::DualVector<float,5>;
typedef Matrix<float,3,2> Matrix32Float;
#include "Matrix.hpp"
}//vec::


#endif /* MATRIX_H */
