#include "dataMap.hpp"
#include <gtest/gtest.h>

class DataMapTest : public ::testing::Test {
protected:
    fp::env::DataMap dataMap;
};

TEST_F(DataMapTest, Insert) {
    dataMap.insert("var1");
    dataMap.insert("var2");
    
    ASSERT_EQ(dataMap.get("var1"), 0.0f);
    ASSERT_EQ(dataMap.get("var2"), 0.0f);
}

TEST_F(DataMapTest, SetAndGet) {
    dataMap.insert("var1");
    
    dataMap.set("var1", 42.5f);
    ASSERT_EQ(dataMap.get("var1"), 42.5f);

    std::string varPath = "var2";
    dataMap.insert(std::move(varPath));
    dataMap.set("var2", 17.3f);
    ASSERT_EQ(dataMap.get("var2"), 17.3f);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
