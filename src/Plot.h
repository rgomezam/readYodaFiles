/*
 * Plot.h
 *
 *  Created on: Sep 6, 2015
 *      Author: raquel
 */

#ifndef PLOT_H_
#define PLOT_H_


#include <iostream>
using namespace std;


namespace rivet {

class Plot {
public:
	Plot(int num, string name);
	virtual ~Plot();
	void setHeader(string, int);
	string* getHeader(){return header;}
	string getFooter(){return footer;}
	void setNumberOfBins(int num);
	int getNumberOfBins(){return numberOfBins;}
	void setValues(long double value, int i, int j);
	void showAllValues();
	long double values[100][7]; //Easier if this one is public


private:
	string title[20];
	int plotNum, numberOfBins;
	string fromFileName;
	string header[14];
	string footer;

};

} /* namespace rivet */

#endif /* PLOT_H_ */
