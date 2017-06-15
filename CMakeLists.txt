cmake_minimum_required(VERSION 3.7)
project(HADB)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        "data structures/BTree.cpp"
        "data structures/BTree.h"
        "data structures/BTreeNode.cpp"
        "data structures/BTreeNode.h"
        "connection/Server.cpp"
        "connection/Server.h" json/jsonParser.cpp json/jsonParser.h object/RequestForm.cpp object/RequestForm.h connection/Protocol.cpp connection/Protocol.h)

add_executable(HADB ${SOURCE_FILES} connection/Protocol.cpp connection/Protocol.h)