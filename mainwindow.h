#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// my dependencies
#include <QFile> // work with files
#include <QFileDialog> // dialogs to save/ open files
#include <QTextStream> //read text from files
#include <QMessageBox> //show messages
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);//no tiene parents
    ~MainWindow();// distructor: liberar recursor

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_As_triggered();

    void on_actionSave_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionPrint_triggered();

private:
    Ui::MainWindow *ui;
    QString currentFile = "";
};
#endif // MAINWINDOW_H
