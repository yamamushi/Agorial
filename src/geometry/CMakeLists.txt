set(AgorialServer_HEADERS
        ${AgorialServer_HEADERS}
        ${CMAKE_CURRENT_SOURCE_DIR}/Bresenham.h
        ${CMAKE_CURRENT_SOURCE_DIR}/VoronoiDiagramGenerator.h
        PARENT_SCOPE
)

set(AgorialServer_SOURCE
        ${AgorialServer_SOURCE}
        ${CMAKE_CURRENT_SOURCE_DIR}/Bresenham.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/VoronoiDiagramGenerator.cpp
        PARENT_SCOPE
)
