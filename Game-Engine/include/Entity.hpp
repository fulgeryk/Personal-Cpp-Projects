#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Component.hpp"
#include <vector>
#include <memory>
#include <utility>
#include <type_traits>

class Entity
{
public:
    Entity() = default;
    
    Entity(const Entity&) = delete;
    Entity& operator=(const Entity&) = delete;

    Entity(Entity&& other) noexcept = default;
    Entity& operator=(Entity&& other) noexcept = default;

    virtual ~Entity() = default;

    bool isActive() const;

    template<typename T, typename... Args>
    T& addComponent(Args&&... args)
    {
        static_assert(std::is_base_of_v<Component, T>, "T must inherit from Component");
        auto component = std::make_unique<T>(std::forward<Args>(args)...);
        T& ref = *component;
        components_.push_back(std::move(component));
        return ref;
    }

    template<typename T>
    T* getComponent()
    {
        static_assert(std::is_base_of_v<Component, T>, "T must inherit from Component");
        for(auto& component : components_)
        {
            auto* comp = dynamic_cast<T*>(component.get());
            if(comp != nullptr)
            {
                return comp;
            }
        }
        return nullptr;
    }
    
    void setActive(bool active);
private:
    bool active_{true};
    std::vector<std::unique_ptr<Component>> components_;
};

#endif /* ENTITY_HPP */