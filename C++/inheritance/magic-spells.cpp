#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <string_view>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal{""};
        static string read() {
            return journal;
        }
}; 

[[nodiscard]] auto LCS_TopDown(std::string_view first, std::string_view second) -> unsigned {
    assert(!first.empty() && !second.empty());
    auto matching_character_matrix = std::vector<std::vector<unsigned>>(first.size() + 1,
                                                                        std::vector<unsigned>(second.size() + 1));

    for (auto i = std::size_t{1}; i < first.size() + 1; i++) {
        for (auto j = std::size_t{1}; j < second.size() + 1; j++) {
            if (first.at(i - 1) == second.at(j - 1)) {
                matching_character_matrix.at(i).at(j) = 1 + matching_character_matrix.at(i - 1).at(j - 1);
            }
            else {
                matching_character_matrix.at(i).at(j) = std::max(matching_character_matrix.at(i).at(j - 1),
                                                                 matching_character_matrix.at(i - 1).at(j));
            }
        }
    }

    return matching_character_matrix.back().back();
}

void counterspell(Spell *spell) {
    if (auto* fireball = dynamic_cast<Fireball*>(spell); fireball != nullptr) {
        fireball->revealFirepower();
    }
    else if (auto* frostbite = dynamic_cast<Frostbite*>(spell); frostbite != nullptr) {
        frostbite->revealFrostpower();
    }
    else if (auto* thunderstorm = dynamic_cast<Thunderstorm*>(spell); thunderstorm != nullptr) {
        thunderstorm->revealThunderpower();
    }
    else if (auto* waterbolt = dynamic_cast<Waterbolt*>(spell); waterbolt != nullptr) {
        waterbolt->revealWaterpower();
    }
    else {
        std::cout << LCS_TopDown(spell->revealScrollName(), SpellJournal::read()) << '\n';
    }
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}