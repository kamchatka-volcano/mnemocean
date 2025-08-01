#include "mnemocean/mnemocean.h"
#include <gtest/gtest.h>

TEST(Petname, DefaultId)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator =
            mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{randomNumberGenerator};
    EXPECT_EQ(generator(), "recently-working-alpaca");
}

TEST(Petname, Short)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator =
            mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::short_name>{randomNumberGenerator};
    EXPECT_EQ(generator(), "working-alpaca");
}

TEST(Petname, CustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::empty_token_generator{},
            ":"};
    EXPECT_EQ(generator(), "recently:working:alpaca");
}

TEST(Petname, DefaultAlphabetTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::alphabetic_token_generator{}};
    EXPECT_EQ(generator(), "recently-working-alpaca-yadhz");
}

TEST(Petname, CustomLengthAlphabetTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::alphabetic_token_generator<3>{}};
    EXPECT_EQ(generator(), "recently-working-alpaca-yad");
}

TEST(Petname, DefaultAlphabetTokenGeneratorAndCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::alphabetic_token_generator{},
            ":"};
    EXPECT_EQ(generator(), "recently:working:alpaca:yadhz");
}

TEST(Petname, CustomLengthAlphabetTokenGeneratorAndCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::alphabetic_token_generator<3>{},
            ":"};
    EXPECT_EQ(generator(), "recently:working:alpaca:yad");
}

TEST(Petname, DefaultAlphanumericalTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::alphanumeric_token_generator{}};
    EXPECT_EQ(generator(), "recently-working-alpaca-8aek0");
}

TEST(Petname, CustomLengthAlphanumericalTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::alphanumeric_token_generator<3>{}};
    EXPECT_EQ(generator(), "recently-working-alpaca-8ae");
}

TEST(Petname, DefaultAlphanumericalTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::alphanumeric_token_generator{},
            ":"};
    EXPECT_EQ(generator(), "recently:working:alpaca:8aek0");
}

TEST(Petname, CustomLengthAlphanumericalTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{1};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::alphanumeric_token_generator<3>{},
            ":"};
    EXPECT_EQ(generator(), "recently:working:alpaca:8ae");
}

TEST(Petname, DefaultNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{16};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::number_token_generator{}};
    EXPECT_EQ(generator(), "namely-firm-swan-5568");
}

TEST(Petname, CustomLengthNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{16};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::number_token_generator<8>{}};
    EXPECT_EQ(generator(), "namely-firm-swan-5694624");
}

TEST(Petname, DefaultZeroPaddedNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{16};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::number_token_generator<5, mnemocean::number_string_format::zero_padded_decimal>{}};
    EXPECT_EQ(generator(), "namely-firm-swan-05568");
}

TEST(Petname, CustomLengthZeroPaddedNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{16};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::number_token_generator<8, mnemocean::number_string_format::zero_padded_decimal>{}};
    EXPECT_EQ(generator(), "namely-firm-swan-05694624");
}

TEST(Petname, DefaultNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{16};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::number_token_generator{},
            ":"};
    EXPECT_EQ(generator(), "namely:firm:swan:5568");
}

TEST(Petname, CustomLengthNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{16};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::number_token_generator<8>{},
            ":"};
    EXPECT_EQ(generator(), "namely:firm:swan:5694624");
}

TEST(Petname, DefaultZeroPaddedNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{16};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::number_token_generator<5, mnemocean::number_string_format::zero_padded_decimal>{},
            ":"};
    EXPECT_EQ(generator(), "namely:firm:swan:05568");
}

TEST(Petname, CustomLengthZeroPaddedNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{16};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::number_token_generator<8, mnemocean::number_string_format::zero_padded_decimal>{},
            ":"};
    EXPECT_EQ(generator(), "namely:firm:swan:05694624");
}

TEST(Petname, DefaultHexNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{16};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::number_token_generator<5, mnemocean::number_string_format::hexadecimal>{}};
    EXPECT_EQ(generator(), "namely-firm-swan-e418");
}

TEST(Petname, CustomLengthHexNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{16};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::number_token_generator<8, mnemocean::number_string_format::hexadecimal>{}};
    EXPECT_EQ(generator(), "namely-firm-swan-e418245");
}

TEST(Petname, DefaultZeroPaddedHexNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{16};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::number_token_generator<5, mnemocean::number_string_format::zero_padded_hexadecimal>{}};
    EXPECT_EQ(generator(), "namely-firm-swan-0e418");
}

TEST(Petname, CustomLengthZeroPaddedHexNumberTokenGenerator)
{
    auto randomNumberGenerator = std::mt19937{16};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::number_token_generator<8, mnemocean::number_string_format::zero_padded_hexadecimal>{}};
    EXPECT_EQ(generator(), "namely-firm-swan-0e418245");
}

TEST(Petname, DefaultHexNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{16};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::number_token_generator<5, mnemocean::number_string_format::hexadecimal>{},
            ":"};
    EXPECT_EQ(generator(), "namely:firm:swan:e418");
}

TEST(Petname, CustomLengthHexNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{16};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::number_token_generator<8, mnemocean::number_string_format::hexadecimal>{},
            ":"};
    EXPECT_EQ(generator(), "namely:firm:swan:e418245");
}

TEST(Petname, DefaultZeroPaddedHexNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{16};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::number_token_generator<5, mnemocean::number_string_format::zero_padded_hexadecimal>{},
            ":"};
    EXPECT_EQ(generator(), "namely:firm:swan:0e418");
}

TEST(Petname, CustomLengthZeroPaddedHexNumberTokenGeneratorWithCustomDelimiter)
{
    auto randomNumberGenerator = std::mt19937{16};
    auto generator = mnemocean::petname_id_generator<std::mt19937, mnemocean::petname_format::long_name>{
            randomNumberGenerator,
            mnemocean::number_token_generator<8, mnemocean::number_string_format::zero_padded_hexadecimal>{},
            ":"};
    EXPECT_EQ(generator(), "namely:firm:swan:0e418245");
}
