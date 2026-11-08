#include <gtest/gtest.h>

namespace
{
    char findMostFrequentChar(const std::string &str)
    {
        if (str.empty())
            return '\0';

        std::map<char, unsigned> charFrequency;

        unsigned streak = 1;
        char currentChar = str.front();
        for (int i = 1; i < str.length(); i++)
        {
            const auto ch = str[i];
            if (ch == currentChar)
            {
                streak++;
            } else
            {
                charFrequency[currentChar] = std::max(charFrequency[currentChar], streak);
                streak = 1;
                currentChar = ch;
            }
        }

        charFrequency[currentChar] = std::max(charFrequency[currentChar], streak);

        const auto max = std::max_element(charFrequency.cbegin(), charFrequency.cend(),
            [](const auto &lhs, const auto &rhs) { return lhs.second < rhs.second; });
        if (max != charFrequency.cend())
        {
            return max->first;
        }
        return 0;
    }
}

TEST(FindMostFrequentChar, trivial)
{
    EXPECT_EQ(findMostFrequentChar(""), '\0');
    EXPECT_EQ(findMostFrequentChar("abcd"), 'a');
    EXPECT_EQ(findMostFrequentChar("aabcd"), 'a');
    EXPECT_EQ(findMostFrequentChar("aabccccd"), 'c');
    EXPECT_EQ(findMostFrequentChar("aabbccccdaaaaa"), 'a');
}
