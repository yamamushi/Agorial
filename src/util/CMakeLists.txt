set(AgorialClient_HEADERS
        ${CMAKE_CURRENT_SOURCE_DIR}/Constants.h
        ${CMAKE_CURRENT_SOURCE_DIR}/IsNumber.h
        ${CMAKE_CURRENT_SOURCE_DIR}/ClientGlobalLogger.h
        ${CMAKE_CURRENT_SOURCE_DIR}/MsgQueue.h
        ${AgorialClient_HEADERS}
        PARENT_SCOPE
)

set(AgorialClient_SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/ClientGlobalLogger.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/UTF8Util.cpp
        ${AgorialClient_SOURCE}
        PARENT_SCOPE
)

set(AgorialServer_HEADERS
        ${CMAKE_CURRENT_SOURCE_DIR}/Constants.h
        ${CMAKE_CURRENT_SOURCE_DIR}/IsNumber.h
        ${CMAKE_CURRENT_SOURCE_DIR}/ServerGlobalLogger.h
        ${CMAKE_CURRENT_SOURCE_DIR}/MsgQueue.h
        ${CMAKE_CURRENT_SOURCE_DIR}/UTF8Util.h
        ${AgorialServer_HEADERS}
        PARENT_SCOPE
)

set(AgorialServer_SOURCE
        ${CMAKE_CURRENT_SOURCE_DIR}/ServerGlobalLogger.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/UTF8Util.cpp
        ${AgorialServer_SOURCE}
        PARENT_SCOPE
)