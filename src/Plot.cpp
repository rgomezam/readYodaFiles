/*
 * Plot.cpp
 *
 *  Created on: Sep 6, 2015
 *      Author: raquel
 */

#include "Plot.h"
#include <iostream>
using namespace std;
//#include <iomanip> //For setprecission
#include <sstream> //For scientific notation

namespace rivet {

Plot::Plot(int num, string name) {
	this->plotNum = num;
	cout << "Creating plot number: " << num << endl;
	this->fromFileName = name;
	cout << "From file named: " << this->fromFileName << endl;
	numberOfBins = 1; //Default
	this->footer = "# END YODA_HISTO1D";

}

Plot::~Plot() {
//cout << "deleting plot " <<  this->plotNum << endl;
}

void Plot::setHeader(string linei,int i) {
		this->header[i] = linei;
}
/*
void Plot::getHeader() {
	for (int i = 0; i < 15; i++) {
		cout << header[i] << endl;
	}
}
*/
void Plot::setNumberOfBins(int num) {
	this->numberOfBins = num;
}

void Plot::setValues(long double value, int i, int j) {
	this->values[i][j] = value;
}

void Plot::showAllValues() {
	for (int j=0; j< this->numberOfBins; j++){
	for (int i= 0; i<7; i++){
	cout << scientific << this->values[j][i] << " \t";
	}
	cout << endl;
	}
}

} /* namespace rivet */
