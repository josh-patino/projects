//
//  EntityComponentSystem.hpp
//  2D_Game
//
//  Created by Joshua Patino on 2/8/23.
//
#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>

class Component;
class Entity;

using ComponentID = std::size_t;

// Let's hide implementation details into an "Internal" namespace:
namespace Internal {
    inline ComponentID getUniqueComponentID() noexcept{
            static ComponentID lastID{0u};
            return lastID++;
        }
}

template <typename T>
inline ComponentID getComponentTypeID() noexcept {
        // We an use a `static_assert` to make sure this function
        // is only called with types that inherit from `Component`.
        static_assert(std::is_base_of<Component, T>::value,"T must inherit from Component");

        static ComponentID typeID{Internal::getUniqueComponentID()};
        return typeID;
}

// Let's define a maximum number of components:
constexpr std::size_t maxComponents{32};

// Let's typedef an `std::bitset` for our components:
using ComponentBitset = std::bitset<maxComponents>;

// And let's also typedef an `std::array` for them:
using ComponentArray = std::array<Component*, maxComponents>;

class Component {
public:
    Entity* entity;
    
    virtual void init(){}
    virtual void update(){}
    virtual void draw(){}
    
    virtual ~Component(){}
};

class Entity {
private:
    bool alive = true;
    std::vector<std::unique_ptr<Component>> components;
    
    ComponentArray componentArray; //quickly get component with ID
    ComponentBitset componentBitset; //check if the component exists
public:
    void update(){ for(auto& c : components) c->update(); }
    void draw() { for(auto& c : components) c->draw(); }
    bool isAlive() const {return alive;}
    void destroy() {alive = false;}
    //check if entity has a componenet, query the bit set
    template<typename T>
    bool hasComponent() const {
        return componentBitset[getComponentTypeID<T>()];
    }
    
    template <typename T, typename... TArgs> //typname... -> parameter packs, zero or more arguments accepted
    T& addComponent(TArgs&&... mArgs){
        //use assert to check if component doesnt already exist before adding
        assert(!hasComponent<T>());
        //adding component
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uniquePtr{c};
        components.emplace_back(std::move(uniquePtr));;
        
        //when adding component of type T, add it to bitset and to the array for checking
        componentArray[getComponentTypeID<T>()] = c;
        componentBitset[getComponentTypeID<T>()] = true;
        
        //can init component
        c->init();
        return *c;
    }
    template <typename T>
    T& getComponent() const {
        //check if compoennt exists
        assert(hasComponent<T>());
        
        auto pointer(componentArray[getComponentTypeID<T>()]);
        return *static_cast<T*>(pointer);
        //this allows for the unity equivalent gameObject.getComponent<PositionComponent>().setXpos(69)
    }
};

class Manager {
private:
    std::vector<std::unique_ptr<Entity>> entities;
public:
    void update() { for(auto& e : entities) e->update(); }
    void draw() {for(auto& e : entities) e->draw(); }
    
    void refresh(){
        entities.erase( //remove entities if they are not alive
                std::remove_if(std::begin(entities), std::end(entities),
                [](const std::unique_ptr<Entity>& mEntity){
                    return !mEntity->isAlive();
                }), std::end(entities));
    }
    
    Entity& addEntity(){
        Entity* e = new Entity();
        std::unique_ptr<Entity> uniquePtr{e};
        entities.emplace_back(std::move(uniquePtr));
        return *e;
        
    }
};

