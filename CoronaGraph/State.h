#ifndef _STATE_H
#define _STATE_H

#include <string>

using namespace std;

#define PSI 0.2
#define PIR 0.1
#define PRI 0
class State {
public:
	State();
	State(double probablity,string name);
	virtual ~State() ;

	double getProbablity() const;
	string getName() const;

protected:
	string name;
	double probablity;
};
inline double State::getProbablity() const {
	return this->probablity;
}
inline string State::getName() const {
	return this->name;
}
class Suspected : public State {
public:
	Suspected();
	virtual ~Suspected() {}
};

class Infected :public State {
public:
	Infected();
	virtual ~Infected() {}
};

class Removed : public State {
public:
	Removed();
	virtual ~Removed() {}
};
#endif // _STATE_H

