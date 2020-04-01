//  Matt Perry, Tailon Russell, Chenyi Ling, McKade Sorensen

#include <iostream>
#include "shape.hpp"
#define CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_FAST_COMPILE
#include "catch.hpp"

int main(int argc, char* argv[]) {
    Catch::Session testing;
    int catchresult;
    catchresult = testing.applyCommandLine(argc, argv);
    if (!catchresult) {
        std::cout << "Begin tests for class shapes and its derived classes: \n";
        catchresult = testing.run();
        std::cout << "End of automated tests.\n"; 
    }
    return 0;
}