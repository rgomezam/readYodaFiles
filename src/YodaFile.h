/*
 * YodaFile.h
 *
 *  Created on: Sep 5, 2015
 *      Author: raquel
 */

#ifndef YODAFILE_H_
#define YODAFILE_H_
#include "Plot.h"


namespace rivet {

class YodaFile {
public:
	YodaFile(char name[30]);
	virtual ~YodaFile();
	void showFile(); //Shows the whole file, before you start working with it
	//void readValues();
	int getNumberOfPlots(); //Subroutine
	void allocatePlots();
	//void showHeaders(); //Shows all headers
	void showAllPlots();

	void comparePlotsTakeSmaller(YodaFile &);
	void comparePlotsTakeBigger(YodaFile &);

private:
	char myName[30];
	int numberOfPlots;
	rivet::Plot *arrPlots[40]; //Its better to leave this fixed in 40 than to do it dynamical (lees steps in the main)
	//string headers[15][40];
	//string values[100][40];
};

} /* namespace rivet */

#endif /* YODAFILE_H_ */
