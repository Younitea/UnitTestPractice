/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, no_repeat)
{
  Password my_password;
  int actual = my_password.count_leading_characters("ZzlLNnAa");
  ASSERT_EQ(1,actual);
}

TEST(PasswordTest, repeat_three_times)
{
  Password my_password;
  int actual = my_password.count_leading_characters("ZZZ");
  ASSERT_EQ(3, actual);
}

TEST(PasswordTest, no_letter_password)
{
  Password my_password;
  int actual = my_password.count_leading_characters("");
  ASSERT_EQ(0,actual);
}

TEST(PasswordTest, long_repeat_space)
{
  Password my_password;
  int actual = my_password.count_leading_characters("                         ");
  ASSERT_EQ(25,actual);
}

TEST(PasswordTest, odd_input)
{
  Password my_password;
  int actual = my_password.count_leading_characters("\n\n\r \"");
  ASSERT_EQ(2,actual);
}

TEST(PasswordTest, upper_lower_no_input)
{
  Password my_password;
  bool actual = my_password.has_mixed_case("");
  ASSERT_FALSE(actual);
}

TEST(PasswordTest, upper_lower_good_input)
{
  Password my_password;
  bool actual = my_password.has_mixed_case("aaaBBB");
  ASSERT_TRUE(actual);
}

TEST(PasswordTest, only_lower)
{
  Password my_password;
  bool actual = my_password.has_mixed_case("aaaaaa");
  ASSERT_FALSE(actual);
}

TEST(PasswordTest, only_upper)
{
  Password my_password;
  bool actual = my_password.has_mixed_case("BBBBACAWFE");
  ASSERT_FALSE(actual);
}

TEST(PasswordTest, up_low_numbers)
{
  Password my_password;
  bool actual = my_password.has_mixed_case("10393r910391039");
  ASSERT_FALSE(actual);
}

TEST(PasswordTest, up_low_true_odd_chars)
{
  Password my_password;
  bool actual = my_password.has_mixed_case("Cc921309u4\n\\$#@#!# p[][{]");
  ASSERT_TRUE(actual);
}

TEST(PasswordTest, one_lower)
{
  Password my_password;
  bool actual = my_password.has_mixed_case("l");
  ASSERT_FALSE(actual);
}

TEST(PasswordTest, one_upper)
{
  Password my_password;
  bool actual = my_password.has_mixed_case("M");
  ASSERT_FALSE(actual);
}

TEST(PasswordTest, last_char_upper)
{
  Password my_password;
  bool actual = my_password.has_mixed_case("aaaaaaaaaaaB");
<<<<<<< HEAD
  ASSERT_TRUE(actual);
=======
  Assert_TRUE(actual);
>>>>>>> 9af1143a1d18ebbb17008c9f5fff2adae2969155
}

TEST(PasswordTest, first_char_upper)
{  
  Password my_password;
  bool actual = my_password.has_mixed_case("Baaaaaaaa");
  ASSERT_TRUE(actual);
}
