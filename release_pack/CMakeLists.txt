cmake_minimum_required(VERSION 3.18)
project(mnemocean VERSION 0.1.0 DESCRIPTION "mnemocean - mnemonic id generator")
include(seal_lake.cmake)

SealLake_v040_HeaderOnlyLibrary(
    COMPILE_FEATURES cxx_std_17
)

