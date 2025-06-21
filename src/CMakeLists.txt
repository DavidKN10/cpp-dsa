# add subdirectories
add_subdirectory(DataStructures)
add_subdirectory(Algorithms)

# list main file
add_executable(Main main.cpp)

# link subdirectories libraries
target_link_libraries(Main PRIVATE Algorithms DataStructures)