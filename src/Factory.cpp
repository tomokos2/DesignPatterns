# include <iostream>
/*
Purpose: When a method returns one of several possible classes that share a common super class
				 It creates the object for you, rathan than you instantiating the object directly
				 AKA "Virtual constructor"
				 Lets you create object without exposing creation logic to the client
				 Flexible object creation process
Type: Creational
Other variations: Lazy instantiation, templating
*/


enum ChildType {
	ChildType1, ChildType2, ChildType3
};

class Parent {
public:
	virtual void Function() = 0;
	static Parent* MakeChild(ChildType& type) {

		switch (type) {
		case ChildType1:
			return new Child1;

		case ChildType2:
			return new Child2;

		case ChildType3:
			return new Child3;

		default:
			// Error
		}
	}
};

class Child1 : public Parent {
public:
	void Function() {
		std::cout << "Function of Child 1 is called" << std::endl;
	}
};

class Child2 : public Parent {
public:
	void Function() {
		std::cout << "Function of Child 2 is called" << std::endl;
	}

};

class Child3 : public Parent {
public:
	void Function() {
		std::cout << "Function of Child 3 is called" << std::endl;
	}
};

int pretendMain() {

	return 0;
}