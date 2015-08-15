# - Try to find SODIUM
# Once done this will define
#
#  SODIUM_FOUND - system has SODIUM
#  SODIUM_INCLUDE_DIRS - the SODIUM include directory
#  SODIUM_LIBRARIES - Link these to use SODIUM
#  SODIUM_DEFINITIONS - Compiler switches required for using SODIUM
#
#  Copyright (c) 2011 Lee Hambley <lee.hambley@gmail.com>
#
#  Redistribution and use is allowed according to the terms of the New
#  BSD license.
#  For details see the accompanying COPYING-CMAKE-SCRIPTS file.
#

if (SODIUM_LIBRARIES AND SODIUM_INCLUDE_DIRS)
  # in cache already
  set(SODIUM_FOUND TRUE)
else (SODIUM_LIBRARIES AND SODIUM_INCLUDE_DIRS)

  find_path(SODIUM_INCLUDE_DIR
    NAMES
      sodium.h
    PATHS
      /usr/include
      /usr/local/include
      /opt/local/include
      /sw/include
  )

  find_library(SODIUM_LIBRARY
    NAMES
      sodium
    PATHS
      /usr/lib
      /usr/local/lib
      /opt/local/lib
      /sw/lib
  )

  set(SODIUM_INCLUDE_DIRS
    ${SODIUM_INCLUDE_DIR}
  )

  if (SODIUM_LIBRARY)
    set(SODIUM_LIBRARIES
        ${SODIUM_LIBRARIES}
        ${SODIUM_LIBRARY}
    )
  endif (SODIUM_LIBRARY)

  include(FindPackageHandleStandardArgs)
  find_package_handle_standard_args(SODIUM DEFAULT_MSG SODIUM_LIBRARIES SODIUM_INCLUDE_DIRS)

  # show the SODIUM_INCLUDE_DIRS and SODIUM_LIBRARIES variables only in the advanced view
  mark_as_advanced(SODIUM_INCLUDE_DIRS SODIUM_LIBRARIES)

endif (SODIUM_LIBRARIES AND SODIUM_INCLUDE_DIRS)
