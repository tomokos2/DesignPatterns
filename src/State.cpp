/*
Purpose: Object virtually changes class when internal state changes
         State describes how the object exhibits different behavior in each state
				 Try to have as few states as possible
				 Easy to add states and trasnitions by defining new subclasses of State
				 Makes state transitions explicit
Parts: ConcreteState - Each subclass implements a behavior associated with a state of context
       Context - Maintains instance of a ConcreteState subclass that defines current state
			           It's what the client is interested in
			 State - Defines interface for encapsulating behavior associated with a particular state of Context
Type: Behavioral
*/

class State;

class Context {
public:
	
	// Just a constructor
	Context(State* s) : current_state_(nullptr) {
		ChangeState(s);
	}

	// Delegates all state-specific requests to state
	void DoSomething() { current_state_->DoSomething(this); };
	void DoThat() { current_state_->DoThat(this); };
	void DoAnother() { current_state_->DoAnother(this); };
	void DoIt() { current_state_->DoIt(this); };

private:

	// Gives State the priviledge to access ChangeState in order to change the current state
	friend class State;

	// Handles requests to change state
	void ChangeState(State* state) { 
		if (current_state_ != nullptr) {
			delete current_state_;
		}

		// Update the state
		current_state_ = state;
	};

	State* current_state_;

};


class State {
	
public:
	virtual void DoSomething(Context* c);
	virtual void DoThat(Context* c);
	virtual void DoAnother(Context* c);
	virtual void DoIt(Context* c);

protected:
	void ChangeState(Context* c, State* s) {

		c->ChangeState(s);
	}
};

class StateSubclass1 : public State {
public:

	void DoSomething(Context* c) {
		// Do something
	}

	void DoIt(Context* c) {
		// Do it in this unique way too
		// Doing it could cause a state change
		ChangeState(c, new StateSubclass3);
	}
};

class StateSubclass2 : public State {
public:
	static State* Instance();

	void DoThat(Context* c) {
		// Do that
		ChangeState(c, new StateSubclass1);
	}
};

class StateSubclass3 : public State {
public:
	static State* Instance();

	void DoAnother(Context* c) {
		// Do another
	}
	void DoIt(Context* c) {
		// Do it
		ChangeState(c, new StateSubclass2);
	}
};