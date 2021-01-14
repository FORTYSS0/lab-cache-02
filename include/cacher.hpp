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

using std::cout;
using std::string;

static const size_t sets = 4;
static const int expcol =1000;
struct Experement{
  enum Type {Strai, Rev, Rand};
  Type type;
  std::vector<double> time;
  explicit  Experement(Type typ, const size_t& size);
  explicit operator string () const;
};

class Cache {
  std::vector<Experement> exp;
  std::vector<double> exp_size;
 public:
  friend std::ostream& operator<< (std::ostream&, const Cache&);

  void out(std::ostream&, Experement) const;
};
#endif // INCLUDE_CACHER_HPP_
