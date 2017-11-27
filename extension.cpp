/********************************************************************
 *            PA 4 - extension
 * Author:      Chien-Han Lin, Tsung-Han Lee
 * Date:        Mar 13, 2017
 * File:        extension.cpp
 * Description: Implementations of extension for planning in Disney.
 *              Read the graph for every spot from X to Y with overall walking
 *              and waiting time as edge weight.
 *              Given the start point (spot) and time to spend (mins) in Disney,
 *              output the result to a assigned file with the best plan.
 * Usage:       ./extension <DisneyGraph> <time budget> <output file> <method>
 *              <method> can be: g:Greedy algorithm, c: Christofides algorithm
 *              ex:
 *                  ./extension Extimated_Distance.txt 500 DisneyPlan.txt g
 * *****************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include "DisneyGraph.h"

using namespace std;

int main(int argc, char const *argv[]) {
  // Fixed the StartPoint (spot) in Disney
  string StartPoint = "Radiator Springs Racers";

  cout << "--- Start running Disney Planner ---" << endl;

  // Examine the number of input arguments
	if (argc < 5 || argc > 6) {
    cout << "Incorrect number of arguments." << endl;
    cout << "Usage: ./extension <time budget> <output> <method>" << "\n\n";
    exit(-1);
  }

  // Examine the content of argv[2]
  // g -- find the plan with Greedy algorithm
  // c -- find the plan with Christofides algorithm
  if (string(argv[4]).compare("g")!=0 && string(argv[4]).compare("c")!=0){
  	cout << "Incorrect arguments." << endl;
    cout << "Usage: ./extension <time budget> <output> <method>" << "\n\n";
    exit(-1);
  }

  // Construct an disneygraph
  DisneyGraph disneygraph;
  disneygraph.loadFromFile(argv[1]);

  // Initialize the output file stream
  ofstream outfile(argv[3]);
  string method;

  outfile << "Format: <Spot Name> --> <Spot Name> --> ... --> <Spot Name>\n\n";

  // Find the earliest year that input actors were met and write to the outfile
  if( argc == 4 && string(argv[4]).compare("c") == 0) {
    method = "Christofides";
    disneygraph.GreedyPlanner(StartPoint, (float) stoi(argv[2]), outfile);
  }
  else {
    method = "Greedy";
    disneygraph.GreedyPlanner(StartPoint, (float) stoi(argv[2]), outfile);
  }

  outfile.close();
  cout << "--- Finish Disney Planner  ---" << endl;
  return 0;
}
