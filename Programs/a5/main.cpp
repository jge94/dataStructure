#include "stdafx.h"
#include <iostream>
#include "Node.h"
#include "Tree.h"

/*********************************************************************
*	a5 - 20 Questions Game
*/
//====================================================================
// SUMMARY:
//		This program plays the 20 questions, and as the user plays more,
// the computer gets better at the game. (savable, loadable)
//
//		[The default game (if not loading) is about countries]
//--------------------------------------------------------------------
// Programmer: 
//		Jinnan Ge
//
// Dates Modified:
//		04/22/2014(jg) started
//		04/23/2014(jg) finished Node.cpp and Node.h
//		04/26/2014(jg) finished testing Tree.cpp
//		04/27/2014(jg) started on main
//		04/30/2014(jg) finished main
//		05/01/2014(jg) all functions finished
//		05/02/2014(jg) comments added
//--------------------------------------------------------------------
// INPUT: 
//		1) whether user wants to load (again) a file
//		2) file name to load from
//		3) yes or no as an answer to questions
//		4) new question (true for user's object but false for computer guess)
//		5) object the user is thinking of
//		6) whether user wants to play another round
//		7) whether user wants to play another round
//		8) file name to save to
//		
// OUTPUT:
//		1) questions from the computer
//		2) whether computer wins at last
//		3) saved file (if user wants to save) of questions
//--------------------------------------------------------------------
//	  [SAMPLE OUTPUT]
//					*** Twenty Questions Game***
//		Do you want to load a file to play the game?
//		y for YES and n for NO
//		n
//		Your should be thinking of a COUNTRY.
//		
//		Is it on the western hemisphere?
//		y for YES and n for NO
//		
//		Are you thinking of: United States?
//		y for YES and n for NO
//		n
//	
//		Oops... Now I need some help...
//		Please enter a question that is:
//		    TRUE for **what you are thinking of** and
//		    FALSE for **United States**.
//		Your questions: Does it speak German?
//		The object you're thinking of is: Germany
//		Do you want to play another round?
//		y for YES and n for NO
//		n
//		Do you want to save the file?
//		y
//		So, enter the name you want to save as: country.txt
//		Now, do you want to load a file to play the game?
//		y for YES and n for NO
//		n
//
//		Done.
//====================================================================

using namespace std;

// --------- function prototypes ------------
bool didTheySayYes();
void playDefaultGame(Tree &T);


// ------------- main function ------------
int main()
{
	cout << "			*** Twenty Questions Game***\n\n";			// title

	cout << "Do you want to load a file to play the game?" ;		// first question

	bool answer, defGameAgain = true;								// answer = whether want to load a file to play the game
	answer = didTheySayYes();										// defGameAgain = whether want to play the default game


	while (!answer && defGameAgain)									// User: "no, I don't want to load, I want to play the default game"
	{

		// ------------------- Play Game ----------------------
		cout << "Your should be thinking of a COUNTRY. \n" << endl;					// default game theme: countries
		Tree T("\nIs it on the western hemisphere? ", "United States", "China");	// declare tree for default game (three nodes)
		playDefaultGame(T);											// play default game


		// ------------------- Save File -----------------------
		cout << "Do you want to save the file? ";					// now... ask the user if they want to save
		if (didTheySayYes())										// if yes
		{
			string outputFile;										// name of the output file
			cout << "So, enter name of file you want to save as: ",
				cin >> outputFile;
			T.SaveTreeToFile(outputFile);							// save the current tree into a file
		}


		// ------------------ Load File --------------------------
		cout << "Now, do you want to load a file to play the game?";		// ask again if user wants to load a game
		answer = didTheySayYes();

		if (!answer)							// "No, I dont want to load a file, either do I want to play the default game again!"
		{										
			defGameAgain = false;				// (since they quit another round, they don't want to go back to the default game either)
		}//end if

	}//end while: play default game (country game)


	// NO default game, just load from files and play
	while (answer == true)						// "yes, I want to load a file!"
	{
		Tree emptyT;							// another tree declaration

		// ----------------- load files ------------------
		string fileName;
		cout << "Enter a file name that you would like to load from: ",
			cin >> fileName;
		emptyT.ReadTreeFromFile(fileName);							// read from the file entered
		playDefaultGame(emptyT);									// play this game	

		// ----------------- save file ------------------
		cout << "Do you want to save the file? "; 
		if (didTheySayYes())		// "Yes, I want to save the file"
		{
			string outputFile;
			cout << "So, enter name of file you want to save as: ",		// prompt input for file name
				cin >> outputFile;
			emptyT.SaveTreeToFile(outputFile);						// save the tree in the file
		}

		// ------ prompt for if user wants to load another game and play it --------
		cout << "Do you want to keep loading a file to play the game?";
		answer = didTheySayYes();
	}// end while


	cout << "\n\nDone." << endl;						// ENDING
	system("PAUSE");
	return 0;
}// end main


