#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

extern "C"
{
#include "stack.h"
#include "taylor_sine.h"
}

// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

TEST_CASE("taylor_sine")
{
    REQUIRE_THAT(taylor_sine(3.1415, 4),
        Catch::Matchers::WithinRel(0.000093, 0.05));

    REQUIRE_THAT(taylor_sine(1.57075, 10),
        Catch::Matchers::WithinRel(0.999944, 0.05));

    REQUIRE_THAT(taylor_sine(0, 1),
        Catch::Matchers::WithinRel(0, 0.05));
    
}

TEST_CASE("stack"){
    stack s;
    initialize(&s);
    REQUIRE(s.head == NULL);

    stack sb0;
    initialize(&sb0);
    stack sb1 = sb0;
    int x = 5;
    push(x, &sb0);
    REQUIRE(sb1.head != sb0.head);
    int y = pop(&sb0);
    REQUIRE(x == y);
    REQUIRE(sb1.head == sb0.head);

    stack sc0;
    initialize(&sc0);
    stack sc1 = sc0;
    int x0 = 1;
    int x1 = 2;
    push(x0, &sc0);
    push(x1, &sc0);
    int y0 = pop(&sc0);
    int y1 = pop(&sc0);
    REQUIRE(x1 == y0);
    REQUIRE(x0 == y1);
    REQUIRE(sc0.head == sc1.head);

}
