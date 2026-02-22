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

# Adding original monolithic test
add_executable(stlTest
    test.cpp)
