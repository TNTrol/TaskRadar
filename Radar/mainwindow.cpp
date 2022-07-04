#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QTextEdit>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto *v = new QVBoxLayout();
    auto *h = new QHBoxLayout();

    m_render = new RenderWidget();
    auto *w = new QWidget();
    auto *button = new QPushButton("Channge position");
    m_text = new QLineEdit();
    h->addWidget(m_text, 1);
    h->addWidget(button, 4);
    h->addWidget(new QWidget(), 5);
    v->addLayout(h, 1);
    v->addWidget(m_render, 20);
    w->setLayout(v);

    connect(button, &QPushButton::released, this, &MainWindow::clickChange);

    this->setCentralWidget(w);
    this->setBaseSize(QSize(200, 500));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_render;
}

void MainWindow::clickChange()
{
    bool check = false;
    float angle = m_text->text().toFloat(&check);
    if(check)
    {
        m_render->setAngle(angle);
    }
    m_render->repaint();
    m_text->clear();
}



