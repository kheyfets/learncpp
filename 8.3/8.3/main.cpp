#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

class Monster {
public:
    enum MonsterType {
        Dragon,
        Goblin,
        Ogre,
        Orc,
        Skeleton,
        Troll,
        Vampire,
        Zombie,
        MAX_MONSTER_TYPES
    };
    
private:
    MonsterType m_type;
    std::string m_name;
    std::string m_roar;
    int m_hitPoints;
    
public:
    Monster(MonsterType type, std::string name, std::string roar, int hitPoints) {
        m_type = type;
        m_name = name;
        m_roar = roar;
        m_hitPoints = hitPoints;
    }
    
    std::string getTypeString() {
        switch (m_type) {
            case Dragon:
                return "dragon";
            case Goblin:
                return "goblin";
            case Ogre:
                return "ogre";
            case Orc:
                return "orc";
            case Skeleton:
                return "skeleton";
            case Troll:
                return "troll";
            case Vampire:
                return "vampire";
            case Zombie:
                return "zombie";
        }
        
        return "unknown";
    }
    
    void print() {
        std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << std::endl;
    }
};

class MonsterGenerator {
public:
    static int getRandomNumber(int min, int max) {
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
        return static_cast<int>(rand() * fraction * (max - min + 1) + min);
    }
    
    static Monster generateMonster() {
        Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1));
        int hitPoints = getRandomNumber(1, 100);
        
        // these are static so they are only initalized once
        static std::string s_names[6]{ "Blarg", "Moog", "Pksh", "Tyrn", "Mort", "Hans" };
        static std::string s_roars[6]{ "*roar*", "*peep*", "*squeal*", "*whine*", "*hum*", "*burp*"};
        
        return Monster(type, s_names[getRandomNumber(0, 5)], s_roars[getRandomNumber(0, 5)], hitPoints);
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));
    rand();
    
    Monster m = MonsterGenerator::generateMonster();
    m.print();
}
