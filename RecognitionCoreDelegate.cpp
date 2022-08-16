#include <iostream>
#include <sstream>
#include <opencv2/opencv.hpp>

#include "RecognitionCoreDelegate.h"
#include "IRecognitionResult.h"
#include "INeuralNetworkResult.h"
#include "INeuralNetworkResultList.h"

static const std::vector<string> alphabet = {" ","A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};

bool IRecognitionCoreDelegate::GetInstance(shared_ptr<IRecognitionCoreDelegate> &recognitionDelegate,
                                           void* platformDelegate, void* recognizer) {
    recognitionDelegate = std::make_shared<CRecognitionCoreDelegate>();
    return recognitionDelegate != 0;
}

void CRecognitionCoreDelegate::RecognitionDidFinish(const shared_ptr<IRecognitionResult>& result, PayCardsRecognizerMode resultFlags) {
    if (resultFlags & PayCardsRecognizerModeNumber) {
        std::ostringstream number_ss;
        if (auto numberResult = result->GetNumberResult()) {
            for (auto it = numberResult->Begin(); it != numberResult->End(); ++it) {
                number_ss << (*it)->GetMaxIndex();
            }
        }
        std::cout << "Result Number: " << number_ss.str() << std::endl;
    }

    if (resultFlags & PayCardsRecognizerModeDate) {
        std::ostringstream date_ss;
        if (auto dateResult = result->GetDateResult()) {
            for (auto it = dateResult->Begin(); it != dateResult->End(); ++it) {
                date_ss << (*it)->GetMaxIndex();
            }
        }
        std::cout << "Result Date: " << date_ss.str() << std::endl;
    }

    if (resultFlags & PayCardsRecognizerModeName) {
        auto name =  result->GetPostprocessedName();
        std::cout << "Result Name: " << name << std::endl;

        std::ostringstream raw_name_ss;
        if (auto nameResult = result->GetNameResult()) {
            for (auto it = nameResult->Begin(); it != nameResult->End(); ++it) {
                raw_name_ss << alphabet[(*it)->GetMaxIndex()];
            }
        }
        std::cout << "Result Raw name: " << raw_name_ss.str() << std::endl;
    }
}

void CRecognitionCoreDelegate::CardImageDidExtract(cv::Mat cardImage) {
    if (!cardImage.empty()) {
        cv::cvtColor(cardImage, cardImage, cv::COLOR_RGB2BGR);
        cv::imwrite("card.png", cardImage);
    }
    return;
}
