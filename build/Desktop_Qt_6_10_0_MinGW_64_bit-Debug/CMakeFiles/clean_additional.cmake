# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Interface_ES_LAPIS_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Interface_ES_LAPIS_autogen.dir\\ParseCache.txt"
  "Interface_ES_LAPIS_autogen"
  )
endif()
