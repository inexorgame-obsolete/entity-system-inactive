// Inexor entity system
// (c)2018 Inexor

#include "TrigonometricTypeSystemManager.hpp"

using namespace inexor::entity_system;
using namespace std;

namespace inexor {
namespace entity_system {
namespace type_system {

	TrigonometricTypeSystemManager::TrigonometricTypeSystemManager(
		shared_ptr<SinEntityTypeProvider> sin_entity_type_provider,
		shared_ptr<SinFactory> sin_factory
	)
	{
		this->sin_entity_type_provider = sin_entity_type_provider;
		this->sin_factory = sin_factory;
	}

	TrigonometricTypeSystemManager::~TrigonometricTypeSystemManager()
	{
	}

	void TrigonometricTypeSystemManager::init()
	{
	}

}
}
}
