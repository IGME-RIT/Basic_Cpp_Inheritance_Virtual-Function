#include "Quad.h"
#include <iostream> // for output
using namespace std;

int Quad::count = 0; // define the value of member count as 0

	/*define constructors*/
	Quad::Quad(double a, double b, double c, double d) : s1(a), s2(b), s3(c), s4(d) {
		label = ++count;  // label gets the value "count+1"
		cout << "Constructing: " << typeid(*this).name() << "->";  // print out the type name of current object
	}

	Quad::Quad() {
		label = ++count;  // label gets the value "count+1"
		s1 = s2 = s3 = s4 = 0;  // if no arguments passed in, initialize s1,s2,s3,s4's value to 0
		cout << "Constructing: " << typeid(*this).name() << "->";  // print out the type name of current object
	}

	Quad::Quad(const Quad& q) {
		label = ++count;  // label gets the value "count+1"
		s1 = q.s1; s2 = q.s2; s3 = q.s3; s4 = q.s4;  // if the constructor is the copy constructor, assign the value of s1,s2,s3,s4 to 0
		output("Q Copy c-str: ");  // call the function output, pass string "Q Copy c-str: "
	}
	/*define destructor*/
	Quad::~Quad() {
		output("Destroying  : ");  // call the function output, pass string "Destroying  : "
	}

	/*define overloaded operators*/
	Quad& Quad::operator=(const Quad& q) {
		output("Q Operator=:   ");  //  call the function output, pass string "Q Operator=:   "
		if (this != &q) {           // if the value of pointer points to the current object is not the address of the parameter passed in 
			label = ++count;        // label gets the value of "count+1"
			s1 = q.s1; s2 = q.s2; s3 = q.s3; s4 = q.s4;  // copy the value of s1,s2,s3,s4 from parameter to the s1,s2,s3,s4 of the current object 
		}
		return *this;  // return the current obejct
	}

	double Quad::operator[](int index) {
		switch (index) {           // switch statement: see https://msdn.microsoft.com/en-us/library/k0t5wee3.aspx
		case 0: return s1; break;  // if gets 0, return to s1, break
		case 1: return s2; break;  // if gets 1, return to s2, break
		case 2: return s3; break;  // if gets 2, return to s3, break
		case 3: return s4; break;  // if gets 3, return to s4, break
		default: cout << "crap!" << endl; abort();  // if gets sth other than the integers above, print out "crap" and abort the statement
		}
	}

	bool Quad::operator==(const Quad& other) const {
		return s1 == other.s1 && s2 == other.s2 && s3 == other.s3 && s4 == other.s4;  // judge whether the current object's values of s1,s2,s3,s4 is the same as the parameter's
		                                                                              // if yes, return true; else return false
	}

	bool Quad::operator!=(const Quad& other) const {
		return !(*this == other);  // Judge whether the current object's values of s1,s2,s3,s4 is the same as the parameter's. If true, return false; else return true
	}

	bool Quad::operator<(const Quad& other) const {
		return area() < other.area();  // Compare the value of the function area of current object and the parameter, 
		                               // If the current object's area is less than the parameter's, return true/1; else return false/0.
	}

	/*define member functions*/
	void Quad::output(string mesg) const {
		cout << mesg << typeid(*this).name() << "; shape #" << label << endl; // print out the type name of current object and its label
	}

	const double Quad::perimeter() const {
		return s1 + s2 + s3 + s4;  // return to the perimeter of the object
	}

	const double Quad::area() const
	{
		return 0.0;  // return to 0.0
	}

	void Quad::print(ostream& out) const {
		out << typeid(*this).name() << label;  // print out the type name of current object and its label
	}
	

