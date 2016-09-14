//: Playground - noun: a place where people can play

import UIKit

var str = "Hello, playground"


class Person {
    
    var Name:String = "Initial Name"
    
    init(){
        
    }
    
    func Walk(){
        print("I'm Walking")
    }
}


var a = Person()
a.Name = "Zachery"
a.Walk()

class subHuman:Person{
    
    var NickName:String = "Zac"
    
    override init(){
        //super.Name = "Super Duper" //Does not work
        super.init()
        super.Name = "Super Duper" // now works
    }
    
    func Fly(){
        print("I'm Flying")
    }
    
    override func Walk(){
        print("I am a subHuman walking")
        
        super.Walk()
    }
}

var 😀 = subHuman() //you can use emojjis
😀.Name
😀.Walk()
😀.Fly()
😀.NickName




