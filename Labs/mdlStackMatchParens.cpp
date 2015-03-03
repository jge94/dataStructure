//
//  StackMatchParens.cpp
//
//  Checks for matching LEFT and RIGHT parens on a line by line basis.
//
//  Created by Mark LeBlanc on 2/28/14.
//  Copyright (c) 2014 Mark LeBlanc. All rights reserved.
//

#include <iostream>
#include <fstream>

#include "MyCharStack.h"

using namespace std;

int main()
{
    ifstream FIN;
    string line;
    bool   lineOK;  // flag to remember if i've seen an error on a line
    
    MyCharStack  S; // stack DATA STRUCTURE for matching ()'s
    
    short lineN = 0;
    
    FIN.open("test2.cpp");
    if ( FIN.is_open() )
    {
        getline(FIN, line);
        while ( FIN )   // while still more lines to check
        {
            cout << line << endl;
            
            lineOK = true; // assume the best
            lineN++;
            short lineLen = line.length();
            
            // for each character on a line
            for (short i=0; i < lineLen; i++)
            {
                char next = line[i];
                
                // handle each character
                switch (next)
                {
                    case '(':
                        if (!S.IsFull())
                            S.Push(next);
                        else {
                            cout << "Stack is FULL!" << endl;
                            exit(-1);
                        }
                        break;
                        
                    case ')':
                        if (!S.IsEmpty())
                            S.Pop();
                        else
                        {
                            cout << "Stack is Empty: Missing LEFT PAREN '(' on line " << lineN << endl;
                            // remember that we've seen an error on this line: the line is NOT ok
                            lineOK=false;
                        }
                        break;
                        
                    default:
                        break;
                } // switch
            } // end FOR chars in this line
            
            if (!S.IsEmpty())
            {
                cout << "Missing RIGHT PAREN ')' on line " << lineN << endl;
                // clean out the Stack
                // NOTE: we know at least one ( is there, so loop runs at least once,
                //          thus a good example of do-while loop: runs at least once
                do {
                    S.Pop();
                } while ( !S.IsEmpty() );
            }
            else if (lineOK)
                cout << "Line #" << lineN << " is OK." << endl;
            
            // any more lines to work on?
            getline(FIN, line);
        } // WHILE more lines
        
    }
    else
        cout << "File didn't open" << endl;
    
    cout << "\n\nDone.\n";
}
