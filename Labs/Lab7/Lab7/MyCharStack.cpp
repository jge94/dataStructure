//----------------------------------------------------------------------
//  IMPLEMENTATION FILE (MyCharStack.cpp)
//  This module exports an ADT for a stack of characters.
//  Stack representation: a vector.
//----------------------------------------------------------------------
#include "stdafx.h"
#include "MyCharStack.h"

// Private members of class:
//  int  top;               // Subscript of current top item 
//                          //    (or -1 if stack is empty)
//  char data[MAX_LENG];    // Array representing the stack
//
// CLASSINV:  -1 <= top < MAX_LENG

MyCharStack::MyCharStack()
    //..................................................................
    // Constructor
    // POST: top == -1
    //..................................................................
{
    top = -1;
}

bool MyCharStack::IsEmpty() const
    //..................................................................
    // POST: RETURN (top == -1)
    //..................................................................
{
    return (top == -1);
}

bool MyCharStack::IsFull() const
    //..................................................................
    // POST: RETURN (top == MAX_LENG-1)
    //..................................................................
{
    return (top == MAX_LENG-1);
}

void MyCharStack::Push( /* in */ char newItem )
    //..................................................................
    // PRE:  top < MAX_LENG-1  &&  Assigned(newItem)
    // POST: top == top<entry> + 1
    //       && data[top<entry>+1] == newItem
    //..................................................................
{

    cout << "Sorry, no one showed me how to Push :( " << endl;
    
}

// inline char Top() const /* inline */      { return data[top];  
	//..................................................................
    // PRE:  top >= 0
    // POST: RETURN data[top]
    //..................................................................

void MyCharStack::Pop()
    //..................................................................
    // PRE:  top<entry> >= 0
    // POST: top == top<entry> - 1
    //..................................................................
{
    
    cout << "Sorry, no one showed me how to Pop :( " << endl;

}
