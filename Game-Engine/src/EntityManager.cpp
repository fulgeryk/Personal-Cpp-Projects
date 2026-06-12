#include "EntityManager.hpp"

Entity& EntityManager::createEntity(float x, float y, float width, float height)
{
    auto entity = std::make_unique<Entity>(x,y,width,height);
    Entity& ref = *entity;
    entities_.push_back(std::move(entity));
    return ref;
}
const std::vector<std::unique_ptr<Entity>>& EntityManager::getEntities() const
{
    return entities_;
}
void EntityManager::removeInactiveEntities()
{
    entities_.erase(
        std::remove_if(
            entities_.begin(),
            entities_.end(),
            [](const std::unique_ptr<Entity>& entity)
            {
                return !entity->isActive();
            }),
        entities_.end()
    );
}