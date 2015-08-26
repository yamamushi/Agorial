set(AgorialClient_INCLUDES
        ${AgorialClient_INCLUDES}
        ${CMAKE_CURRENT_SOURCE_DIR}/ClientNetworkManager.h
        PARENT_SCOPE
)

set(AgorialClient_SOURCE
        ${AgorialClient_SOURCE}
        ${CMAKE_CURRENT_SOURCE_DIR}/ClientNetworkManager.cpp
        PARENT_SCOPE
)


set(AgorialServer_HEADERS
        ${AgorialServer_HEADERS}
        ${CMAKE_CURRENT_SOURCE_DIR}/AccountManager.h
        ${CMAKE_CURRENT_SOURCE_DIR}/CombatManager.h
        ${CMAKE_CURRENT_SOURCE_DIR}/EntityManager.h
        ${CMAKE_CURRENT_SOURCE_DIR}/PlayerManager.h
        ${CMAKE_CURRENT_SOURCE_DIR}/ServerNetworkManager.h
        ${CMAKE_CURRENT_SOURCE_DIR}/WorldManager.h
        PARENT_SCOPE
)

set(AgorialServer_SOURCE
        ${AgorialServer_SOURCE}
        ${CMAKE_CURRENT_SOURCE_DIR}/AccountManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/CombatManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/EntityManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/PlayerManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ServerNetworkManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/WorldManager.cpp
        PARENT_SCOPE
)
