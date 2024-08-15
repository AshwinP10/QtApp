#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), socket(new QTcpSocket(this)), videoLabel(new QLabel(this)) {

    // Set up the GUI
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(videoLabel);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Connect to the TCP server
    socket->connectToHost("raspberry_pi_ip", 12345); // Replace with your Raspberry Pi's IP and port

    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::onReadyRead);
}

MainWindow::~MainWindow() {
}

void MainWindow::onReadyRead() {
    while (socket->canReadLine()) {
        // Read incoming data
        QByteArray data = socket->readAll();
        
        // Append to buffer
        buffer.append(data);
        
        // For demonstration purposes, let's assume the data contains raw RGB frames
        // Convert the buffer to QImage and display
        QImage img(reinterpret_cast<const uchar*>(buffer.constData()), 640, 480, QImage::Format_RGB888);
        videoLabel->setPixmap(QPixmap::fromImage(img));

        // Clear buffer for next frame
        buffer.clear();
    }
}
