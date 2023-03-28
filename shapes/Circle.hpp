#pragma once

#include "Shape.hpp"

class alignas(128) Circle final : public Shape {
public:
    using Shape::Shape;

    Circle() = delete;

    Circle(double r);
    Circle(const Circle& other) = default;

    [[deprecated("Przestarzala")]] double getPi() const;

    double getArea() const override;
    double getPerimeter() const override;
    double getRadius() const;
    void print() const override;

public:
    double r_ = 1.0;
    Color color = Shape::color;
};
