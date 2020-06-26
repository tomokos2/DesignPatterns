#include <vector>
#include <algorithm>
/*
Purpose: One-to-many dependency between objects, where when one subscriber object changes state
         all other subscriber objects are notified and updated.
				 A subject has any number of dependent observers
				 AKA publish-subscribe
				 Useful for when you don't know how many objects need to be changed
				 Can notify other objects without assumptions about who the objects are
Type: Behavioral
*/

class Publisher;

class Subscriber {
public:
	virtual ~Subscriber();
	virtual void Update(Publisher* changedPublisher) = 0;

protected:
	Subscriber();
};


// Abstract publisher
class Publisher {
public:
	virtual ~Publisher();
	
	virtual void Attach(Subscriber* s) {
		subscribers_.push_back(s);
	};

	virtual void Detatch(Subscriber* s) {
		std::remove(subscribers_.begin(), subscribers_.end(), s);
	};

	virtual void Notify() {
		for (Subscriber* s : subscribers_) {
			s->Update(this);
		}
	}

protected:

	Publisher();

private:
	
	// The publisher knows who all of the subscribers are
	std::vector<Subscriber*> subscribers_;

};


// Implemented publisher
class TimeKeeper : public Publisher {
public:
	TimeKeeper();
	
	// Provides accurate time
	void Tick() {
		// Update internal time state

		// Tell all subscribers
		Notify();
	}
};


// Keeps updated with every tick of timekeeper
class DigitalClock : public Subscriber {

public:

	DigitalClock(TimeKeeper* p) {
		// Notify the publisher to be added to the listener list
		publisher_ = p;
		p->Attach(this);
	}

	// Overrides the Subscriber operation
	void Update(Publisher* p) {

		// Only do operations if the publisher is yours
		if (p == publisher_) {
			// Do stuff to update yourself
			// Get time information from publisher
			
		}
	}

private:

	TimeKeeper* publisher_;

};

class AnalogClock : public Subscriber {

public:

	AnalogClock(TimeKeeper* p) {
		// Notify the publisher to be added to the listener list
		publisher_ = p;
		p->Attach(this);
	}

	// Overrides the Subscriber operation
	void Update(Publisher* p) {

		// Only do operations if the publisher is yours
		if (p == publisher_) {
			// Do stuff to update yourself
			// Get time information from publisher

			// Maybe its analog clock related or something

		}
	}

private:

	TimeKeeper* publisher_;

};

