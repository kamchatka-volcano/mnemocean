cmake_minimum_required(VERSION 3.18)
project(test-mnemocean)

if(MNEMOCEAN_TEST_RELEASE)
    add_subdirectory(release)
endif()

SealLake_v040_GoogleTest(
        NAME test_mnemocean
        COMPILE_FEATURES cxx_std_17
        SOURCES
        test_heroku.cpp
        test_petname.cpp
        test_custom.cpp
        test_custom_token_generator.cpp
        LIBRARIES
            mnemocean::mnemocean
)