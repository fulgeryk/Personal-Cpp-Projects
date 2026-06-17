#ifndef COMPONENT_HPP
#define COMPONENT_HPP

class Component
{
public:
    Component() = default;
    virtual ~Component() = default;

    Component(const Component&) = delete;
    Component& operator=(const Component&) = delete;

    Component(Component&&) noexcept = default;
    Component& operator=(Component&&) noexcept = default;
};
#endif /* COMPONENT_HPP */