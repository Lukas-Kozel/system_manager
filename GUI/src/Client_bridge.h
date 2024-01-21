#pragma once 
#include <QObject>
#include "RPC_client.h"

class Client_bridge : public QObject{
    Q_OBJECT

    public:
        Client_bridge(RPCclient* client, QObject* parent = nullptr);

    signals:
        void temperatureUpdated(float temperature, const QString& timestamp);
    
    private slots:
        void onTemperatureReceived(float temperature, const std::string& timestamp);

    private:
        RPCclient* client_;
};