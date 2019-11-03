#include <gtest/gtest.h>
#include "GUIDBase.hpp"

using namespace inexor::entity_system;

// @class Test class for GUIDBase.
class ThingThatNeedsGuid : public GUIDBase
{
public:
	ThingThatNeedsGuid() : GUIDBase()
	{
	}
	ThingThatNeedsGuid(const xg::Guid &param_GUID) : GUIDBase(param_GUID)
	{
	}
};


TEST(GUIDBase, guid_generation)
{
	std::shared_ptr<ThingThatNeedsGuid> test_thing = std::make_shared<ThingThatNeedsGuid>();

	// Create an empty GUID.
	xg::Guid empty_guid = xg::Guid(std::string(""));

	// Make sure the GUID is not empty.
	EXPECT_NE(empty_guid, test_thing->get_GUID());
}


TEST(GUIDBase, guid_regeneration)
{
	std::shared_ptr<ThingThatNeedsGuid> test_thing = std::make_shared<ThingThatNeedsGuid>();

	xg::Guid start_guid = test_thing->get_GUID();

	// Generate a new GUID.
	test_thing->generate_new_GUID();

	xg::Guid end_guid = test_thing->get_GUID();

	// The GUID should have changed now.
	EXPECT_NE(start_guid, end_guid);
}


TEST(GUIDBase, guid_copy_constructor_test)
{
	xg::Guid random_guid = xg::newGuid();

	std::shared_ptr<ThingThatNeedsGuid> test_thing = std::make_shared<ThingThatNeedsGuid>(random_guid);

	// Check if the GUID has been passed to the copy constructor.
	EXPECT_EQ(random_guid, test_thing->get_GUID());

	random_guid = xg::newGuid();

	// Now that we generated a new guid they should no longer be equal.
	EXPECT_NE(random_guid, test_thing->get_GUID());
}
