/*
 * YodaFile.cpp
 *
 *  Created on: Sep 5, 2015
 *      Author: raquel
 */

#include "YodaFile.h"
#include <iostream>
using namespace std;
#include <fstream>
#include "Plot.h"
#include <sstream> //For scientific notation

namespace rivet {

YodaFile::YodaFile(char name[30]) {
	for (int i = 0; i < 30; i++) {
		this->myName[i] = name[i];
	}
	cout << "Working on file: " << myName << endl;

	this->numberOfPlots = this->getNumberOfPlots();

	for (int j = 0; j < 40; j++) {
		this->arrPlots[j] = NULL;
	}
}


YodaFile::~YodaFile() {
	cout << "deleting YodaFile" << endl;
	for (int j=0; j<40; j++){
		if (this->arrPlots[j] != NULL){
			delete this->arrPlots[j];
			this->arrPlots[j]=NULL;
		}
	}

}


void YodaFile::showFile() {

	ifstream in(this->myName);

	in.seekg(0, in.end);
	int length = in.tellg();
	in.seekg(0, in.beg);

	char * buffer = new char[length];

	std::cout << "Reading " << length << " characters... ";
	// read data as a block:
	in.read(buffer, length);

	cout << endl;
	cout << buffer << endl;

	if (in)
		std::cout << "all characters read successfully.";
	else
		std::cout << "error: only " << in.gcount() << " could be read";
	in.close();

	delete[] buffer;
}



int YodaFile::getNumberOfPlots() {
	string line;
	int numPlots = 0;

	ifstream file;
	file.open(this->myName);

	while (!file.eof()) {
		getline(file, line);
		if (line == "# END YODA_HISTO1D") {
			++numPlots;
		}
	}
	return numPlots;
}


void YodaFile::allocatePlots() {
	string line;
	ifstream file;
	int numOfBins = 0;
	long double entry;

	file.open(this->myName);

	int n;

	for (int i = 0; i < this->numberOfPlots; i++) {
		this->arrPlots[i] = new Plot(i, this->myName);

		for (int j = 0; j < 14; j++) {
			getline(file, line);
			arrPlots[i]->setHeader(line,j);
		}
		n = 0;
		do{
			getline(file, line);
			arrPlots[i]->setNumberOfBins(n);
			n++;
		}while (line != "# END YODA_HISTO1D");
		getline(file,line); //To pass the blank line between plots!
	}
	file.close();

	file.open(this->myName);
	for (int k = 0; k < this->numberOfPlots ; k++) {

				numOfBins = arrPlots[k]->getNumberOfBins();

				do {
					getline(file, line);
				} while (line!= "# xlow	 xhigh	 sumw	 sumw2	 sumwx	 sumwx2	 numEntries");

				for (int i = 0; i < numOfBins; i++) {
					for (int j = 0; j < 7; j++) {
						file >> entry;
						arrPlots[k]->setValues(entry, i, j);
					}
					cout << endl;
				}

		}
	file.close();
}


void YodaFile::showAllPlots() {
	string* a;

	for (int i = 0; i < this->numberOfPlots; i++) {
		cout << "Plot number: " << i << endl;
		a = (arrPlots[i]->getHeader());
		for (int j=0; j<14; j++){
		cout << a[j] << endl;
		}
			arrPlots[i]->showAllValues();
		cout <<	arrPlots[i]->getFooter();
			cout << endl;
			cout << endl;

	}
}


void YodaFile::comparePlotsTakeSmaller(YodaFile &rhs) {
	long double temp1, temp2, temp3;
	ofstream file("./newFiles/smallest.yoda");
	 string* a;


	for (int i= 0; i< this->getNumberOfPlots() ; i++){ //Test with 3 plots first
	a = (arrPlots[i]->getHeader());
	for (int h=0; h<14; h++){
	file << a[h] << endl;
	}
	for (int k=0; k< this->arrPlots[i]->getNumberOfBins() ; k++ ){
		for (int l=0; l<7; l++ ){  //only columns 2-3-4-5 change, but its easier to compare all for printing reasons
	temp1= this->arrPlots[i]->values[k][l];
	temp2= rhs.arrPlots[i]->values[k][l];
	(temp2 < temp1 ? temp3=temp2 : temp3=temp1); // (a ? b : c) -> if/then/else
	file << scientific << temp3 << "\t";
	}
		file << endl;
	}
	file << this->arrPlots[i]->getFooter() << endl << endl;
	}
	file.close();
}

void YodaFile::comparePlotsTakeBigger(YodaFile &rhs) {
	long double temp1, temp2, temp3;
	ofstream file("./newFiles/biggest.yoda");
	 string* a;


	for (int i= 0; i< this->getNumberOfPlots() ; i++){ //Test with 3 plots first
	a = (arrPlots[i]->getHeader());
	for (int h=0; h<14; h++){
	file << a[h] << endl;
	}
	for (int k=0; k< this->arrPlots[i]->getNumberOfBins() ; k++ ){
		for (int l=0; l<7; l++ ){  //only columns 2-3-4-5 change, but its easier to compare all for printing reasons
	temp1= this->arrPlots[i]->values[k][l];
	temp2= rhs.arrPlots[i]->values[k][l];
	(temp2 > temp1 ? temp3=temp2 : temp3=temp1); // (a ? b : c) -> if/then/else
	file << scientific << temp3 << "\t";
	}
		file << endl;
	}
	file << this->arrPlots[i]->getFooter() << endl << endl;

	}
	file.close();
}


}// End namespace
