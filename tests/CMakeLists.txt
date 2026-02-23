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

#deque
add_executable(deque
    deque_test.cpp)

target_link_libraries(deque
    PRIVATE GTest::gtest_main
    PRIVATE MyTinySTL)

gtest_add_tests(TARGET deque)

#iterators
add_executable(iterators
    iterator_test.cpp)

target_link_libraries(iterators
    PRIVATE GTest::gtest_main
    PRIVATE MyTinySTL)

gtest_add_tests(TARGET iterators)

#list
add_executable(list
    list_test.cpp)

target_link_libraries(list
    PRIVATE GTest::gtest_main
    PRIVATE MyTinySTL)

gtest_add_tests(TARGET list)

#map
add_executable(map
    map_test.cpp)

target_link_libraries(map
    PRIVATE GTest::gtest_main
    PRIVATE MyTinySTL)

gtest_add_tests(TARGET map)

#queue
add_executable(queue
    queue_test.cpp)

target_link_libraries(queue
    PRIVATE GTest::gtest_main
    PRIVATE MyTinySTL)

gtest_add_tests(TARGET queue)

#set
add_executable(set
    set_test.cpp)

target_link_libraries(set
    PRIVATE GTest::gtest_main
    PRIVATE MyTinySTL)

gtest_add_tests(TARGET set)

#stack
add_executable(stack
    stack_test.cpp)

target_link_libraries(stack
    PRIVATE GTest::gtest_main
    PRIVATE MyTinySTL)

gtest_add_tests(TARGET stack)

#string
add_executable(string
    string_test.cpp)

target_link_libraries(string
    PRIVATE GTest::gtest_main
    PRIVATE MyTinySTL)

gtest_add_tests(TARGET string)

#unordered_map
add_executable(unordered_map
    unordered_map_test.cpp)

target_link_libraries(unordered_map
    PRIVATE GTest::gtest_main
    PRIVATE MyTinySTL)

gtest_add_tests(TARGET unordered_map)

#unordered_set
add_executable(unordered_set
    unordered_set_test.cpp)

target_link_libraries(unordered_set
    PRIVATE GTest::gtest_main
    PRIVATE MyTinySTL)

gtest_add_tests(TARGET unordered_set)

#vector
add_executable(vector
    vector_test.cpp)

target_link_libraries(vector
    PRIVATE GTest::gtest_main
    PRIVATE MyTinySTL)

gtest_add_tests(TARGET vector)

# Adding original monolithic test
add_executable(stlTest
    test.cpp)
