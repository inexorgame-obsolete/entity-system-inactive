/*
 * RestServerLogger.hpp
 *
 *  Created on: 19.01.2019
 *      Author: aschaeffer
 */

#pragma once

#include <cstdarg>
#include <restbed>
#include <fmt/format.h>
#include <fmt/printf.h>

#include "spdlog/spdlog.h"

using namespace std;
using namespace restbed;

#define LOGGER_ENTITY_REST "inexor.entity.rest"
#define INEXOR_REST_API_MAX_MESSAGE_SIZE 4096

namespace inexor {
namespace entity_system {

	class RestServerLogger: public Logger
    {
		public:
			RestServerLogger() {};
			virtual ~RestServerLogger() {};
			void stop( void ) { return; };
			void start( const shared_ptr< const Settings >& ) { return; };


            /// Write down a server message in spdlog.
			void log(const Level level, const char* format, ...)
			{
                char spdlog_message[INEXOR_REST_API_MAX_MESSAGE_SIZE];

                va_list log_arguments;
                va_start(log_arguments, format);
                std::vsnprintf(spdlog_message, INEXOR_REST_API_MAX_MESSAGE_SIZE, format, log_arguments);
                va_end(format);

                auto spdlog_handle = spdlog::get(LOGGER_ENTITY_REST);

                switch(level)
                {
                    case restbed::Logger::INFO:
                        spdlog_handle->info(spdlog_message);
                        break;
                    case restbed::Logger::DEBUG:
                        spdlog_handle->debug(spdlog_message);
                        break;
                    case restbed::Logger::FATAL:
                    case restbed::Logger::SECURITY: // Security messages are seen as critical errors!
                        spdlog_handle->critical(spdlog_message);
                        break;
                    case 3000: // ERROR
                        spdlog_handle->error(spdlog_message);
                        break;
                    case restbed::Logger::WARNING:
                        spdlog_handle->warn(spdlog_message);
                        break;
                }
			};


			void log_if(bool expression, const Level level, const char* format, ...)
			{
				if (expression)
				{
					va_list arguments;
					va_start(arguments, format);
					log(level, format, arguments);
					va_end(arguments);
				}

			};
	};

}
}
