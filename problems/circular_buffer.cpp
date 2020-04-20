#include <stdint.h>
#include <array>
#include "gtest/gtest.h"
#include <algorithm>

template <std::size_t N>
class CircularBuffer {
public:
  CircularBuffer() : size_(N), start_(0), len_(0) {
  }

  template <class Iter>
  int read(int len, Iter it_out) {
    int read_len = std::min(len, len_);
  
    int first_len = std::min(read_len, size_ - start_);
    std::copy_n(buf_.begin()+start_, first_len, it_out);
    
    std::copy_n(buf_.begin(), read_len-first_len, it_out+first_len);
    start_ = (start_ + read_len) % size_;
    len_ -= read_len;
  
    return read_len;
  }
  
  template <class Iter>
  int write(int len, Iter it_in) {
    int write_len = std::min(len, size_ - len_);
  
    int end = (start_ + len_) % size_;
    int first_len = std::min(write_len, size_ - end); 
    std::copy_n(it_in, first_len, buf_.begin()+end);
  
    std::copy_n(it_in+first_len, write_len-first_len, buf_.begin());
    len_ += write_len;
    
    return write_len;
  }

private:
  int size_;
  int start_;
  int len_;
  std::array<uint8_t, N> buf_; 
};

int main(int argc, char* argv[])
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(CircularBufferTests, CBTest1) { 
  int ret;
  CircularBuffer<20> cb;
  std::array<uint8_t, 20> buf_in = {1,3,6,7,23,27,34,38,44,48,52,57,61,68,70,75,88,92,93,99};
  std::array<uint8_t, 20> buf_golden = {7,23,27,34,38,44,48,52,57,61,68,70,75,88,92,93,99,1,3,6};
  std::array<uint8_t, 20> buf_out = {};

  ret = cb.write(5, buf_in.begin());
  std::cout << "write returns " << ret << std::endl;
  ret = cb.read(3, buf_out.begin());
  std::cout << "read returns " << ret << std::endl;

  for(const auto& c: buf_out)
    std::cout << (uint32_t)c << ' ';
  std::cout << std::endl;

  cb.write(15, buf_in.begin()+5);
  cb.write(3, buf_in.begin());
  cb.read(20, buf_out.begin());
  
  for(const auto& c: buf_out)
  std::cout << (uint32_t)c << ' ';
  std::cout << std::endl;

  EXPECT_EQ(buf_out, buf_golden);
}
