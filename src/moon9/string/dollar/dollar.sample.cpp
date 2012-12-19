#include <cassert>
#include <iostream>
#include "dollar.hpp"

int main( int argc, const char **argv )
{
    // 1) Simple interpolation usage:
    //    - Use $(symbol) macro to create/update a symbol.
    //    - Use $$(string) macro to translate all symbols in string.
    //      - All defined $symbols are replaced.
    //      - All undefined $symbols are quoted.

    $(PLAYER_1) = "Mark";
    $(PLAYER_2) = "John";

    std::cout << $$("Defined symbols are replaced: $PLAYER_1 and $PLAYER_2 joined the game") << std::endl;
    std::cout << $$("Undefined symbols are quoted: $PLAYER_3 joined the game") << std::endl;

    // 2) composition/chaining is supported through recursive lookups.

    $(HEY) = "Hello stranger";
    $(GREETING) = "$HEY! How are you?";
    std::cout << $$("Recursive lookups are supported: $GREETING") << std::endl;

    // 3) However, loopback lookups are quoted for security reasons.

    $(LOOPBACK) = "$LOOPBACK is quoted.";
    std::cout << $$("Loopback lookups are just quoted: $LOOPBACK") << std::endl;

    // 4) Symbol hot-swapping is supported.

    $(HEY) = "Hey $PLAYER_1 and $PLAYER_2";
    std::cout << $$("Symbol hot-swapping is supported: $GREETING") << std::endl;

    // 5) Symbols can hold many different types.

    $(name) = "John Doe";   // string
    $(flag) = true;         // boolean
    $(letter) = 'a';        // character
    $(items) = 100;         // integer
    $(price) = 99.95f;      // floating
    $(pi) = 3.141592;       // real

    std::cout << $$("Symbols can hold different types: $flag, $letter, $items, $price, $pi, $name") << std::endl;

    // 6) These symbols work internally as strings. You can cast them by using these additional macros.

    assert( $bool(flag) ^ true == false );
    assert( $string(letter) == 'a' );
    assert( $int(items) * 2 == 200 );
    assert( abs( $float(price) - 99.95f ) < 1 );
    assert( abs( $double(pi) - 3.141592 ) < 1 );
    assert( $string(name) + $string(name) == "John DoeJohn Doe" );

    // 7) Custom casts are supported as well, by using $cast(symbol,type)

    typedef int my_custom_currency;
    my_custom_currency currency = 100;
    $(price) = currency;
    assert( $cast(price,my_custom_currency) == currency );

    std::cout << "All ok." << std::endl;

    return 0;
}
