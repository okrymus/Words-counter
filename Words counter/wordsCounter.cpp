// Word counter HOMEWORK
// The program determines the average length of the words and the number of words in a sentence or a file   " <<
// Programmer: Panupong Leenawarat	
// Last modified 2/5/2016

#include<iostream>
#include<fstream>                                                      
#include<string>                                                       // Declare to use functions in the c++ library
#include<cctype>                                                       // Declare to use several functions in the string class
using namespace std;

// Global variables
unsigned int wordCount = 0;                                            // To get the number of words
unsigned int letterCount = 0;                                          // To get the length of the words
string word, fileName, sentence;                                       // TO store string from input

// Function Prototype
void countNumberOfWords();
void countWordFromFile();

int main()
{
	int option;                                                        // To get the chosen option from input

	// Display the program's introduction
	cout
		<< endl 
		<< "\t                ----- Word Counter -----               " << endl
		<< "\t The program determines the average length of the words" << endl
		<< "\t    and the number of words in a sentence or a file   " << endl
		<< "\t                    By Lee. Panupong                   " << endl << endl;

	// Display the options and allow the user to select
	cout
		<< "\t1) Count the words from a file  " << endl
		<< "\t2) Count the words from the input" << endl 
		<< "\t         Choose 1 or 2: ";
	cin >> option;                                                     // Get a option from the user
	cin.ignore();                                                      // Remove everything else from cin

	while (option != 1 && option != 2)                                 // While getting the invalid option from the user, process it
	{
		cout << "\tPlease enter only 1 or 2, try again: ";             
		cin >> option;                                                 // Get a option from the user again
		cin.ignore();                                                  // Remove everything else from cin
	}
	
	if (option == 1)                                                   // If the option is 1, the user want to count the words from a file 
	{
		cout << endl << " Enter the file name: ";                              // Display for getting a file name to open
		cin >> fileName;                                               // Get the file name to open

		countWordFromFile();                                           // Calling wordCountFromFile() function to get the number of the words and the total length of the words in the file
	}
	if (option == 2)                                                   // If the option is 2, the user want to count the words from input sentence 
	{
		cout << endl << " Enter a sentence: ";                         // Display for getting a sentence from input
		getline(cin, sentence);                                        // Get the sentence from the user
		
		countNumberOfWords();                                          // Calling countNumberOfWords() function to get get the number of the words and the total length of the words in the sentence
	}

	// If wordCount is not 0, process it to display the number of the words and the average length of the words
	if (wordCount != 0)
	{
		cout << " The " << (option ==1 ? "file" : "sentence") << " certains with " << wordCount << (wordCount > 1 ? " words" : " word") << endl;
		cout << " The average length of the words in the " << (option == 1 ? "file" : "sentence") << " is " << letterCount / wordCount << endl;
	}
	
	cout << endl;
	system("pause");
}

//***********************************************************
// Definition of function countNumberOfWords.               *
// This function accepts none argument                      *
// This function is sharing with the global variable        *
// The function counts the number of the words in the input *
// sentence and the total length of the words               *                             
//***********************************************************
void countNumberOfWords()
{
	int count,wordLength = 0;                                                         // Declare the loop variabla and wordLength is 0

	wordLength = sentence.length();                                                   // Assign wordLength is equal to the lenght of the sentence

	if (sentence[0] != '\0' && wordLength != 0)                                       // If the input is not blank, process it
		for (count = 0; count < wordLength; count++)
		{
			if (isalpha(sentence[count]))                                             // Count for the total length of the words 
				letterCount++;                                                       
			if ((isalpha(sentence[count])) && (!isalpha(sentence[count - 1])))        // Count for the number of the words
				wordCount++;
		}
}

//***********************************************************
// Definition of function countWordFromFile.                *
// This function accepts none argument                      *
// This function is sharing with the global variable        *
// The function counts the number of the words in the input *
// file name and the total of the length of the words       *                             
//***********************************************************
void countWordFromFile()
{
	ifstream inputFile;                                                              // Input file stream opject

	inputFile.open(fileName);                                                        // Open the fileName to read

	if (inputFile)                                                                   // If the file is able to reach and get data from it
	{
		while (!inputFile.eof() && inputFile >> word)                                // Get data from the file
		{
			if (word.length() != 0)                                                  // If the words length is not 0, process it
			{
				wordCount++;                                                         // wordCount is incresing by 1 while the number of the words is increasing
				letterCount += word.length();                                        // Count for the total length of the words 
			}
		}
	}
	else
	{
		cout << "\tThe file cannot open" << endl;                                    // Display if the file name cannot open
		wordCount = 0;
	}

	inputFile.close();                                                               // Close the file
}

