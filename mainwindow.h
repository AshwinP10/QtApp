#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QImage>
#include <QLabel>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onReadyRead();

private:
    QTcpSocket *socket;
    QLabel *videoLabel;
    QImage image;
    QByteArray buffer;
};

#endif // MAINWINDOW_H
