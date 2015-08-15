set(AgorialClient_INCLUDES
   ${AgorialClient_INCLUDES}
   ${CMAKE_CURRENT_SOURCE_DIR}/ClientConfigParser.h
   ${CMAKE_CURRENT_SOURCE_DIR}/ClientResponseParser.h
   PARENT_SCOPE
)

set(AgorialClient_SOURCE
   ${AgorialClient_SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/ClientConfigParser.cpp
   ${CMAKE_CURRENT_SOURCE_DIR}/ClientResponseParser.cpp
   PARENT_SCOPE
)


set(AgorialServer_INCLUDES
   ${AgorialServer_INCLUDES}
   ${CMAKE_CURRENT_SOURCE_DIR}/ServerConfigParser.h
   PARENT_SCOPE
)

set(AgorialServer_SOURCE
   ${AgorialServer_SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/ServerConfigParser.cpp
   PARENT_SCOPE
)