#include "GateFactories.hpp"

namespace inexor {
namespace entity_system {
namespace type_system {

	GateFactories::GateFactories(
		NotFactoryPtr not_factory,
		OrFactoryPtr or_factory,
		AndFactoryPtr and_factory,
		XorFactoryPtr xor_factory,
		NorFactoryPtr nor_factory,
		NandFactoryPtr nand_factory
	)
	{
		this->not_factory = not_factory;
		this->or_factory = or_factory;
		this->and_factory = and_factory;
		this->xor_factory = xor_factory;
		this->nor_factory = nor_factory;
		this->nand_factory = nand_factory;
	}

	GateFactories::~GateFactories()
	{
	}

	void GateFactories::init()
	{
		not_factory->init();
		or_factory->init();
		and_factory->init();
		xor_factory->init();
		nor_factory->init();
		nand_factory->init();
	}

}
}
}
