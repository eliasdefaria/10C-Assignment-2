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
signals:
    void compute_overall();


public slots:
    void update_overall(int);
    void update_schema(QString);
<<<<<<< HEAD
    void update_class(QString schema);
=======
>>>>>>> 20aab481563c9cf57d1f947b7040b5e01e3f7c4e

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
