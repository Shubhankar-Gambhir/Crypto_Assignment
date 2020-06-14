
#include <bits/stdc++.h>
#include "gtest/gtest.h"


using namespace std;

TEST(TypeCasting,int_long){
    int i;
    for(i=0;i<10000;i++){
        int a = rand();
        long b = (long)a ;
        EXPECT_EQ(a,b);
    }
}
TEST(TypeCasting,float_double){
    float a = rand();
    float b = rand();
    a = (float) a/b ;
    double c = (double) a;
    double margin = abs(c - a);
    EXPECT_LE(margin,0.1);
}
TEST(Vectors,Chec_equality){
    vector <int> v1, v2, v3;
    int a;
    for (int i = 0; i < 1000; i++) {
        a = rand();
        v1.push_back(a);
        v2.push_back(a);
    }
    EXPECT_EQ(v1, v2);
}

int main (int argc, char **argv) {
    ::testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS();
}
