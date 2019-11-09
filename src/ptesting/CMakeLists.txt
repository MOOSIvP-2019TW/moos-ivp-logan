#--------------------------------------------------------
# The CMakeLists.txt for:                       ptesting
# Author(s):                              logan
#--------------------------------------------------------

SET(SRC
  testing.cpp
  testing_Info.cpp
  main.cpp
)

ADD_EXECUTABLE(ptesting ${SRC})

TARGET_LINK_LIBRARIES(ptesting
   ${MOOS_LIBRARIES}
   apputil
   mbutil
   m
   geometry
   pthread)

