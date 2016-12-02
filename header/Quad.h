#pragma once

#include <typeinfo>
#include <string>    // for using keyword string
using namespace std; // for cout and endl

class Quad { // define base class Quad
public:
	/*constructor*/
	Quad(double a, double b, double c, double d);
	Quad();
	Quad(const Quad& q);
	/*destructor*/
	~Quad();
	/*member function*/
	virtual void output(string mesg) const;
	virtual const double perimeter() const;
	virtual const double area() const;
	/*operator overloading*/
	virtual Quad& operator=(const Quad& q);
	virtual double operator[](int index);
	virtual bool operator==(const Quad& other) const;
	virtual bool operator!=(const Quad& other) const;
	virtual bool operator<(const Quad& other) const;

	// why friend? see bottom of http://msdn.microsoft.com/en-us/library/czs2584d.aspx and 14.9 (Liang)
	// why bother? see https://isocpp.org/wiki/faq/input-output#virtual-friend-fns and
	//                 http://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Virtual_Friend_Function

	friend ostream& operator<<(ostream& out, const Quad& q);

	static int count;
	int label;

protected:
	virtual void print(ostream& out) const;  // declare private member function
	double s1, s2, s3, s4;                   // declare member function (store values of edge lengths of a Quad)

};

inline std::ostream& operator<<(ostream& out, const Quad& q) {  // overload operator<< to call protected function print
	q.print(out);
	return out;
}
