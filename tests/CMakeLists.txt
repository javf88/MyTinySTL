#******************************************************************************U*
# Define tests
#*******************************************************************************

# algorithm
add_executable(algorithm
    algorithm_test.cpp)

target_link_libraries(algorithm
    PRIVATE GTest::gtest_main
    PRIVATE MyTinySTL)

gtest_add_tests(TARGET algorithm)

# performance
add_executable(performance
    algorithm_performance_test.cpp)

target_link_libraries(performance
    PRIVATE GTest::gtest_main
    PRIVATE MyTinySTL)

gtest_add_tests(TARGET performance)

add_executable(deque
    deque_test.cpp)

add_executable(iterators
    iterator_test.cpp)

add_executable(list
    list_test.cpp)

add_executable(map
    map_test.cpp)

add_executable(queue
    queue_test.cpp)

add_executable(set
    set_test.cpp)

add_executable(stack
    stack_test.cpp)

add_executable(string
    string_test.cpp)

add_executable(unordered_map
    unordered_map_test.cpp)

add_executable(unordered_set
    unordered_set_test.cpp)

add_executable(vector
    vector_test.cpp)

# Adding original monolithic test
add_executable(stlTest
    test.cpp)
