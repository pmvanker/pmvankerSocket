add_executable(Server Server.cpp)
include_directories(PUBLIC $ENV{ROOT}/include)
include_directories(PUBLIC ../library/libpmvankerSocket)

add_library(Server_objects STATIC
../library/libpmvankerSocket/Socket.hpp
Server.hpp
Server.cpp
)
target_link_libraries(Server Server_objects pmvankerSocket)

add_executable(Client Client.cpp)
include_directories(PUBLIC $ENV{ROOT}/include)
include_directories(PUBLIC ../library/libpmvankerSocket)

add_library(Client_objects STATIC
../library/libpmvankerSocket/Socket.hpp
Client.hpp
Client.cpp
)
target_link_libraries(Client Client_objects pmvankerSocket)
