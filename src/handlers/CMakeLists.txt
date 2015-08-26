set(AgorialClient_INCLUDES
        ${AgorialClient_INCLUDES}
        ${CMAKE_CURRENT_SOURCE_DIR}/KeyboardHandler.h
        ${CMAKE_CURRENT_SOURCE_DIR}/FilesystemHandler.h
        PARENT_SCOPE
)

set(AgorialClient_SOURCE
        ${AgorialClient_SOURCE}
        ${CMAKE_CURRENT_SOURCE_DIR}/KeyboardHandler.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/FilesystemHandler.cpp
        PARENT_SCOPE
)

set(AgorialServer_INCLUDES
        ${AgorialServer_INCLUDES}
        ${CMAKE_CURRENT_SOURCE_DIR}/CertHandler.h
        ${CMAKE_CURRENT_SOURCE_DIR}/FilesystemHandler.h
        PARENT_SCOPE
)

set(AgorialServer_SOURCE
        ${AgorialServer_SOURCE}
        ${CMAKE_CURRENT_SOURCE_DIR}/CertHandler.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/FilesystemHandler.cpp
        PARENT_SCOPE
)