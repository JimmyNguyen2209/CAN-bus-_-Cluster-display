# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Cluster_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Cluster_autogen.dir/ParseCache.txt"
  "Cluster_autogen"
  )
endif()
