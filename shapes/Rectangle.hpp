#pragma once

#include "Shape.hpp"

class Rectangle : public Shape {
public:
    using Shape::Shape;
    Rectangle() = delete;

    Rectangle(double x, double y);
    Rectangle(const Rectangle& other) = default;

    virtual double getArea() const noexcept override;
    virtual double getPerimeter() const noexcept override;
    virtual double getX() const final;
    double getY() const;
    virtual void print() const override;

private:
    double x_ = 1.0;
    double y_ = 1.0;
};
