add_subdirectory(utils)

target_sources(bitmarksdk
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/api_client.cpp
    ${CMAKE_CURRENT_LIST_DIR}/api_client.h
    ${CMAKE_CURRENT_LIST_DIR}/asset.cpp
    ${CMAKE_CURRENT_LIST_DIR}/bitmark.cpp
    ${CMAKE_CURRENT_LIST_DIR}/query_builder.cpp
    ${CMAKE_CURRENT_LIST_DIR}/sdk.cpp
    ${CMAKE_CURRENT_LIST_DIR}/transaction.cpp
)
