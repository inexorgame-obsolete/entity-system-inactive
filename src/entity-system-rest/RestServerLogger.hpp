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

namespace inexor {
namespace entity_system {

	class RestServerLogger: public Logger {
		public:
			RestServerLogger() {};
			virtual ~RestServerLogger() {};
			void stop( void ) { return; };
			void start( const shared_ptr< const Settings >& ) { return; };
			void log(const Level level, const char* format, ...)
			{

	            va_list arguments;
	            va_start( arguments, format );
	             vfprintf( stderr, format, arguments );
	             fprintf( stderr, "\n" );
	            va_end( arguments );

//	            va_list arguments;
//				va_start( arguments, format );
//				switch (level) {
//					case restbed::Logger::DEBUG:
//						spdlog::get(LOGGER_ENTITY_REST)->debug(fmt::sprintf(format, arguments));
//						break;
//					default:
//						spdlog::get(LOGGER_ENTITY_REST)->trace(format, arguments);
//						break;
//				}
//				va_end( arguments );
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
