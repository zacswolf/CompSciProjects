//
//  stackTester.cpp
//  
//
//  Created by Zac Schulwolf on 2/19/17.
//
//

#include <stdio.h>
#include "stackTest.hpp"
#include <iostream>
using namespace std;

int main(){
    stackTest<int*>* test = new stackTest<int*>;
    int* i = new int;
    *i = 124;
    test->push(i);
    cout << test->size() << endl;
    cout << *(test->pop()) << endl;
    
}
