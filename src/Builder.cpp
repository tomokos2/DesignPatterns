/*
Purpose: Create objects made from a bunch of other objects
         Use same construction process for different representations
				 Gives clear control over construction process
				 Products can be unrelated -- they may not follow the same interface
Parts: Builder - specifies abstract interface for creating parts of Product
       ConcreteBuilder - implements Builder and keeps track of the representation it creates
			                   Provides interface for retrieving product
		   Director - constructs object using builder interface
			 Product - Is the object under construction, to be built and assembled by ConcreteBuilder
Type: Creational
*/

class Product {
public:
	int a_;
	int b_;
	bool c_;
};

// Interface for building object
class Builder {

public:
	// Nothing by default so derived classes override only methods they want
	virtual void BuildPartA() {};
	virtual void BuildPartB(int num) {};
	virtual void BuildPartC(bool boolean) {};

};


class Director {

public:
	void set_builder(Builder* b) {
		builder_ = b;
	}

	// Director can make different product variations

	void BuildMVP() {
		builder_->BuildPartA();
	}

	void BuildSuper() {
		builder_->BuildPartA();
		builder_->BuildPartB(5);
		builder_->BuildPartC(true);
	}


private:
	Builder* builder_;
};

// Provides specific building steps and gives a way to retrieve results
class ConcreteBuilder : public Builder {
public:

	ConcreteBuilder() {
		Reset();
	}

	// Fresh product object
	void Reset() {
		product_ = new Product();
	}


	// Fill out production steps
	void BuildPartA() const {
		product_->a_ = 5;
	}

	void BuildPartB(int num) const {
		product_->b_ = num;
	}

	void BuildPartC(bool boolean) const {
		product_->c_ = boolean;
	}

	
	// The user is now responsible for deleting the result
	Product* GetProduct() {
		Product* result = product_;
		Reset();
		return result;
	}

private:
	Product* product_;
};


void ClientCode() {
	ConcreteBuilder* builder = new ConcreteBuilder();
	Director director;
	director.set_builder(builder);

	// Build a product
	director.BuildMVP();
	Product* p = builder->GetProduct();
	delete p;


	// Build a different prodct
	director.BuildSuper();
	p = builder->GetProduct();
	delete p;


	// Can also build without a director
	builder->BuildPartA();
	builder->BuildPartB(4);
	p = builder->GetProduct();
	delete p;

	delete builder;
}