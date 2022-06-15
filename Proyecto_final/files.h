#pragma once
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>

using namespace System;
using namespace std;

class File
{
private:
	ofstream fileWrite;
	ifstream fileRead;
	string text;

	int time;
	int nenemies;

public:
	File() {}
	~File() {}

	void reaData() {
		fileRead.open("configuration.txt", ios::in);

		if (fileRead.fail()) {

			fileRead.close();

			fileWrite.open("configuration.txt", ios::out);
			fileWrite << "100" << endl;
			fileWrite << "20" << endl;
			fileWrite.close();


			fileRead.open("configuration.txt", ios::in);

		}
		getline(fileRead, text);
		time = atoi(text.c_str());
		getline(fileRead, text);
		nenemies = atoi(text.c_str());

		fileRead.close();

	}
	int getTime() { return time; }
	int getNAgentes() {
		return nenemies;
	}



};

