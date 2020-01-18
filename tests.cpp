#include "gtest/gtest.h"
#include "lib.h"
#include <iostream>

std::ifstream file ("../f.txt");
int a[SIZE][SIZE]={0};
std::string ver[SIZE]={" "};
std::string start,final;

TEST(minumumway,way){
 read_file (file, a, ver);
 start="vladivostok";
 final="shanghai";
 EXPECT_EQ(minway(a,start,final,ver),9);

  start="vladivostok";
  final="hanoi";
  EXPECT_EQ(minway(a,start,final,ver),0);

  start="moscow";
  final="beijing";
  EXPECT_EQ(minway(a,start,final,ver),34);

  start="moscow";
  final="spassk";
  EXPECT_EQ(minway(a,start,final,ver),-1);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}