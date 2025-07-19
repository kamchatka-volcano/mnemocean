cmake_minimum_required(VERSION 3.18)
project(mnemocean VERSION 0.1.0 DESCRIPTION "mnemocean - mnemonic id generator")
include(external/seal_lake)

SealLake_V040_Bundle(
        NAME mnemocean_eel
        URL https://github.com/kamchatka-volcano/eel/releases/download/v0.3.0/eel-v0.3.0.zip
        DESTINATION include/mnemocean/detail/external
        DIRECTORIES include/eel
        TEXT_REPLACEMENTS
        "namespace eel" "namespace mnemocean::eel"
        "EEL_" "CMDLIME_EEL_"
)

SealLake_v040_HeaderOnlyLibrary(
        COMPILE_FEATURES cxx_std_17
        PROPERTIES
            CXX_EXTENSIONS OFF
)

SealLake_v040_OptionalSubProjects(tests)