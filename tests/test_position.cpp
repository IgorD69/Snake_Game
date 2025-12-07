/**
 * @file test_position.cpp
 * @brief Unit tests for Position class
 * 
 * @project Snake Game
 * @author Dodan Igor
 * @date 2025
 */

#include <gtest/gtest.h>
#include "../Position.hpp"

/**
 * @class PositionTest
 * @brief Test fixture for Position class tests
 */
class PositionTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed
    }

    void TearDown() override {
        // Cleanup code if needed
    }
};

// ============================================================================
// Constructor Tests
// ============================================================================

TEST_F(PositionTest, DefaultConstructor) {
    Position pos;
    EXPECT_EQ(pos.x, 0);
    EXPECT_EQ(pos.y, 0);
}

TEST_F(PositionTest, ParameterizedConstructor) {
    Position pos(10, 20);
    EXPECT_EQ(pos.x, 10);
    EXPECT_EQ(pos.y, 20);
}

TEST_F(PositionTest, NegativeCoordinates) {
    Position pos(-5, -10);
    EXPECT_EQ(pos.x, -5);
    EXPECT_EQ(pos.y, -10);
}

TEST_F(PositionTest, MixedCoordinates) {
    Position pos(-5, 10);
    EXPECT_EQ(pos.x, -5);
    EXPECT_EQ(pos.y, 10);
}

TEST_F(PositionTest, CopyConstructor) {
    Position original(15, 25);
    Position copy(original);
    EXPECT_EQ(copy.x, 15);
    EXPECT_EQ(copy.y, 25);
}

// ============================================================================
// Operator Tests
// ============================================================================

TEST_F(PositionTest, AssignmentOperator) {
    Position pos1(10, 20);
    Position pos2(5, 15);
    pos2 = pos1;
    EXPECT_EQ(pos2.x, 10);
    EXPECT_EQ(pos2.y, 20);
}

TEST_F(PositionTest, EqualityOperator_Equal) {
    Position pos1(10, 20);
    Position pos2(10, 20);
    EXPECT_TRUE(pos1 == pos2);
}

TEST_F(PositionTest, EqualityOperator_NotEqual_X) {
    Position pos1(10, 20);
    Position pos2(15, 20);
    EXPECT_FALSE(pos1 == pos2);
}

TEST_F(PositionTest, EqualityOperator_NotEqual_Y) {
    Position pos1(10, 20);
    Position pos2(10, 25);
    EXPECT_FALSE(pos1 == pos2);
}

TEST_F(PositionTest, EqualityOperator_NotEqual_Both) {
    Position pos1(10, 20);
    Position pos2(15, 25);
    EXPECT_FALSE(pos1 == pos2);
}

TEST_F(PositionTest, EqualityOperator_Zero) {
    Position pos1;
    Position pos2(0, 0);
    EXPECT_TRUE(pos1 == pos2);
}

TEST_F(PositionTest, EqualityOperator_Negative) {
    Position pos1(-10, -20);
    Position pos2(-10, -20);
    EXPECT_TRUE(pos1 == pos2);
}

// ============================================================================
// Stream Operator Tests
// ============================================================================

TEST_F(PositionTest, OutputOperator) {
    Position pos(10, 20);
    std::ostringstream oss;
    oss << pos;
    EXPECT_EQ(oss.str(), "10 20");
}

TEST_F(PositionTest, OutputOperator_Zero) {
    Position pos;
    std::ostringstream oss;
    oss << pos;
    EXPECT_EQ(oss.str(), "0 0");
}

TEST_F(PositionTest, OutputOperator_Negative) {
    Position pos(-5, -10);
    std::ostringstream oss;
    oss << pos;
    EXPECT_EQ(oss.str(), "-5 -10");
}

TEST_F(PositionTest, InputOperator) {
    Position pos;
    std::istringstream iss("15 25");
    iss >> pos;
    EXPECT_EQ(pos.x, 15);
    EXPECT_EQ(pos.y, 25);
}

TEST_F(PositionTest, InputOperator_Negative) {
    Position pos;
    std::istringstream iss("-10 -20");
    iss >> pos;
    EXPECT_EQ(pos.x, -10);
    EXPECT_EQ(pos.y, -20);
}

TEST_F(PositionTest, InputOperator_Zero) {
    Position pos(100, 100);
    std::istringstream iss("0 0");
    iss >> pos;
    EXPECT_EQ(pos.x, 0);
    EXPECT_EQ(pos.y, 0);
}

// ============================================================================
// Edge Cases and Special Tests
// ============================================================================

TEST_F(PositionTest, LargeCoordinates) {
    Position pos(10000, 10000);
    EXPECT_EQ(pos.x, 10000);
    EXPECT_EQ(pos.y, 10000);
}

TEST_F(PositionTest, SelfAssignment) {
    Position pos(10, 20);
    pos = pos;
    EXPECT_EQ(pos.x, 10);
    EXPECT_EQ(pos.y, 20);
}

TEST_F(PositionTest, ChainedAssignment) {
    Position pos1(10, 20);
    Position pos2, pos3;
    pos3 = pos2 = pos1;
    EXPECT_EQ(pos2.x, 10);
    EXPECT_EQ(pos2.y, 20);
    EXPECT_EQ(pos3.x, 10);
    EXPECT_EQ(pos3.y, 20);
}

TEST_F(PositionTest, MultipleComparisons) {
    Position pos1(5, 5);
    Position pos2(5, 5);
    Position pos3(5, 5);
    EXPECT_TRUE(pos1 == pos2);
    EXPECT_TRUE(pos2 == pos3);
    EXPECT_TRUE(pos1 == pos3);
}

// ============================================================================
// Coordinate Modification Tests
// ============================================================================

TEST_F(PositionTest, DirectModification_X) {
    Position pos(10, 20);
    pos.x = 30;
    EXPECT_EQ(pos.x, 30);
    EXPECT_EQ(pos.y, 20);
}

TEST_F(PositionTest, DirectModification_Y) {
    Position pos(10, 20);
    pos.y = 40;
    EXPECT_EQ(pos.x, 10);
    EXPECT_EQ(pos.y, 40);
}

TEST_F(PositionTest, DirectModification_Both) {
    Position pos(10, 20);
    pos.x = 30;
    pos.y = 40;
    EXPECT_EQ(pos.x, 30);
    EXPECT_EQ(pos.y, 40);
}

// ============================================================================
// Boundary Tests
// ============================================================================

TEST_F(PositionTest, ZeroBoundary) {
    Position pos(0, 0);
    EXPECT_EQ(pos.x, 0);
    EXPECT_EQ(pos.y, 0);
}

TEST_F(PositionTest, MapBoundary_TopLeft) {
    Position pos(0, 0);
    EXPECT_TRUE(pos.x >= 0 && pos.y >= 0);
}

TEST_F(PositionTest, MapBoundary_BottomRight) {
    Position pos(39, 39);  // Default map is 40x40
    EXPECT_TRUE(pos.x < 40 && pos.y < 40);
}

TEST_F(PositionTest, OutOfBounds_Negative) {
    Position pos(-1, -1);
    EXPECT_LT(pos.x, 0);
    EXPECT_LT(pos.y, 0);
}

TEST_F(PositionTest, OutOfBounds_Positive) {
    Position pos(40, 40);  // Beyond default 40x40 map
    EXPECT_GE(pos.x, 40);
    EXPECT_GE(pos.y, 40);
}

// // Run all tests
// int main(int argc, char **argv) {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
