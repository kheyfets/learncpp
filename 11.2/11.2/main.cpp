#include <iostream>
#include <string>

class Fruit {
private:
    std::string m_name;
    std::string m_color;
    
public:
    Fruit(std::string name, std::string color) {
        m_name = name;
        m_color = color;
    }
    
    std::string getName() {
        return m_name;
    }
    
    std::string getColor() {
        return m_color;
    }
};

class Apple: public Fruit {
protected:
    Apple(std::string name, std::string color)
    : Fruit(name, color) {}
    
public:
    Apple(std::string color = "red")
    : Fruit("apple", color) {}
};

class Banana : public Fruit {
public:
    Banana()
    : Fruit("banana", "yellow") {}
};

class GrannySmith : public Apple {
public:
    GrannySmith()
    : Apple("granny smith apple", "green") {}
};

int main() {
    Apple a("red");
    Banana b;
    GrannySmith c;
    
    std::cout << "My " << a.getName() << " is " << a.getColor() << "." << std::endl;
    std::cout << "My " << b.getName() << " is " << b.getColor() << "." << std::endl;
    std::cout << "My " << c.getName() << " is " << c.getColor() << "." << std::endl;
}
