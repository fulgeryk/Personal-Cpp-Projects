#ifndef _ENTITY_MANAGER_HPP_
#define _ENTITY_MANAGER_HPP_

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

    Entity& createEntity(float x, float y, float width, float height);

    const std::vector<std::unique_ptr<Entity>>& getEntities() const;

    void removeInactiveEntities();
private:
    std::vector<std::unique_ptr<Entity>> entities_;
};
#endif /* _ENTITYH_MANAGER_HPP_ */