#include <iostream>
#include <memory>
#include "RecognitionCoreDelegate.h"
#include "TorchDelegate.h"
#include "RecognitionCore.h"


int main(int argc, const char * argv[]) {
    std::shared_ptr<IRecognitionCoreDelegate> rec_delegate;
    std::shared_ptr<ITorchDelegate> torch_delegate;
    IRecognitionCoreDelegate::GetInstance(rec_delegate);
    ITorchDelegate::GetInstance(torch_delegate);
    
    std::shared_ptr<IRecognitionCore> rec_core;
    IRecognitionCore::GetInstance(rec_core, rec_delegate, torch_delegate);

    cv::Mat bgr_image = cv::imread("/Users/20142423/Desktop/work/paycards_source_deanit/warped.png");
    cv::Mat bgr_image_resized;
    cv::Mat yuv_image;
    cv::resize(bgr_image, bgr_image_resized, {720, 1280}, 0.0, 0.0, INTER_CUBIC);
    cv::cvtColor(bgr_image_resized, yuv_image, COLOR_BGR2YUV_I420);

    std::cout << "bgr image " << bgr_image.size() << std::endl;
    std::cout << "yuv image " << yuv_image.size() << std::endl;

    if (auto rec_core_p = rec_core.get()) {
        rec_core_p->SetOrientation(PayCardsRecognizerOrientationPortrait);
        auto working_area = rec_core_p->CalcWorkingArea({1280, 720}, 32);

        rec_core_p->SetRecognitionMode(PayCardsRecognizerModeNumber);

        auto stdPath = std::string("/Users/20142423/Desktop/work/paycards_source_deanit/PayCardsRecognizer/CaffeResources/");

        rec_core_p->SetPathNumberRecognitionStruct(stdPath + "NumberRecognition/NumberRecognition.prototxt");
        rec_core_p->SetPathNumberRecognitionModel(stdPath + "NumberRecognition/NumberRecognition.caffemodel");

        rec_core_p->SetPathNumberLocalizationXModel(stdPath + "NumberLocalization/loc_x.caffemodel");
        rec_core_p->SetPathNumberLocalizationXStruct(stdPath + "NumberLocalization/loc_x.prototxt");
        rec_core_p->SetPathNumberLocalizationYModel(stdPath + "NumberLocalization/loc_y.caffemodel");
        rec_core_p->SetPathNumberLocalizationYStruct(stdPath + "NumberLocalization/loc_y.prototxt");

        rec_core_p->SetPathDateRecognitionModel(stdPath + "DateRecognition/DateRecognition.caffemodel");
        rec_core_p->SetPathDateRecognitionStruct(stdPath + "DateRecognition/DateRecognition.prototxt");
        rec_core_p->SetPathDateLocalization0Model(stdPath + "DateLocalization/DateLocalizationL0.caffemodel");
        rec_core_p->SetPathDateLocalization0Struct(stdPath + "DateLocalization/DateLocalizationL0.prototxt");
        rec_core_p->SetPathDateLocalization1Model(stdPath + "DateLocalization/DateLocalizationL1.caffemodel");
        rec_core_p->SetPathDateLocalization1Struct(stdPath + "DateLocalization/DateLocalizationL1.prototxt");
        rec_core_p->SetPathDateLocalizationViola(stdPath + "DateLocalization/cascade_date.xml");

        rec_core_p->SetPathNameLocalizationXModel(stdPath + "NameLocalization/NameLocalizationX.caffemodel");
        rec_core_p->SetPathNameLocalizationXStruct(stdPath + "NameLocalization/NameLocalizationX.prototxt");
        rec_core_p->SetPathNameYLocalizationViola(stdPath + "NameLocalization/cascade_name.xml");

        rec_core_p->SetPathNameSpaceCharModel(stdPath + "NameRecognition/NameSpaceCharRecognition.caffemodel");
        rec_core_p->SetPathNameSpaceCharStruct(stdPath + "NameRecognition/NameSpaceCharRecognition.prototxt");
        rec_core_p->SetPathNameListTxt(stdPath + "NameRecognition/names.txt");

        rec_core_p->Deploy();
    }

    DetectedLineFlags res;
    int buffer_size = yuv_image.size().area() / 3 * 2;

    rec_core.get()->ProcessFrame(res, (void*)(yuv_image.data), (void*)(yuv_image.data + buffer_size), buffer_size, buffer_size / 2);

    std::cout << "Done!\n";
    return 0;
}
