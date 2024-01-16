#include "MainWindow.h"

MainWindow::MainWindow(RPCclient* client, Client_bridge* client_bridge, QWidget *parent) : QMainWindow(parent), Client_bridge(client_bridge), RPCclient(client){
    connect(client_bridge, &Client_bridge::temperatureUpdated, this, &MainWindow::updateTemperatureLabel);
    client->streamData();
    QWidget* centralWidget = new QWidget(this);
    temperatureDataLabel = new QLabel(centralWidget);
}

MainWindow::updateTemperatureLabel(float temperature, const std::string& timestamp){
    QString temp;
    temp.sprintf("temperature: %.3f; timestamp: %s", temperature,timestamp);
    dronePoseLabel->setText(temp);
}