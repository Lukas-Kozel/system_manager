#pragma once
#include <grpcpp/grpcpp.h>
#include "service.grpc.pb.h"
#include "service.pb.h"
#include <functional>

class RPCclient{

    public:
        RPCclient(std::shared_ptr<grpc::Channel> channel);
        using TemperatureDataCallback = std::function<void(float, const std::string&)>;
        void StreamTemperature();
        void setTemperatureDataCallback(TemperatureDataCallback callback);

    private:
        std::unique_ptr<RPC::TemperatureService::Stub> stub_;
        TemperatureDataCallback temperatureDataCallback_;
};