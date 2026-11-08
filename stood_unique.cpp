#include <gtest/gtest.h>

namespace
{
    void removeDuplicates(std::vector<int> &nums)
    {
        if (nums.empty())
            return;

        auto currentUnique = nums.begin();

        for (auto current = nums.begin() + 1; current != nums.end(); ++current)
        {
            if (*current != *currentUnique)
            {
                ++currentUnique;
                *currentUnique = *current;
            }
        }

        nums.erase(currentUnique + 1, nums.end());
    }
}

TEST(StoodUnique, trivial)
{
    std::vector test = {1, 1, 2, 2, 2, 3, 4, 4};
    const std::vector expected = {1, 2, 3, 4};
    removeDuplicates(test);
    EXPECT_TRUE(std::equal(test.begin(), test.end(), expected.begin(), expected.end()));
}

TEST(StoodUnique, empty)
{
    std::vector<int> test = {};
    const std::vector<int> expected = {};
    removeDuplicates(test);
    EXPECT_TRUE(std::equal(test.begin(), test.end(), expected.begin(), expected.end()));
}

TEST(StoodUnique, alreadyUnique)
{
    std::vector<int> test = {1, 2, 3, 4, 5};
    const std::vector<int> expected = {1, 2, 3, 4, 5};
    removeDuplicates(test);
    EXPECT_TRUE(std::equal(test.begin(), test.end(), expected.begin(), expected.end()));
}
