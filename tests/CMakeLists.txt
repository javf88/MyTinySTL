#******************************************************************************U*
# Define tests
#*******************************************************************************

add_executable(algorithm
    algorithm_test.cpp)

add_executable(performance
    algorithm_performance_test.cpp)

add_executable(deque
    deque_test.cpp)

add_executable(iterators
    iterator_test.cpp)

add_executable(list
    list_test.cpp)

add_executable(map
    map_test.cpp)

# Adding original monolithic test
add_executable(stlTest
    test.cpp)
