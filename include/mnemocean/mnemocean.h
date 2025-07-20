#ifndef MNEMOCEAN_H
#define MNEMOCEAN_H
#include "detail/external/eel/functional.h"
#include "detail/external/eel/string_utils.h"

#ifdef MNEMOCEAN_USE_BOOST_RANDOM
#include <boost/random/uniform_int_distribution.hpp>
#endif

#include <iomanip>
#include <random>
#include <sstream>
#include <string>
#include <string_view>
#include <variant>
#include <vector>

namespace mnemocean {

#ifdef MNEMOCEAN_USE_BOOST_RANDOM
namespace random = boost::random;
#else
namespace random = std;
#endif

struct dictionary_preset {
    std::vector<std::string_view> nouns;
    std::vector<std::string_view> adjectives;
    std::vector<std::string_view> adverbs;
};

struct heroku_dictionary : dictionary_preset {
    heroku_dictionary()
        : dictionary_preset{
                  {"art",     "band",   "bar",       "base",     "bird",      "block",  "boat",       "bonus",
                   "bread",   "breeze", "brook",     "bush",     "butterfly", "cake",   "cell",       "cherry",
                   "cloud",   "credit", "darkness",  "dawn",     "dew",       "disk",   "dream",      "dust",
                   "feather", "field",  "fire",      "firefly",  "flower",    "fog",    "forest",     "frog",
                   "frost",   "glade",  "glitter",   "grass",    "hall",      "hat",    "haze",       "heart",
                   "hill",    "king",   "lab",       "lake",     "leaf",      "limit",  "math",       "meadow",
                   "mode",    "moon",   "morning",   "mountain", "mouse",     "mud",    "night",      "paper",
                   "pine",    "poetry", "pond",      "queen",    "rain",      "recipe", "resonance",  "rice",
                   "river",   "salad",  "scene",     "sea",      "shadow",    "shape",  "silence",    "sky",
                   "smoke",   "snow",   "snowflake", "sound",    "star",      "sun",    "sun",        "sunset",
                   "surf",    "term",   "thunder",   "tooth",    "tree",      "truth",  "union",      "unit",
                   "violet",  "voice",  "water",     "water",    "waterfall", "wave",   "wildflower", "wind",
                   "wood"},
                  {"aged",     "ancient",  "autumn",    "billowing", "bitter",   "black",    "blue",      "bold",
                   "broad",    "broken",   "calm",      "cold",      "cool",     "crimson",  "curly",     "damp",
                   "dark",     "dawn",     "delicate",  "divine",    "dry",      "empty",    "falling",   "fancy",
                   "flat",     "floral",   "fragrant",  "frosty",    "gentle",   "green",    "hidden",    "holy",
                   "icy",      "jolly",    "late",      "lingering", "little",   "lively",   "long",      "lucky",
                   "misty",    "morning",  "muddy",     "mute",      "nameless", "noisy",    "odd",       "old",
                   "orange",   "patient",  "plain",     "polished",  "proud",    "purple",   "quiet",     "rapid",
                   "raspy",    "red",      "restless",  "rough",     "round",    "royal",    "shiny",     "shrill",
                   "shy",      "silent",   "small",     "snowy",     "soft",     "solitary", "sparkling", "spring",
                   "square",   "steep",    "still",     "summer",    "super",    "sweet",    "throbbing", "tight",
                   "tiny",     "twilight", "wandering", "weathered", "white",    "wild",     "winter",    "wispy",
                   "withered", "yellow",   "young"},
                  {}}
    {
    }
};

struct petname_dictionary : dictionary_preset {
    petname_dictionary()
        : dictionary_preset{
                  {"ox",       "ant",      "ape",      "asp",      "bat",      "bee",      "boa",      "bug",
                   "cat",      "cod",      "cow",      "cub",      "doe",      "dog",      "eel",      "eft",
                   "elf",      "elk",      "emu",      "ewe",      "fly",      "fox",      "gar",      "gnu",
                   "hen",      "hog",      "imp",      "jay",      "kid",      "kit",      "koi",      "lab",
                   "man",      "owl",      "pig",      "pug",      "pup",      "ram",      "rat",      "ray",
                   "yak",      "bass",     "bear",     "bird",     "boar",     "buck",     "bull",     "calf",
                   "chow",     "clam",     "colt",     "crab",     "crow",     "dane",     "deer",     "dodo",
                   "dory",     "dove",     "drum",     "duck",     "fawn",     "fish",     "flea",     "foal",
                   "fowl",     "frog",     "gnat",     "goat",     "grub",     "gull",     "hare",     "hawk",
                   "ibex",     "joey",     "kite",     "kiwi",     "lamb",     "lark",     "lion",     "loon",
                   "lynx",     "mako",     "mink",     "mite",     "mole",     "moth",     "mule",     "mutt",
                   "newt",     "orca",     "oryx",     "pika",     "pony",     "puma",     "seal",     "shad",
                   "slug",     "sole",     "stag",     "stud",     "swan",     "tahr",     "teal",     "tick",
                   "toad",     "tuna",     "wasp",     "wolf",     "worm",     "wren",     "yeti",     "adder",
                   "akita",    "alien",    "aphid",    "bison",    "boxer",    "bream",    "bunny",    "burro",
                   "camel",    "chimp",    "civet",    "cobra",    "coral",    "corgi",    "crane",    "dingo",
                   "drake",    "eagle",    "egret",    "filly",    "finch",    "gator",    "gecko",    "ghost",
                   "ghoul",    "goose",    "guppy",    "heron",    "hippo",    "horse",    "hound",    "husky",
                   "hyena",    "koala",    "krill",    "leech",    "lemur",    "liger",    "llama",    "louse",
                   "macaw",    "midge",    "molly",    "moose",    "moray",    "mouse",    "panda",    "perch",
                   "prawn",    "quail",    "racer",    "raven",    "rhino",    "robin",    "satyr",    "shark",
                   "sheep",    "shrew",    "skink",    "skunk",    "sloth",    "snail",    "snake",    "snipe",
                   "squid",    "stork",    "swift",    "tapir",    "tetra",    "tiger",    "troll",    "trout",
                   "viper",    "wahoo",    "whale",    "zebra",    "alpaca",   "amoeba",   "baboon",   "badger",
                   "beagle",   "bedbug",   "beetle",   "bengal",   "bobcat",   "caiman",   "cattle",   "cicada",
                   "collie",   "condor",   "cougar",   "coyote",   "dassie",   "dragon",   "earwig",   "falcon",
                   "feline",   "ferret",   "gannet",   "gibbon",   "glider",   "goblin",   "gopher",   "grouse",
                   "guinea",   "hermit",   "hornet",   "iguana",   "impala",   "insect",   "jackal",   "jaguar",
                   "jennet",   "kitten",   "kodiak",   "lizard",   "locust",   "maggot",   "magpie",   "mammal",
                   "mantis",   "marlin",   "marmot",   "marten",   "martin",   "mayfly",   "minnow",   "monkey",
                   "mullet",   "muskox",   "ocelot",   "oriole",   "osprey",   "oyster",   "parrot",   "pigeon",
                   "piglet",   "poodle",   "possum",   "python",   "quagga",   "rabbit",   "raptor",   "rodent",
                   "roughy",   "salmon",   "sawfly",   "serval",   "shiner",   "shrimp",   "spider",   "sponge",
                   "tarpon",   "thrush",   "tomcat",   "toucan",   "turkey",   "turtle",   "urchin",   "vervet",
                   "walrus",   "weasel",   "weevil",   "wombat",   "anchovy",  "anemone",  "bluejay",  "buffalo",
                   "bulldog",  "buzzard",  "caribou",  "catfish",  "chamois",  "cheetah",  "chicken",  "chigger",
                   "cowbird",  "crappie",  "crawdad",  "cricket",  "dogfish",  "dolphin",  "firefly",  "garfish",
                   "gazelle",  "gelding",  "giraffe",  "gobbler",  "gorilla",  "goshawk",  "grackle",  "griffon",
                   "grizzly",  "grouper",  "haddock",  "hagfish",  "halibut",  "hamster",  "herring",  "javelin",
                   "jawfish",  "jaybird",  "katydid",  "ladybug",  "lamprey",  "lemming",  "leopard",  "lioness",
                   "lobster",  "macaque",  "mallard",  "mammoth",  "manatee",  "mastiff",  "meerkat",  "mollusk",
                   "monarch",  "mongrel",  "monitor",  "monster",  "mudfish",  "muskrat",  "mustang",  "narwhal",
                   "oarfish",  "octopus",  "opossum",  "ostrich",  "panther",  "peacock",  "pegasus",  "pelican",
                   "penguin",  "phoenix",  "piranha",  "polecat",  "primate",  "quetzal",  "raccoon",  "rattler",
                   "redbird",  "redfish",  "reptile",  "rooster",  "sawfish",  "sculpin",  "seagull",  "skylark",
                   "snapper",  "spaniel",  "sparrow",  "sunbeam",  "sunbird",  "sunfish",  "tadpole",  "terrier",
                   "unicorn",  "vulture",  "wallaby",  "walleye",  "warthog",  "whippet",  "wildcat",  "aardvark",
                   "airedale", "albacore", "anteater", "antelope", "arachnid", "barnacle", "basilisk", "blowfish",
                   "bluebird", "bluegill", "bonefish", "bullfrog", "cardinal", "chipmunk", "cockatoo", "crayfish",
                   "dinosaur", "doberman", "duckling", "elephant", "escargot", "flamingo", "flounder", "foxhound",
                   "glowworm", "goldfish", "grubworm", "hedgehog", "honeybee", "hookworm", "humpback", "kangaroo",
                   "killdeer", "kingfish", "labrador", "lacewing", "ladybird", "lionfish", "longhorn", "mackerel",
                   "malamute", "marmoset", "mastodon", "moccasin", "mongoose", "monkfish", "mosquito", "pangolin",
                   "parakeet", "pheasant", "pipefish", "platypus", "polliwog", "porpoise", "reindeer", "ringtail",
                   "sailfish", "scorpion", "seahorse", "seasnail", "sheepdog", "shepherd", "silkworm", "squirrel",
                   "stallion", "starfish", "starling", "stingray", "stinkbug", "sturgeon", "terrapin", "titmouse",
                   "tortoise", "treefrog", "werewolf", "woodcock"},
                  {"able",     "above",    "absolute", "accepted", "accurate", "ace",      "active",   "actual",
                   "adapted",  "adapting", "adequate", "adjusted", "advanced", "alert",    "alive",    "allowed",
                   "allowing", "amazed",   "amazing",  "ample",    "amused",   "amusing",  "apparent", "apt",
                   "arriving", "artistic", "assured",  "assuring", "awaited",  "awake",    "aware",    "balanced",
                   "becoming", "beloved",  "better",   "big",      "blessed",  "bold",     "boss",     "brave",
                   "brief",    "bright",   "bursting", "busy",     "calm",     "capable",  "capital",  "careful",
                   "caring",   "casual",   "causal",   "central",  "certain",  "champion", "charmed",  "charming",
                   "cheerful", "chief",    "choice",   "civil",    "classic",  "clean",    "clear",    "clever",
                   "climbing", "close",    "closing",  "coherent", "comic",    "communal", "complete", "composed",
                   "concise",  "concrete", "content",  "cool",     "correct",  "cosmic",   "crack",    "creative",
                   "credible", "crisp",    "crucial",  "cuddly",   "cunning",  "curious",  "current",  "cute",
                   "daring",   "darling",  "dashing",  "dear",     "decent",   "deciding", "deep",     "definite",
                   "delicate", "desired",  "destined", "devoted",  "direct",   "discrete", "distinct", "diverse",
                   "divine",   "dominant", "driven",   "driving",  "dynamic",  "eager",    "easy",     "electric",
                   "elegant",  "emerging", "eminent",  "enabled",  "enabling", "endless",  "engaged",  "engaging",
                   "enhanced", "enjoyed",  "enormous", "enough",   "epic",     "equal",    "equipped", "eternal",
                   "ethical",  "evident",  "evolved",  "evolving", "exact",    "excited",  "exciting", "exotic",
                   "expert",   "factual",  "fair",     "faithful", "famous",   "fancy",    "fast",     "feasible",
                   "fine",     "finer",    "firm",     "first",    "fit",      "fitting",  "fleet",    "flexible",
                   "flowing",  "fluent",   "flying",   "fond",     "frank",    "free",     "fresh",    "full",
                   "fun",      "funky",    "funny",    "game",     "generous", "gentle",   "genuine",  "giving",
                   "glad",     "glorious", "glowing",  "golden",   "good",     "gorgeous", "grand",    "grateful",
                   "great",    "growing",  "grown",    "guided",   "guiding",  "handy",    "happy",    "hardy",
                   "harmless", "healthy",  "helped",   "helpful",  "helping",  "heroic",   "hip",      "holy",
                   "honest",   "hopeful",  "hot",      "huge",     "humane",   "humble",   "humorous", "ideal",
                   "immense",  "immortal", "immune",   "improved", "in",       "included", "infinite", "informed",
                   "innocent", "inspired", "integral", "intense",  "intent",   "internal", "intimate", "inviting",
                   "joint",    "just",     "keen",     "key",      "kind",     "knowing",  "known",    "large",
                   "lasting",  "leading",  "learning", "legal",    "legible",  "lenient",  "liberal",  "light",
                   "liked",    "literate", "live",     "living",   "logical",  "loved",    "loving",   "loyal",
                   "lucky",    "magical",  "magnetic", "main",     "major",    "many",     "massive",  "master",
                   "mature",   "maximum",  "measured", "meet",     "merry",    "mighty",   "mint",     "model",
                   "modern",   "modest",   "moral",    "more",     "moved",    "moving",   "musical",  "mutual",
                   "national", "native",   "natural",  "nearby",   "neat",     "needed",   "neutral",  "new",
                   "next",     "nice",     "noble",    "normal",   "notable",  "noted",    "novel",    "obliging",
                   "on",       "one",      "open",     "optimal",  "optimum",  "organic",  "oriented", "outgoing",
                   "patient",  "peaceful", "perfect",  "pet",      "picked",   "pleasant", "pleased",  "pleasing",
                   "poetic",   "polished", "polite",   "popular",  "positive", "possible", "powerful", "precious",
                   "precise",  "premium",  "prepared", "present",  "pretty",   "primary",  "prime",    "pro",
                   "probable", "profound", "promoted", "prompt",   "proper",   "proud",    "proven",   "pumped",
                   "pure",     "quality",  "quick",    "quiet",    "rapid",    "rare",     "rational", "ready",
                   "real",     "refined",  "regular",  "related",  "relative", "relaxed",  "relaxing", "relevant",
                   "relieved", "renewed",  "renewing", "resolved", "rested",   "rich",     "right",    "robust",
                   "romantic", "ruling",   "sacred",   "safe",     "saved",    "saving",   "secure",   "select",
                   "selected", "sensible", "set",      "settled",  "settling", "sharing",  "sharp",    "shining",
                   "simple",   "sincere",  "singular", "skilled",  "smart",    "smashing", "smiling",  "smooth",
                   "social",   "solid",    "sought",   "sound",    "special",  "splendid", "square",   "stable",
                   "star",     "steady",   "sterling", "still",    "stirred",  "stirring", "striking", "strong",
                   "stunning", "subtle",   "suitable", "suited",   "summary",  "sunny",    "super",    "superb",
                   "supreme",  "sure",     "sweeping", "sweet",    "talented", "teaching", "tender",   "thankful",
                   "thorough", "tidy",     "tight",    "together", "tolerant", "top",      "topical",  "tops",
                   "touched",  "touching", "tough",    "true",     "trusted",  "trusting", "trusty",   "ultimate",
                   "unbiased", "uncommon", "unified",  "unique",   "united",   "up",       "upright",  "upward",
                   "usable",   "useful",   "valid",    "valued",   "vast",     "verified", "viable",   "vital",
                   "vocal",    "wanted",   "warm",     "wealthy",  "welcome",  "welcomed", "well",     "whole",
                   "willing",  "winning",  "wired",    "wise",     "witty",    "wondrous", "workable", "working",
                   "worthy"},
                  {"abnormally", "absolutely", "accurately", "actively",   "actually",   "adequately", "admittedly",
                   "adversely",  "allegedly",  "amazingly",  "annually",   "apparently", "arguably",   "awfully",
                   "badly",      "barely",     "basically",  "blatantly",  "blindly",    "briefly",    "brightly",
                   "broadly",    "carefully",  "centrally",  "certainly",  "cheaply",    "cleanly",    "clearly",
                   "closely",    "commonly",   "completely", "constantly", "conversely", "correctly",  "curiously",
                   "currently",  "daily",      "deadly",     "deeply",     "definitely", "directly",   "distinctly",
                   "duly",       "eagerly",    "early",      "easily",     "eminently",  "endlessly",  "enormously",
                   "entirely",   "equally",    "especially", "evenly",     "evidently",  "exactly",    "explicitly",
                   "externally", "extremely",  "factually",  "fairly",     "finally",    "firmly",     "firstly",
                   "forcibly",   "formally",   "formerly",   "frankly",    "freely",     "frequently", "friendly",
                   "fully",      "generally",  "gently",     "genuinely",  "ghastly",    "gladly",     "globally",
                   "gradually",  "gratefully", "greatly",    "grossly",    "happily",    "hardly",     "heartily",
                   "heavily",    "hideously",  "highly",     "honestly",   "hopefully",  "hopelessly", "horribly",
                   "hugely",     "humbly",     "ideally",    "illegally",  "immensely",  "implicitly", "incredibly",
                   "indirectly", "infinitely", "informally", "inherently", "initially",  "instantly",  "intensely",
                   "internally", "jointly",    "jolly",      "kindly",     "largely",    "lately",     "legally",
                   "lightly",    "likely",     "literally",  "lively",     "locally",    "logically",  "loosely",
                   "loudly",     "lovely",     "luckily",    "mainly",     "manually",   "marginally", "mentally",
                   "merely",     "mildly",     "miserably",  "mistakenly", "moderately", "monthly",    "morally",
                   "mostly",     "multiply",   "mutually",   "namely",     "nationally", "naturally",  "nearly",
                   "neatly",     "needlessly", "newly",      "nicely",     "nominally",  "normally",   "notably",
                   "noticeably", "obviously",  "oddly",      "officially", "only",       "openly",     "optionally",
                   "overly",     "painfully",  "partially",  "partly",     "perfectly",  "personally", "physically",
                   "plainly",    "pleasantly", "poorly",     "positively", "possibly",   "precisely",  "preferably",
                   "presently",  "presumably", "previously", "primarily",  "privately",  "probably",   "promptly",
                   "properly",   "publicly",   "purely",     "quickly",    "quietly",    "radically",  "randomly",
                   "rapidly",    "rarely",     "rationally", "readily",    "really",     "reasonably", "recently",
                   "regularly",  "reliably",   "remarkably", "remotely",   "repeatedly", "rightly",    "roughly",
                   "routinely",  "sadly",      "safely",     "scarcely",   "secondly",   "secretly",   "seemingly",
                   "sensibly",   "separately", "seriously",  "severely",   "sharply",    "shortly",    "similarly",
                   "simply",     "sincerely",  "singularly", "slightly",   "slowly",     "smoothly",   "socially",
                   "solely",     "specially",  "steadily",   "strangely",  "strictly",   "strongly",   "subtly",
                   "suddenly",   "suitably",   "supposedly", "surely",     "terminally", "terribly",   "thankfully",
                   "thoroughly", "tightly",    "totally",    "trivially",  "truly",      "typically",  "ultimately",
                   "unduly",     "uniformly",  "uniquely",   "unlikely",   "urgently",   "usefully",   "usually",
                   "utterly",    "vaguely",    "vastly",     "verbally",   "vertically", "vigorously", "violently",
                   "virtually",  "visually",   "weekly",     "wholly",     "widely",     "wildly",     "willingly",
                   "wrongly",    "yearly"}}
    {
    }
};

struct petname_dictionary_short : petname_dictionary {
    petname_dictionary_short()
    {
        adverbs.clear();
    }
};

class dictionary {
    struct data {
        std::vector<std::string> nouns;
        std::vector<std::string> adjectives;
        std::vector<std::string> adverbs;
    };

public:
    dictionary(dictionary_preset preset)
        : data_{preset}
    {
    }

