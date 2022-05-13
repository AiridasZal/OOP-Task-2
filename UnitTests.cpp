#include "functions.h"

#define CATCH_CONFIG_MAIN
#include"catch.hpp"

TEST_CASE("Galutinio balo su vidurkiu skaiciavimas")
{
    REQUIRE(GalutinisV(5, 7) == 6.2);
	REQUIRE(GalutinisV(9, 4) == 6);
	REQUIRE(GalutinisV(2, 4) == 2.3); //
	REQUIRE(GalutinisV(8, 6) == 6.8);
}

TEST_CASE("Mokiniu skirstymas pagal galutini bala")
{
    REQUIRE(Islaikyta(5) == TRUE);
    REQUIRE(Islaikyta(2) == TRUE); //
    REQUIRE(Islaikyta(7) == TRUE);
    REQUIRE(Islaikyta(1) == FALSE);
}