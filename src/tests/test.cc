#include <gtest/gtest.h>

#include "cppcalc.h"

TEST(calculate_expressions, test0) {
  ASSERT_EQ(entryPoint("2^3+sin(30)-sqrt(16)", 0, true), 4.5);
}

TEST(calculate_expressions, test1) {
  ASSERT_EQ(entryPoint("2*4*5*(6)", 0, true), 240);
}

TEST(calculate_expressions, test2) {
  ASSERT_NEAR(entryPoint("8*sin(6)", 0, false), -2.23532398559, 1e-6);
}

TEST(calculate_expressions, test3) {
  ASSERT_NEAR(entryPoint("log(16)", 0, true), 1.20411998266, 0.001);
}

TEST(calculate_expressions, test4) {
  ASSERT_EQ(entryPoint("6^5-14*2", 0, true), 7748);
}

TEST(calculate_expressions, test5) {
  ASSERT_EQ(entryPoint("6mod4", 0, true), 2);
}

TEST(calculate_expressions, test6) { ASSERT_EQ(entryPoint("-0", 0, true), 0); }

TEST(calculate_expressions, test8) {
  ASSERT_EQ(entryPoint("-25+6-8", 0, true), -27);
}

TEST(calculate_expressions, test9) {
  ASSERT_EQ(entryPoint("+10+10+5", 0, true), 25);
}

TEST(calculate_expressions, test10) {
  ASSERT_NEAR(entryPoint("15+75*1/3-42+3^3", 0, true), 25, 1e-6);
}

TEST(calculate_expressions, test11) {
  ASSERT_NEAR(entryPoint("asin(0.6)", 0, true), 0.643501109, 1e-6);
}

TEST(calculate_expressions, test12) {
  ASSERT_NEAR(entryPoint("acos(3*0.08)", 0, true), 1.32843048, 0.001);
}

TEST(calculate_expressions, test13) {
  ASSERT_NEAR(entryPoint("atan(-0.4)", 0, false), -0.3805064, 1e-6);
}

TEST(calculate_expressions, test14) {
  ASSERT_NEAR(entryPoint("tan(-6)", 0, false), 0.2910062, 1e-6);
}

TEST(calculate_expressions, test15) {
  ASSERT_NEAR(entryPoint("sqrt(256.5)", 0, true), 16.0156174, 1e-6);
}

TEST(calculate_expressions, test16) {
  ASSERT_NEAR(entryPoint("ln(10)", 0, true), 2.3025851, 1e-6);
}

TEST(calculate_expressions, test17) {
  ASSERT_NEAR(entryPoint("log(125)", 0, true), 2.096910, 1e-6);
}

TEST(calculate_expressions, test18) {
  ASSERT_NEAR(entryPoint("-2*cos(-2-3)", 0, false), -0.567324, 1e-6);
}

TEST(calculate_expressions, test19) {
  ASSERT_EQ(entryPoint("3-(-3)", 0, true), 6);
}

TEST(calculate_expressions, test20) {
  ASSERT_EQ(entryPoint("3-(+3)", 0, true), 0);
}

TEST(calculate_expressions, test21) {
  ASSERT_EQ(static_cast<int>(entryPoint("1+2+3+4*5*6^7", 0, true)), 5598726);
}

TEST(calculate_expressions, test22) {
  ASSERT_NEAR(entryPoint("123.456+2*3^4", 0, true), 285.456, 1e-6);
}

TEST(calculate_expressions, test23) {
  ASSERT_EQ(entryPoint("(8+2*5)/(1+3*2-4)", 0, true), 6);
}

TEST(calculate_expressions, test24) {
  ASSERT_EQ(
      entryPoint(
          "(15/(7-(1+1))*3-(2+(1+1-1+1*2/2))+15/(7-(1+1))*3-(2+(1+1+1-1*2/2)))",
          0, true),
      10);
}

TEST(calculate_expressions, test25) {
  ASSERT_NEAR(entryPoint("cos(1*2)-1", 0, false), -1.41614683655, 1e-6);
}

TEST(calculate_expressions, test26) {
  ASSERT_NEAR(entryPoint("cos(15/(7-(1+1))*3-(2+(1+1-1+1*2/2))+15/"
                         "(7-(1+1))*3-(2+(1+1+1-1*2/2)))-1",
                         0, false),
              -1.83907152908, 1e-6);
}

TEST(calculate_expressions, test27) {
  ASSERT_NEAR(entryPoint("sin(cos(5))", 0, false), 0.27987335076, 1e-6);
}

TEST(calculate_expressions, test28) {
  ASSERT_NEAR(entryPoint("2.33mod1", 0, true), 0.33, 1e-6);
}

TEST(calculate_expressions, test29) {
  ASSERT_EQ(entryPoint("3+4*2/(1-5)^2", 0, true), 3.5);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
