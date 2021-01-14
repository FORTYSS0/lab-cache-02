// Copyright 2020 by FORTYSS

#include <cacher.hpp>
auto genarr(uint64_t size){
  auto arr= new long double [size];

  for (size_t i = 0; i < size; i+=sets) {
    arr[i] = random();
  }
  return arr;
}
double pryam(size_t size) {
  auto arr = genarr(size);
  long double sum = 0;
  for (size_t i = 0; i < size; i += sets) {
    sum += arr[i];
  }
  sum = 0;
  auto time1 = std::chrono::high_resolution_clock::now();
  for(size_t i = 0; i < size*expcol; i+=sets) {
    sum += arr[i%size];
  }
  auto time2 = std::chrono::high_resolution_clock::now();
  return static_cast<double>((std::chrono::nanoseconds(time2-time1).count())
                             /expcol);
}
double back(size_t size) {
  auto arr = genarr(size);
  long double sum = 0;
  for (size_t i = 0; i < size; i += sets) {
    sum += arr[i];
  }
  sum = 0;
  auto time1 = std::chrono::high_resolution_clock::now();
  for(size_t i = size*expcol; i > 0 ; i-=sets) {
    sum += arr[i%size];
  }
  auto time2 = std::chrono::high_resolution_clock::now();
  return static_cast<double>((std::chrono::nanoseconds(time2-time1).count())
                             /expcol);
}
double rand(size_t size) {
  auto arr = genarr(size);
  long double sum = 0;
  std::vector<size_t> x(size);
  for (size_t i = 0; i < size; i += sets) {
    sum += arr[i];
    x[i] = i;
  }
  sum = 0;
  srand(unsigned(time(0)));
  random_shuffle(x.begin(), x.end());
  auto time1 = std::chrono::high_resolution_clock::now();
  for(size_t i = 0; i < size*expcol; i+=sets) {
    sum += arr [x[i%size]];
  }
  auto time2 = std::chrono::high_resolution_clock::now();
  return static_cast<double>((std::chrono::nanoseconds(time2-time1).count())
                             /expcol);
}
Experement::Experement(Type typ, const size_t &size) {
  size_t s =
}