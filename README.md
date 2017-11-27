# Disney
Have you ever spend a lot of time planning routes before you visit disnayland? 
In this extension task, we are going to suggest you one of the best route plans
to explore as many as possible spots matching to your total time budget. 

Start from one of best entertainments called "Radiator Springs Racers", located 
in Disney California Adventure Park, the estimated route will be written in a 
files with the format <Spot Name> --> <Spot Name> --> ... --> <Spot Name>...".

First, we manually select 100+ spots from Disneyland Park and Disney California 
Adventure Park using Google map. These spots are classified in four groups: 
Entertainment, Dining & Restaurants,Shop and Others. Distances between <Start, 
Destination> pairs, e.g. <Entertainment,c>, <Dining,Dining>, <Shop,Shop>, <Others,
Others>, <Entertainment,Shop>, <Shop,Entertainment> etc, are calculated and transformed 
the unit of length (foot) into time (minutes) as we assumed the human average walking 
speed is 272.8 foot/min. In addition, time distances of <Start, Destination> pairs 
will be appended with waiting times of destinations. 

After spots, viewed as nodes in a graph, and distances, regarded as weighted edges 
in a graph, are all constructed, we implement greedy algorithm to solve this 
problem.

$make<br>
$./extension Extimated_Distance.txt 500 DisneyPlan.txt g<br>

a. <"Usage: ./extension <DisneyGraph> <time budget(mins)> <outputfile> <method>">
  , and g stands for greedy algorithm.<br>
b. All files needed for this extension task: DisneyGraph.h, DisneyGraph.cpp, DisneyNode.h, 
Extimated_Distance.txt, extension.cpp<br>
