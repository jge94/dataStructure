SUMMARY: 

This program simulates the working process of CPU: it takes in new jobs while working on ones already loaded,
and processes the jobs within certain time slice in queue until finishing all of them.



Files:

README.txt  --  This file

*** .cpp files

main.cpp -- source code (main)
		directs the project to use all functions, get user's 
		input and run the program based on these time slices

JOB.cpp -- defines all functions used for JOB class
		including constructor of JOB


*** .h files

JOB.h -- defines the class JOB, declaration of all private and public 
	     functions assigned to it


*** other files

Output with Graph.xlsx -- output of the program, two columns of data
	     	showing relationship between time and number of jobs

Output with Graph.csv -- comma seperated file on the output of the
		program

Graph Analysis.pdf -- analysis on the graph produced by the program:
		relationship between time and number of jobs




All code tested and working fine.