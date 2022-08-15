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
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