    dictionary(
            std::vector<std::string> nouns,
            std::vector<std::string> adjectives = {},
            std::vector<std::string> adverbs = {})
        : data_{data{std::move(nouns), std::move(adjectives), std::move(adverbs)}}

    {
    }

    std::string_view noun(int index) const
    {
        return std::visit(
                [&](const auto& data)
                {
                    return std::string_view{data.nouns.at(index)};
                },
                data_);
    }

    std::string_view adjective(int index) const
    {
        return std::visit(
                [&](const auto& data)
                {
                    return std::string_view{data.adjectives.at(index)};
                },
                data_);
    }

    std::string_view adverb(int index) const
    {
        return std::visit(
                [&](const auto& data)
                {
                    return std::string_view{data.adverbs.at(index)};
                },
                data_);
    }

    int noun_count() const
    {
        return std::visit(
                [&](const auto& data)
                {
                    return static_cast<int>(data.nouns.size());
                },
                data_);
    }

    int adjective_count() const
    {
        return std::visit(
                [&](const auto& data)
                {
                    return static_cast<int>(data.adjectives.size());
                },
                data_);
    }

    int adverb_count() const
    {
        return std::visit(
                [&](const auto& data)
                {
                    return static_cast<int>(data.adverbs.size());
                },
                data_);
    }

private:
    std::variant<dictionary_preset, data> data_;
};

template<typename RandomNumberGenerator>
using token_generator = std::function<std::string(std::string_view, RandomNumberGenerator&)>;

struct empty_token_generator {
    template<typename RandomNumberGenerator>
    std::string operator()(std::string_view, RandomNumberGenerator&) const
    {
        return {};
    }
};

template<int tokenLength = 5>
struct alphabetic_token_generator {
    template<typename RandomNumberGenerator>
    std::string operator()(std::string_view, RandomNumberGenerator& randomNumberGenerator) const
    {
        static const auto letters = std::string{"abcdefghijklmnopqrstuvwxyz"};
        auto token = std::string{};
        token.reserve(tokenLength);
        for (int i = 0; i < tokenLength; ++i) {
            const auto randomLetterIndex =
                    random::uniform_int_distribution{0, static_cast<int>(letters.size() - 1)}(randomNumberGenerator);
            token += letters.at(randomLetterIndex);
        }
        return token;
    }
};

template<int tokenLength = 5>
struct alphanumeric_token_generator {
    template<typename RandomNumberGenerator>
    std::string operator()(std::string_view, RandomNumberGenerator& randomNumberGenerator) const
    {
        static const auto letters = std::string{"abcdefghijklmnopqrstuvwxyz1234567890"};
        auto token = std::string{};
        token.reserve(tokenLength);
        for (int i = 0; i < tokenLength; ++i) {
            const auto randomLetterIndex =
                    random::uniform_int_distribution{0, static_cast<int>(letters.size() - 1)}(randomNumberGenerator);
            token += letters.at(randomLetterIndex);
        }
        return token;
    }
};

enum class number_string_format {
    decimal,
    zero_padded_decimal,
    hexadecimal,
    zero_padded_hexadecimal
};

template<int tokenLength = 5, number_string_format tokenNumberFormat = number_string_format::decimal>
struct number_token_generator {
    template<typename RandomNumberGenerator>
    std::string operator()(std::string_view, RandomNumberGenerator& randomNumberGenerator) const
    {
        const auto base = (tokenNumberFormat == number_string_format::hexadecimal ||
                           tokenNumberFormat == number_string_format::zero_padded_hexadecimal)
                ? 16
                : 10;
        const auto max_value = std::pow(base, tokenLength) - 1;
        const auto value = random::uniform_int_distribution<unsigned long long>(
                0,
                static_cast<unsigned long long>(max_value))(randomNumberGenerator);

        auto ss = std::stringstream{};
        if constexpr (tokenNumberFormat == number_string_format::decimal)
            ss << value;
        else if constexpr (tokenNumberFormat == number_string_format::zero_padded_decimal)
            ss << std::setw(tokenLength) << std::setfill('0') << value;
        else if constexpr (tokenNumberFormat == number_string_format::hexadecimal)
            ss << std::hex << value;
        else if constexpr (tokenNumberFormat == number_string_format::zero_padded_hexadecimal)
            ss << std::hex << std::setw(tokenLength) << std::setfill('0') << value;

        return ss.str();
    }
};

struct user_dictionary {};

template<typename RandomNumberGenerator, typename DictionaryPreset = user_dictionary>
class mnemonic_id_generator {
public:
    template<
            typename TCheckPreset = DictionaryPreset,
            std::enable_if_t<std::is_same_v<TCheckPreset, user_dictionary>>* = nullptr>
    mnemonic_id_generator(
            RandomNumberGenerator& randomNumberGenerator,
            dictionary dictionary,
            token_generator<RandomNumberGenerator> tokenGenerator = empty_token_generator{},
            std::string delimiter = "-")
        : randomNumberGenerator_(randomNumberGenerator)
        , dictionary_(std::move(dictionary))
        , tokenGenerator_(std::move(tokenGenerator))
        , delimiter_(std::move(delimiter))
    {
    }

