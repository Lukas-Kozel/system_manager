#include "Client_bridge.h"

Client_bridge::Client_bridge(RPCclient* client, QObject* parent): QObject(parent), client_(client) {

    client_->setTemperatureDataCallback([this](float temperature, const std::string& timestamp) {
        emit temperatureUpdated(temperature, QString::fromStdString(timestamp));
    });
}
