#include <iostream>

class Visitor;

class Element {
public:
    virtual void accept(Visitor& visitor) = 0;
};

class ConcreteElementA : public Element {
public:
    void accept(Visitor& visitor) override;
    void operationA() {
        std::cout << "Операція на ConcreteElementA" << std::endl;
    }
};

class ConcreteElementB : public Element {
public:
    void accept(Visitor& visitor) override;
    void operationB() {
        std::cout << "Операція на ConcreteElementB" << std::endl;
    }
};

class Visitor {
public:
    virtual void visit(ConcreteElementA& element) = 0;
    virtual void visit(ConcreteElementB& element) = 0;
};

class ConcreteVisitor : public Visitor {
public:
    void visit(ConcreteElementA& element) override {
        element.operationA();
    }

    void visit(ConcreteElementB& element) override {
        element.operationB();
    }
};

void ConcreteElementA::accept(Visitor& visitor) {
    visitor.visit(*this);
}

void ConcreteElementB::accept(Visitor& visitor) {
    visitor.visit(*this);
}

int main() {
    ConcreteElementA elementA;
    ConcreteElementB elementB;

    ConcreteVisitor visitor;
    elementA.accept(visitor);
    elementB.accept(visitor);

    return 0;
}
