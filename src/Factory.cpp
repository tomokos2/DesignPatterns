# include <iostream>
/*
Purpose: When a method returns one of several possible classes that share a common super class
				 It creates the object for you, rathan than you instantiating the object directly
				 AKA "Virtual constructor"
				 Lets you create object without exposing creation logic to the client
				 Flexible object creation process
*/

class Factory {
public:

	Factory(const Factory&) {}
private:
	Factory() { };

};


class Parent {
public:
	virtual void Function() = 0;
};

class Child1 : public Parent {
public:
	void Function() {
		std::cout << "Function of Child 1 is called" << std::endl;
	}
};

class Child2 : public Parent {
public:

};

class Child3 : public Parent {
public:
};