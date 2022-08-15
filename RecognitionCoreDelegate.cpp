#include "RecognitionCoreDelegate.h"

bool IRecognitionCoreDelegate::GetInstance(shared_ptr<IRecognitionCoreDelegate> &recognitionDelegate,
                                           void* platformDelegate, void* recognizer) {
    recognitionDelegate = std::make_shared<CRecognitionCoreDelegate>();
    return recognitionDelegate != 0;
}

void CRecognitionCoreDelegate::RecognitionDidFinish(const shared_ptr<IRecognitionResult>& result, PayCardsRecognizerMode resultFlags) { return; }

void CRecognitionCoreDelegate::CardImageDidExtract(cv::Mat cardImage) { return; }
