add_executable(MultiServer Server.cpp)
include_directories(PUBLIC $ENV{ROOT}/include)
include_directories(PUBLIC ../library/libpmvankerSocket)

add_library(MultiServer_objects STATIC
../library/libpmvankerSocket/Socket.hpp
Server.hpp
Server.cpp
)
target_link_libraries(MultiServer MultiServer_objects pmvankerSocket)

add_executable(MultiClient Client.cpp)
include_directories(PUBLIC $ENV{ROOT}/include)
include_directories(PUBLIC ../library/libpmvankerSocket)

add_library(MultiClient_objects STATIC
../library/libpmvankerSocket/Socket.hpp
Client.hpp
Client.cpp
)
target_link_libraries(MultiClient MultiClient_objects pmvankerSocket)
