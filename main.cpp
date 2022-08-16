#include <iostream>
#include <memory>
#include "RecognitionCoreDelegate.h"
#include "TorchDelegate.h"
#include "RecognitionCore.h"

std::shared_ptr<IRecognitionCore> init_recognition_core() {
    std::shared_ptr<IRecognitionCoreDelegate> rec_delegate;
    std::shared_ptr<ITorchDelegate> torch_delegate;
    IRecognitionCoreDelegate::GetInstance(rec_delegate);
    ITorchDelegate::GetInstance(torch_delegate);
    
    std::shared_ptr<IRecognitionCore> rec_core;
    IRecognitionCore::GetInstance(rec_core, rec_delegate, torch_delegate);

    rec_core->SetOrientation(PayCardsRecognizerOrientationPortrait);
    auto working_area = rec_core->CalcWorkingArea({1280, 720}, 32);

    rec_core->SetRecognitionMode(
        (PayCardsRecognizerMode)(
            PayCardsRecognizerModeNumber | PayCardsRecognizerModeDate | PayCardsRecognizerModeName | PayCardsRecognizerModeGrabCardImage
        )
    );

    std::string stdPath("CaffeResources/");

    rec_core->SetPathNumberRecognitionStruct(stdPath + "NumberRecognition/NumberRecognition.prototxt");
    rec_core->SetPathNumberRecognitionModel(stdPath + "NumberRecognition/NumberRecognition.caffemodel");

    rec_core->SetPathNumberLocalizationXModel(stdPath + "NumberLocalization/loc_x.caffemodel");
    rec_core->SetPathNumberLocalizationXStruct(stdPath + "NumberLocalization/loc_x.prototxt");
    rec_core->SetPathNumberLocalizationYModel(stdPath + "NumberLocalization/loc_y.caffemodel");
    rec_core->SetPathNumberLocalizationYStruct(stdPath + "NumberLocalization/loc_y.prototxt");

    rec_core->SetPathDateRecognitionModel(stdPath + "DateRecognition/DateRecognition.caffemodel");
    rec_core->SetPathDateRecognitionStruct(stdPath + "DateRecognition/DateRecognition.prototxt");
    rec_core->SetPathDateLocalization0Model(stdPath + "DateLocalization/DateLocalizationL0.caffemodel");
    rec_core->SetPathDateLocalization0Struct(stdPath + "DateLocalization/DateLocalizationL0.prototxt");
    rec_core->SetPathDateLocalization1Model(stdPath + "DateLocalization/DateLocalizationL1.caffemodel");
    rec_core->SetPathDateLocalization1Struct(stdPath + "DateLocalization/DateLocalizationL1.prototxt");
    rec_core->SetPathDateLocalizationViola(stdPath + "DateLocalization/cascade_date.xml");

    rec_core->SetPathNameLocalizationXModel(stdPath + "NameLocalization/NameLocalizationX.caffemodel");
    rec_core->SetPathNameLocalizationXStruct(stdPath + "NameLocalization/NameLocalizationX.prototxt");
    rec_core->SetPathNameYLocalizationViola(stdPath + "NameLocalization/cascade_name.xml");

    rec_core->SetPathNameSpaceCharModel(stdPath + "NameRecognition/NameSpaceCharRecognition.caffemodel");
    rec_core->SetPathNameSpaceCharStruct(stdPath + "NameRecognition/NameSpaceCharRecognition.prototxt");
    rec_core->SetPathNameListTxt(stdPath + "NameRecognition/names.txt");

    rec_core->Deploy();

    return rec_core;
}

cv::Mat get_image(const char* input_filename) {
    cv::Mat bgr_image = cv::imread(input_filename);
    std::cout << "bgr image " << bgr_image.size() << std::endl;
    cv::resize(bgr_image, bgr_image, {720, 1280}, 0.0, 0.0, cv::INTER_CUBIC);

    cv::Mat yuv_image;
    cv::cvtColor(bgr_image, yuv_image, cv::COLOR_BGR2YUV_I420);
    std::cout << "yuv image " << yuv_image.size() << std::endl;

    return yuv_image;
}

void do_recognition(std::shared_ptr<IRecognitionCore>& rec_core, cv::Mat& image) {
    DetectedLineFlags detected_lines;
    int buffer_size = image.size().area() / 3 * 2;

    rec_core.get()->ProcessFrame(detected_lines, (void*)(image.data), (void*)(image.data + buffer_size), buffer_size, buffer_size / 2);
    std::cout << "Result line T detection: " << !!(detected_lines & DetectedLineTopFlag) << std::endl;
    std::cout << "Result line B detection: " << !!(detected_lines & DetectedLineBottomFlag) << std::endl;
    std::cout << "Result line L detection: " << !!(detected_lines & DetectedLineLeftFlag) << std::endl;
    std::cout << "Result line R detection: " << !!(detected_lines & DetectedLineRightFlag) << std::endl;
}

int main(int argc, const char * argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <image-filename>" << std::endl;
        return 1;
    }
    cv::Mat image = get_image(argv[1]);
    std::shared_ptr<IRecognitionCore> rec_core = init_recognition_core();
    do_recognition(rec_core, image);    
    std::cout << "Done!\n";
    return 0;
}