// ---------- didTheySayYes function -----------
bool didTheySayYes(void)
/* 
	PRE: None
	POST: return T/F represented for 'yes' or 'no' user enters
*/
{
	cout << "\ny for YES and n for NO\n";
	char answer;
	cin >> answer;
	answer = tolower(answer);				// change answer to lowercase

	// trap invalid input
	while (answer != 'y' && answer != 'n')	
	{
		cout << "Bad input! Please enter y for YES and n for NO\n",
			cin >> answer;
	}

	if (answer == 'y')					// if they say "yes"
		return true;
	else								// if they say "no"
		return false;
}// end didTheySayYes


// --------- playDefaultGame function -------------
void playDefaultGame(Tree& T)
/*
	PRE: assigned object T (Tree)
	POST: none
*/
{
	do											// do-while loop: asking at least one question
	{
		Node* currP;							// current pointer that points to a node
		currP = T.GetRoot();					// current pointer pointing to the root of the tree

		while (!currP->IsLeaf())				// while not a leaf (not the bottom of the tree)
		{
			cout << currP->GetText();			// print the question (the GetText part of the node that current pointer points to)

			if (didTheySayYes())				// if user anwers yes
				currP = currP->LChild();		// move current pointer to the left child
			else								// if user answers no
				currP = currP->RChild();		// move current pointer to the right child
		}//end while

		// now we're a leaf, time to guess
		// YOU TEACH YOUR BABY-COMPUTER TO LEARN, every time you play

		// print out guess
		cout << "\nAre you thinking of: " << currP->GetText() << "?";
		if (didTheySayYes())
		{
			cout << "Yeah! Computer wins!" << endl;
			cout << "Do you want to play another round?";		// ask user if they want to start over again
		}//end if

		else									// guess wrong, now ask user what they are thinking of
		{
			cout << "\nOops... Now I need some help..." << endl;
			cout << "Please enter a question that is:\n";		// prompt input
			cout << "    TRUE for **what you are thinking of** and\n";
			cout << "    FALSE for **" << currP->GetText() << "**." << endl;

			// record answer
			string newQ, newCountry;			// newQ = new question user adds
												// newCountry = what user is thinking about
			cout << "Your questions is: ";
			cin.get();							// "get" the newline char left in the input stream
			getline(cin, newQ);					// store new question
			cout << "The object you're thinking of is: ";
			getline(cin, newCountry);			// store answer (the object)


			// -------- create left and right children ---------

			Node *Pointer_newRChild = new Node(*currP);		// pointer pointing to a Node that copies what current pointer is pointing to

			currP->StoreText(newQ);							// store user entered question into local root 
			Node* Pointer_newLChild = new Node;				// pointer pointing to the newly appended left child
			Pointer_newLChild->StoreText(newCountry);		// store the correct answer in newly appended left child

			currP->AppendLeft(Pointer_newLChild);			// link new left child to the left
			currP->AppendRight(Pointer_newRChild);			// link new right child to the right

			// Ask user if want to play the game again
			cout << "Do you want to play another round?";

		}//end else

	} while (didTheySayYes());								// loop this as long as they said "yes" (not 1st time)
}