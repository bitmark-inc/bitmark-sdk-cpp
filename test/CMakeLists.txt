project(Bitmark-sdk-cpp-test)

add_executable(tests testmain.cpp)
target_link_libraries(tests PRIVATE bitmarksdk)
