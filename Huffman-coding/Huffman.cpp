#include "Huffman.h"
#include<fstream>
#include<bitset>
#include<string>
#include<vector>
#include<algorithm>
Huffman::Huffman()
{
}


Huffman::~Huffman()
{
}
void Huffman::readFile(vector<string> &v, string f)		//this function reads a file from memory and stores it in a vector
{
	char c;
	ifstream file;
	file.open(f);		//open file for reading
	while (!file.eof())	//while you have not reached the end of text 
	{
		string c;
		getline(file,c);			//keep on reading to buffer
		v.push_back(c);		//and store each character in file in a vector 
	}
	file.close();			//close file after reading.
}
void Huffman::toASCII(vector<char> c, vector<int> &a)		//function converts character to ASCII
{
	for (int i = 0; i < c.size(); i++)
	{
		a.push_back(int(c[i]));		//convert character to ASCII codes
	}
}
void Huffman::toChar(vector<string> s, vector<char> &c)	//function that extracts strings from a sentence and stores them in char vector
{
	string t;
	for (int i = 0; i < s.size(); i++)
	{
		t = s[i];
		for (int j = 0; j < t.length(); j++)
		{
			c.push_back(t[j]);
		}
	}
}
void Huffman::toBinary(vector<int> a, vector<string> &b)		//function converts ASCII to binary
{
	for (int i = 0; i < a.size(); i++)
	{
		bitset<7> t(a[i]);					//convert each ASCII to binary
		b.push_back(t.to_string());			//store each binary as string to
	}
}
void Huffman::reduceChar(vector<char> &c)
{
	sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.end());
}
void Huffman::frequency(vector<char> c, vector<char> C, vector<int> &freq)	//compute frequency of each letter in text
{
	int f = 0;
	for (int i = 0; i < c.size(); i++)
	{
		for (int j = 0; j < C.size(); j++)
		{
			if (c[i] == C[j]) f += 1;
		}
		freq.push_back(f);
		f = 0;
	}
}