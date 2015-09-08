//============================================================================
// Name        : readYODA3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include<iostream>
#include<fstream>
using namespace std;
//#include "Plot.h"
#include "YodaFile.h"
#include <sys/stat.h>

rivet::YodaFile p1("mcfilePow.yoda");
rivet::YodaFile p2("mcfilePow-scale-1.yoda");


int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	mkdir("./newFiles",ACCESSPERMS);




	 p1.allocatePlots(); //YOU can only show headers after allocating them
	 //	cout << "Number of plots: " <<  p1.getNumberOfPlots() << endl;
	 p1.showAllPlots();

	// cin.get(); //Pause


	 p2.allocatePlots(); //YOU can only show headers after allocating them
	 //	cout << "Number of plots: " <<  p1.getNumberOfPlots() << endl;
	 p2.showAllPlots();


	 p1.comparePlotsTakeSmaller(p2);

	 p2.comparePlotsTakeBigger(p1);

	 cin.get(); //Pause

	 rivet::YodaFile p3("./newFiles/biggest.yoda");
	p3.showFile();

	 cin.get(); //Pause
	 rivet::YodaFile p4("./newFiles/smallest.yoda");

	p4.showFile();

	 return 0;
}


