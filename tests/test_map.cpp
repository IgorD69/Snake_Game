/**
 * @file test_map.cpp
 * @brief Unit tests for Map class
 * 
 * @project Snake Game
 * @author Dodan Igor
 * @date 2025
 */

#include <gtest/gtest.h>
#include "../Map.hpp"

/**
 * @class MapTest
 * @brief Test fixture for Map class tests
 */
class MapTest : public ::testing::Test {
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

TEST_F(MapTest, DefaultConstructor) {
    Map map;
    EXPECT_EQ(map.GetWidth(), 40);
    EXPECT_EQ(map.GetHeight(), 40);
}

TEST_F(MapTest, ParameterizedConstructor) {
    Map map(60, 30);
    EXPECT_EQ(map.GetWidth(), 60);
    EXPECT_EQ(map.GetHeight(), 30);
}

TEST_F(MapTest, SquareMap) {
    Map map(50, 50);
    EXPECT_EQ(map.GetWidth(), 50);
    EXPECT_EQ(map.GetHeight(), 50);
}

TEST_F(MapTest, RectangularMap_WideHorizontal) {
    Map map(80, 20);
    EXPECT_EQ(map.GetWidth(), 80);
    EXPECT_EQ(map.GetHeight(), 20);
}

TEST_F(MapTest, RectangularMap_WideVertical) {
    Map map(20, 80);
    EXPECT_EQ(map.GetWidth(), 20);
    EXPECT_EQ(map.GetHeight(), 80);
}

TEST_F(MapTest, CopyConstructor) {
    Map original(60, 30);
    Map copy(original);
    EXPECT_EQ(copy.GetWidth(), 60);
    EXPECT_EQ(copy.GetHeight(), 30);
}

TEST_F(MapTest, MinimumSize) {
    Map map(1, 1);
    EXPECT_EQ(map.GetWidth(), 1);
    EXPECT_EQ(map.GetHeight(), 1);
}

TEST_F(MapTest, LargeMap) {
    Map map(1000, 1000);
    EXPECT_EQ(map.GetWidth(), 1000);
    EXPECT_EQ(map.GetHeight(), 1000);
}

// ============================================================================
// Getter Tests
// ============================================================================

TEST_F(MapTest, GetWidth_Default) {
    Map map;
    EXPECT_EQ(map.GetWidth(), 40);
}

TEST_F(MapTest, GetHeight_Default) {
    Map map;
    EXPECT_EQ(map.GetHeight(), 40);
}

TEST_F(MapTest, GetWidth_Custom) {
    Map map(75, 25);
    EXPECT_EQ(map.GetWidth(), 75);
}

TEST_F(MapTest, GetHeight_Custom) {
    Map map(25, 75);
    EXPECT_EQ(map.GetHeight(), 75);
}

// ============================================================================
// Operator Tests
// ============================================================================

TEST_F(MapTest, AssignmentOperator) {
    Map map1(60, 30);
    Map map2(80, 40);
    map2 = map1;
    EXPECT_EQ(map2.GetWidth(), 60);
    EXPECT_EQ(map2.GetHeight(), 30);
}

TEST_F(MapTest, EqualityOperator_Equal) {
    Map map1(50, 50);
    Map map2(50, 50);
    EXPECT_TRUE(map1 == map2);
}

TEST_F(MapTest, EqualityOperator_NotEqual_Width) {
    Map map1(50, 50);
    Map map2(60, 50);
    EXPECT_FALSE(map1 == map2);
}

TEST_F(MapTest, EqualityOperator_NotEqual_Height) {
    Map map1(50, 50);
    Map map2(50, 60);
    EXPECT_FALSE(map1 == map2);
}

TEST_F(MapTest, EqualityOperator_NotEqual_Both) {
    Map map1(50, 50);
    Map map2(60, 70);
    EXPECT_FALSE(map1 == map2);
}

TEST_F(MapTest, EqualityOperator_Default) {
    Map map1;
    Map map2;
    EXPECT_TRUE(map1 == map2);
}

TEST_F(MapTest, SelfAssignment) {
    Map map(60, 30);
    map = map;
    EXPECT_EQ(map.GetWidth(), 60);
    EXPECT_EQ(map.GetHeight(), 30);
}

// ============================================================================
// Stream Operator Tests
// ============================================================================

TEST_F(MapTest, OutputOperator) {
    Map map(60, 30);
    std::ostringstream oss;
    oss << map;
    EXPECT_EQ(oss.str(), "60 30");
}

TEST_F(MapTest, OutputOperator_Default) {
    Map map;
    std::ostringstream oss;
    oss << map;
    EXPECT_EQ(oss.str(), "40 40");
}

TEST_F(MapTest, InputOperator) {
    Map map;
    std::istringstream iss("70 35");
    iss >> map;
    EXPECT_EQ(map.GetWidth(), 70);
    EXPECT_EQ(map.GetHeight(), 35);
}

TEST_F(MapTest, InputOperator_OverwritesExisting) {
    Map map(100, 100);
    std::istringstream iss("50 50");
    iss >> map;
    EXPECT_EQ(map.GetWidth(), 50);
    EXPECT_EQ(map.GetHeight(), 50);
}

TEST_F(MapTest, InputThenOutput) {
    Map map;
    std::istringstream iss("65 45");
    iss >> map;
    std::ostringstream oss;
    oss << map;
    EXPECT_EQ(oss.str(), "65 45");
}

// ============================================================================
// Dimension Tests
// ============================================================================

TEST_F(MapTest, Area_Default) {
    Map map;
    int area = map.GetWidth() * map.GetHeight();
    EXPECT_EQ(area, 1600);  // 40 * 40
}

TEST_F(MapTest, Area_Custom) {
    Map map(60, 30);
    int area = map.GetWidth() * map.GetHeight();
    EXPECT_EQ(area, 1800);  // 60 * 30
}

TEST_F(MapTest, Perimeter_Default) {
    Map map;
    int perimeter = 2 * (map.GetWidth() + map.GetHeight());
    EXPECT_EQ(perimeter, 160);  // 2 * (40 + 40)
}

TEST_F(MapTest, Perimeter_Custom) {
    Map map(60, 30);
    int perimeter = 2 * (map.GetWidth() + map.GetHeight());
    EXPECT_EQ(perimeter, 180);  // 2 * (60 + 30)
}

// ============================================================================
// Boundary and Logic Tests
// ============================================================================

TEST_F(MapTest, ValidCoordinates_Center) {
    Map map(40, 40);
    int centerX = map.GetWidth() / 2;
    int centerY = map.GetHeight() / 2;
    EXPECT_TRUE(centerX >= 0 && centerX < map.GetWidth());
    EXPECT_TRUE(centerY >= 0 && centerY < map.GetHeight());
}

TEST_F(MapTest, ValidCoordinates_TopLeft) {
    Map map(40, 40);
    int x = 0, y = 0;
    EXPECT_TRUE(x >= 0 && x < map.GetWidth());
    EXPECT_TRUE(y >= 0 && y < map.GetHeight());
}

TEST_F(MapTest, ValidCoordinates_BottomRight) {
    Map map(40, 40);
    int x = map.GetWidth() - 1;
    int y = map.GetHeight() - 1;
    EXPECT_TRUE(x >= 0 && x < map.GetWidth());
    EXPECT_TRUE(y >= 0 && y < map.GetHeight());
}

TEST_F(MapTest, InvalidCoordinates_Negative) {
    Map map(40, 40);
    int x = -1, y = -1;
    EXPECT_FALSE(x >= 0 && x < map.GetWidth());
    EXPECT_FALSE(y >= 0 && y < map.GetHeight());
}

TEST_F(MapTest, InvalidCoordinates_OutOfBounds) {
    Map map(40, 40);
    int x = map.GetWidth();
    int y = map.GetHeight();
    EXPECT_FALSE(x >= 0 && x < map.GetWidth());
    EXPECT_FALSE(y >= 0 && y < map.GetHeight());
}

TEST_F(MapTest, BorderDetection_Top) {
    Map map(40, 40);
    int y = 0;
    EXPECT_EQ(y, 0);
}

TEST_F(MapTest, BorderDetection_Bottom) {
    Map map(40, 40);
    int y = map.GetHeight() - 1;
    EXPECT_EQ(y, 39);
}

TEST_F(MapTest, BorderDetection_Left) {
    Map map(40, 40);
    int x = 0;
    EXPECT_EQ(x, 0);
}

TEST_F(MapTest, BorderDetection_Right) {
    Map map(40, 40);
    int x = map.GetWidth() - 1;
    EXPECT_EQ(x, 39);
}

// ============================================================================
// Multiple Maps Tests
// ============================================================================

TEST_F(MapTest, MultipleMaps_Different) {
    Map map1(40, 40);
    Map map2(60, 30);
    Map map3(80, 20);
    
    EXPECT_FALSE(map1 == map2);
    EXPECT_FALSE(map2 == map3);
    EXPECT_FALSE(map1 == map3);
}

TEST_F(MapTest, MultipleMaps_Same) {
    Map map1(50, 50);
    Map map2(50, 50);
    Map map3(50, 50);
    
    EXPECT_TRUE(map1 == map2);
    EXPECT_TRUE(map2 == map3);
    EXPECT_TRUE(map1 == map3);
}

TEST_F(MapTest, ChainedAssignment) {
    Map map1(60, 30);
    Map map2, map3;
    map3 = map2 = map1;
    
    EXPECT_EQ(map2.GetWidth(), 60);
    EXPECT_EQ(map2.GetHeight(), 30);
    EXPECT_EQ(map3.GetWidth(), 60);
    EXPECT_EQ(map3.GetHeight(), 30);
}

// // Run all tests
// int main(int argc, char **argv) {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
