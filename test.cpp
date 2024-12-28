#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "calc.h"

TEST_CASE("GetNumbers") {
    std::vector<double> v1 {2, 3}, v2 {1.5, -2};
    CHECK(GetNumbers("2+3")==v1);
    CHECK(GetNumbers("1.5*-2")==v2);
    CHECK_THROWS(GetNumbers("2+3#"));
    CHECK_THROWS(GetNumbers("hello, world!"));
}

TEST_CASE("GetOperations"){
    std::string s1="*+//-", s2="*++/*++*";
    CHECK(GetOperations("12.456*55+-456/-1/0-7")==s1);
    CHECK(GetOperations("1*-456.+-120.3456+-44/-6546*-6464+-4656+4656*6")==s2);
    CHECK_THROWS(GetOperations("123+++*012---65465++/*6546++-64-"));
    CHECK_THROWS(GetOperations("123++456**456//456--456++-456-+"));
}

TEST_CASE("Multiplication"){
    // 123 + 123 + 123 * 3 - 456 * 2 + 123 * 0 +123 
    std::string op1="++*-*+*+";
    std::vector<double> num1={123, 123, 123, 3, 456, 2, 123, 0, 123};
    mult(num1, op1);
    std::vector<double> num1_res={123, 123, 369, 912, 0, 123};
    std::string op1_res="++-++";
    CHECK( num1==num1_res );
    CHECK( op1==op1_res );
}

TEST_CASE("Devision"){
    // 123 * 123 + 123 / 3 - 456 * 2 + 123 + 0 + 123 + 0 / 3;
    std::string op1="*+/-*++++/";
    std::vector<double> num1={123, 123, 123, 3, 456, 2, 123, 0, 123, 0, 3};
    dev(num1, op1);
    std::vector<double> num1_res={123, 123, 41, 456, 2, 123, 0, 123, 0};
    std::string op1_res="*+-*++++";
    CHECK( num1==num1_res );
    CHECK( op1==op1_res );

    // 123 * 123 + 123 / 3 - 456 * 2 + 123 / 0 + 123 + 0 / 3;
    std::string op2="*+/-*+/++/";
    std::vector<double> num2={123, 123, 123, 3, 456, 2, 123, 0, 123, 0, 3};
    CHECK_THROWS( dev(num2, op2) );
}

TEST_CASE("Is double"){
    CHECK(isNumeric_1_dot(".123"));
    CHECK(isNumeric_1_dot("123."));
    CHECK(isNumeric_1_dot("-156.1"));
    CHECK_FALSE(isNumeric_1_dot("s12.12."));
    CHECK_FALSE(isNumeric_1_dot(".123.123"));
    CHECK_FALSE(isNumeric_1_dot(".123 123"));
}


















