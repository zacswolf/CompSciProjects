//: Playground - noun: a place where people can play

import UIKit

var str = "Hello, playground"

class Person {
    
    var Name:String
    var Age:Int
    
    init() {
        self.Name = "Initial Name"
        self.Age = 10
    }
    
    func UpdateNameAndAge(){
        self.Name = "Tom"
        self.Age = 12
    }
    
}

var a = Person()    
a.UpdateNameAndAge()
a.Name