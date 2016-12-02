/*
TestVirtualFriend
(c) 2016
original authors: David I. Schwartz
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*	This tutorial illustrates the use and concept of virtual friend function idiom.
	In this tutorial, we overload operator << to access protected members of a class.
*	It covers issues such as instaniation of class, constructor and destructor, 
	operator overloading and switch statement, keyword inline.
*/

// things to do:
// - Quad inherits from Shape (a pure abstract class)
// - let someone call Quad (and other shapes) with an array of sides
//   (virtual destructor, calls to delete, ... other changes?)
// - slicing? http://www.devx.com/tips/Tip/14570

# include "Quad.h"
# include "Rect.h"
# include "Square.h"
# include <iostream>


int main() {

	cout << "Make a square (by value)" << endl;                 // output: Make a square (by value)
	cout << "*************************************" << endl;    // output: *************************************
	Square s1(10);                                              // output: Constructing: class Quad->class Rect->class Square->
	//create an instance of Square type object s1; pass 10 to its constructor
	cout << s1.label << endl;                                   // output: 1

	cout << "\n\nMake a rect (by value)" << endl;               // output: Make a rect (by value)
	cout << "*************************************" << endl;    // output: *************************************
	Rect r1(10, 20);                                            // output: Constructing: class Quad->class Rect->
	//create an instance of Rect type object r1; pass 10 and 20 to its constructor
	cout << r1.label << endl;                                   // output: 2
	cout << "3rd side using []: " << r1[2] << endl;             // output: 3rd side using []: 10

	// Quad q; // fails...why?  // output: Constructing: class Quad->

	cout << "\n\nMake square #2 (by value): " << endl;          // output: Make square #2 (by value):
	cout << "*************************************" << endl;    // output: *************************************
	Square s2(30);                                              // output: Constructing: class Quad->class Rect->class Square->
	//create an instance of Square type object s2; pass 30 to its constructor
	cout << s2.label << endl;                                   // output: 3
	cout << "See its side: " << s2;                             // output: See its side: class Square3: 30
	cout << "See its area: " << s2.area() << endl;              // output: See its area: 900

	cout << "\n\nSet Square1 to Square2: " << endl;             // output: Set Square1 to Square2:
	cout << "*************************************" << endl;    // output: *************************************
	s1 = s2;  // assign s2 to s1 using overloaded operator "="  // output: S Operator= : class Square; shape #1 (the label stays 1)
	cout << "See its side: " << s1;                             // output: See its side: class Square1: 30
	cout << "See its area: " << s1.area() << endl;              // output: See its area : 900

	cout << "\n\nSet Rect1 to Square2: " << endl;               // output: Set Rect1 to Square2:
	cout << "*************************************" << endl;    // output: *************************************
	r1 = s2;  // assign s2 to r1 using overloaded operator "="  // output: R Operator= : class Rect; shape #2 (pay attention to the fact in what way the "=" was overloaded )
	cout << "See sides:    " << r1;                             // output: See sides:    class Rect2 #2: 30, 30
	cout << "See its area: " << r1.area() << endl;              // output: See its area: 900

	cout << "\n\nSet a new Rect to Square2: " << endl;          // output: Set a new Rect to Square2:
	cout << "*************************************" << endl;    // output: *************************************
	Rect r3(s2);                                                // output: Constructing: class Quad->R Copy c-str: class Rect; shape #4
	// create an instance of Rect object r3, assign s2 to its constructor
	// calls c-tor; same with Rect r3 = s2; why? think "Complex num = 1;" (using initializer-style constructor)
	cout << "See sides:    " << r1;                             // output: See sides:    class Rect2 #2: 30, 30
	cout << "See perim:    " << r1.perimeter() << endl;         // output: See perim:    120

	cout << "\n\nDestroy!" << endl;                             // output: Destroy!            
	cout << "*************************************" << endl;    // output: *************************************

	cin.get();
}