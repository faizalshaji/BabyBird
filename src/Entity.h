#pragma once
#include <unordered_map>
#include <memory>
#include <typeindex>

class Entity {
public:
    using ComponentID = std::type_index;

    template <typename T>
    void addComponent(std::shared_ptr<T> component) {
        components[typeid(T)] = component;
    }

    template <typename T>
    std::shared_ptr<T> getComponent() {
        auto it = components.find(typeid(T));
        if (it != components.end()) {
            return std::static_pointer_cast<T>(it->second);
        }
        return nullptr;
    }

private:
    std::unordered_map<ComponentID, std::shared_ptr<void>> components;
};
