
cmake_minimum_required(VERSION 2.8)
Project (pcl_multi_object_recognition CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=gnu++0x")
set(CMAKE_BUILD_TYPE Release) 

set(INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(GRABBER_PATH ${INCLUDE_PATH}/grabber)
set(SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(IMPL_PATH ${INCLUDE_PATH}/impl)


#######find Openmp
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()
#######



#######find openni2
  find_path(OPENNI2_INCLUDE_DIRS NAMES OpenNI.h)
  find_library(OPENNI_LIBRARY NAMES OpenNI2 libOpenNI2 )
  include_directories(${OPENNI2_INCLUDE_DIRS})
#######

#######find pcl
  find_package(PCL 1.7 REQUIRED)
  include_directories(${PCL_INCLUDE_DIRS})
  link_directories(${PCL_LIBRARY_DIRS})
  add_definitions(${PCL_DEFINITIONS})
#######

#######find freenect
  SET(FREENECT_ROOT "/usr")

  # Include dir
  find_path(Freenect_INCLUDE_DIR
    NAMES libfreenect.hpp
    PATHS ${FREENECT_ROOT}/include 
  )

  include_directories(${Freenect_INCLUDE_DIR} )

  # Finally the library itself
  find_library(Freenect_LIBRARY
    NAMES freenect
    PATHS ${FREENECT_ROOT}/lib  /usr/local/lib64/
  )
#######

include_directories(${INCLUDE_PATH})
include_directories(${GRABBER_PATH})
include_directories(${IMPL_PATH})


add_executable (pcl_multi_object_recognition pcl_multi_object_recognition.cpp  ${SOURCE_PATH}/Visualizer.cpp  ${SOURCE_PATH}/Cluster.cpp ${SOURCE_PATH}/Keypoints.cpp ${SOURCE_PATH}/Sampling.cpp ${SOURCE_PATH}/Icp.cpp  ${SOURCE_PATH}/Ppfe.cpp ${SOURCE_PATH}/OpenniStreamer.cpp ${SOURCE_PATH}/Error.cpp ${SOURCE_PATH}/find_function.cpp ${SOURCE_PATH}/define.cpp ${SOURCE_PATH}/help.cpp ${SOURCE_PATH}/utils.cpp ${SOURCE_PATH}/KeyDes.cpp)# ${GRABBER_PATH}/registration.cpp)

target_link_libraries( pcl_multi_object_recognition  ${OPENNI_LIBRARY} ${PCL_LIBRARIES} ${Freenect_LIBRARY} )
