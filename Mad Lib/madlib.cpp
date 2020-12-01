/***********************************************************************
* Program:
*    Project 10, Mad Lib Program
*    Brother Comeau, CS124
* Author:
*    Marshall Haymond
* Summary: 
*    This program will read a file and find words that need to be answered
*    by the user in the file. Then it will display the answers with a story
*
*    Estimated:  2.0 hrs   
*    Actual:     2.0 hrs
*      The spacing between the words
************************************************************************/

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

/**********************************************************************
 * This function will get the word form the story and filter out each
 * Question. The user will input his text
 ***********************************************************************/
void askQuestion(char text[])
{

   if (text[0] != ':' || !isalpha(text[1]))
   {
      cout << ""; 
   }
   else
   {
      cout << "\t" << (char) toupper(text[1]);
      for (int iText = 2; text[iText] != '\0'; iText++)
      {
         if (text[iText] == '_')
         {
            text[iText] = ' ';
         }
         cout << (char)tolower(text[iText]);
          
      }
      cout << ": ";
      cin.getline(text,256);
   
   }

   

}

/**********************************************************************
 * Gets the file name
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin >> fileName;
   
}

/**********************************************************************
 * Opens file and reads each word from the text into the askQuestion
 * function
 ***********************************************************************/
int readFileName(char fileName[], char story [][32])
{
   cin.ignore();
   ifstream fin(fileName);
   if (fin.fail())
   {
      cout << "Error reading file \"" << fileName << "\"" << endl;
      return -1;
   }
   int numWords = 0;    
   while (numWords < 256 && fin >> story[numWords])
   {
         
      askQuestion(story[numWords]);
      numWords++;
      
         
   }
   fin.close();                
   return numWords;                     
}

/**********************************************************************
 * This will check the story for the right punctuation
 ***********************************************************************/
void isPunc(char story)
{
   if ( story == '!')
   {
      cout << "\n";
   }
   if ( story == '<')
   {
      cout << " \"";
   }
   if ( story == '>')
   {
      cout << "\" ";
   }
   if ( story == '.')
   {
      cout << ". ";
   }
   if ( story == ',')
   {
      cout << ", ";
   }

}

/**********************************************************************
 * This will read the file and call isPunc to read the story right
 ***********************************************************************/
void display(char story[][32], int length)
{
   cout << endl;
   for (int i = 0; i < length; i++)
   { 
      if (story[i][0] == ':')
      {
         isPunc(story[i][1]);
         story[i][0] = '\0';
      }
      if (isalpha(story[i][0]))
      {
         if (isalpha(story[i][0]) && story[i + 1][0] == ':')
            cout << story[i];
         else if (ispunct(story[i+1][0]) && story[i + 1][0] == '!')   
            cout << story[i];
         else
            cout << story[i] << " ";
      }
      else
      {
         cout << story[i];
      }
      
   }



}

/**********************************************************************
 * Main calls the two functions getFileName and readFileName
 ***********************************************************************/
int main()
{
   bool play = true;
   do
   {
      char fileName[256];
      char story [256][32];
      getFileName(fileName);
      int length = readFileName(fileName, story);
      display(story, length);
      
   
   
      char YesNo;
      cout << "\nDo you want to play again (y/n)? ";
      cin >> YesNo;
      if ( YesNo == 'n')
      {
         cout << "Thank you for playing.\n";
         play = false;
         
      }
      
      else 
      {
         play = true;
      }
      
   }
   while (play);
   return 0;
}
