// Copyright 2020 by FORTYSS

#ifndef INCLUDE_CACHER_HPP_
#define INCLUDE_CACHER_HPP_

#include <chrono>
#include <iostream>
#include <utility>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <ctime>
#include <math.h>

using std::cout;
using std::string;

static const size_t sets = 16;
static const int expcol =1000;
std::vector<uint> Genarr();
auto progrev(uint64_t size);
std::vector<double> pryam(const std::vector<uint>& buf);
std::vector<double> back(const std::vector<uint>& buf);
std::vector<double> rand(const std::vector<uint>& buf);
void Out(const std::vector<uint>& buf);

#endif // INCLUDE_CACHER_HPP_
