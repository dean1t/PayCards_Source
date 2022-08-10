# Generated on 2022-8-8 22:46:51 by version 0.9.0 of mulle-xcode-to-cmake
# Command line:
#    mulle-xcode-to-cmake export PayCardsRecognizer.xcodeproj


cmake_minimum_required (VERSION 3.4)
project(PayCardsRecognitionCore VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED COMPONENTS core imgproc highgui objdetect)

MACRO(HEADER_DIRECTORIES return_list)
    FILE(GLOB_RECURSE new_list *.h)
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

HEADER_DIRECTORIES(INCLUDE_DIRS)
include_directories(${INCLUDE_DIRS})

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/PayCardsRecognizer/include")
# include_directories("${CMAKE_CURRENT_SOURCE_DIR}/PayCardsRecognizer/include/caffee")
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/PayCardsRecognizer/include/Eigen")
# include_directories("${CMAKE_CURRENT_SOURCE_DIR}/PayCardsRecognizer/include/google")
# include_directories("${CMAKE_CURRENT_SOURCE_DIR}/PayCardsRecognizer/include/opencv2")

#
# Platform specific definitions
#

if(APPLE)
   set(CMAKE_POSITION_INDEPENDENT_CODE FALSE)
   set(CMAKE_INSTALL_RPATH "@rpath/../lib")

   set(BEGIN_ALL_LOAD "-all_load")
   set(END_ALL_LOAD)
else()
   set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)

   if(WIN32)
   # windows
   else()
   # linux / gcc
      set(BEGIN_ALL_LOAD "-Wl,--whole-archive")
      set(END_ALL_LOAD "-Wl,--no-whole-archive")
      set(CMAKE_INSTALL_RPATH "\$ORIGIN/../lib")
   endif()
endif()


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
PayCardsRecognizer/Vendors/GoogleProtobuf/README.md
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/descriptor.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/descriptor.pb.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/descriptor_database.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/dynamic_message.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/extension_set.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/extension_set_heavy.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/generated_message_reflection.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/generated_message_util.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/io/coded_stream.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/io/gzip_stream.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/io/printer.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/io/tokenizer.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/io/zero_copy_stream.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/io/zero_copy_stream_impl.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/io/zero_copy_stream_impl_lite.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/message.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/message_lite.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/reflection_ops.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/repeated_field.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/service.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/stubs/common.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/stubs/once.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/stubs/structurally_valid.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/stubs/strutil.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/stubs/substitute.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/text_format.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/unknown_field_set.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/wire_format.cc
PayCardsRecognizer/Vendors/GoogleProtobuf/google/protobuf/wire_format_lite.cc
)


##
## PayCardsRecognitionCore
##

add_executable(PayCardsRecognitionCore
${SOURCES}
${PUBLIC_HEADERS}
${PROJECT_HEADERS}
${PRIVATE_HEADERS}
${RESOURCES}
main.cpp
)

target_link_libraries(PayCardsRecognitionCore ${OpenCV_LIBS})

add_compile_definitions(CPU_ONLY)
add_compile_definitions(USE_EIGEN)
