//Destructor
template<typename T, int D>
VectorImpl<T,D>::~VectorImpl(){
}

template<typename T, int D>
bool VectorImpl<T,D>::equals(const typename VectorImpl<T,D>::ModulePtr rhs) const {
    for(int i=0; i <dim; ++i) {
        VectorImpl<T,D>::RingPtr left  = entries[i];
        VectorImpl<T,D>::RingPtr right = rhs->get(i);
        if(	! (left->equals(right)) ) {
            return false;
        }
    }
    return true;
}

/*
 * Two different ways of building new VectorImpls, compare 'plus' and 'minus'.
 */

template<typename T, int D>
typename VectorImpl<T,D>::ModulePtr VectorImpl<T,D>::plus(const typename VectorImpl<T,D>::ModulePtr rhs) const {
	RingPtr entrs[dim];
	for(int i=0; i < VectorImpl<T,D>::dim ; ++i){
	    RingPtr left( this->entries[i] );
	    RingPtr right( (*rhs)[i] );
		entrs[i] =  (left)->plus(right);
	}
	VectorImpl<T,D>::ModulePtr sum(new VectorImpl<T,D>(entrs));
	return sum;
}

template<typename T, int D>
typename VectorImpl<T,D>::ModulePtr VectorImpl<T,D>::minus(const typename VectorImpl<T,D>::ModulePtr rhs) const {
	VectorImpl<T,D>* result(new VectorImpl<T,D>());
	for(int i=0; i < VectorImpl<T,D>::dim ; ++i){
	    RingPtr left( this->entries[i] );
	    RingPtr right( (*rhs)[i] );
		result->entries[i] = left->minus(right);
	}
	return VectorImpl<T,D>::ModulePtr(result);
}

template<typename T, int D>
typename VectorImpl<T,D>::ModulePtr VectorImpl<T,D>::scalarTimes(const typename VectorImpl<T,D>::RingPtr rhs) const {
	VectorImpl<T,D>* result(new VectorImpl<T,D>());
	for(int i=0; i < VectorImpl<T,D>::dim ; ++i){
	    RingPtr left( this->entries[i] );
		result->entries[i] = left->times(rhs);
	}
	return VectorImpl<T,D>::ModulePtr(result);
}

template<typename T, int D>
std::ostream& VectorImpl<T,D>::toCout(std::ostream &out) const{
	for(int i=0; i < VectorImpl<T,D>::dim; ++i){
		out << "|" << this->entries[i] << "|" << std::endl ;
	}
	return out;
}

