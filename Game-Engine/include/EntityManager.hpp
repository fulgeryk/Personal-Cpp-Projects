#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include "Entity.hpp"
#include <memory>
#include <vector>
#include <algorithm>

class EntityManager
{
public:
    EntityManager() = default;
    ~EntityManager() = default;

    EntityManager(const EntityManager&) = delete;
    EntityManager& operator=(const EntityManager&) = delete;

    EntityManager(EntityManager&&) = delete;
    EntityManager& operator=(EntityManager&&) = delete;

    Entity& createEntity();

    const std::vector<std::unique_ptr<Entity>>& getEntities() const;

    void removeInactiveEntities();
private:
    std::vector<std::unique_ptr<Entity>> entities_;
};
#endif /* ENTITYH_MANAGER_HPP */