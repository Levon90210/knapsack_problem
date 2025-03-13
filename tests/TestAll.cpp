#include "UnboundedKnapsackTests.h"
#include "BoundedKnapsackTests.h"
#include "ZeroOneKnapsackTests.h"

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}