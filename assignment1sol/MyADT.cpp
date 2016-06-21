/*
 * MyADT.cpp
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


#include <iostream>
#include <cctype>
#include "MyADT.h"  // Header file
#include "Profile.h"

// Default constructor.
MyADT::MyADT() {
   //cout << "MyADT::default constructor" << endl;   // For testing purposes ... and curiosity
 
   for (int index = 0; index < MyADT::MAX_ALPHA; index++) {
       elements[index] = NULL;
       elementCount[index] = 0; 
       capacity[index] = MyADT::MAX_ELEMENTS;
   }
}  // end default constructor

// Copy constructor
MyADT::MyADT(const MyADT& rhs) {
   //cout << "MyADT::copy constructor" << endl; // For testing purposes ... and curiosity

   for (int index = 0; index < MyADT::MAX_ALPHA; index++) {
       elements[index] = NULL;
       elementCount[index] = rhs.elementCount[index];
       capacity[index] = rhs.capacity[index];
       
       // Deep copy the elements
       if (rhs.elements[index] != NULL && rhs.elementCount[index] ==  0) {
          elements[index] = new Profile[capacity[index]];
          for (int element = 0; element < elementCount[index]; element++) {
             elements[index][element] = rhs.elements[index][element];
          }
       }
   }
}  // end copy constructor


MyADT::~MyADT() {
   //cout << "MyADT::destructor" << endl;  // For testing purposes ... and curiosity

   // Delete all dynamically allocated memory
   deleteAll();

}  // end destructor

// Description: Returns the total element count currently stored in MyADT.
int  MyADT::getElementCount() const {
   int total = 0;

   //cout << "MyADT::getElementCount" << endl; // For testing purposes

   for (int index = 0; index < MyADT::MAX_ALPHA; index++) 
      total += elementCount[index]; 
   
   return total;
}


// Description: Inserts an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
bool MyADT::insert(const Profile& newElement) {
   bool ableToInsert = false;
   bool hasRoomToInsert = false;
   int index = -1;

   //cout << "MyADT::insert" << endl; // For testing purposes

   // Make sure that newElement is not already in data collection.
   int indexOfElementInList = find(newElement);
   
   // If newElement not already in List then insert newElement
   if ( indexOfElementInList == -1 ) {   

		// Get array index of newElement
		index = getIndex(newElement);
		
		// Initially, if array for this letter does not yet exist, get dynamic array
		if ( elements[index] == NULL && elementCount[index] ==  0)
		   elements[index] = new Profile[capacity[index]];

		else { // If it exists, does it have some room to add newElement?
        	
        	hasRoomToInsert = (elementCount[index] < capacity[index]);
				
			// If not, expand the array
			// At this point elementCount[index] = capacity[index]
	        if ( !hasRoomToInsert ) {		
	           // Anchor full array
			   Profile * fullArray = elements[index]; 
			   // Get a new array that is twice as large
			   elements[index] = new Profile[2 * capacity[index]]; 
			   // Copy elements from full array to new twice-as-large array
			   for ( int eachMember = 0; eachMember < elementCount[index]; eachMember++ )           	   	
	                elements[index][eachMember] = fullArray[eachMember];
	           // Delete full (old) array           
	           delete [ ] fullArray;
	           fullArray = NULL;
	           // Keep track of the capacity of new array
	           capacity[index] = 2 * capacity[index];
	        }
	    }

	    // Insert newElement into correct element array based on first letter of name
	    elements[index][elementCount[index]] = newElement;
	    	    
	    // Increment elementCount for that element array
	    elementCount[index]++;
   	    
	    // Report success.
	     ableToInsert = true;
	}
	   
    return ableToInsert;
}  // end insert


// Description: Search for target element. 
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Profile* MyADT::search(const Profile& target) {
    Profile* result = NULL;
    int whichElement = -1;
    int index = -1;

	//cout << "MyADT::search()" << endl;  // For testing purposes

	// Get array index of target
	index = getIndex(target);

    // If target found
	if ( ( whichElement = find(target) ) > -1 ) 
		result = &elements[index][whichElement];

    return result; 
}  // end of search

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and the appropriate elementCount has been decremented.
bool MyADT::remove( const Profile& toBeRemoved ) {  
	bool ableToRemove = false;
	int whichElement = -1;
	int index = -1;

	//cout << "MyADT::remove()" << endl; // For testing purposes

	// Find the element
	// Get array index of element toBeRemoved
	index = getIndex(toBeRemoved);

    // If toBeRemoved is found
	if ( ( whichElement = find(toBeRemoved) ) > -1 ) {
		ableToRemove = true;			
		// Remove the element by overwriting it with last element
		elements[index][whichElement] = elements[index][elementCount[index] - 1];				
		// Decrement element count	
		elementCount[index]--;
	}
					   
    return ableToRemove;
 }  // end remove


// Description: Remove all elements.
void MyADT::removeAll() {
   //cout << "MyADT::removeAll()" << endl; // For testing purposes
   
   // Reset the data collection as it was when it was initially constructed
   deleteAll();      

}  // end removeAll

// Utility methods
// Description: Computes an array index from the first letter of a element's name.
int MyADT::getIndex(const Profile& newElement) {

    // Make sure we consider the UPPER case version of the first letter of name
	return toupper(newElement.getName()[0]) - 'A';
} // end getIndex

// Description: Returns the index of target element in the array containing elements
//              with names starting with same first letter as target.
int MyADT::find(const Profile& target) {
	bool found = false;
	int result = -1;
    int index = -1;
    
	//cout << "MyADT::find()" << endl;  // For testing purposes

	// Get array index of target
	index = getIndex(target);

    // Go directly to array of elements with same first letter as target's and ...
	if ( elements[index] != NULL && elementCount[index] > 0 ) {
		for (int eachMember = 0; eachMember < elementCount[index] && !found; eachMember++) {
			// ... search for target's name - see Profile class overloaded operator ==
			if ( elements[index][eachMember] == target ) {
				result = eachMember;
			    found = true;
			}
		}
	}

    return result; 
}  // end of find


// Description: Deletes all dynamically allocated memory.
void MyADT::deleteAll() {
   //cout << "MyADT::deleteAll()" << endl; // For testing purposes ... and curiosity	

   // Delete each array of elements associated with a letter ...
   for (int index = 0; index < MyADT::MAX_ALPHA; index++) {
      if ( elements[index] != NULL ) {
         delete [] elements[index];
         elements[index] = NULL;
      }
      // and set its corresponding element count to 0 ...
      elementCount[index] = 0;
      // and its corresponding capacity to original capacity
      capacity[index] = MyADT::MAX_ELEMENTS;
   }
}  // end deleteAll


// Overloaded Operators
// Description: Prints the content of "this". For Testing Purposes - See Labs 3 and 4.
// Description: Prints all elements stored in MyADT.
ostream & operator<<(ostream & os, const MyADT& rhs) {
   int totalOfMembers = rhs.getElementCount();
   os << "\nFriendsBook has now " << totalOfMembers << " members:" << endl;

   for (int index = 0; index < MyADT::MAX_ALPHA; index++) {
		if ( rhs.elements[index] != NULL && rhs.elementCount[index] > 0 ) {
            for (int eachMember = 0; eachMember < rhs.elementCount[index]; eachMember++)
				//os << rhs.elements[index][eachMember].getName() << endl;
				os << rhs.elements[index][eachMember] << endl;
		}
   }   
   return os;
} // end of operator << 

//  End of implementation file