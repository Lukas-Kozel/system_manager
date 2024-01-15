#include "Client_bridge.h"

Client_bridge::Client_bridge(RPCclient* client, QObject* parent)
    : QObject(parent), client_(client) {
    connect(client_, &RPCclient::newTemperatureData, this, &Client_bridge::onTemperatureReceived);
}

void Client_bridge::onTemperatureReceived(float temperature, const std::string& timestamp) {
    emit temperatureUpdated(temperature, QString::fromStdString(timestamp));
}
