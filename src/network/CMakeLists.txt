set(AgorialClient_HEADERS
   ${AgorialClient_HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/zmq.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/zhelpers.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/zmsg.hpp

   PARENT_SCOPE
)

set(AgorialServer_HEADERS
   ${AgorialServer_HEADERS}
   ${CMAKE_CURRENT_SOURCE_DIR}/zmq.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/zhelpers.hpp
   ${CMAKE_CURRENT_SOURCE_DIR}/zmsg.hpp

   PARENT_SCOPE
)
