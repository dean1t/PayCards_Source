cmake_minimum_required (VERSION 3.4)
project(PayCardsRecognitionCore VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)  # only way to use protobuf in runtime

find_package(OpenCV REQUIRED COMPONENTS core imgproc highgui objdetect)
find_package(Eigen3 REQUIRED)

# project includes
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/PayCardsRecognizer/CrossPlatform")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/PayCardsRecognizer/CrossPlatform/CV")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/PayCardsRecognizer/CrossPlatform/CaffePredictor")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/PayCardsRecognizer/CrossPlatform/Include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/PayCardsRecognizer/CrossPlatform/Include/NeuralNetwork")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/PayCardsRecognizer/CrossPlatform/Include/Public")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/PayCardsRecognizer/CrossPlatform/Include/Recognizer")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/PayCardsRecognizer/CrossPlatform/Include/Torch")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/PayCardsRecognizer/CrossPlatform/Recognizer")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/PayCardsRecognizer/CrossPlatform/Torch")

# third-party
include_directories("${OpenCV_INCLUDE_DIRS}")
include_directories("${EIGEN3_INCLUDE_DIR}")
include_directories("${EIGEN3_INCLUDE_DIR}/Eigen")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/PayCardsRecognizer/include")

##
## PayCardsRecognitionCore Files
##

file(GLOB_RECURSE SOURCES PayCardsRecognizer/CrossPlatform/*.cpp)
file(GLOB_RECURSE CAFFE_SOURCES PayCardsRecognizer/Vendors/Caffe/*.cpp PayCardsRecognizer/Vendors/Caffe/*.cc)
file(GLOB_RECURSE PROTOBUF_SOURCES PayCardsRecognizer/include/google/protobuf/*.cpp PayCardsRecognizer/include/google/protobuf/*.cc)

set(MY_SOURCES
    RecognitionCoreDelegate.cpp
    RecognitionCoreDelegate.h
    TorchDelegate.cpp
    TorchDelegate.h
    main.cpp
)

##
## PayCardsRecognitionCore
##

add_executable(PayCardsRecognitionCore
    ${SOURCES}
    ${CAFFE_SOURCES}
    ${PROTOBUF_SOURCES}
    ${MY_SOURCES}
)

target_link_libraries(PayCardsRecognitionCore ${OpenCV_LIBS})

add_compile_definitions(CPU_ONLY)
add_compile_definitions(USE_EIGEN)
