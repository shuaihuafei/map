#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QDebug"
#include "QImage"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "I am runing!!!";
    this->setFixedHeight(800);
    this->setFixedWidth(1200);
    ui->label_pic->setFixedHeight(700);
    ui->label_pic->setFixedWidth(850);
    ui->label_log->setFixedHeight(50);
    ui->label_log->setFixedWidth(50);
    QPixmap img_log;
    img_log.load("/home/shuai/QtProjects/map/pictures/gaode.png");
    QPixmap fit_img_log = img_log.scaled(ui->label_log->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_log->setPixmap(fit_img_log);
    ui->label_log->setAlignment(Qt::AlignCenter);
    ui->label_log->show();

    QPixmap img_before;
    QPixmap img_after;
    img_before.load("/home/shuai/QtProjects/map/pictures/before.png");
    img_after.load("/home/shuai/QtProjects/map/pictures/after.png");
    QPixmap fit_img_before = img_before.scaled(ui->label_pic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    QPixmap fit_img_after = img_after.scaled(ui->label_pic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_pic->setPixmap(fit_img_before);
    ui->label_pic->setAlignment(Qt::AlignCenter);
    ui->label_pic->show();
    connect(ui->pushButton,&QPushButton::clicked,this,[=](){
        ui->textEdit->setText("路径生成成功!!!");
        ui->label_pic->setPixmap(fit_img_after);
        ui->label_pic->setAlignment(Qt::AlignCenter);
        ui->label_pic->show();
    });
    connect(ui->action, &QAction::triggered,this,[=](){
        ui->textEdit->setText("");
        ui->label_pic->setPixmap(fit_img_before);
        ui->label_pic->setAlignment(Qt::AlignCenter);
        ui->label_pic->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

