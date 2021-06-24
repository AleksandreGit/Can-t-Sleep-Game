#pragma once
#include <queue>
#include <array>
#include <assert.h>
#include "Entity.h"
#include "Signature.h"

/**
* CLASS EntityManager
* TODO : describe this class
*/
class EntityManager {
public:

	/**
	* Constructor
	* Initialize the queue with all possible entity IDs
	*/
	EntityManager() {
		m_livingEntityCount = 0;
		for (Entity entity = 0; entity < MAX_ENTITIES; entity++) {
			m_availableEntities.push(entity);
		}
	}

	/**
	* Get an available id in the list of entity ids and returns it
	* 
	* @return the created entity
	*/
	Entity createEntity() {
		assert(m_livingEntityCount < MAX_ENTITIES && "Too many entities");

		Entity id = m_availableEntities.front();
		m_availableEntities.pop();
		m_livingEntityCount++;

		return id;
	}

	/**
	* Destroy an existing entity
	* 
	* @param entity : the entity to destroy
	*/
	void destroyEntity(Entity entity) {
		assert(entity < MAX_ENTITIES && "Entity out of range");

		// Invalidate the destroyed entity's signature
		m_signatures[entity].reset();

		// Put the destroyed ID at the back of the queue
		m_availableEntities.push(entity);
		m_livingEntityCount--;
	}

	/**
	* Set the signature of a given entity
	* 
	* @param entity : the entity to which change the signature
	* @param signature : the new signature
	*/
	void setSignature(Entity entity, Signature signature) {
		assert(entity < MAX_ENTITIES && "Entity out of range");

		m_signatures[entity] = signature;
	}

	/**
	* Get the signature of a given entity
	* 
	* @param entity : the entity to which get the signature
	*/
	Signature getSignature(Entity entity) {
		assert(entity < MAX_ENTITIES && "Entity out of range");

		return m_signatures[entity];
	}

private:
	// Queue of unused entity IDs
	std::queue<Entity> m_availableEntities{};

	// Array of signatures where the index corresponds to the entity ID
	std::array<Signature, MAX_ENTITIES> m_signatures{};
	
	// Total living entities
	uint32_t m_livingEntityCount;
};