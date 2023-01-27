#pragma once

enum class Color : unsigned char
{
    RED,
    BLUE,
    GREEN
};

class Shape
{

    Color color = Color::RED;

public:
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
};
