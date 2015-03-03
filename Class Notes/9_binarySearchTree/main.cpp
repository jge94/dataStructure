
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// ----------- tree NODE ---------
struct node
{
   long data;
   node* left;
   node* right;
};
// ---------------------------------

node* makeNode();
void  insertInTree(node* root, node* nextNode);
long  search(node* root, long findMe, bool success);


int main()
{
 srand(time(NULL));

 long        N;  // make binary tree with N values
 long MAXtests;  // TEST search this many times

 //N = 1000;
 //MAXtests = 1000;
 cout << "Enter number of integers to put in a binary tree: ";
 cin >> N;

 cout << "\nEnter number of searches to test: ";
 cin >> MAXtests;
 cin.get();  // gobble up newline

 while (1)  // hack:  run forever ...
 {

    node* root = makeNode(); 

    for (long i=1; i < N; i++)
    {
	node* nextNode = makeNode();
	insertInTree(root, nextNode);
    }

    long sumChecks = 0;
    for (long i=1; i < MAXtests; i++)
    {
	//cout << "\n--------------------------------" << endl;
	//cout << "Enter integer between 0 and " << RAND_MAX << ": ";
	long findMe;
	//cin >> findMe;
	findMe = rand();

	bool success = false;
        long nChecks = search(root, findMe, success);
	/*
	if (success)
		cout << "\nFOUND ";
	else
		cout << "\nNOT FOUND ";
	cout << "in " << nChecks << " == tests" << endl;
	*/

	sumChecks += nChecks;
  }

  cout << "\nAverage check with tree with " << N << " nodes." << endl;
  printf("AVG: %5.1f\n", (sumChecks/(double)MAXtests) );     

   
  cout << "\nHit RETURN to test again ..." << endl;
  cout << "=================================================" << endl;
  cin.get();
  }



} // main()

// --------------------------------
node* makeNode()
{
   node* temp;
   temp = new node;
   temp->data = rand();
   temp->right = temp->left = 0;
   return temp;
}

// --------------------------------
void insertInTree(node* root, node* nextNode)
{
	node* parent = root;

	bool inserted = false;
	while (!inserted)
	{
		if (nextNode->data < parent->data)
			if (parent->left != 0)
				parent = parent->left;
			else {
				parent->left = nextNode;
				inserted = true;
			}
		else if (nextNode->data > parent->data)
			if (parent->right != 0)
				parent = parent->right;
			else {
				parent->right = nextNode;
				inserted = true;
			}
	}

}

// --------------------------------
long  search(node* root, long findMe, bool found)
{
	long countChecks = 0;

	node* p = root;

 	found = false;
	while (!found && p != 0)
	{
		countChecks++;
		if (p->data == findMe)
			found = true;
		else if (findMe < p->data)
			p = p->left;
		else // if (findMe > p->data)
			p = p->right;
	}

	return countChecks;
}