    template<
            typename TCheckPreset = DictionaryPreset,
            std::enable_if_t<!std::is_same_v<TCheckPreset, user_dictionary>>* = nullptr>
    mnemonic_id_generator(
            RandomNumberGenerator& randomNumberGenerator,
            token_generator<RandomNumberGenerator> tokenGenerator = empty_token_generator{},
            std::string delimiter = "-")
        : randomNumberGenerator_(randomNumberGenerator)
        , dictionary_(DictionaryPreset{})
        , tokenGenerator_(std::move(tokenGenerator))
        , delimiter_(std::move(delimiter))
    {
    }

    std::string operator()()
    {

        const auto randomNoun = [&]() -> std::string_view
        {
            if (dictionary_.noun_count() == 0)
                return {};

            const auto randomNounIndex =
                    random::uniform_int_distribution{0, dictionary_.noun_count() - 1}(randomNumberGenerator_.get());
            return dictionary_.noun(randomNounIndex);
        }();
        const auto randomAdjective = [&]() -> std::string_view
        {
            if (dictionary_.adjective_count() == 0)
                return {};

            const auto randomAdjectiveIndex = random::uniform_int_distribution{0, dictionary_.adjective_count() - 1}(
                    randomNumberGenerator_.get());
            return dictionary_.adjective(randomAdjectiveIndex);
        }();

        const auto randomAdverb = [&]() -> std::string_view
        {
            if (dictionary_.adverb_count() == 0)
                return {};

            const auto randomAdverbIndex =
                    random::uniform_int_distribution{0, dictionary_.adverb_count() - 1}(randomNumberGenerator_.get());
            return dictionary_.adverb(randomAdverbIndex);
        }();

        const auto phrase = eel::concat(
                randomAdverb,
                std::string_view{randomAdverb.empty() ? "" : delimiter_},
                randomAdjective,
                std::string_view{randomAdjective.empty() ? "" : delimiter_},
                randomNoun);
        const auto token = tokenGenerator_(phrase, randomNumberGenerator_.get());
        return eel::concat(phrase, std::string_view{token.empty() ? "" : delimiter_}, token);
    }

private:
    eel::ref<RandomNumberGenerator> randomNumberGenerator_;
    dictionary dictionary_;
    token_generator<RandomNumberGenerator> tokenGenerator_;
    std::string delimiter_;
};

//Dictionary is from https://github.com/Atrox/haikunatorjs
template<typename UniformRandomNumberGenerator>
using heroku_id_generator = mnemonic_id_generator<UniformRandomNumberGenerator, heroku_dictionary>;

enum class petname_format {
    short_name,
    long_name
};

//Dictionary is from https://github.com/dustinkirkland/python-petname
template<typename UniformRandomNumberGenerator, petname_format format = petname_format::short_name>
using petname_id_generator = mnemonic_id_generator<
        UniformRandomNumberGenerator,
        std::conditional_t<format == petname_format::long_name, petname_dictionary, petname_dictionary_short>>;

} //namespace mnemocean

#endif // MNEMOCEAN_H