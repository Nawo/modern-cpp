#pragma once
#include <iostream>
#include <memory>

enum class Color : unsigned char {
    RED,
    BLUE,
    GREEN
};

std::ostream& operator<<(std::ostream& os, Color c);

class Shape {
public:
    Shape();
    Shape(Color c);
    virtual ~Shape();

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;

public:
    Color color = Color::RED;
};
