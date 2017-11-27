#include "DisneyGraph.h"

/********************************************************************
 * Function Name: constructor
 * Description:   Construct an DisneyGraph instance
 * Input:         None
 * Output:        None
 * *****************************************************************/
DisneyGraph::DisneyGraph(void){}

/********************************************************************
 * Function Name: destructor
 * Description:   Destruct all the instance inside the DisneyGraph
 * Input:         None
 * Output:        None
 * *****************************************************************/
DisneyGraph::~DisneyGraph(void){
  for(auto ele:DisneyMap) {
    delete ele.second;
  }
}

/********************************************************************
 * Function Name: loadFromFile
 * Description:   Load spot to spot pair from the input file
 * Input:         (const char*) spots graph in Disney
 * Output:        (bool) whether the loading succeed.
 * *****************************************************************/
bool DisneyGraph::loadFromFile(const char* in_filename) {
  // Initialize the file stream
  ifstream infile(in_filename);
  int numOfNodes = 0;
  // Keep reading lines until the end of file is reached
  while (infile) {
    string s;
    // Get the next line
    if (!getline( infile, s )) break;

    istringstream ss( s );
    vector <string> record;

    while (ss) {
      string next;
      // Get the next string before hitting a tab character
      // and put it in 'next'
      if (!getline( ss, next, ',' )) break;

      record.push_back( next );
    }

    if (record.size() != 3) {
      // We should have exactly 3 columns
      continue;
    }

    string StartName(record[0]);
    string EndName(record[1]);
    float timeCost = stoi(record[2]);

    // Implement an iterator to find the actor in the ActorMap
    unordered_map<string, DisneyNode*>::iterator dis_itr1 = DisneyMap.find(StartName);
    unordered_map<string, DisneyNode*>::iterator dis_itr2 = DisneyMap.find(EndName);

    // Add the disneyNode if it's not exist in the DisneyMap
    // Otherwise, get the the mapped DisneyNode* pointer
    DisneyNode* disPtr1;
    if(dis_itr1 != DisneyMap.end()) {
      disPtr1 = dis_itr1->second;
    }
    else {
      disPtr1 = new DisneyNode(StartName);
      DisneyMap.insert( {StartName, disPtr1} );
      numOfNodes++;
    }

    DisneyNode* disPtr2;
    if(dis_itr2 != DisneyMap.end()) {
      disPtr2 = dis_itr2->second;
    }
    else {
      disPtr2 = new DisneyNode(EndName);
      DisneyMap.insert( {EndName, disPtr2} );
      numOfNodes++;
    }

    // Add disPtr2 into disPtr1's nextVec
    disPtr1->nextVec.push_back( {disPtr2, timeCost} );
  }

  if (!infile.eof()) {
    cerr << "Failed to read " << in_filename << "!\n";
    return false;
  }
  infile.close();

  totalNodes = numOfNodes;
  return true;
}

/********************************************************************
 * Function Name: GreedyPlanner
 * Description:   Load spot to spot pair from the input file
 * Input:         (const string&) start point in Disney
 *                (const float&) Time to spend in Disney
 *                (ofstream&) output file stream
 * Output:        (none)
 * *****************************************************************/
void DisneyGraph::GreedyPlanner(const string& Start, const float& budgetTime,
                                ofstream& outfile) {
  queue<DisneyNode*> Plan;
  float remainTime = budgetTime;

  // Initialize to the start point
  DisneyNode* curr = DisneyMap[Start];
  curr->isVisited = true;
  Plan.push(curr);

  // Finding the path
  while (remainTime > 0) {
    DisneyNode* nextNode = curr;
    float MinTime = 9999;
    // Find the smallest cost for as the nextNode
    for (auto candidate : curr->nextVec) {
      if (!candidate.first->isVisited && candidate.second < MinTime) {
        nextNode = candidate.first;
        MinTime = candidate.second;
      }
    }

    if (curr == nextNode) {
      break;
    }

    // Curr points to the nextNode
    curr = nextNode;

    // Mark the curr as Visited
    curr->isVisited = true;

    // Put curr it into Plan
    Plan.push(curr);

    // Subtract the remainTime
    remainTime -= MinTime;
  }

  cout<<"Total # of Spots: "<<Plan.size()<<endl;

  // Output to file
  while( !Plan.empty() ) {
    outfile << Plan.front()->name;
    if (Plan.size() > 1 ) {
      outfile << " --> ";
    }
    Plan.pop();
  }
}
