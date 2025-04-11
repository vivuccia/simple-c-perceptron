
Simple Perceptron v1.0.0

Basic perceptron program in C. Core idea taken from Python tutorial at https://realpython.com/python-ai-neural-network/. First prototype of program was essentially a copy of this tutorial, rewritten in C. Has diverged more significantly later on, but core logic was learnt from here.
Added functionality for setting a list of input vectors and setting the target + learnrate yourself.

CORRECT SYNTAX:

for settings.ini:
	target = (double)
	learnrate = (double)
	max_iterations = (integer)

for vectors.conf
	[x1 y1] [x2 y2] [x3 y3] ... [xn yn]

Using incorrect syntax WILL break the program. Error handling is very rudimentary at best. Example inputs have already been provided with the correct syntax. 

This is the first properly functional version. My drafts, and any prior versions, with their syntax errors, typos, and other failures, are in the "history" branch. May it serve as documentation of my working process.

Makefile uses GCC, and program has been tested on Linux. Other compilers and environments have not been tested. 

Contributions, issues, and feedback are always welcome. 
