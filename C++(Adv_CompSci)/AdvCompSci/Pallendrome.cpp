//
//  Pallendrome.cpp
//  
//
//  Created by Zac Schulwolf on 4/21/17.
//
//

#include <iostream>
#include <string>


struct Node{
    char data;
    Node* next;
    Node* prev;
};

class list{
  private:
    Node* head;
    int size;
    
  public:
    list(){
        head = nullptr;
        size = 0;
    }
    ~list(){
        if (head != nullptr){
            while (head->next != nullptr){
                head = head->next;
                delete head->prev;
                size--;
            }
            delete head;
            size--;
        }
    }
    
    void clear(){
        if (head != nullptr){
            while (head->next != nullptr){
                head = head->next;
                delete head->prev;
                size--;
                std::cout << "a" << std::endl;
            }
            std::cout << "size " << size << std::endl;
            delete head;
            size--;
            std::cout << "sadjk" << std::endl;
        }
        std::cout << "size is " << size << std::endl;
    }
    
    void insert(char ins){ // insNode will be head
        Node* insNode = new Node();
        insNode->data = ins;
        insNode->prev = nullptr;
        if (head == nullptr){
            head = insNode;
            insNode->next = nullptr;
        } else {
            head->prev = insNode;
            insNode->next = head;
            head = insNode;
        }
        size++;
    }
    
    char popFront(){
        char ret = head->data;
        
        if (head->next != nullptr){
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        } else {
            delete head;
        }
        size--;
        return ret;
    }
    char popBack(){
        Node* current = head;
        while (current->next != nullptr){
            current = current->next;
        }
        char ret = current->data;
        if (current->prev != nullptr){
            current = current->prev;
            delete current->next;
            current->next = nullptr;
        }
        size--;
        return ret;
    }
    
    int Size(){
        return size;
    }
    
    bool checkIfPallendrome(){
        bool pal = true;
        while (size > 1){
            if (popFront() != popBack()){
                pal = false;
            }
        }
        return pal;
    }
    
    bool checkIfPallendrome(std::string check){
        for (int i = check.length()-1; i >= 0; i--){
            insert(check.at(i));
        }
        std::cout << "the size "<< size << std::endl;
        
        bool pal = true;
        
        while (size > 1){
            if (popFront() != popBack()){
                
                pal = false;
            }
        }
        std::cout << "the size2  "<< size << std::endl;
        return pal;
    }
    
};



int main(){
    list* test = new list();
    std::cout << test->checkIfPallendrome("hi") << std::endl;
    std::cout << test->Size() << std::endl;
    test->clear();
    //std::cout << test->checkIfPallendrome("asdsa") << std::endl;
    //test->clear();
    //std::cout << test->checkIfPallendrome("dad") << std::endl;
    //test->clear();
    
    return 0;
}




