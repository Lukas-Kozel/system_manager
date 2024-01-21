#include <QMainWindow>
#include "Client_bridge.h"
#include "RPC_client.h"
#include <QWidget>
#include <QString>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(RPCclient* client,Client_bridge* client_bridge, QWidget *parent = nullptr);
    QLabel* temperatureDataLabel;

private:
    Client_bridge* client_bridge;
    RPCclient* client;

private slots:
    void updateTemperatureLabel(float temperature, const QString& timestamp);

};