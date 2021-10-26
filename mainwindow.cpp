#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->mainTextEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    currentFile.clear();
    ui->mainTextEdit->setText(QString());
}


void MainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Choose a File");
    QFile file(filename);
    currentFile = filename;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this,"Warning","cannot open file :" + file.errorString());
        return;
    }
    setWindowTitle(filename);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->mainTextEdit->setText(text);
    file.close();

}


void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save file as");
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this,"Warning","cannot save file :" + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->mainTextEdit->toPlainText();
    out << text;
    file.close();
}


void MainWindow::on_actionSave_triggered()
{
    QString fileName = windowTitle();
    if(fileName == "MainWindow"){
        MainWindow::on_actionSave_As_triggered();
        return;
    }
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this,"Warning","cannot save file :" + file.errorString());
        return;
    }
    currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->mainTextEdit->toPlainText();
    out << text;
    file.close();
    QMessageBox::information(this,"File Saved","File Succesfuly Save");
}


void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->mainTextEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->mainTextEdit->paste();
}


void MainWindow::on_actionCut_triggered()
{
    ui->mainTextEdit->cut();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->mainTextEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->mainTextEdit->redo();
}


void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Printer Name");
    QPrintDialog pDialog(&printer,this);
    if (pDialog.exec() == QDialog::Rejected ) {
        QMessageBox::warning(this,"Warning","Cannot Access The Printer");
        return;
    }

    ui->mainTextEdit->print(&printer);
}

