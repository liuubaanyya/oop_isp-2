#include <iostream>
#include <vector>

class Component {
public:
    virtual void operation() const = 0;
};

class Leaf : public Component {
public:
    void operation() const override {
        std::cout << "Виконання операції на листку" << std::endl;
    }
};

class Composite : public Component {
private:
    std::vector<Component*> children;

public:
    void add(Component* component) {
        children.push_back(component);
    }

    void operation() const override {
        std::cout << "Виконання операції на складовому об'єкті" << std::endl;
        
        for (const auto& child : children) {
            child->operation();
        }
    }
};

int main() {
    Composite composite;
    Leaf leaf1;
    Leaf leaf2;
    Leaf leaf3;

    composite.add(&leaf1);
    composite.add(&leaf2);
    composite.add(&leaf3);

    composite.operation();

    return 0;
}
