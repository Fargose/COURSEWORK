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
    void on_StartButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_listWidget_currentRowChanged(int currentRow);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
