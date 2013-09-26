
template<typename T, int rowDim, int colDim>
void vec::Matrix<T,rowDim,colDim>::setValue(T value){
	this->value = value;
}
template<typename T, int rowDim, int colDim>
T vec::Matrix<T,rowDim,colDim>::getValue(){
	return this->value;
}

template class vec::Matrix<float,3,2>;

