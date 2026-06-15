#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

#include "Component.hpp"
#include <vector>
#include <memory>
#include <utility>

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
        auto component = std::make_unique<T>(std::forward<Args>(args)...);
        T& ref = *component;
        components_.push_back(std::move(component));
        return ref;
    }

    template<typename T>
    T* getComponent()
    {
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

#endif /* _ENTITY_HPP_ */