//Destructor
template<typename T, int D>
Vector<T,D>::~Vector(){
}

template<typename T, int D>
bool Vector<T,D>::equals(const typename Vector<T,D>::ModulePtr rhs) const {
    for(int i=0; i <dim; ++i) {
        Vector<T,D>::RingPtr left  = entries[i];
        Vector<T,D>::RingPtr right = rhs->get(i);
        if(	! (left->equals(right)) ) {
            return false;
        }
    }
    return true;
}

/*
 * Two different ways of building new vectors, compare 'plus' and 'minus'.
 */

template<typename T, int D>
typename Vector<T,D>::ModulePtr Vector<T,D>::plus(const typename Vector<T,D>::ModulePtr rhs) const {
	RingPtr entrs[dim];
	for(int i=0; i < Vector<T,D>::dim ; ++i){
	    RingPtr left( this->entries[i] );
	    RingPtr right( (*rhs)[i] );
		entrs[i] =  (left)->plus(right);
	}
	Vector<T,D>::ModulePtr sum(new Vector<T,D>(entrs));
	return sum;
}

template<typename T, int D>
typename Vector<T,D>::ModulePtr Vector<T,D>::minus(const typename Vector<T,D>::ModulePtr rhs) const {
	Vector<T,D>* result(new Vector<T,D>());
	for(int i=0; i < Vector<T,D>::dim ; ++i){
	    RingPtr left( this->entries[i] );
	    RingPtr right( (*rhs)[i] );
		result->entries[i] = left->minus(right);
	}
	return Vector<T,D>::ModulePtr(result);
}

template<typename T, int D>
typename Vector<T,D>::ModulePtr Vector<T,D>::scalarTimes(const typename Vector<T,D>::RingPtr rhs) const {
	Vector<T,D>* result(new Vector<T,D>());
	for(int i=0; i < Vector<T,D>::dim ; ++i){
	    RingPtr left( this->entries[i] );
		result->entries[i] = left->times(rhs);
	}
	return Vector<T,D>::ModulePtr(result);
}

template<typename T, int D>
std::ostream& Vector<T,D>::toCout(std::ostream &out) const{
	for(int i=0; i < Vector<T,D>::dim; ++i){
		out << "|" << this->entries[i] << "|" << std::endl ;
	}
	return out;
}

