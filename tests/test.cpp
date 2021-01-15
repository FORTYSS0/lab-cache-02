// Copyright 2020 by FORTYSS

#include <gtest/gtest.h>
#include "cacher.hpp"

TEST(Test, Main) {
  std::vector<uint> buf = Genarr();
  Out(buf);
    EXPECT_TRUE(true);
}
