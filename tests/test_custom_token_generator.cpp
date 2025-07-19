#include "mnemocean/mnemocean.h"
#include <gtest/gtest.h>
#include <unordered_map>

class ConflictResolverTokenGenerator
{
public:
    ConflictResolverTokenGenerator(std::unordered_map<std::string, int>& generatedTokens)
        : generatedTokens_(&generatedTokens)
    {
    }

    template<typename UniformRandomNumberGenerator>
    std::string operator()(std::string_view phrase, UniformRandomNumberGenerator&) const
    {
        auto tokenIt = generatedTokens_->find(std::string{phrase});
        if (tokenIt != generatedTokens_->end()){
            tokenIt->second++;
            return std::to_string(tokenIt->second);
        }
        (*generatedTokens_)[std::string{phrase}] = 1;
        return "1";
    }

private:
    std::unordered_map<std::string, int>* generatedTokens_{};
};

TEST(CustomTokenGenerator, ConflictResolver)
{
    auto generatedTokens = std::unordered_map<std::string, int>{};
    auto conflictResolver = ConflictResolverTokenGenerator{generatedTokens};
    auto randomNumberGenerator = std::mt19937{1};
    const auto exhaustedDictionary = mnemocean::dictionary{{"foo"}, {"green"}, {}};
    auto generator = mnemocean::mnemonic_id_generator<std::mt19937>{
            randomNumberGenerator, exhaustedDictionary, conflictResolver};
    EXPECT_EQ(generator(), "green-foo-1");
    EXPECT_EQ(generator(), "green-foo-2");
    EXPECT_EQ(generator(), "green-foo-3");
}