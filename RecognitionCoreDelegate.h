#ifndef RecognitionCoreDelegate_hpp
#define RecognitionCoreDelegate_hpp

#include "IRecognitionCoreDelegate.h"

class CRecognitionCoreDelegate : public IRecognitionCoreDelegate {
public:

    virtual ~CRecognitionCoreDelegate() {};
    
public:
    virtual void RecognitionDidFinish(const shared_ptr<IRecognitionResult>& result, PayCardsRecognizerMode resultFlags);
    virtual void CardImageDidExtract(cv::Mat cardImage);
};

#endif /* RecognitionCoreDelegate_hpp */
