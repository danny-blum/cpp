
#include <stdint.h>
#include <array>
#include "gtest/gtest.h"

typedef uint16_t WID;

class WidManager {
public:
  bool getID(WID &widOut);
  bool releaseID(WID widIn);
  WidManager() : top_(0) {};
private:
  WID top_;
  std::set<WID> relSet_;
};

bool WidManager::getID(WID &widOut) {
  WID ret;
  std::set<WID>::iterator it = relSet_.begin();
  
  if (it != relSet_.end()) {
    ret = *it;
    relSet_.erase(ret);
  }
  else {
    if (top_ == UINT16_MAX)
      return false;
    else
      ret = top_++;
  }

  widOut = ret;
  return true;
}

bool WidManager::releaseID(WID widIn) {
  if (widIn >= top_)
    return false;

  if (relSet_.find(widIn) != relSet_.end())
    return false;
  
  relSet_.insert(widIn);

  return true;
}

class WidManagerBV {
public:
  static constexpr int num_entries = ((1<<16) / 64);
  bool getID(WID &widOut);
  bool releaseID(WID widIn);
  WidManagerBV() : bv_{0} {};
private:
  uint64_t bv_[num_entries];
};


bool WidManagerBV::getID(WID &widOut) {
  int idx=0;

  while (bv_[idx]==0xffffffffffffffff) {
    if (idx == num_entries-1)
      return false;
    idx++;
  }

  uint64_t entry = bv_[idx];
  for (int i=0; i<64; ++i) {
    if ((entry & 0x1) == 0) {
      widOut = idx*64 + i;
      bv_[idx] |= (1<<i);
      break;
    }

    entry >>= 1;
  }

  return true;
}

bool WidManagerBV::releaseID(WID widIn) {
  int idx = widIn / 64;
  int i = widIn % 64;

  uint64_t entry = bv_[idx];
  if ((entry & (1<<i)) == 0)
    return false;

  bv_[idx] &= ~(1<<i);

  return true;
}

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


TEST(WidManagerTests, WMTest1) {
  WidManager wm;
  WID wid;
  bool bret;
  std::array<int, 20> rel_ids = {1,3,6,7,23,27,34,38,44,48,52,57,61,68,70,75,88,92,93,99};

  for (int i=0; i<=100; ++i) {
    bret = wm.getID(wid);
    EXPECT_EQ(true, bret);
    EXPECT_EQ(i, wid);
  }
  for (int i=0; i<rel_ids.size(); ++i) {
    bret = wm.releaseID(rel_ids[i]);
    EXPECT_EQ(true, bret);
  }
  for (int i=0; i<rel_ids.size(); ++i) {
    bret = wm.getID(wid);
    EXPECT_EQ(true, bret);
    EXPECT_EQ(rel_ids[i], wid);
  }
  bret = wm.getID(wid);
  EXPECT_EQ(true, bret);
  EXPECT_EQ(101, wid);
}

