#include "ringbuffer.h"
#include <gtest/gtest.h>

TEST(RingBufferTests, RingBufferInitalizesDefaultArg) {
  RingBuffer *a = new RingBuffer();
  ASSERT_EQ(a->GetMaxCapacity(), 1);
};

TEST(RingBufferTests, RingBufferInitalizesExplicit) {
  RingBuffer *b = new RingBuffer(10);
  ASSERT_EQ(b->GetMaxCapacity(), 10);
};

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
