#include "mnemocean/mnemocean.h"
#include <gtest/gtest.h>

namespace {
const auto customDictionary = mnemocean::dictionary{{"foo", "bar", "baz"}, {"red", "green", "blue"}, {}};
}

TEST(Custom, DefaultId)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{randomNumberGenerator, customDictionary};
    EXPECT_EQ(generator(), "red-bar");
}

TEST(Custom, CustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::empty_token_generator{},
            ":"};
    EXPECT_EQ(generator(), "red:bar");
}

TEST(Custom, DefaultAlphabetTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::alphabet_token_generator{}};
    EXPECT_EQ(generator(), "red-bar-syadh");
}

TEST(Custom, CustomLengthAlphabetTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::alphabet_token_generator<3>{}};
    EXPECT_EQ(generator(), "red-bar-sya");
}

TEST(Custom, DefaultAlphabetTokenGeneratorAndCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::alphabet_token_generator{},
            ":"};
    EXPECT_EQ(generator(), "red:bar:syadh");
}

TEST(Custom, CustomLengthAlphabetTokenGeneratorAndCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::alphabet_token_generator<3>{},
            ":"};
    EXPECT_EQ(generator(), "red:bar:sya");
}

TEST(Custom, DefaultAlphanumericalTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::alphanumeric_token_generator{}};
    EXPECT_EQ(generator(), "red-bar-z8aek");
}

TEST(Custom, CustomLengthAlphanumericalTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::alphanumeric_token_generator<3>{}};
    EXPECT_EQ(generator(), "red-bar-z8a");
}

TEST(Custom, DefaultAlphanumericalTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::alphanumeric_token_generator{},
            ":"};
    EXPECT_EQ(generator(), "red:bar:z8aek");
}

TEST(Custom, CustomLengthAlphanumericalTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::alphanumeric_token_generator<3>{},
            ":"};
    EXPECT_EQ(generator(), "red:bar:z8a");
}

TEST(Custom, DefaultNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::number_token_generator{}};
    EXPECT_EQ(generator(), "blue-bar-2592");
}

TEST(Custom, CustomLengthNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::number_token_generator<8>{}};
    EXPECT_EQ(generator(), "blue-bar-2592622");
}

TEST(Custom, DefaultZeroPaddedNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::number_token_generator<5, mnemocean::number_string_format::zero_padded_decimal>{}};
    EXPECT_EQ(generator(), "blue-bar-02592");
}

TEST(Custom, CustomLengthZeroPaddedNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::number_token_generator<8, mnemocean::number_string_format::zero_padded_decimal>{}};
    EXPECT_EQ(generator(), "blue-bar-02592622");
}

TEST(Custom, DefaultNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::number_token_generator{},
            ":"};
    EXPECT_EQ(generator(), "blue:bar:2592");
}

TEST(Custom, CustomLengthNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::number_token_generator<8>{},
            ":"};
    EXPECT_EQ(generator(), "blue:bar:2592622");
}

TEST(Custom, DefaultZeroPaddedNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::number_token_generator<5, mnemocean::number_string_format::zero_padded_decimal>{},
            ":"};
    EXPECT_EQ(generator(), "blue:bar:02592");
}

TEST(Custom, CustomLengthZeroPaddedNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::number_token_generator<8, mnemocean::number_string_format::zero_padded_decimal>{},
            ":"};
    EXPECT_EQ(generator(), "blue:bar:02592622");
}

TEST(Custom, DefaultHexNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::number_token_generator<5, mnemocean::number_string_format::hexadecimal>{}};
    EXPECT_EQ(generator(), "blue-bar-6a31");
}

TEST(Custom, CustomLengthHexNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::number_token_generator<8, mnemocean::number_string_format::hexadecimal>{}};
    EXPECT_EQ(generator(), "blue-bar-6a319ed");
}

TEST(Custom, DefaultZeroPaddedHexNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::number_token_generator<5, mnemocean::number_string_format::zero_padded_hexadecimal>{}};
    EXPECT_EQ(generator(), "blue-bar-06a31");
}

TEST(Custom, CustomLengthZeroPaddedHexNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::number_token_generator<8, mnemocean::number_string_format::zero_padded_hexadecimal>{}};
    EXPECT_EQ(generator(), "blue-bar-06a319ed");
}

TEST(Custom, DefaultHexNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::number_token_generator<5, mnemocean::number_string_format::hexadecimal>{},
            ":"};
    EXPECT_EQ(generator(), "blue:bar:6a31");
}

TEST(Custom, CustomLengthHexNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::number_token_generator<8, mnemocean::number_string_format::hexadecimal>{},
            ":"};
    EXPECT_EQ(generator(), "blue:bar:6a319ed");
}

TEST(Custom, DefaultZeroPaddedHexNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::number_token_generator<5, mnemocean::number_string_format::zero_padded_hexadecimal>{},
            ":"};
    EXPECT_EQ(generator(), "blue:bar:06a31");
}

TEST(Custom, CustomLengthZeroPaddedHexNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator,
            customDictionary,
            mnemocean::number_token_generator<8, mnemocean::number_string_format::zero_padded_hexadecimal>{},
            ":"};
    EXPECT_EQ(generator(), "blue:bar:06a319ed");
}