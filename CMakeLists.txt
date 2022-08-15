cmake_minimum_required (VERSION 3.4)
project(PayCardsRecognitionCore VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED COMPONENTS core imgproc highgui objdetect)

# Macro-helper to get include-dirs
MACRO(HEADER_DIRECTORIES return_list)
    FILE(GLOB_RECURSE new_list PayCardsRecognizer/CrossPlatform/*.h)
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
    message("${return_list}")
ENDMACRO()

# HEADER_DIRECTORIES(INCLUDE_DIRS)
# include_directories(${INCLUDE_DIRS})

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
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/PayCardsRecognizer/include")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/PayCardsRecognizer/include/Eigen")
# include_directories("${CMAKE_CURRENT_SOURCE_DIR}/PayCardsRecognizer/include/google")
# include_directories("${CMAKE_CURRENT_SOURCE_DIR}/PayCardsRecognizer/include")
# include_directories("${CMAKE_CURRENT_SOURCE_DIR}/PayCardsRecognizer/include/opencv2")

##
## PayCardsRecognitionCore Files
##

set( SOURCES
PayCardsRecognizer/CrossPlatform/CV/canny.cpp
PayCardsRecognizer/CrossPlatform/CV/hough.cpp
PayCardsRecognizer/CrossPlatform/CV/warp.cpp
PayCardsRecognizer/CrossPlatform/CaffePredictor/CaffeDatum.cpp
PayCardsRecognizer/CrossPlatform/CaffePredictor/CaffeDatumList.cpp
PayCardsRecognizer/CrossPlatform/CaffePredictor/CaffeNeuralNetwork.cpp
PayCardsRecognizer/CrossPlatform/CaffePredictor/CaffeObjectFactory.cpp
PayCardsRecognizer/CrossPlatform/CaffePredictor/CaffeResult.cpp
PayCardsRecognizer/CrossPlatform/CaffePredictor/CaffeResultList.cpp
PayCardsRecognizer/CrossPlatform/Recognizer/DateRecognizer.cpp
PayCardsRecognizer/CrossPlatform/Recognizer/EdgesDetector.cpp
PayCardsRecognizer/CrossPlatform/Recognizer/FrameStorage.cpp
PayCardsRecognizer/CrossPlatform/Recognizer/NameRecognizer.cpp
PayCardsRecognizer/CrossPlatform/Recognizer/NumberRecognizer.cpp
PayCardsRecognizer/CrossPlatform/Recognizer/RecognitionCore.cpp
PayCardsRecognizer/CrossPlatform/Recognizer/RecognitionResult.cpp
PayCardsRecognizer/CrossPlatform/Recognizer/Utils.cpp
PayCardsRecognizer/CrossPlatform/ServiceContainer.cpp
PayCardsRecognizer/CrossPlatform/Torch/TorchManager.cpp
PayCardsRecognizer/Vendors/Caffe/blob.cpp
PayCardsRecognizer/Vendors/Caffe/common.cpp
PayCardsRecognizer/Vendors/Caffe/layer_factory.cpp
PayCardsRecognizer/Vendors/Caffe/layers/base_conv_layer.cpp
PayCardsRecognizer/Vendors/Caffe/layers/base_data_layer.cpp
PayCardsRecognizer/Vendors/Caffe/layers/bnll_layer.cpp
PayCardsRecognizer/Vendors/Caffe/layers/concat_layer.cpp
PayCardsRecognizer/Vendors/Caffe/layers/conv_layer.cpp
PayCardsRecognizer/Vendors/Caffe/layers/eltwise_layer.cpp
PayCardsRecognizer/Vendors/Caffe/layers/flatten_layer.cpp
PayCardsRecognizer/Vendors/Caffe/layers/im2col_layer.cpp
PayCardsRecognizer/Vendors/Caffe/layers/inner_product_layer.cpp
PayCardsRecognizer/Vendors/Caffe/layers/loss_layer.cpp
PayCardsRecognizer/Vendors/Caffe/layers/lrn_layer.cpp
PayCardsRecognizer/Vendors/Caffe/layers/memory_data_layer.cpp
PayCardsRecognizer/Vendors/Caffe/layers/neuron_layer.cpp
PayCardsRecognizer/Vendors/Caffe/layers/pooling_layer.cpp
PayCardsRecognizer/Vendors/Caffe/layers/power_layer.cpp
PayCardsRecognizer/Vendors/Caffe/layers/relu_layer.cpp
PayCardsRecognizer/Vendors/Caffe/layers/sigmoid_layer.cpp
PayCardsRecognizer/Vendors/Caffe/layers/softmax_layer.cpp
PayCardsRecognizer/Vendors/Caffe/layers/softmax_loss_layer.cpp
PayCardsRecognizer/Vendors/Caffe/layers/split_layer.cpp
PayCardsRecognizer/Vendors/Caffe/layers/tanh_layer.cpp
PayCardsRecognizer/Vendors/Caffe/net.cpp
PayCardsRecognizer/Vendors/Caffe/proto/caffe.pb.cc
PayCardsRecognizer/Vendors/Caffe/syncedmem.cpp
PayCardsRecognizer/Vendors/Caffe/util/im2col.cpp
PayCardsRecognizer/Vendors/Caffe/util/insert_splits.cpp
PayCardsRecognizer/Vendors/Caffe/util/io.cpp
PayCardsRecognizer/Vendors/Caffe/util/math_functions.cpp
PayCardsRecognizer/Vendors/Caffe/util/upgrade_proto.cpp
PayCardsRecognizer/include/google/protobuf/descriptor.cc
PayCardsRecognizer/include/google/protobuf/descriptor.pb.cc
PayCardsRecognizer/include/google/protobuf/descriptor_database.cc
PayCardsRecognizer/include/google/protobuf/dynamic_message.cc
PayCardsRecognizer/include/google/protobuf/extension_set.cc
PayCardsRecognizer/include/google/protobuf/extension_set_heavy.cc
PayCardsRecognizer/include/google/protobuf/generated_message_reflection.cc
PayCardsRecognizer/include/google/protobuf/generated_message_util.cc
PayCardsRecognizer/include/google/protobuf/io/coded_stream.cc
PayCardsRecognizer/include/google/protobuf/io/gzip_stream.cc
PayCardsRecognizer/include/google/protobuf/io/printer.cc
PayCardsRecognizer/include/google/protobuf/io/tokenizer.cc
PayCardsRecognizer/include/google/protobuf/io/zero_copy_stream.cc
PayCardsRecognizer/include/google/protobuf/io/zero_copy_stream_impl.cc
PayCardsRecognizer/include/google/protobuf/io/zero_copy_stream_impl_lite.cc
PayCardsRecognizer/include/google/protobuf/message.cc
PayCardsRecognizer/include/google/protobuf/message_lite.cc
PayCardsRecognizer/include/google/protobuf/reflection_ops.cc
PayCardsRecognizer/include/google/protobuf/repeated_field.cc
PayCardsRecognizer/include/google/protobuf/service.cc
PayCardsRecognizer/include/google/protobuf/stubs/common.cc
PayCardsRecognizer/include/google/protobuf/stubs/once.cc
PayCardsRecognizer/include/google/protobuf/stubs/structurally_valid.cc
PayCardsRecognizer/include/google/protobuf/stubs/strutil.cc
PayCardsRecognizer/include/google/protobuf/stubs/substitute.cc
PayCardsRecognizer/include/google/protobuf/text_format.cc
PayCardsRecognizer/include/google/protobuf/unknown_field_set.cc
PayCardsRecognizer/include/google/protobuf/wire_format.cc
PayCardsRecognizer/include/google/protobuf/wire_format_lite.cc
)

# file(GLOB_RECURSE SOURCES PayCardsRecognizer/*.cpp PayCardsRecognizer/*.cc)

set(MY_SOURCES
RecognitionCoreDelegate.cpp
RecognitionCoreDelegate.h
TorchDelegate.cpp
TorchDelegate.h
main.cpp
)

# message("${SOURCES}")

##
## PayCardsRecognitionCore
##

add_executable(PayCardsRecognitionCore
${SOURCES}
${MY_SOURCES}
)

target_link_libraries(PayCardsRecognitionCore ${OpenCV_LIBS})

add_compile_definitions(CPU_ONLY)
add_compile_definitions(USE_EIGEN)
