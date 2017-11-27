/********************************************************************
 *            PA 4 - Extension
 * Author:      Chien-Han Lin, Tsung-Han Lee
 * Date:        Mar 13, 2017
 * File:        DisneyNode.h
 * Description: Definition of DisneyNode
 * *****************************************************************/

#ifndef DISNEYNODE_H
#define DISNEYNODE_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class DisneyNode {
public:
  int category;
  float waitingTime;
  string name;
  pair<float, float> coordinate;
  vector< pair<DisneyNode*, float> > nextVec; //Next spot children vector

  bool isVisited;
  DisneyNode* previous;

  /********************************************************************
   * Function Name: DisneyNode constructor
   * Description:   Construct an instance of DisneyNode
   * Input:         (string) name spot in Disney
   * Output:        None
   * *****************************************************************/
  DisneyNode(string n):
    category(0), waitingTime(0), name(n), coordinate( {0,0} ),
    isVisited(false), previous(nullptr) {}

  /********************************************************************
   * Function Name: DisneyNode constructor
   * Description:   Construct an instance of DisneyNode
   * Input:         (int) category of the spot
   *                (float) waitingTime of the spot
   *                (string) name spot in Disney
   *                (pair<float, float>) coordinates of the spot
   * Output:        None
   * *****************************************************************/
  DisneyNode(int cat, float time, string n, pair<float, float> coord):
    category(cat), waitingTime(time), name(n), coordinate(coord),
    isVisited(false), previous(nullptr) {}
};

#endif //DISNEYNODE_H
