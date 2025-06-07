#include <iostream>
#include <memory>
#include <string>

class Character{
public:
    std::string name;
    std::string classType;
    int health = 100;
    int mana = 50;
    int strength = 10;
    int intelligence = 10;

    void showStats() const{
        std::cout << "Character: " << name << " (" << classType << ")\n"
        << " HP: " << health << ", Mana: " << mana << "\n"
        << " STR: " << strength << ", INT: " << intelligence << "\n";
    }
};

class CharacterBuilder{
public: 
    virtual ~CharacterBuilder() = default;
    virtual CharacterBuilder& setName(const std::string&) = 0;
    virtual CharacterBuilder& setStats() = 0;
    virtual std::unique_ptr<Character> build() = 0;
};

class WarriorBuilder : public CharacterBuilder{
    std::unique_ptr<Character> character = std::make_unique<Character>();

public: 
    CharacterBuilder& setName(const std::string& n) override{
        character->name = n;
        character->classType = "Warrior";
        return *this;
    }

    CharacterBuilder& setStats() override{
        character->health = 150;
        character->mana = 20;
        character->strength = 50;
        character->intelligence = 10;
        return *this;
    }

    std::unique_ptr<Character> build() override{
        return std::move(character);
    }
};

 class MageBuilder : public CharacterBuilder{
    std::unique_ptr<Character> character = std::make_unique<Character>();

public:
    CharacterBuilder& setName(const std::string& n) override{
        character->name = n;
        character->classType = "Mage";
        return *this;
    }

    CharacterBuilder& setStats() override{
        character->health = 90;
        character->mana = 50;
        character->strength = 20;
        character->intelligence = 30;
        return *this;
    }

    std::unique_ptr<Character> build() override{
        return std::move(character);
    }
 };


class CharacterDirector{
public: 
    std::unique_ptr<Character> createWarrior(CharacterBuilder& builder, const std::string& name){
        return builder.setName(name).setStats().build();
    }

    std::unique_ptr<Character> createMage(CharacterBuilder& builder, const std::string& name){
        return builder.setName(name).setStats().build();
    }
 };


 int main(){
    CharacterDirector director;

    WarriorBuilder warriorBuilder;
    MageBuilder mageBuilder;

    auto war = director.createWarrior(warriorBuilder, "Ragnar");
    auto mage = director.createMage(mageBuilder, "Marlin");

    war->showStats();
    std::cout << "\n";
    mage->showStats();
 }