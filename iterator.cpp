#include <iostream>
#include <vector>

class Iterator {
public:
    virtual int next() = 0;
    virtual bool hasNext() const = 0;
};

class ConcreteIterator : public Iterator {
private:
    std::vector<int> data;
    int position;

public:
    ConcreteIterator(const std::vector<int>& collection) : data(collection), position(0) {}

    int next() override {
        return data[position++];
    }

    bool hasNext() const override {
        return position < data.size();
    }
};

class Collection {
private:
    std::vector<int> data;

public:
    void add(int item) {
        data.push_back(item);
    }

    Iterator* createIterator() {
        return new ConcreteIterator(data);
    }
};

int main() {
    Collection collection;
    collection.add(1);
    collection.add(2);
    collection.add(3);

    Iterator* iterator = collection.createIterator();
    while (iterator->hasNext()) {
        std::cout << iterator->next() << " ";
    }

    delete iterator;

    return 0;
}
