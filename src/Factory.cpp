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


class Factory {
public:
	Factory() {};

	virtual Parent* MakeChild(ChildType& type) {

		switch (type) {

		case ChildType1:
			return new Child1;

		case ChildType2:
			return new Child2;

		case ChildType3:
			return new Child3;

		default:
			return new Child1;
		}
	}
};

// By keepign the factory separate, can have different implementations on how to deliver the children
// This example mixes them up
class AnotherFactory {
	 Parent* MakeChild(ChildType& type) {

		switch (type) {

		case ChildType1:
			return new Child3;

		case ChildType2:
			return new Child2;

		case ChildType3:
			return new Child1;

		default:
			return new Child3;
		}
	}
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
	
	// Now, can create objects indirectly
	Factory factory;
	ChildType childtype = ChildType1;
	Parent* child = factory.MakeChild(childtype);

	return 0;
}