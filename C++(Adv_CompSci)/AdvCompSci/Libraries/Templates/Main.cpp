#include <iostream>
#include "Add.h"
#include "Subtract.h"
using namespace std;

int main(){
   int a = 10;
   int b = 20;
   cout << "Add " << a << "+" << b << ": " << math::add(a,b)<<endl;
   cout << "Subtract " << a << "-" << b << ": " << math::subtract(a,b)<<endl;
   
   double c = 9.99;
   double d = 20.01;
   cout << "Add " << c << "+" << d << ": " << math::add(c,d)<<endl;
   cout << "Subtract " << c << "-" << d << ": " << math::subtract(c,d)<<endl;
   
   bool e = 1;
   bool f = 0;
   cout << "Add " << e << "+" << f << ": " << math::add(e,f)<<endl;
   cout << "Subtract " << e << "-" << f << ": " << math::subtract(e,f)<<endl;
}