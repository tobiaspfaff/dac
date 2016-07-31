project (DAC)

cmake_minimum_required(VERSION 2.8)

option(DEBUG "Enable debug compilation" OFF)

set(SOURCES 
	src/i2c.cpp
	src/main.cpp
	src/mcp4725.cpp
	src/utils.cpp
)

set(INCPATHS "src")

set(LIBS "wiringPi")

set(FLAGS "-Wall -std=c++11")
if (DEBUG)
    SET(EXECCMD dacd)
    set(FLAGS "${FLAGS} -g -DDEBUG" )
else()
    SET(EXECCMD dac)
    set(FLAGS "${FLAGS} -O2" )
endif()

add_executable(${EXECCMD} ${SOURCES} )
target_link_libraries(${EXECCMD} ${LIBS})
set_target_properties(${EXECCMD} PROPERTIES COMPILE_FLAGS ${FLAGS})
target_include_directories(${EXECCMD} PUBLIC ${INCPATHS})
