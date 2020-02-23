#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>
#include <chrono>
#include <numeric>
#include <math.h>

using namespace std;
using data_t = int;
std::random_device rd;
std::mt19937 gp(rd());
default_random_engine dre(rd());
uniform_int_distribution<int> uid(1,99999);
uniform_int_distribution<int> uniform_value(1, 150);

data_t* generate_random_list(int size) //Create a dynimically allocated memory and return
{

  int *buffer = new int[size];
  generate(buffer, buffer + sizeof(buffer) / sizeof(int), [&] () { return uid(dre); }); //fill up the array with random values

  return buffer;

}


int main(int argc, char *argv[])
{
  if (argc!= 3)
  {
    cout<<"We need 2 arguments, size and number of iterations"<<endl;
  }

  const int size = atoi(argv[1]);
  const int iters = atoi(argv[2]);


  auto sample = generate_random_list(size);         // Get a random list filled with numbers
  int hashed,r1;                                    // Our strategy is to use a unique hash function everytime to foil the prefetcher.


  std::uniform_real_distribution<data_t> uniform_dist2(1, 50);
  std::default_random_engine e2(size);

  auto t1 = std::chrono::high_resolution_clock::now();

  for (int i=0; i < iters; i++)                      //Number of iterations, usually set to 10000
  {
    hashed = ((i*i)%(size+i) + i)%(size-1);          //Access the hashed value randomly upto the desired memory length and
		sample[hashed] = sample[hashed]+1;               //increment its value by 1
  }
  auto t2 = std::chrono::high_resolution_clock::now();

  double duration = (std::chrono::duration_cast<std::chrono::nanoseconds>( t2 - t1 ).count());

  double mean_time = (duration)/(iters);             //Calculate the mean time across all iterations.
	cout<<size<<","<<mean_time<<endl;

  delete[] sample;                                   //Free up the memory

  return 0;
}
