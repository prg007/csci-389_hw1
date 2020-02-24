# csci-389_hw1
## PRASUN 

### Homework files for CSCI 389 HW1

There are 4 files in total. The main program is in the **benchmark.cpp** file. My main strategy for beating the prefetcher was to use a hash function. The hash function works in a manner that prevents the compiler from prefetching any values. It does so by accessing a random part of the buffer and incrementing its value by 1. The hash function only hashes values upto a certain size depending on the byte length. For each byte length in powers of 2, we perform 20000 iterations and then take the mean across all those iterations. A shell file called **benchmark.sh** has been added. More instructions on how to run the shell function has been provided below. I ran the shell function for 16 trials and then took the minimum value across all those trials for each Buffer size. The minimum value tabulated across all those trials have been put in the **bnchmark_minimum.csv** file. Here's the tabulated data below:

Buffer Size | NanoSecons (Minimum Mean Time Across 16 runs of benchmark.sh)
------------|-------------------------------------------------------------
1 | 15.7971
2 | 15.8022
3 | 16.2768
4 | 16.2831
5 | 16.2858
6 | 16.2917
7 | 17.2986
8 | 22.3465 
9 | 26.3044
10 | 27.1835
11 | 34.0345
12 | 41.0302
13 | 48.1885
14 | 49.2076
15 | 61.9139
16 | 75.847
17 | 88.8333
18 | 101.9648
19 | 117.8102
20 | 137.5671

Here's the graph for the data above
![Graph for Minimum Access Time](https://github.com/prg007/csci-389_hw1/blob/master/MinimumAccessTime.png)

Before running the shell file, you need to compile the code. Compile the code using the following:

* ```clang++ -O3 -Wall -Werror -Wextra  -std=c++17 benchmark.cpp -o a```
* ```./a (size) (iters)``` or you can run the shell file below

Here's the code for running the shell file **benchmark.sh**. This applies only to Macs

* Go to the folder, open terminal 
* ```chmod +x benchmark.sh```
* ```./benchmark.sh```


 



