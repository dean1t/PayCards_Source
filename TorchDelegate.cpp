#include "TorchDelegate.h"

bool ITorchDelegate::GetInstance(shared_ptr<ITorchDelegate> &torchDelegate,
                                 void* platformDelegate) {
    torchDelegate = std::make_shared<CTorchDelegate>();
    return torchDelegate != 0;
}

void CTorchDelegate::TorchStatusDidChange(bool status) { return; }


