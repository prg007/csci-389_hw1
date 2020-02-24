# csci-389_hw1
## PRASUN 

### Homework files for CSCI 389 HW1

There are 4 files in total. The main program is in the **benchmark.cpp** file. My main strategy for beating the prefetcher was to use a hash function. The hash function works in a manner that prevents the compiler from prefetching any values. It does so by accessing a random part of the buffer and incrementing its value by 1. The hash function only hashes values upto a certain size depending on the byte length. For each byte length in powers of 2, we perform 20000 iterations and then take the mean across all those iterations. A shell file called **benchmark.sh** has been added. More instructions on how to run the shell function has been provided below. I ran the shell function for 16 trials and then took the minimum value across all those trials for each Buffer size. The code in benchmark.cpp isn't that complicated and you should be able to follow along with the help of comments I have added.  The minimum value tabulated across all those trials have been put in the **bnchmark_minimum.csv** file. Here's the tabulated data below:

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

### PART 3 (Analysis) 

#### a) 

I am trying to infer the different cache sizes by noticing the different step increments that are happening at different times in my graph. As you can notice from the graph above, the first step increment appears to happen around 2<sup>7</sup> and lasts until 2<sup>9</sup>. This makes me guess that my **L1** cache size is around **128 KB** and my **L2** cache size is around **512KB**. Another step increase occurs from 2<sup>10</sup> to 2<sup>13</sup>. So, I think my **L3** cache is around **4-8MB**. After this point from 2<sup>14</sup>, the large step increment might be caused by access to **DRAM**.


#### b)

We see that our access times for L1 and L2 cache are greater than the ones given in the link. Access values for **L1** is 0.5 ns but it took me around 15-16ns. Also, the access values for L2 are supposed to around 7ns but it took me around 25 ns on average.  I think this is because of 2 main reasons.

* I am using a hash function in my code. This hash value is computed inside the while loop. There is definitely going to be some overhead in computing the hash value so this could have added to the latency.(Penalty of 1ns per instruction)
* The purpose of this assignent is to try and foil the prefetcher. I think the hash function is suceeding in doing that. Branch mispredictions(given in the link) add to a tally of 5ns per penalty for L1 and L2, so I guess this could also be a reason. 

Our numbers for main memory are lower than they should be. Notice that the graph which has been computed above takes the minimum run across 16 iterations (essentially the best case across the observed latencies). Also, the prefetcher might be doing a good job for larger buffer sizes in accessing the memory and loads stuff into L1 and L2, so this might also explain the speed increment.

#### c)

The specifications for my system are the following

* L1 - 128KB
* L2 - 512 KB (In the screenshot below it says 256Kb/core and I have 2 cores )
* L3 - 4 MB

I have attached an image below

![Screenshot_System_Specs](https://github.com/prg007/csci-389_hw1/blob/master/Screen%20Shot%202020-02-23%20at%205.35.15%20PM.png)



This more or less falls with my predictions. 





