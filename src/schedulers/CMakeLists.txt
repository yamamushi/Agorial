set(AgorialServer_INCLUDES
        ${AgorialServer_INCLUDES}
        ${CMAKE_CURRENT_SOURCE_DIR}/Parallelize.h
        ${CMAKE_CURRENT_SOURCE_DIR}/TaskSpawner.h
        PARENT_SCOPE
)

set(AgorialServer_SOURCE
        ${AgorialServer_SOURCE}
        ${CMAKE_CURRENT_SOURCE_DIR}/Parallelize.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/TaskSpawner.cpp
        PARENT_SCOPE
)