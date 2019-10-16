// path-kata-tests.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define AUTOMATIC_MAIN

#ifdef AUTOMATIC_MAIN

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "include/catch.hpp"

#else

#define CATCH_CONFIG_RUNNER

#include "include/catch.hpp"

int main(int argc, char* const argv[])
{
    Catch::Session session; // There must be exactly one instance

    // writing to session.configData() here sets defaults
    // this is the preferred way to set them

    const auto returnCode = session.applyCommandLine(argc, argv);
    if (returnCode != 0) // Indicates a command line error
        return returnCode;

    // writing to session.configData() or session.Config() here
    // overrides command line args
    // only do this if you know you need to
    session.configData().showSuccessfulTests = true;                        // --success
    session.configData().showDurations = Catch::ShowDurations::Always;      // --durations yes

    return session.run();
}

#endif // AUTOMATIC_MAIN