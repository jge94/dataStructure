#ifndef MYCHARSTACK
#define MYCHARSTACK
//----------------------------------------------------------------------
//  SPECIFICATION FILE (MyCharStack.h)
//  This module exports an ADT for a stack of characters.
//----------------------------------------------------------------------

// DOMAIN: Each stack is a list of char values

const short MAX_LENG = 100;

class MyCharStack 
{
	public:
		MyCharStack();
        // Default Constructor
        // POST: Empty stack created
		
		bool IsEmpty() const;
        // POST: RETURN == (stack is empty?)
		
		bool IsFull() const;
        // POST: RETURN == (stack is full?)
		
		void Push( /* in */ char newItem );
        // PRE:  NOT IsFull()  &&  Assigned(newItem)
        // POST: newItem is at top of stack
		
		inline char Top() const /* inline */      { return data[top];  }
        // PRE:  NOT IsEmpty()
        // POST: RETURN == char at top of stack
		
		void Pop();
        // PRE:  NOT IsEmpty()
        // POST: Top char removed from stack
		
	
	private:
		int  top;
		
		char data[MAX_LENG];
		
		
}; // end class MyCharStack

#endif
