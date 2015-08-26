set(AgorialServer_INCLUDES
        ${AgorialServer_INCLUDES}
        ${CMAKE_CURRENT_SOURCE_DIR}/MapChunk.h
        ${CMAKE_CURRENT_SOURCE_DIR}/MapLayer.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Tile.h
        ${CMAKE_CURRENT_SOURCE_DIR}/WorldGenerator.h
        PARENT_SCOPE
)

set(AgorialServer_SOURCE
        ${AgorialServer_SOURCE}
        ${CMAKE_CURRENT_SOURCE_DIR}/MapChunk.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/MapLayer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Tile.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/WorldGenerator.cpp
        PARENT_SCOPE
)