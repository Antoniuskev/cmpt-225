/*
 * MyADT.h
 * 
 * Class Description: A data collection ADT class to satisfy Assn 1's requirements.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicate).
 *                   - Once it has been ascertained that the element has not already been 
 *                     inserted, its data structure allows insertion in O(1) and 
 *                     once the element to be removed as been found, removal in O(1).
 *                   - Its data structure is resizable: when full, it expands to accommodate 
 *                     new element insertions. This is done unbeknown to the client code.
 *
 * Inspired on: May 20, 2016
 * Author: AL
 */

#pragma once
#include <string>
#include "Profile.h"

using namespace std;


class MyADT 
{

private:
	static const int MAX_ALPHA = 26;   // 26 letters in the alphabet 
	static const int MAX_ELEMENTS = 5; // Small capacity so can test when data collection becomes full 
	Profile* elements[MAX_ALPHA];      // MAX_ALPHA arrays of elements -> the data collection (or container)
	int elementCount[MAX_ALPHA];       // Current element count in each of the MAX_ALPHA arrays of elements
	int capacity[MAX_ALPHA];           // Actual max capacity of each of the MAX_ALPHA arrays of elements

	// Utility methods
	// Description: Computes an array index from the first letter of a element's name.
	int getIndex(const Profile& newElement);

	// Description: Returns the index of target element in the array containing elements
	//              with names starting with same first letter as target.
	int find(const Profile& target);

	// Description: Deletes all dynamically allocated memory.
	void deleteAll();
      
public:
	// Default constructor
	MyADT();

	// Copy constructor
	MyADT(const MyADT& rhs);

	// Destructor
	~MyADT();

	// Description: Returns the total element count currently stored in MyADT.
	int  getElementCount() const;

	// Description: Insert an element.
	// Precondition: newElement must not already be in data collection.  
	// Postcondition: newElement inserted and the appropriate elementCount has been incremented.   
	bool insert(const Profile& newElement);

	// Description: Remove an element. 
	// Postcondition: toBeRemoved is removed and the appropriate elementCount has been decremented.	
	bool remove( const Profile& toBeRemoved );
	
	// Description: Remove all elements.
	void removeAll();
   
    // Description: Search for target element.
    //              Returns a pointer to the element if found,
	//              otherwise, returns NULL.
    Profile* search(const Profile& target);
   

    // Overloaded Operators
	// Description: Prints the content of "this". For Testing Purposes - See Labs 3 and 4.
	// Description: Prints all elements stored in MyADT.
    friend ostream & operator<<(ostream & os, const MyADT& rhs);

}; // end MyADT