#include <iostream>

using namespace std;

class Rectangle {
		int width,height;//intance var
	public:
	Rectangle(){//default constructor
		width=0;
		height=0;
	}
	Rectangle(int w,int h){//default constructor
		width=w;
		height=h;
	}
		void set_value(int, int);
		int area (void);
}rect1;

void Rectangle::set_value(int w, int h){
	width = w;
	height =h;
}

int Rectangle::area(){
	return width*height;
}

int main(){
	rect1.set_value(1,2);
	Rectangle rect2(4,8);
	cout << rect1.area() << endl;
	cout << rect2.area() << endl;
	return 0;
}
