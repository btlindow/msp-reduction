# MSP-Reduction

I suck at coding. I suck at C++. I suck at using vim. This project is my attempt to get better at the latter two. The first is a lost casue.

## Maximal Subclique Problem
A graph is a construct in discrete mathematics that contains other discrete constructs called vertices and edges. In the movie "Good Will Hunting," Will Hunting draws a discrete graph on the hallway chalkboard in an attempt to solve Professor
 Lambeau's challenge to his students. The circles he was drawing were vertices and the lines connecting those vertices together were edges. 

 The Maximal Subclique Problem (MSP) is a problem focused in Computer Science that aims to find a maximal, complete subgraph of the input graph. Let's break that down. A complete graph is a graph where every vertex in that graph has an edge connecting them to every other node in the graph. A subgraph is just a smaller collection, or subset, of the vertices and edges of the main graph. A maximal, complete subgraph is the largest subgraph that is also complete.  

 It may help to think of graphs in a more concrete way. Consider a body of students consisting of different groups, cliques, of friends. Think of each individual in the student body as a vertex and their various friendships as edges to other students. What you are left with is this giant graph of vertices and edges that define the relationships within that student body. The goal of the MSP is to find the largest group of friends inside that student body.

 ## Reduction Technique
 After many hours of shower thoughts thinking about how to find a polynomial solution to this problem, I (re)discovered a way to reduce the size of the problem for a given "k" sized subclique. I will probably come back and write more about this later. I can't take all of the credit for this soultion because I was researching it after-the-fact and found a paper mentioning it in the 1980's. But I figured it would be cool to implement it in ole' fashion C++.

 ## Tools
 I am using CMake because whats easier than having a machine write your Makefile for you.  
 I am using Astro Vim because its cool and forcing me to get better at Vim.  
 I am using C++ because after writing a ton of embedded C, I should probably get better at some OOP.
