/*
Purpose: Eliminate the option of instantiating more than one object
				 More organized than a namespace
				 Be careful of thread safety: https://www.codeproject.com/Articles/96942/Singleton-Design-Pattern-and-Thread-Safety
Type: Creational
*/

class Singleton {

public:

	// This is the single instance of singleton that is held
	static Singleton* s_instance_;

	// Disable the copy constructor
	Singleton(const Singleton&) = delete;

	~Singleton() { delete s_instance_; };

	static Singleton* Get() {

		if (s_instance_ == nullptr) {
			s_instance_ = new Singleton();
		}

		return s_instance_;
	}

	// A function to return the member variable
	// Because it is a variable, this is different from a static function outside a singleton
	int Function() { return private_var_; };

	// No longer have to use get when calling the function
	// Static functions can be called when no class members exist
	static int ConciseFunction() { return Get()->InternalFunction(); };

private:


	int InternalFunction() { return private_var_; };

	// Key about singleton is that it can hold member variables
	int private_var_ = 6;

	// Make the constructor private
	Singleton() {};


};


// Must initialize static member variable
Singleton* Singleton::s_instance_ = 0;


// If one were to use a singleton in context
int PretendMain() {

	int my_num = Singleton::Get()->Function();

	// See how putting get in the function makes the call less verbose?
	int my_num2 = Singleton::ConciseFunction();

	return 0;
}