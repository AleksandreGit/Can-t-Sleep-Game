#pragma once
#include "Signature.h"
#include "System.h"
#include "ComponentManager.h"

/**
* CLASS SystemManager
* TODO : describe the class
*/
class SystemManager {
public:

	/**
	* Register a system
	*/
	template<typename T>
	std::shared_ptr<T> registerSystem()
	{
		const char* typeName = typeid(T).name();

		assert(m_systems.find(typeName) == m_systems.end() && "Registering system more than once.");

		// Create a pointer to the system and return it so it can be used externally
		auto system = std::make_shared<T>();
		m_systems.insert({ typeName, system });
		return system;
	}

	/**
	* Set the signature of the system
	* The signature consists of a combination of the signatures
	* of the components with which it interacts
	* 
	* @param signature : the signature
	*/
	template<typename T>
	void setSignature(Signature signature)
	{
		const char* typeName = typeid(T).name();

		assert(m_systems.find(typeName) != m_systems.end() && "System used before registered.");

		// Set the signature for this system
		m_signatures.insert({ typeName, signature });
	}

	/**
	* Delete an entity into the list of all the systems after it was destroyed
	* 
	* @param entity : the destroyed entity
	*/
	void entityDestroyed(Entity entity)
	{
		// Erase a destroyed entity from all system lists
		// m_entities is a set so no check needed
		for (auto const& pair : m_systems)
		{
			auto const& system = pair.second;

			system->m_entities.erase(entity);
		}
	}

	/**
	* Change the signature of a given entity in all the systems
	* 
	* @param entity : the entity whom signature has been changed
	* @param entitySignature : the new signature
	*/
	void entitySignatureChanged(Entity entity, Signature entitySignature)
	{
		// Notify each system that an entity's signature changed
		for (auto const& pair : m_systems)
		{
			auto const& type = pair.first;
			auto const& system = pair.second;
			auto const& systemSignature = m_signatures[type];

			// Entity signature matches system signature - insert into set
			if ((entitySignature & systemSignature) == systemSignature)
			{
				system->m_entities.insert(entity);
			}
			// Entity signature does not match system signature - erase from set
			else
			{
				system->m_entities.erase(entity);
			}
		}
	}

private:
	// Map from system type string pointer to a signature
	std::unordered_map<const char*, Signature> m_signatures{};

	// Map from system type string pointer to a system pointer
	std::unordered_map<const char*, std::shared_ptr<System>> m_systems{};
};