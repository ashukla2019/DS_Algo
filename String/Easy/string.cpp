#include <iostream>
#include <unordered_map>
using namespace std;

/*
//String class:
getline():- This function is used to store a stream of characters as entered by the user in the 
object memory.
getline(cin,str);
push_back():- This function is used to input a character at the end of the string.
pop_back():- Introduced from C++11(for strings), this function is used to delete the last character 
from the string.
length():-This function finds the length of the string.
*/

/*
Streams: I/O in C++ is implemented with streams. Abstractly, a stream is just a 
sequence of bytes that can be accessed sequentially. Over time, a stream may produce or consume
potentially unlimited amounts of data.

The istream class is the primary class used when dealing with input streams. With input streams,
the extraction operator (>>) is used to remove values from the stream. 
This makes sense: when the user presses a key on the keyboard, the key code is placed in an input
stream. Your program then extracts the value from the stream so it can be used.

The ostream class is the primary class used when dealing with output streams. 
With output streams, the insertion operator (<<) is used to put values in the stream. 
This also makes sense: you insert your values into the stream, and the data consumer
(e.g. monitor) uses them.

A standard stream is a pre-connected stream provided to a computer program by its environment. 
C++ comes with four predefined standard stream objects that have already been set up for your use. 
The first three, you have seen before:
cin -- an istream class tied to the standard input (typically the keyboard)
cout -- an ostream class tied to the standard output (typically the monitor)
cerr -- an ostream class tied to the standard error (typically the monitor), providing unbuffered output
clog -- an ostream class tied to the standard error (typically the monitor), providing buffered output

istringstream is an input stream and typically wraps some external source of text that you can
extract with the >> operator. You cannot write to this stream.

stringstream: is a stream that allows you to both read and write with the >> and << operators.


*/

/*
Tokenize a string in C++
Using stringstream: A stringstream associates a string object with a stream allowing you to read 
from the string as if it were a stream.
*/
// Tokenizing a string using stringstream
#include <bits/stdc++.h>

int main()
{
	
	string line = "GeeksForGeeks is a must try";
	
	// Vector of string to save tokens
	vector <string> tokens;
	
	// stringstream class check1
	stringstream check1(line);
	
	string intermediate;
	
	// Tokenizing w.r.t. space ' '
	while(getline(check1, intermediate, ' ')) //or while(check1 >> intermediate)
	{
		tokens.push_back(intermediate);
	}
	
	// Printing the token vector
	for(int i = 0; i < tokens.size(); i++)
		cout << tokens[i] << '\n';
}

//Tokenizing a string using strtok():
int main()
{
	char str[] = "Geeks-for-Geeks";

	//Returns first token
	char *token = strtok(str, "-");

	//Keep printing tokens while one of the delimiters present in str[].
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, "-");
	}

	return 0;
}

/*
strrchr() function:
In C++, strrchr() is a predefined function used for string handling. cstring is the header file required
for string functions. This function returns a pointer to the last occurrence of a character in a string. 
*/

/*String stream applications:
// CPP program to count words in a string using stringstream.
#include <bits/stdc++.h>

int countWords(string str)
{
	// breaking input into word using string stream
	stringstream s(str); // Used for breaking words
	string word; // to store individual words

	int count = 0;
	while (s >> word)
		count++;
	return count;
}

// Driver code
int main()
{
	string s = "geeks for geeks geeks "
			"contribution placements";
	cout << " Number of words are: " << countWords(s);
	return 0;
}

// CPP program to demonstrate use of stringstream to count frequencies of words.
void printFrequency(string st)
{
	// each word it mapped to it's frequency
	map<string, int> FW;
	stringstream ss(st); // Used for breaking words
	string Word; // To store individual words

	while (ss >> Word)
		FW[Word]++;

	map<string, int>::iterator m;
	for (m = FW.begin(); m != FW.end(); m++)
		cout << m->first << " -> "
			<< m->second << "\n";
}

// Driver code
int main()
{
	string s = "Geeks For Geeks Ide";
	printFrequency(s);
	return 0;
}

/*
// Function to remove spaces
string removeSpaces(string str)
{
	stringstream ss(str);
	string temp;
    str = "";
    while(ss >> temp)
    {
        str = str + temp;
    }
	return str;
}

// Driver function
int main()
{
	// Sample Inputs
	string s = "This is a test";
	cout << removeSpaces(s) << endl;
*/

/*
//Find words greater than k length....
void findWords(string str, int K)
{
    string word;
      
    // using stringstream to break
    // the string into tokens
    stringstream ss(str); 
      
    int count = 0;
    while (ss >> word) { // reading words
        if (word.size() > K) {
            cout << word << " ";
            count++;
        }
    }
}

*/

//Swap two strings:
void swap(char *str1, char *str2)
{
  char *temp = str1;
  str1 = str2;
  str2 = temp;
}  

//Get frequency of all chars in given string
void printFrequency(string str)
{
	// Define an unordered_map
	unordered_map<char, int> M;

	// Traverse string str check if
	// current character is present
	// or not
	for (int i = 0; str[i]; i++)
	{
		// If the current characters is not found then insert current characters with
		// frequency 1
		if (M.find(str[i]) == M.end())
		{
			M.insert(make_pair(str[i], 1));
			
		}

		// Else update the frequency
		else
		{
			M[str[i]]++;
		}
	}

	// Traverse the map to print the
	// frequency
	for (auto& it : M) 
	{
		cout << it.first << ' ' << it.second << '\n';
	}
}

int findstrlen(const char *str)
{
	int len=0;
	while(*str)
	{
		len++;
		str++;
	}
	return len;
}
char* mystrcat(char* dest, const char*src)
{
	int i = 0, j =0;
	int len = findstrlen(dest);
	while(dest[i] != '\0')
	{
	printf("string before concating is %c\n", dest[i]);
	i++;
	}
	while(src[j] != '\0')
	{
	dest[i] = src[j];
	i++;
	j++;
	}
	dest[i] = '\0';
	printf("concanated string is %s\n", dest);
	return dest;
}
// Function to implement strcmp function
/*
strcmp returns value:
1) if first non matching character has lower ascii value in s1 than s2(returns <0)
2) if both strings are equal(returns 0)
3) if first non matching character has higher ascii value in s1 than s2(returns >0)

*/

int strcmp(const char *X, const char *Y)
{
	while(*X)
	{
		// if characters differ or end of second string is reached
		if (*X != *Y)
		break;
		// move to next pair of characters
		X++;
		Y++;
	}
	// return the ASCII difference after converting char* to unsigned char*
	return *(const unsigned char*)X - *(const unsigned char*)Y;
}
char* mystrcpy(char* dest, const char* src)
{
	int i = 0;
	while(src[i] != '\0')
	{
	dest[i] = src[i];
	i++;
	}
	dest[i] = '\0';
	return dest;
}

/*
//Parse string and return if string contains int/float/alphanumeric

enum type
{
	inttype,
	floattype,
	alphanumeric
};

int checkStringType(char* str)
{
	int length = strlen(str);
	int type;
	for(int i = 0; i< length; i++)
	{
		if(str[i] == '.')
		{
			type = floattype;
			break;
		}
		else if(!isdigit(str[i]))
		{
			type = alphanumeric;
			break;
		}
		else
		{
			type = inttype;
		}
	}
	return type;
}

// Driver Code 
int main() 
{ 
	char str[] = "121";
	cout<<"type of string is:"<<checkStringType(str)<<endl;
	return 0; 
} 

*/







