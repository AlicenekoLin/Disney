/********************************************************************
 *            PA 4 - Extension
 * Author:      Chien-Han Lin, Tsung-Han Lee
 * Date:        Mar 13, 2017
 * File:        DisneyGraph.h
 * Description: Definition of DisneyGraph
 * *****************************************************************/

#ifndef DISNEYGRAPH_H
#define DISNEYGRAPH_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <queue>
#include "DisneyNode.h"

using namespace std;

class DisneyGraph {
public:
  int totalNodes;

  DisneyGraph(void);
  ~DisneyGraph(void);

  /********************************************************************
   * Function Name: loadFromFile
   * Description:   Load spot to spot pair from the input file
   * Input:         (const char*) spots graph in Disney
   * Output:        (bool) whether the loading succeed.
   * *****************************************************************/
  bool loadFromFile(const char* in_filename);

  /********************************************************************
   * Function Name: GreedyPlanner
   * Description:   Load spot to spot pair from the input file
   * Input:         (const string&) start point in Disney
   *                (const float&) Time to spend in Disney
   *                (ofstream&) output file stream
   * Output:        (none)
   * *****************************************************************/
  void GreedyPlanner(const string& Start, const float& budgetTime, ofstream& outfile);

private:
  // Store all the spots instance in DisneyMap
  unordered_map<string, DisneyNode*> DisneyMap;

};


#endif //DISNEYGRAPH_H
