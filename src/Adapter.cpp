/*
Purpose: Allow 2 incompatible interfaces to work together
         Used when client expects a target interface
				 AKA Wrapper
Parts: Target - defines interface that Client uses
       Client - Collaborates with objects conforming to Target interface
			 Adaptee - defines interface that needs adapting
			 Adapter: Adapts the interface of Adaptee to Target
Type: Structural
*/

class Target {
public:
	Target();

	// Return what the target usually ddoes
	virtual int Request(int one, int two) const {
		// Does something with the two numbers
	}


	// A function that the adaptee doesn't know how to do
	virtual bool TargetSpecificFunction() const {
		return false;
	};
};

class Adaptee {
public:
	Adaptee();

	// Returns something unexpected and cannot be used
	float OtherRequest() const {
		return 5.5;
	}

	void Something() const {};

	// Something only the adaptee can do;
	bool AdapteeSpecificFunction() const { return false; };
};

// Inherit the interface publicly and inherit the implementation privately
// Also consider holding a pointer instead
class Adapter : public Target, private Adaptee {
public:
	Adapter();

	// Adapting the function to return something meaningful as a Target
	virtual int Request(int one, int two) const {
		Something();
		return (int) OtherRequest();
	}

	// Wrapping the Adaptee's function
	virtual bool AdapteeSpecificFunction() const { return AdapteeSpecificFunction(); };

	// Implement this from scratch
	virtual bool TargetSpecificFunction() const {
		// Do something in the way an adapter would do it
		Something();
		return AdapteeSpecificFunction();
	};
};