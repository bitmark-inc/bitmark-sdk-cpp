cmake_minimum_required(VERSION 3.10)

project(Bitmark-sdk-cpp)

# third-party libraries
add_subdirectory(thirdparty/nlohmann)
add_subdirectory(thirdparty/cpp-httplib)

# require OpenSSL >= 1.1.1
find_package(OpenSSL 1.1.1 COMPONENTS Crypto SSL REQUIRED)

add_library(bitmarksdk STATIC "")

# recursively add target sources
add_subdirectory(src)

target_include_directories(bitmarksdk
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_features(bitmarksdk PUBLIC cxx_std_11)

set_target_properties(bitmarksdk PROPERTIES COMPILE_FLAGS "-Wall -Werror")

target_link_libraries(bitmarksdk
  PRIVATE json httplib OpenSSL::SSL OpenSSL::Crypto
)
target_compile_definitions(bitmarksdk PRIVATE CPPHTTPLIB_OPENSSL_SUPPORT)

# unit test
# TODO
#add_subdirectory(test)
