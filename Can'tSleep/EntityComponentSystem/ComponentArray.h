#pragma once
#include "Entity.h"
#include <array>
#include <unordered_map>

/* 
An interface is needed so that the ComponentManager 
can tell a generic ComponentArray that an entity has been destroyed
and that it needs to update its array mappings.
*/
class IComponentArray {
public:
	virtual ~IComponentArray() = default;
	virtual void entityDestroyed(Entity entity) = 0;
};

/**
* CLASS ComponentArray
* Class linked to a certain Component to contain all of its iterations
*/
template<typename T>
class ComponentArray : public IComponentArray {
public:

	/**
	* Add a component to an entity
	* 
	* @param entity : the entity to which to add the component
	* @param component : the component to add
	*/
	void insertData(Entity entity, T component) {
		assert(m_entityToIndexMap.find(entity) == m_entityToIndexMap.end() && "Component added to same entity more than once.");

		// Put new entry at end and update the maps
		size_t newIndex = m_size;
		m_entityToIndexMap[entity] = newIndex;
		m_indexToEntityMap[newIndex] = entity;
		m_componenArray[newIndex] = component;
		++m_size;
	}

	/**
	* Remove the component to the entity
	* 
	* @param entity : the entity to which delete the component
	*/
	void removeData(Entity entity)
	{
		assert(m_entityToIndexMap.find(entity) != m_entityToIndexMap.end() && "Removing non-existent component.");

		// Copy element at end into deleted element's place to maintain density
		size_t indexOfRemovedEntity = m_entityToIndexMap[entity];
		size_t indexOfLastElement = m_size - 1;
		m_componentArray[indexOfRemovedEntity] = m_componentArray[indexOfLastElement];

		// Update map to point to moved spot
		Entity entityOfLastElement = m_indexToEntityMap[indexOfLastElement];
		m_entityToIndexMap[entityOfLastElement] = indexOfRemovedEntity;
		m_indexToEntityMap[indexOfRemovedEntity] = entityOfLastElement;

		m_entityToIndexMap.erase(entity);
		m_indexToEntityMap.erase(indexOfLastElement);

		--m_size;
	}

	/**
	* Return the component linked to the given entity
	* 
	* @param entity : the entity from which we want the component value
	*/
	T& getData(Entity entity)
	{
		assert(m_entityToIndexMap.find(entity) != m_entityToIndexMap.end() && "Retrieving non-existent component.");

		// Return a reference to the entity's component
		return m_componentArray[m_entityToIndexMap[entity]];
	}

	/**
	* Remove the entity's component if it existed into the array
	* 
	* @param entity : the destroyed entity
	*/
	void entityDestroyed(Entity entity) override
	{
		if (m_entityToIndexMap.find(entity) != m_entityToIndexMap.end())
		{
			removeData(entity);
		}
	}

private:

	/* The packed array of components (of generic type T),
	set to a specified maximum amount, matching the maximum number
	of entities allowed to exist simultaneously, so that each entity
	has a unique spot. */
	std::array<T, MAX_ENTITIES> m_componentArray;

	// Map from an entity ID to an array index.
	std::unordered_map<Entity, size_t> m_entityToIndexMap;

	// Map from an array index to an entity ID.
	std::unordered_map<size_t, Entity> m_indexToEntityMap;
	
	// Total size of valid entries in the array.
	size_t m_size;
};
