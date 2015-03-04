SUMMARY: 

This program plays the 20 questions, and as the user plays more,
the computer gets better at the game. (savable, loadable)

[The default game (if not loading) is about countries]

Files:

README.txt  --  This file

*** .cpp files

main.cpp -- source code (main)
		ask users input, walk through the whole procedure
		to determine if saving, loading, and replaying 
		the game

Tree.cpp -- defines all functions used for Tree class
		including constructor, DTOR of Tree
	        check if empty fuction, get root of the Tree function,
            	save the tree to a file, 
             	read tree from file functions

Node.cpp -- defines all functions used for Node Class
		including CTOR, DTOR of Node class
		store text in the node function,
		append to right and left function,
		get text in the node function,
		return left and right child function,
		check if it is a leaf function 
             

*** .h files

Tree.h -- defines the class Tree, declaration of all private and public 
	     functions assigned to it
Node.h --declaration of all private and public 
	     functions assigned to Node.cpp





All code tested and working fine.