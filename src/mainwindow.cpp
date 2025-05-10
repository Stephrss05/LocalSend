#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	ui->comboBox->addItems({ "Receiver mode", "Sender mode"});
	connect(ui->comboBox, &QComboBox::currentIndexChanged, this, [this](int index) {
		ui->stackedWidget->setCurrentIndex(index);
		});

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::page1Widget()
{
	ui->stackedWidget->setCurrentIndex(0);


}

void MainWindow::page2Widget()
{
	ui->stackedWidget->setCurrentIndex(1);


}

