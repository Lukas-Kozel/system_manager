#include "MainWindow.h"

MainWindow::MainWindow(RPCclient* client, Client_bridge* client_bridge, QWidget *parent) 
    : QMainWindow(parent), client_bridge(client_bridge), client(client) {
    connect(client_bridge, &Client_bridge::temperatureUpdated, this, &MainWindow::updateTemperatureLabel);
    client->StreamTemperature();
    QWidget* centralWidget = new QWidget(this);
    temperatureDataLabel = new QLabel(centralWidget);
    this->setCentralWidget(centralWidget);
};

void MainWindow::updateTemperatureLabel(float temperature, const QString& timestamp) {
    QString temp = QString("temperature: %1; timestamp: %2").arg(temperature, 0, 'f', 3).arg(timestamp);
    temperatureDataLabel->setText(temp);
}
