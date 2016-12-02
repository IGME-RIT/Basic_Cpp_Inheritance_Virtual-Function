# include "Square.h"
# include <iostream>  // for cout

/*define constructors*/
Square::Square(double s): Rect(s,s)
{
		cout << typeid(*this).name() << "->";  // if pass one double parameters, pass two parameters in the same value to Rect print out the type name of the current object
}

Square::Square() : Rect() 
{
	cout << typeid(*this).name() << "->";  // print out the type name of the current object
}

Square::Square(const Square& q) {
	// what happens if I don't provide a default constructor for Square/Rect/...? (Hint: What would "Thing t;" do?)
	//label = ++count;
	s1 = q.s1; s2 = q.s2; s3 = s1; s4 = s2;  // copy the s1, s2, s3,s4 to current object
	output("S Copy c-str: ");  // call function output, pass string "S Copy c-str: " to it
}

/*define destructor*/
Square::~Square() 
{
	output("Destroying  : ");  // call the funtion output, pass string "Destroying : " to it
}

/*define overloaded operator*/
Square& Square::operator=(const Square& q) 
{
	output("S Operator= : ");  // call the function output, pass string "S Operator= : " to it
	if (this != &q) {          // if the s1,s2,s3,s4 is not the same
		//label = ++count;
		s1 = q.s1; s4 = s3 = s2 = s1; // copy them from the parameter to the current
	}
	return *this;  // return current object
}

void Square::print(ostream& out) const 
{
	Quad::print(out);
	out << ": " << s1 << endl;  // print out s1 (the length of the edge of the square)
}
