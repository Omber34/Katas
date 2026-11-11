#include <gtest/gtest.h>

namespace
{
    class SampleTest : public ::testing::Test
    {
    public:
        static void SetUpTestSuite()
        {

        }
        static void TearDownTestSuite()
        {

        }

    protected:
        void SetUp() override
        {

        }
        void TearDown() override
        {

        }
    };
}

TEST_F(SampleTest, test)
{

}

TEST(SampleTest, trivial)
{

}