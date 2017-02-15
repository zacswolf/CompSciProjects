#ifndef SUBTRACT_H_
//Always do this for .h files

#define SUBTRACT_H_
//Always do this for .h files
namespace math{
	template <typename T>
	static T subtract (T const& a, T const& b){ 
		//if using templates put cpp file inside of h file
		return a-b; 
	}
}

#endif //SUBTRACT_H_
//Always do this for .h files