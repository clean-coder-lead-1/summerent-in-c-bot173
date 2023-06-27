#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("Infer breach Too High")
{
  REQUIRE(inferBreach(50,30,40) == TOO_HIGH);
}

TEST_CASE("Infer breach Normal")
{
  REQUIRE(inferBreach(-70,-50,-100) == NORMAL);
}

TEST_CASE("Infer breach Invalid")
{
  REQUIRE(inferBreach(0,0,0) == NORMAL);
}

TEST_CASE("Classify Breach passive cooling within limit")
{
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING,20)==NORMAL);
}

TEST_CASE("Classify Breach passive cooling over limit")
{
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING,50)==TOO_HIGH);
}

TEST_CASE("Classify Breach passive cooling under limit")
{
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING,-10)==TOO_LOW);
}

TEST_CASE("Classify Breach hi active cooling within limit")
{
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING,20)==NORMAL);
}

TEST_CASE("Classify Breach hi active cooling over limit")
{
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING,50)==TOO_HIGH);
}

TEST_CASE("Classify Breach hi active cooling under limit")
{
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING,-10)==TOO_LOW);
}

TEST_CASE("Classify Breach med active cooling within limit")
{
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING,20)==NORMAL);
}

TEST_CASE("Classify Breach med active cooling over limit")
{
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING,50)==TOO_HIGH);
}

TEST_CASE("Classify Breach med active cooling under limit")
{
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING,-10)==TOO_LOW);
}

TEST_CASE("Classify Breach invalid cooling type")
{
  REQUIRE(classifyTemperatureBreach(COOLING_MAX,-10)==TOO_HIGH);
}