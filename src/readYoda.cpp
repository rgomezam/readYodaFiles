/============================================================================
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

//rivet::YodaFile p1("mcfilePow.yoda");  //Test
rivet::YodaFile p1("mcfileMGNLO-scale1.yoda");
rivet::YodaFile p2("mcfileMGNLO-scale2.yoda");
rivet::YodaFile p3("mcfileMGNLO-scale3.yoda");
rivet::YodaFile p4("mcfileMGNLO-scale4.yoda");
rivet::YodaFile p5("mcfileMGNLO-scale5.yoda");
rivet::YodaFile p6("mcfileMGNLO-scale6.yoda");
rivet::YodaFile p7("mcfileMGNLO-scale7.yoda");
rivet::YodaFile p8("mcfileMGNLO-scale8.yoda");

// And for Powheg:
/*rivet::YodaFile p1("mcfilePow-scale-1-2.yoda");
rivet::YodaFile p2("mcfilePow-scale-2-2.yoda");
rivet::YodaFile p3("mcfilePow-scale-3-2.yoda");
rivet::YodaFile p4("mcfilePow-scale-4-2.yoda");
rivet::YodaFile p5("mcfilePow-scale-5-2.yoda");
rivet::YodaFile p6("mcfilePow-scale-6-2.yoda");
rivet::YodaFile p7("mcfilePow-scale-7-2.yoda");
rivet::YodaFile p8("mcfilePow-scale-8-2.yoda");*/  



int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	mkdir("./newFiles", ACCESSPERMS);

	p1.allocatePlots(); //YOU can only show headers after allocating them

	p2.allocatePlots();

	p1.comparePlotsTakeSmaller(p2);

	rivet::YodaFile temp1("./newFiles/smallest.yoda");
	temp1.showFile();

	//cin.get();

	p3.allocatePlots();
	temp1.allocatePlots();

	p3.comparePlotsTakeSmaller(temp1);

	rivet::YodaFile temp2("./newFiles/smallest.yoda");

	p4.allocatePlots();
	temp2.allocatePlots();

	p4.comparePlotsTakeSmaller(temp2);

	rivet::YodaFile temp3("./newFiles/smallest.yoda");

	p5.allocatePlots();
	temp3.allocatePlots();
	p5.comparePlotsTakeSmaller(temp3);

	rivet::YodaFile temp4("./newFiles/smallest.yoda");

	p6.allocatePlots();
	temp4.allocatePlots();
	p6.comparePlotsTakeSmaller(temp4);

	rivet::YodaFile temp5("./newFiles/smallest.yoda");

	p7.allocatePlots();
	temp5.allocatePlots();
	p7.comparePlotsTakeSmaller(temp5);

	rivet::YodaFile temp6("./newFiles/smallest.yoda");

	p8.allocatePlots();
	temp6.allocatePlots();
	p8.comparePlotsTakeSmaller(temp6);

	rivet::YodaFile smallest("./newFiles/smallest.yoda"); //Not really necessary, you already have the yoda file

	p1.comparePlotsTakeBigger(p2);

	rivet::YodaFile temp7("./newFiles/biggest.yoda");
	temp7.allocatePlots();

	p3.comparePlotsTakeBigger(temp7);
	rivet::YodaFile temp8("./newFiles/biggest.yoda");
	temp8.allocatePlots();

	p4.comparePlotsTakeBigger(temp8);
	rivet::YodaFile temp9("./newFiles/biggest.yoda");
	temp9.allocatePlots();
	p5.comparePlotsTakeBigger(temp9);

	rivet::YodaFile temp10("./newFiles/biggest.yoda");
	temp10.allocatePlots();
	p6.comparePlotsTakeBigger(temp10);

	rivet::YodaFile temp11("./newFiles/biggest.yoda");
	temp11.allocatePlots();
	p7.comparePlotsTakeBigger(temp11);

	rivet::YodaFile temp12("./newFiles/biggest.yoda");
	temp12.allocatePlots();
	p8.comparePlotsTakeBigger(temp12);

	rivet::YodaFile biggest("./newFiles/biggest.yoda");

	// p1.allocatePlots(); //YOU can only show headers after allocating them
	//	cout << "Number of plots: " <<  p1.getNumberOfPlots() << endl;
	//p1.showAllPlots();

	// cin.get(); //Pause

	//p2.allocatePlots(); //YOU can only show headers after allocating them
	//	cout << "Number of plots: " <<  p1.getNumberOfPlots() << endl;
	//p2.showAllPlots();

	//p1.comparePlotsTakeSmaller(p2);
	//p1.comparePlotsTakeBigger(p2);

	//p1.showStatistics(p2);
	//p2.showStatistics(p1);

	//cin.get(); //Pause

	//p1.switchHeaders(p2);
	// rivet::YodaFile p3("./newFiles/biggest.yoda");
	//p3.showFile();

	//cin.get(); //Pause

	//rivet::YodaFile p4("./newFiles/smallest.yoda");
	//p4.showFile();

	return 0;
}
