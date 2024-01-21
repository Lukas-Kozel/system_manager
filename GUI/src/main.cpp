#include <QApplication>
#include <QWidget>
#include "MainWindow.h"
#include "Client_bridge.h"
#include "RPC_client.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    RPCclient* client = new RPCclient(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
    Client_bridge* bridge = new Client_bridge(client, nullptr);
    MainWindow window(client,bridge);
    window.show();
    return app.exec();
}
