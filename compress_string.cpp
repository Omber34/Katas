#include <gtest/gtest.h>

namespace
{
    std::string CompressString(const std::string &str)
    {
        if (str.empty())
            return "";

        std::string result;
        unsigned streak = 1;
        char current = str[0];

        for (unsigned i = 1; i < str.length(); ++i)
        {
            if (current == str[i])
            {
                ++streak;
            } else
            {
                if (streak > 1)
                {
                    result += std::to_string(streak);
                }
                result += current;
                streak = 1;
                current = str[i];
            }
        }

        if (streak > 1)
        {
            result += std::to_string(streak);
        }
        result += current;

        return result;
    }
}

TEST(CompressStringTest, trivial)
{
    EXPECT_EQ(CompressString(""), "");
    EXPECT_EQ(CompressString("abc"), "abc");
    EXPECT_EQ(CompressString("aabb"), "2a2b");
    EXPECT_EQ(CompressString("aaabbc"), "3a2bc");
}
