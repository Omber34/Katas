#include <unordered_set>
#include <gtest/gtest.h>

namespace
{
    // returns length
    unsigned findLongestUniqueSubstring(const std::string &str)
    {
        if (str.empty())
            return 0;

        std::unordered_set<char> streakSet;
        uint64_t streakPos = 0;
        uint64_t longestStreak = 0;
        for (std::size_t it = 0; it < str.length();)
        {
            const char ch = str[it];
            if (streakSet.contains(ch))
            {
                longestStreak = std::max(longestStreak, streakSet.size());
                streakSet.clear();
                it = str.find(ch, streakPos) + 1;
                streakPos = it;
            } else
            {
                streakSet.insert(ch);
                ++it;
            }
        }
        return std::max(longestStreak, streakSet.size());
    }
}

TEST(SlidingWindow, trivial)
{
    EXPECT_EQ(findLongestUniqueSubstring("abcbde"), 4);
    EXPECT_EQ(findLongestUniqueSubstring("abc"), 3);
    EXPECT_EQ(findLongestUniqueSubstring("abcabcbb"), 3);
    EXPECT_EQ(findLongestUniqueSubstring("bbbbb"), 1);
    EXPECT_EQ(findLongestUniqueSubstring("pwwkew"), 3);
    EXPECT_EQ(findLongestUniqueSubstring("abcdef"), 6);
    EXPECT_EQ(findLongestUniqueSubstring(""), 0);
}
