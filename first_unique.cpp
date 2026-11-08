#include <gtest/gtest.h>

namespace
{
    char firstUnique(const std::string& str)
    {
        if (str.empty())
            return 0;

        std::map<char, unsigned> unique;
        std::set<char> nonUnique;

        for (unsigned i = 0; i < str.size(); ++i)
        {
            const auto itUnique = unique.find(str[i]);
            if (unique.end() == itUnique)
            {
                if (!nonUnique.contains(str[i]))
                    unique.emplace(str[i], i);
            }
            else
            {
                unique.erase(itUnique);
                nonUnique.emplace(str[i]);
            }
        }

        if (unique.empty())
            return 0;

        const auto firstUnique = std::min_element(unique.begin(), unique.end(), [] (const auto& lhs, const auto& rhs) {return lhs.second < rhs.second; });
        return firstUnique->first;
    }
}

TEST(FirstUnique, trivial)
{
    EXPECT_EQ(firstUnique(""), 0);
    EXPECT_EQ(firstUnique("aabbcc"), 0);
    EXPECT_EQ(firstUnique("aabcc"), 'b');
    EXPECT_EQ(firstUnique("programming"), 'p');
    EXPECT_EQ(firstUnique("aabbccdee"), 'd');
    EXPECT_EQ(firstUnique("abcdabd"), 'c');
    EXPECT_EQ(firstUnique("abcdcdcdb"), 'a');
}