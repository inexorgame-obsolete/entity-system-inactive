#include <boost/di.hpp>
#include "spdlog/spdlog.h"
#include "InexorApplication.hpp"

// #include "graphql/EntitiesSchema.h"
#include "graphql/UnifiedToday.h"

#include <graphqlservice/JSONResponse.h>


using namespace graphql;

int main(int argc, char* argv[])
{

	response::IdType binAppointmentId;
	response::IdType binTaskId;
	response::IdType binFolderId;

	std::string fakeAppointmentId("fakeAppointmentId");
	binAppointmentId.resize(fakeAppointmentId.size());
	std::copy(fakeAppointmentId.cbegin(), fakeAppointmentId.cend(), binAppointmentId.begin());

	std::string fakeTaskId("fakeTaskId");
	binTaskId.resize(fakeTaskId.size());
	std::copy(fakeTaskId.cbegin(), fakeTaskId.cend(), binTaskId.begin());

	std::string fakeFolderId("fakeFolderId");
	binFolderId.resize(fakeFolderId.size());
	std::copy(fakeFolderId.cbegin(), fakeFolderId.cend(), binFolderId.begin());

	auto query = std::make_shared<entities::Query>(
		[&binAppointmentId]() -> std::vector<std::shared_ptr<entities::Appointment>>
	{
		std::cout << "Called getAppointments..." << std::endl;
		return { std::make_shared<entities::Appointment>(std::move(binAppointmentId), "tomorrow", "Lunch?", false) };
	}, [&binTaskId]() -> std::vector<std::shared_ptr<entities::Task>>
	{
		std::cout << "Called getTasks..." << std::endl;
		return { std::make_shared<entities::Task>(std::move(binTaskId), "Don't forget", true) };
	}, [&binFolderId]() -> std::vector<std::shared_ptr<entities::Folder>>
	{
		std::cout << "Called getUnreadCounts..." << std::endl;
		return { std::make_shared<entities::Folder>(std::move(binFolderId), "\"Fake\" Inbox", 3) };
	});
	auto mutation = std::make_shared<entities::Mutation>(
		[](entities::CompleteTaskInput&& input) -> std::shared_ptr<entities::CompleteTaskPayload>
	{
		return std::make_shared<entities::CompleteTaskPayload>(
			std::make_shared<entities::Task>(std::move(input.id), "Mutated Task!", *(input.isComplete)),
			std::move(input.clientMutationId)
		);
	});
	auto subscription = std::make_shared<entities::Subscription>();
	auto service = std::make_shared<entities::Operations>(query, mutation, subscription);

	std::cout << "Created the service..." << std::endl;

	try
	{
		peg::ast query;
  		std::string input = "{ tasks{ edges{ node { title } } } }";
		query = peg::parseString(std::move(input));
		if (!query.root)
		{
			std::cerr << "Unknown error!" << std::endl;
			std::cerr << std::endl;
			return 1;
		}

		std::cout << "Executing query..." << std::endl;

		std::cout << response::toJSON(service->resolve(nullptr, *query.root, ((argc > 2) ? argv[2] : ""), response::Value(response::Type::Map)).get()) << std::endl;
	}
	catch (const std::runtime_error& ex)
	{
		std::cerr << ex.what() << std::endl;
		return 1;
	}
  return EXIT_SUCCESS;
	auto injector = boost::di::make_injector();
	auto application = injector.create<inexor::InexorApplication>();
	application.pre_init(argc, argv);
	application.init();
	application.run();
    return EXIT_SUCCESS;
}
