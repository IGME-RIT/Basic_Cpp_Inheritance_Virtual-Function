#pragma once
#include "Quad.h"

class Rect : public Quad {  // define a derived class Rect from Quad
public:
	/*constructor*/
	Rect(double s1, double s2);
	Rect();
	Rect(const Rect& q);
	/*destructor*/
	~Rect();
	virtual Rect& operator=(const Rect& q); // overload operator
	virtual const double area() const;      // declare virtual function area
		
protected:
	virtual void print(ostream& out) const; // declare protected member function print
};
