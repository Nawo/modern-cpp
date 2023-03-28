#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numbers>
#include <string>
#include <vector>
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Shape.hpp"
#include "Square.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

auto sortByArea = [](shared_ptr<Shape> first, shared_ptr<Shape> second) {
    if (first == nullptr || second == nullptr)
        return false;
    return (first->getArea() < second->getArea());
};

auto perimeterBiggerThan20 = [](shared_ptr<Shape> s) {
    if (s)
        return (s->getPerimeter() > 20);
    return false;
};

auto areaLessThanX = [i = 10](shared_ptr<Shape> s) mutable -> bool {
    if (s)
        return (s->getArea() < i);
    return false;
};

auto printCollectionElements = [](const Collection& collection) {
    for (Collection::const_iterator it = collection.begin(); it != collection.end(); ++it)
        if (*it)
            (*it)->print();
};

auto printAreas = [](const Collection& collection) {
    for (vector<shared_ptr<Shape>>::const_iterator it = collection.begin(); it != collection.end(); ++it)
        if (*it)
            cout << (*it)->getArea() << std::endl;
};

auto findFirstShapeMatchingPredicate = [](const Collection& collection, std::function<bool(shared_ptr<Shape>)> predicate, std::string info) {
    Collection::const_iterator iter = std::find_if(collection.begin(), collection.end(), predicate);
    if (*iter != 0) {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    } else {
        cout << "There is no shape matching predicate " << info << endl;
    }
};

bool operator==(const shared_ptr<Shape>& lhs, const shared_ptr<Shape>& rhs) {
    return lhs->getPerimeter() == rhs->getPerimeter();
}

bool operator<(const shared_ptr<Shape>& lhs, const shared_ptr<Shape>& rhs) {
    return lhs->getPerimeter() < rhs->getPerimeter();
}

int main() {
    Collection shapes = {make_shared<Circle>(2.0), make_shared<Circle>(3.0), make_shared<Circle>(4.0), make_shared<Rectangle>(10.0, 5.0),
                         make_shared<Square>(3.0), make_shared<Circle>(4.0)};

    shapes.push_back(make_shared<Circle>(Color::BLUE));
    shapes.push_back(make_shared<Circle>(12.0));
    shapes.push_back(make_shared<Rectangle>(Color::GREEN));
    shapes.push_back(make_shared<Square>(Color::GREEN));

    std::map<std::shared_ptr<Shape>, double> shapes_map;
    std::transform(shapes.begin(), shapes.end(), std::inserter(shapes_map, shapes_map.begin()),
                   [](const std::shared_ptr<Shape>& a) {
                       auto perimeter = 0.0;
                       if (a) {
                           perimeter = a->getPerimeter();
                       }
                       return std::make_pair(a, perimeter);
                   });

    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    std::cout << "Rozmiar struktury danych: " << alignof(Circle) << std::endl;

    for (const auto& [key, value] : shapes_map) {
        std::cout << "Key: " << key << " | value: " << value << std::endl;
    }

    return 0;
}
