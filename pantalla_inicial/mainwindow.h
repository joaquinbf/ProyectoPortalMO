#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_botonNuevaPartida_clicked();

    void on_botonBuscarServidor_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
