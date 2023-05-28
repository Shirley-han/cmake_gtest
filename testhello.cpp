#include "gtest/gtest.h"
#include "hello.h"
#include <iostream>
using namespace std;
class helloa : public ::testing::Test
{
public:
  helloa(){}
  ~helloa(){}
  void SetUp() override
  {  
    cout << "==========================SetUp" << endl;
  }

  void TearDown() override
  {  
    cout << "==========================TearDown" << endl;
  }

  static void SetUpTestSuite() {
    std::cout << "=====================SetUpTestSuite" << std::endl;
  }
  static void TearDownTestSuite() {
    std::cout << "=====================TearDownTestSuite" << std::endl;
  }
};

TEST_F(helloa, ret1) {
  EXPECT_EQ(1, hello());
  EXPECT_EQ(1, hello());
}

TEST_F(helloa, ret2) {
  EXPECT_EQ(1, hello());
}

TEST(add, ret) {
  EXPECT_EQ(10, add(4, 6));
}
TEST(add, ret2) {
  EXPECT_EQ(10, add(4, 6));
}
TEST(add, ret1) {
  EXPECT_EQ(10, add(5, 5));
}

TEST(string, s1) {
  EXPECT_STREQ("10", "10");
}
TEST(string, s2) {
  EXPECT_STRNE("10", "0");
}

TEST(string, s3) {
  EXPECT_STRCASEEQ("abc", "ABC");
  EXPECT_STRCASENE("abcz", "ABC");
  // EXPECT_STREQ("abc", "ABC");
  EXPECT_STRNE("abc", "ABC");
}

// int main(int argc, char **argv) {
//   printf("Running main() from %s\n", __FILE__);
//   testing::InitGoogleTest(&argc, argv);
//   return RUN_ALL_TESTS();
// }
