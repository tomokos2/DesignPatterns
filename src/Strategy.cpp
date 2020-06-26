#include <string>
/*
Purpose: Creates a "has a" relationship instead of "is a" relationship
         Objects can have properties that vary greatly and that are interchangeable in runtime
				 Encapsulate families of algorithms
				 Eliminates many if statements
				 If the strategy does not need to be changed at runtime, better use Templates
Parts: Strategy - declares interface common to all supported algs
       ConcreteStrategy - implements Strategy interface
			 Context - configured with ConcreteStrategy and may define interface that lets strategy access its data
Type: Behavioral
Source: https://refactoring.guru/design-patterns/strategy/cpp/example
*/


// Context uses this interace to call alg defined by Concrete Strategies
class Strategy {

public:
	virtual ~Strategy() {}
	virtual std::string DoAlg(int data) const = 0;
};


// Interface of interest to clients
class Context {
	
public:
	// You do not have to provide a strategy to construtor
	Context(Strategy* strategy = nullptr) : strategy_(strategy) {}


	// Can also change strategy at runtime
	void SetStrategy(Strategy* s) {
		delete strategy_;
		strategy_ = s;
	}


	// The client uses the strategy without needing to know what type of strategy is implemented
	void Function() const {
		std::string result = strategy_->DoAlg(5);
	}

private:
	Strategy* strategy_;
};


// Concrete strategies implement the Algoritm in their own way
class ConcreteStrategyA : public Strategy {

public:
	std::string DoAlg(int data) const override {
		return std::to_string(data);
	}
};

class ConcreteStrategyB : public Strategy {

public:
	std::string DoAlg(int data) const override {
		data -= 50;
		return std::to_string(data);
	}
};


int anotherMain() {

	Context* context = new Context(new ConcreteStrategyA());
	// Set to use strategy A
	context->Function();
	// Will call strategy A's implementation of DoAlg

	context->SetStrategy(new ConcreteStrategyB());
	// Now uses strategyB
	context->Function();
	// Will call strategy B's implementation of DoAlg

	// Avoided recreation of context. Flexibly changled strategies.
	return 0;
}

