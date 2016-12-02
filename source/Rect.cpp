# include "Rect.h"
# include <iostream>  // for output

/*define constructors*/
Rect::Rect(double s1, double s2) : Quad(s1, s2, s1, s2) 
{
	cout << typeid(*this).name() << "->";  // if the constructor gets two double type parameters, pass s1 as Quad's s1 and s3, s2 as Quad's s2 and s4, and print out its type name 
};

Rect::Rect() : Quad() 
{
	cout << typeid(*this).name() << "->"; // print out the current object's type name
}

Rect::Rect(const Rect& q) {
	//label = ++count;
	s1 = q.s1; s2 = q.s2; s3 = s1; s4 = s2;  // if using copy constructor to initialize. Copy the values of s1,s2 to the current object
	output("R Copy c-str: ");  // call function output, pass string "R Copy c-str: " to it 
}

/*define destructor*/
Rect::~Rect()
{
	output("Destroying  : ");  // call function output, pass string "Destroying  : " to it
};


/*define overloaded operator*/
Rect& Rect::operator=(const Rect& q) {  
	output("R Operator= : ");  // call function output, pass string "R Operator= : " to it
	if (this != &q) {          // if the value of s1,s2,s3,s4 of current object is different from the values of the parameter
		//label = ++count;
		s1 = q.s1; s2 = q.s2; s3 = s1; s4 = s2;  // copy them
	}
	return *this;  // return to the current object
}

const double Rect::area() const { return s1*s2; }  // return to the value of "s1*s2"

void Rect::print(ostream& out) const {
	Quad::print(out);  // call the protected function print in Quad
	out << " #" << label << ": " << s1 << ", " << s2 << endl;  // access the function using << and print out its label and the values of s1 and s2
}

