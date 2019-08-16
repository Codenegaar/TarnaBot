#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <string>
#include <json/json.h>
#include "tarnabot/objects/user.hpp"

TEST_CASE("Construct User from JSON", "[user]")
{
    Json::Value value;
    value["id"] = 123456;
    value["is_bot"] = true;
    value["first_name"] = "Ali";
    value["last_name"] = "Rashidi";
    value["username"] = "codenegaar";
    value["language_code"] = "fa-IR";

    Tarna::User user(value);

    REQUIRE(user.id() == 123456);
    REQUIRE(user.isBot());
    REQUIRE(user.firstName() == "Ali");
    REQUIRE(user.lastName() == "Rashidi");
    REQUIRE(user.username() == "codenegaar");
    REQUIRE(user.languageCode() == "fa-IR");
}
