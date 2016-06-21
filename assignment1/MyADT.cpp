/*
 * filename: MyADT.cpp
 * 
 * Class Description: A data collection ADT class to satisfy Assn 1's requiremetns.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicate).
 *                   - Once it has been ascertained that the element has not already been 
 *                     inserted, its data structure allows insertion in O(1)
 *                   - Once the element to be removed as been found, 
 *                     its data structure allows removal in O(1).
 *                   - Its data structure is resizable: when full, it expands to accommodate 
 *                     new element insertions. This is done unbeknown to the client code.
 *
 * Creation date: May 30, 2016
 * Author: Kevin Antonius
 */
 
 #include <iostream>
 #include <string>
 #include <locale>
 #include "profile.h"

//Constructor of MyADT
 MyADT::MyADT(){
 	capacity = defaultCapacity;
 	elementCount = 0;
 	array[capacity];

 }

// Description: Returns the total of elements currently stored in MyADT.
int  MyADT::getElementCount() const
{
	return elementCount;
}

// Description: Inserts an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
bool MyADT::insert(const Profile& newElement)
{
	if (capacity < newElement) // if size doesnt valid double the size
		capacity = capacity* 2;

	Profile* arr = new Profile[capacity]; // making new array that has double size called arr

	for(int i= 0;newElement.array[i+1] != NULL;i++){
		arr[i] = newElement.array[i]
	}
	elementCount++;
	delete array;
	return 1;
	

// Description: Removes an element. 
// Postcondition: toBeRemoved is removed and the appropriate elementCount has been decremented.	
bool MyADT::remove(const Profile& toBeRemoved){
	
}

// Description: Searches for target element.
Profile* search(const Profile& target);

// Description: Removes all elements.
void removeAll();

// Description: Prints all elements stored in MyADT.
friend ostream & operator<<(ostream & os, const MyADT& rhs);

};
if arr.string == arr 