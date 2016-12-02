#pragma once
#include "Rect.h"

class Square : public Rect {  // define a derived class Square from Rect
public:
	/*constructor*/
	Square(double s);
	Square();
	// what if I don't write The Big Three?
	Square(const Square& q);
	/*destructor*/
	~Square();
	/*operator overloading*/
	virtual Square& operator=(const Square& q);

protected:
	virtual void print(ostream& out) const; // declare protected member function print
};
