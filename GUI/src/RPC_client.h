#pragma once
#include <grpcpp/grpcpp.h>
#include "service.grpc.pb.h"
#include "service.pb.h"


class RPCclient{

    public:
        RPCclient(std::shared_ptr<grpc::Channel> channel);
        using TemperatureDataCallback = std::function<void(float, const std::string&)>;
        void streamData();
        void setTemperatureDataCallback(TemperatureDataCallback callback);

    private:
        std::unique_ptr<service::TemperatureService::Stub> stub_;
        TemperatureDataCallback temperatureDataCallback_;
}
