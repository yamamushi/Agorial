set(AgorialServer_INCLUDES
   ${AgorialServer_INCLUDES}
   ${CMAKE_CURRENT_SOURCE_DIR}/OpenSimplexNoise.h
   PARENT_SCOPE
)

set(AgorialServer_SOURCE
   ${AgorialServer_SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/OpenSimplexNoise.c
   PARENT_SCOPE
)