#ifndef TorchDelegate_hpp
#define TorchDelegate_hpp

#include "ITorchDelegate.h"

class CTorchDelegate : public ITorchDelegate {
public:
    
    virtual ~CTorchDelegate() {};
    
public:
    virtual void TorchStatusDidChange(bool status);
};


#endif /* TorchDelegate_hpp */
