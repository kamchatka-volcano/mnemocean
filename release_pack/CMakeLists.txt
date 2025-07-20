cmake_minimum_required(VERSION 3.18)
project(mnemocean VERSION 0.1.0 DESCRIPTION "mnemocean - mnemonic id generator")
include(seal_lake.cmake)

option(MNEMOCEAN_USE_BOOST_RANDOM "Use uniform_int_distribution from Boost::random" OFF)

if (MNEMOCEAN_USE_BOOST_RANDOM)
    find_package(Boost 1.66 REQUIRED COMPONENTS random)
endif ()

SealLake_v040_HeaderOnlyLibrary(
        COMPILE_FEATURES cxx_std_17
)

if (MNEMOCEAN_USE_BOOST_RANDOM)
    SealLake_v040_AddLibraries(Boost::boost)
endif ()

if (MNEMOCEAN_USE_BOOST_RANDOM)
    target_compile_definitions(mnemocean INTERFACE "MNEMOCEAN_USE_BOOST_RANDOM")
endif ()