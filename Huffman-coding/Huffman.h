#pragma once
#ifndef HUFFMAN_H
#define HUFFMAN_H
#include<vector>
#include<string>
using namespace std;
class Huffman
{
public:
	Huffman();
	~Huffman();
	
	void readFile(vector<string> &, string );			//read file text and store in vector
	void toChar(vector<string>, vector<char> &);		//converts each string to char	
	void toASCII(vector<char>, vector<int> &);		//convert text char to ASCII
	void toBinary(vector<int>, vector<string> &);		//convert ASCII  to binary
	void reduceChar(vector<char> &);
	void frequency(vector<char>,vector<char> ,vector<int> &);
};
#endif
