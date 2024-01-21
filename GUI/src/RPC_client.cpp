#include "RPC_client.h"


RPCclient::RPCclient(std::shared_ptr<grpc::Channel> channel): stub_(RPC::TemperatureService::NewStub(channel)){}

void RPCclient::setTemperatureDataCallback(TemperatureDataCallback callback) {
    temperatureDataCallback_ = callback;
}


void RPCclient::StreamTemperature(){
        RPC::StreamRequest request;
        grpc::ClientContext context;

        auto reader = stub_->StreamTemperature(&context,request);
        RPC::TemperatureData data;

        while(reader->Read(&data)){
            std::cout << "Received temperature: " << data.temperature()
            << ", Timestamp: " << data.timestamp() << std::endl;
            if (temperatureDataCallback_) {
                temperatureDataCallback_(data.temperature(), data.timestamp());
            }
        }
        grpc::Status status = reader->Finish();
        if (!status.ok()) {
            std::cerr << "StreamTemperature RPC failed." << std::endl;
        }
}