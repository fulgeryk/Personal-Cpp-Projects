#ifndef _COMPONENT_HPP_
#define _COMPONENT_HPP_

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
#endif /* _COMPONENT_HPP_ */