#include <gtest/gtest.h>

namespace
{
    int stringToInt(const char *str)
    {
        if (str == nullptr)
            return 0;

        if (*str == '\n')
            return 0;

        bool negative = false;
        auto current = 0;
        if (str[current] == '-')
        {
            negative = true;
            ++current;
        }

        int result = 0;
        while (str[current] != '\0')
        {
            const char digit = str[current];

            if (digit < '0' || digit > '9')
                return 0;


            result = result * 10 + (digit - '0');
            ++current;
        }

        return negative ? -result : result;
    }
}

TEST(StringToNumberTests, test)
{
    EXPECT_EQ(stringToInt("1000"), 1000);
    EXPECT_EQ(stringToInt("1000 "), 0);
    EXPECT_EQ(stringToInt("0"), 0);
    EXPECT_EQ(stringToInt(""), 0);
    EXPECT_EQ(stringToInt("  1"), 0);
    EXPECT_EQ(stringToInt("  1000"), 0);
    EXPECT_EQ(stringToInt("123"), 123);
    EXPECT_EQ(stringToInt("-123"), -123);
}
