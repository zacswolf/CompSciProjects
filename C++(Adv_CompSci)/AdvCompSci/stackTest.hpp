//
//  stackTest.hpp
//  
//
//  Created by Zac Schulwolf on 2/19/17.
//
//

#ifndef stackTest_hpp
#define stackTest_hpp

#include <stdio.h>
#include <iostream>


template <typename T>//T is a pointer pointing to a datatype
class stackTest{
    struct Node{
        T Data;
        Node* Under;
    };
  public:
    int Size;
    Node* head;
    
    stackTest(){
        Size = 0;
        head = new Node;
        head->Data = NULL;
        head->Under = NULL;
    }
    
    void push(T pushIt){
        if (Size == 0){
            head->Data = pushIt;
        }
        else{
            Node* newNode = new Node;
            newNode->Data = pushIt;
            newNode->Under = head;
            head = newNode;
        }
        Size++;
    }
    
    T pop(){
        Size--;
        Node* popIt = head;
        head = head->Under;
        return popIt->Data;
    }
    
    int size(){
        return Size;
    }
};







#endif /* stackTest_hpp */
