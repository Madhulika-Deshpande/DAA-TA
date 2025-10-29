Q1. Travelling Salesman Problem for travelling cities:

This program figures out shortest path to visit four cities A,B,C,D and return back to starting city.
The tsp function recursively tries every possible route by visiting cities.
It stores each route and it's distance and it keeps track of shortest route.

Shortest routes are: A->B->D->C->A and A->C->D->B->A = 80km

Q2.Deilvery Driver's shortest route:

In this program we find best route for delivery driver visiting three customers C1,C2,C3.
The cost matrix shows distance between each location.
The program tries every possible route and using recursion and backtracking it calculates total distance for each route.
And then finds shortest route.

Shortest route are:D->C1->C2->C3->D and D->C3->C2->C1->D = 19km

Q3.DNA Sequence combination:

There are 4 DNA fragments AGT, GTC, TCA, CAT.
The program joins them together in combinations so that overlapping parts are not reapeated. 
The function extraLength checks how much overlap the two fragments have. 
Function shortestSequence calculates total sequence length for each string and finds shortest length.

Shortest sequence: F1->F2->F3->F4 AGTCAT = 6
