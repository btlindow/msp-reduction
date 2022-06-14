# MSP-Reduction

I suck at coding. I suck at C++. I suck at using vim. This project is my attempt to get better at the latter two. The first is a lost casue.

## Maximal Subclique Problem
A graph is a construct in discrete mathematics that contains other discrete constructs called vertices and edges. In the movie "Good Will Hunting," Will Hunting draws a discrete graph on the hallway chalkboard in an attempt to solve Professor
 Lambeau's challenge to his students. The circles he was drawing were vertices and the lines connecting those vertices together were edges. 

 The Maximal Subclique Problem (MSP) is a problem focused in Computer Science that aims to find a maximal, complete subgraph of the input graph. Let's break that down. A complete graph is a graph where every vertex in that graph has an edge connecting them to every other node in the graph. A subgraph is just a smaller collection, or subset, of the vertices and edges of the main graph. A maximal, complete subgraph is the largest subgraph that is also complete.  

 It may help to think of graphs in a more concrete way. Consider a body of students consisting of different groups, cliques, of friends. Think of each individual in the student body as a vertex and their various friendships as edges to other students. What you are left with is this giant graph of vertices and edges that define the relationships within that student body. The goal of the MSP is to find the largest group of friends inside that student body.

 ## Reduction Technique
 After many hours of shower thoughts thinking about how to find a polynomial solution to this problem, I (re)discovered a way to reduce the size of the problem for a given "k" sized subclique. I will probably come back and write more about this later. I can't take all of the credit for this soultion because I was researching it after-the-fact and found a paper mentioning it in the 1980's. But I figured it would be cool to implement it in ole' fashion C++.  

 Okay, here is the "more." When we are looking for a clique of size "k", that is a group of "k" friends, we only need to look at all of the students in the student body who have at least "k-1" friends. Think about it. If we are looking for a clique of size 10, we don't need to consider the students who have 2 friends. Obviously they don't have enough frineds to be in our clique. But this is where we can make this problem simpler by "reducing" the input problem.  

 Lets say we are looking for a clique of 10 friends in the student body. We can segregate the student body into two groups. The group on the left are the cool kids who all have 9 or more friends (because all the members in a 10-clique must have at least 9 friends), and the group on the right are all the losers with less than 9 friends. Now that we have the students separated, we can kick all of the loser kids out of the gymnasium. There time here is over. But wait... what if they were friends with some of the cool kids on the left? Well, those cool kids just got a little less cool. We will go through each one of them, decrease their number of friends by the number that had to leave, and we restart the process. Chances are there were a few "cool" kids that only had 9 friends, some of which were on the "uncool" side. When it comes time to repeat this process again, these "cool" kids suddenly become "uncool" and are kicked out of the gymansium. We repeat this process until we are left with one of two conditions: a) there aren't any "uncool" kids waiting to be kicked out, or b) there are no kids reminaing in the gymansium.  

 If we still have kids reminaing and none of them are "uncool", then we have successfully reduced the size of students we need to check in our clique. On the other hand, if we have no students left in the gymansium, then we know we don't have a clique of size 10. The beauty of this process is we can perform this process for any size group. Whatsmore, is we can even be clever with what "k" to start and stop with.  

 Lets say our student body has 100 students. Of those 100 students, the most popular student (there is only one popular student in this example) has 31 friends. In this example, can we have a clique of size 99? No, because we know nobody has 98 friends. Likewise, we know there aren't any cliques of size 32, because there is only 1 student with 31 friends. We can eventually work our way down, counting the number of students with friends larger than k, and once we hit that threshold we know we can start looking. But what about a lower bound?  

 We know that in ANY student body with at least 1 friendship (that is, a graph with at least 1 edge in it), that there will be a clique of size 2. That clique is just the two nodes on either end of that friendship. We can use Turan's Theorem to find the maximum number of edges in a graph before a clique is created. This will allow us to define an upper and lower limit on the "k" we should search for in our graph, further optimizing the runtime of our algorithm.  

 Now, because I am spending way too much time writing this, I am going to cheat a little bit when I report my metrics about how much of a "reduction" this soultion is. I am going to write a brute force algorithm that will still attempt to check for a 100-clique even if the max of any one node is 32. Why? Because I can.

 ## Tools
 I am using CMake because whats easier than having a machine write your Makefile for you.  
 I am using Astro Vim because its cool and forcing me to get better at Vim.  
 I am using C++ because after writing a ton of embedded C, I should probably get better at some OOP.
