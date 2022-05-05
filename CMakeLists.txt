cmake_minimum_required(VERSION 3.21)
project (DataStructure)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataStructure main.cpp Linked/SingleLinked.cpp Linked/MergeBySize.cpp Test/CinDebugTest.cpp Stack/Stack.cpp Stack/ConvertDecimal.cpp Queue/Queue.cpp String/String.cpp Tree/NonRecursionTree.cpp Tree/RecursionTree.cpp)
