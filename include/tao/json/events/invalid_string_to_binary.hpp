// Copyright (c) 2019 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/json/

#ifndef TAO_JSON_EVENTS_INVALID_STRING_TO_BINARY_HPP
#define TAO_JSON_EVENTS_INVALID_STRING_TO_BINARY_HPP

#include "../binary_view.hpp"
#include "../utf8.hpp"

namespace tao::json::events
{
   template< typename Consumer >
   struct invalid_string_to_binary
      : public Consumer
   {
      using Consumer::Consumer;

      void string( const std::string_view v )
      {
         if( internal::validate_utf8( v ) ) {
            Consumer::string( v );
         }
         else {
            Consumer::binary( tao::binary_view( reinterpret_cast< const std::byte* >( v.data() ), v.size() ) );  // NOLINT
         }
      }
   };

}  // namespace tao::json::events

#endif
