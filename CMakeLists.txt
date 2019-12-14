cmake_minimum_required(VERSION 2.8.7)
project(test_dome)

add_compile_options(-std=c++17)

add_library(userInput src/userInput.cpp)
add_library(twoSum src/twoSum.cpp)
add_library(BST src/BST.cpp)
add_library(trainComposition src/trainComposition.cpp)
add_library(palindrome src/palindrome.cpp)
add_library(sortedSearch src/sortedSearch.cpp)
add_library(MultipleChoiceTest src/MultipleChoiceTest.cpp)

add_executable(nonRecursivePlaylist src/nonRecursivePlaylist.cpp)
add_executable(path src/path.cpp)
add_executable(Playlist src/Playlist.cpp)
add_executable(quadraticEquation src/quadraticEquation.cpp)
add_executable(uniqueNames src/uniqueNames.cpp)
