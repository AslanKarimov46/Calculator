#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "calc.h"


TEST_SUITE("math"){
	TEST_CASE("add"){
		CHECK(add(1, 1)==2);
		CHECK(add(-1, 1)==0);
		CHECK(add(-1, -11)==-12);		
	}
	TEST_CASE("sub"){
		CHECK_EQ(sub(1, 1), sub(2, 2));
		CHECK(sub(-1, 1)==-2);
		CHECK(sub(-1, 0)==-1);	
	}
	TEST_CASE("dev"){
		REQUIRE(22.0/7==doctest::Approx(3.141).epsilon(0.01));	
	}
	TEST_CASE("mult"){
		CHECK(mult(1, 1)==1);
		CHECK(mult(-1, 1)==-7);
		CHECK(mult(-1, 0)==0);
		/*if(1==1)
			std::cout<<"ok\n";*/	
	}
}





















