#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "..\3_1_2\carClass.h"

TEST_CASE("1", "[single-file]")
{
	carClass test;
	REQUIRE(test.turnOnEngine() == carClass::success);
}

TEST_CASE("2", "[single-file]")
{
	carClass test;
	REQUIRE(test.turnOnEngine() == carClass::success);
	REQUIRE(test.turnOnEngine() == carClass::error);
}

TEST_CASE("3", "[single-file]")
{
	carClass test;
	REQUIRE(test.turnOnEngine() == carClass::success);
	REQUIRE(test.SetGear(1) == carClass::success);
	REQUIRE(test.SetSpeed(20) == carClass::success);
}

TEST_CASE("4", "[single-file]")
{
	carClass test;
	REQUIRE(test.turnOnEngine() == carClass::success);
	REQUIRE(test.SetGear(1) == carClass::success);
	REQUIRE(test.SetSpeed(100) == carClass::error);
}

TEST_CASE("5", "[single-file]")
{
	carClass test;
	REQUIRE(test.turnOnEngine() == carClass::success);
	REQUIRE(test.SetGear(1) == carClass::success);
	REQUIRE(test.SetSpeed(10) == carClass::success);
	REQUIRE(test.SetGear(3) == carClass::error);
}

TEST_CASE("6", "[single-file]")
{
	carClass test;
	REQUIRE(test.turnOnEngine() == carClass::success);
	REQUIRE(test.SetGear(-1) == carClass::success);
	REQUIRE(test.SetSpeed(10) == carClass::success);
	REQUIRE(test.SetGear(1) == carClass::error);
}

TEST_CASE("7", "[single-file]")
{
	carClass test;
	REQUIRE(test.turnOnEngine() == carClass::success);
	REQUIRE(test.SetGear(-1) == carClass::success);
	REQUIRE(test.SetSpeed(10) == carClass::success);
	REQUIRE(test.SetSpeed(0) == carClass::success);
	REQUIRE(test.SetGear(0) == carClass::success);
	REQUIRE(test.SetSpeed(10) == carClass::error);
}

TEST_CASE("8", "[single-file]")
{
	carClass test;
	REQUIRE(test.turnOnEngine() == carClass::success);
	REQUIRE(test.SetGear(-1) == carClass::success);
	REQUIRE(test.SetSpeed(10) == carClass::success);
	REQUIRE(test.SetGear(1) == carClass::error);
}

TEST_CASE("9", "[single-file]")
{
	carClass test;
	REQUIRE(test.turnOnEngine() == carClass::success);
	REQUIRE(test.SetGear(-1) == carClass::success);
	REQUIRE(test.SetSpeed(10) == carClass::success);
	REQUIRE(test.turnOffEngine() == carClass::error);
}

TEST_CASE("10", "[single-file]")
{
	carClass test;
	REQUIRE(test.turnOnEngine() == carClass::success);
	REQUIRE(test.SetGear(1) == carClass::success);
	REQUIRE(test.SetSpeed(20) == carClass::success);
	REQUIRE(test.SetGear(2) == carClass::success);
	REQUIRE(test.SetSpeed(40) == carClass::success);
	REQUIRE(test.SetGear(3) == carClass::success);
	REQUIRE(test.SetSpeed(50) == carClass::success);
	REQUIRE(test.SetGear(4) == carClass::success);
	REQUIRE(test.SetSpeed(60) == carClass::success);
	REQUIRE(test.SetGear(5) == carClass::success);
	REQUIRE(test.SetSpeed(150) == carClass::success);
	REQUIRE(test.SetGear(0) == carClass::success);
	REQUIRE(test.SetSpeed(0) == carClass::success);
	REQUIRE(test.turnOffEngine() == carClass::success);
}