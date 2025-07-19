#include "mnemocean/mnemocean.h"
#include <gtest/gtest.h>

TEST(Heroku, DefaultId)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{randomNumberGenerator};
    EXPECT_EQ(generator(), "young-hill");
    EXPECT_EQ(generator(), "white-shape");
}

TEST(Heroku, CustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{
            randomNumberGenerator,
            mnemocean::empty_token_generator{},
            ":"};
    EXPECT_EQ(generator(), "young:hill");
}

TEST(Heroku, DefaultAlphabetTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator =
            mnemocean::heroku_id_generator<std::mt19937>{randomNumberGenerator, mnemocean::alphabet_token_generator{}};
    EXPECT_EQ(generator(), "young-hill-syadh");
    EXPECT_EQ(generator(), "crimson-wood-gckek");
}

TEST(Heroku, CustomLengthAlphabetTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{
            randomNumberGenerator,
            mnemocean::alphabet_token_generator<3>{}};
    EXPECT_EQ(generator(), "young-hill-sya");
}

TEST(Heroku, DefaultAlphabetTokenGeneratorAndCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{
            randomNumberGenerator,
            mnemocean::alphabet_token_generator{},
            ":"};
    EXPECT_EQ(generator(), "young:hill:syadh");
}

TEST(Heroku, CustomLengthAlphabetTokenGeneratorAndCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{
            randomNumberGenerator,
            mnemocean::alphabet_token_generator<3>{},
            ":"};
    EXPECT_EQ(generator(), "young:hill:sya");
}

TEST(Heroku, DefaultAlphanumericalTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{
            randomNumberGenerator,
            mnemocean::alphanumeric_token_generator{}};
    EXPECT_EQ(generator(), "young-hill-z8aek");
    EXPECT_EQ(generator(), "crimson-wood-idogn");
}

TEST(Heroku, CustomLengthAlphanumericalTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{
            randomNumberGenerator,
            mnemocean::alphanumeric_token_generator<3>{}};
    EXPECT_EQ(generator(), "young-hill-z8a");
}

TEST(Heroku, DefaultAlphanumericalTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{
            randomNumberGenerator,
            mnemocean::alphanumeric_token_generator{},
            ":"};
    EXPECT_EQ(generator(), "young:hill:z8aek");
}

TEST(Heroku, CustomLengthAlphanumericalTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{
            randomNumberGenerator,
            mnemocean::alphanumeric_token_generator<3>{},
            ":"};
    EXPECT_EQ(generator(), "young:hill:z8a");
}

TEST(Heroku, DefaultNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator =
            mnemocean::heroku_id_generator<std::mt19937>{randomNumberGenerator, mnemocean::number_token_generator{}};
    EXPECT_EQ(generator(), "dark-lab-2592");
    EXPECT_EQ(generator(), "plain-water-94773");
}

TEST(Heroku, CustomLengthNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator =
            mnemocean::heroku_id_generator<std::mt19937>{randomNumberGenerator, mnemocean::number_token_generator<8>{}};
    EXPECT_EQ(generator(), "dark-lab-2592622");
}

TEST(Heroku, DefaultZeroPaddedNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{
            randomNumberGenerator,
            mnemocean::number_token_generator<5, mnemocean::number_string_format::zero_padded_decimal>{}};
    EXPECT_EQ(generator(), "dark-lab-02592");
}

TEST(Heroku, CustomLengthZeroPaddedNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{
            randomNumberGenerator,
            mnemocean::number_token_generator<8, mnemocean::number_string_format::zero_padded_decimal>{}};
    EXPECT_EQ(generator(), "dark-lab-02592622");
}

TEST(Heroku, DefaultNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{
            randomNumberGenerator,
            mnemocean::number_token_generator{},
            ":"};
    EXPECT_EQ(generator(), "dark:lab:2592");
}

TEST(Heroku, CustomLengthNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{
            randomNumberGenerator,
            mnemocean::number_token_generator<8>{},
            ":"};
    EXPECT_EQ(generator(), "dark:lab:2592622");
}


TEST(Heroku, DefaultZeroPaddedNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{
            randomNumberGenerator,
            mnemocean::number_token_generator<5, mnemocean::number_string_format::zero_padded_decimal>{},
            ":"};
    EXPECT_EQ(generator(), "dark:lab:02592");
}


TEST(Heroku, CustomLengthZeroPaddedNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{
            randomNumberGenerator,
            mnemocean::number_token_generator<8, mnemocean::number_string_format::zero_padded_decimal>{},
            ":"};
    EXPECT_EQ(generator(), "dark:lab:02592622");
}

TEST(Heroku, DefaultHexNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{
            randomNumberGenerator,
            mnemocean::number_token_generator<5, mnemocean::number_string_format::hexadecimal>{}};
    EXPECT_EQ(generator(), "dark-lab-6a31");
}

TEST(Heroku, CustomLengthHexNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{
            randomNumberGenerator,
            mnemocean::number_token_generator<8, mnemocean::number_string_format::hexadecimal>{}};
    EXPECT_EQ(generator(), "dark-lab-6a319ed");
}

TEST(Heroku, DefaultZeroPaddedHexNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{
            randomNumberGenerator,
            mnemocean::number_token_generator<5, mnemocean::number_string_format::zero_padded_hexadecimal>{}};
    EXPECT_EQ(generator(), "dark-lab-06a31");
}

TEST(Heroku, CustomLengthZeroPaddedHexNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{
            randomNumberGenerator,
            mnemocean::number_token_generator<8, mnemocean::number_string_format::zero_padded_hexadecimal>{}};
    EXPECT_EQ(generator(), "dark-lab-06a319ed");
}

TEST(Heroku, DefaultHexNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{
            randomNumberGenerator,
            mnemocean::number_token_generator<5, mnemocean::number_string_format::hexadecimal>{},
            ":"};
    EXPECT_EQ(generator(), "dark:lab:6a31");
}


TEST(Heroku, CustomLengthHexNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{
            randomNumberGenerator,
            mnemocean::number_token_generator<8, mnemocean::number_string_format::hexadecimal>{},
            ":"};
    EXPECT_EQ(generator(), "dark:lab:6a319ed");
}


TEST(Heroku, DefaultZeroPaddedHexNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{
            randomNumberGenerator,
            mnemocean::number_token_generator<5, mnemocean::number_string_format::zero_padded_hexadecimal>{},
            ":"};
    EXPECT_EQ(generator(), "dark:lab:06a31");
}

TEST(Heroku, CustomLengthZeroPaddedHexNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{2};
    auto generator = mnemocean::heroku_id_generator<std::mt19937>{
            randomNumberGenerator,
            mnemocean::number_token_generator<8, mnemocean::number_string_format::zero_padded_hexadecimal>{},
            ":"};
    EXPECT_EQ(generator(), "dark:lab:06a319ed");
}
