#include <iostream>

using namespace std;

class Animal {
   private:
    string name;

   public:
    Animal(string name);
    string getName();
};

Animal::Animal(string name) { this->name = name; }

string Animal::getName() {
    cout << "name = " << this->name << "\n";
    return this->name;
}

class Dog : public Animal {
   public:
    Dog(string name) : Animal(name) {};
};

int main(int argc, char const *argv[]) {
    // Dog dog;

    Animal animal("animal");
    string animalName = animal.getName();
    cout << "animalName: " << animalName << "\n";

    Dog dog("dog");
    string dogName = dog.getName();
    cout << "dogName: " << dogName << "\n";
}
