#pragma once
#include <grpcpp/grpcpp.h>
#include "RPC/service.grpc.pb.h"
#include "RPC/service.pb.h"


class RPCclient{

    public:
        RPCclient(std::shared_ptr<grpc::Channel> channel);

        void streamData();
    private:
        std::unique_ptr<service::TemperatureService::Stub> stub_;
}
