include_directories(${Agorial_SOURCE_DIR}/src/)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin/)

set(AgorialClient_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/client/main.cpp)
set(AgorialClient_HEADERS)

set(AgorialServer_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/server/main.cpp)
set(AgorialServer_HEADERS)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${ZMQ_INCLUDE_DIRS} ${CZMQ_INCLUDE_DIR} ${MSGPACK_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${SDL_INCLUDE_DIRS}
                    ${SDL_IMAGE_INCLUDE_DIR}
                    ${SDL_TTF_INCLUDE_DIR}
                    ${SDL_MIXER_INCLUDE_DIR})

#INCLUDE_DIRECTORIES(/usr/local/include/libtcod)

add_subdirectory(account)
add_subdirectory(client)
add_subdirectory(database)
add_subdirectory(engine)
add_subdirectory(entity)
add_subdirectory(geometry)
add_subdirectory(handlers)
add_subdirectory(managers)
add_subdirectory(network)
add_subdirectory(noise)
add_subdirectory(octree)
add_subdirectory(parsers)
add_subdirectory(player)
add_subdirectory(server)
add_subdirectory(util)
add_subdirectory(world)


add_executable(Agorial ${AgorialClient_SOURCE})

add_executable(AgorialServer ${AgorialServer_SOURCE})

target_link_libraries(Agorial ${SDL_LIBRARY}
                              ${SDL_TTF_LIBRARIES}
                              ${SDL_IMAGE_LIBRARIES}
                              ${SDL_MIXER_LIBRARIES}
                              ${ZMQ_LIBRARIES}
                              ${CZMQ_LIBRARIES}
                              ${SODIUM_LIBRARIES}
                              )


target_link_libraries(AgorialServer ${ZMQ_LIBRARIES} ${CZMQ_LIBRARIES} ${SODIUM_LIBRARIES})

SET_TARGET_PROPERTIES(Agorial PROPERTIES LINK_FLAGS "-lboost_system -lboost_thread-mt -ltcod -ltcodxx -lboost_program_options -lboost_filesystem -lboost_serialization -lboost_regex")

SET_TARGET_PROPERTIES(AgorialServer PROPERTIES LINK_FLAGS ${ZMQ_DEFINITIONS} "-lboost_system -lboost_thread-mt -lboost_program_options -lboost_filesystem -lboost_serialization -lboost_regex")

install(TARGETS Agorial RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
