// Copyright (c) 2019 The PIVX developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "qt/fls/settings/settingsfaqwidget.h"
#include "qt/fls/settings/forms/ui_settingsfaqwidget.h"
#include <QScrollBar>
#include <QMetaObject>
#include "qt/fls/qtutils.h"

SettingsFaqWidget::SettingsFaqWidget(FLSGUI *parent) :
    QDialog(parent),
    ui(new Ui::SettingsFaqWidget)
{
    ui->setupUi(this);

    this->setStyleSheet(parent->styleSheet());

    ui->labelTitle->setText(tr("Frequently Asked Questions"));
    ui->labelWebLink->setText(tr("You can read more here"));
#ifdef Q_OS_MAC
    ui->container->load("://bg-welcome");
    setCssProperty(ui->container, "container-welcome-no-image");
#else
    setCssProperty(ui->container, "container-welcome");
#endif
    setCssProperty(ui->labelTitle, "text-title-faq");
    setCssProperty(ui->labelWebLink, "text-content-white");

    // Content
    setCssProperty({
           ui->labelNumber1,
           ui->labelNumber2,
           ui->labelNumber3,
           ui->labelNumber4,
           ui->labelNumber5,
           ui->labelNumber6,
           ui->labelNumber7,
           ui->labelNumber8,
           ui->labelNumber9,
           ui->labelNumber10
        }, "container-number-faq");

    setCssProperty({
              ui->labelSubtitle1,
              ui->labelSubtitle2,
              ui->labelSubtitle3,
              ui->labelSubtitle4,
              ui->labelSubtitle5,
              ui->labelSubtitle6,
              ui->labelSubtitle7,
              ui->labelSubtitle8,
              ui->labelSubtitle9,
              ui->labelSubtitle10
            }, "text-subtitle-faq");


    setCssProperty({
              ui->labelContent1,
              ui->labelContent2,
              ui->labelContent3,
              ui->labelContent4,
              ui->labelContent5,
              ui->labelContent6,
              ui->labelContent7,
              ui->labelContent8,
              ui->labelContent9,
              ui->labelContent10
            }, "text-content-faq");


    setCssProperty({
              ui->pushButtonFaq1,
              ui->pushButtonFaq2,
              ui->pushButtonFaq3,
              ui->pushButtonFaq4,
              ui->pushButtonFaq5,
              ui->pushButtonFaq6,
              ui->pushButtonFaq7,
              ui->pushButtonFaq8,
              ui->pushButtonFaq9,
              ui->pushButtonFaq10
            }, "btn-faq-options");

    ui->labelContent3->setOpenExternalLinks(true);
    ui->labelContent5->setOpenExternalLinks(true);
    ui->labelContent8->setOpenExternalLinks(true);

    // Exit button
    ui->pushButtonExit->setText(tr("Exit"));
    setCssProperty(ui->pushButtonExit, "btn-faq-exit");

    // Web Link
    ui->pushButtonWebLink->setText("https://flitsnode.app/");
    setCssProperty(ui->pushButtonWebLink, "btn-faq-web");
    setCssProperty(ui->containerButtons, "container-faq-buttons");

    // Buttons
    connect(ui->pushButtonExit, &QPushButton::clicked, this, &SettingsFaqWidget::close);
    connect(ui->pushButtonFaq1, &QPushButton::clicked, this, &SettingsFaqWidget::onFaq1Clicked);
    connect(ui->pushButtonFaq2, &QPushButton::clicked, this, &SettingsFaqWidget::onFaq2Clicked);
    connect(ui->pushButtonFaq3, &QPushButton::clicked, this, &SettingsFaqWidget::onFaq3Clicked);
    connect(ui->pushButtonFaq4, &QPushButton::clicked, this, &SettingsFaqWidget::onFaq4Clicked);
    connect(ui->pushButtonFaq5, &QPushButton::clicked, this, &SettingsFaqWidget::onFaq5Clicked);
    connect(ui->pushButtonFaq6, &QPushButton::clicked, this, &SettingsFaqWidget::onFaq6Clicked);
    connect(ui->pushButtonFaq7, &QPushButton::clicked, this, &SettingsFaqWidget::onFaq7Clicked);
    connect(ui->pushButtonFaq8, &QPushButton::clicked, this, &SettingsFaqWidget::onFaq8Clicked);
    connect(ui->pushButtonFaq9, &QPushButton::clicked, this, &SettingsFaqWidget::onFaq9Clicked);
    connect(ui->pushButtonFaq10, &QPushButton::clicked, this, &SettingsFaqWidget::onFaq10Clicked);

    if (parent)
        connect(parent, &FLSGUI::windowResizeEvent, this, &SettingsFaqWidget::windowResizeEvent);
}

void SettingsFaqWidget::showEvent(QShowEvent *event){
    if(pos != 0){
        QPushButton* btn = getButtons()[pos - 1];
        QMetaObject::invokeMethod(btn, "setChecked", Qt::QueuedConnection, Q_ARG(bool, true));
        QMetaObject::invokeMethod(btn, "clicked", Qt::QueuedConnection);
    }
}

void SettingsFaqWidget::setSection(int num){
    if (num < 1 || num > 10)
        return;
    pos = num;
}

void SettingsFaqWidget::onFaq1Clicked(){
    ui->scrollAreaFaq->verticalScrollBar()->setValue(ui->widgetFaq1->y());
}

void SettingsFaqWidget::onFaq2Clicked(){
   ui->scrollAreaFaq->verticalScrollBar()->setValue(ui->widgetFaq2->y());
}

void SettingsFaqWidget::onFaq3Clicked(){
   ui->scrollAreaFaq->verticalScrollBar()->setValue(ui->widgetFaq3->y());
}

void SettingsFaqWidget::onFaq4Clicked(){
    ui->scrollAreaFaq->verticalScrollBar()->setValue(ui->widgetFaq4->y());
}

void SettingsFaqWidget::onFaq5Clicked(){
    ui->scrollAreaFaq->verticalScrollBar()->setValue(ui->widgetFaq5->y());
}

void SettingsFaqWidget::onFaq6Clicked(){
    ui->scrollAreaFaq->verticalScrollBar()->setValue(ui->widgetFaq6->y());
}

void SettingsFaqWidget::onFaq7Clicked(){
    ui->scrollAreaFaq->verticalScrollBar()->setValue(ui->widgetFaq7->y());
}

void SettingsFaqWidget::onFaq8Clicked(){
    ui->scrollAreaFaq->verticalScrollBar()->setValue(ui->widgetFaq8->y());
}

void SettingsFaqWidget::onFaq9Clicked(){
    ui->scrollAreaFaq->verticalScrollBar()->setValue(ui->widgetFaq9->y());
}

void SettingsFaqWidget::onFaq10Clicked(){
    ui->scrollAreaFaq->verticalScrollBar()->setValue(ui->widgetFaq10->y());
}

void SettingsFaqWidget::windowResizeEvent(QResizeEvent* event)
{
    QWidget* w = qobject_cast<QWidget*>(parent());
    this->resize(w->width(), w->height());
    this->move(QPoint(0, 0));
}

std::vector<QPushButton*> SettingsFaqWidget::getButtons(){
    return {
            ui->pushButtonFaq1,
            ui->pushButtonFaq2,
            ui->pushButtonFaq3,
            ui->pushButtonFaq4,
            ui->pushButtonFaq5,
            ui->pushButtonFaq6,
            ui->pushButtonFaq7,
            ui->pushButtonFaq8,
            ui->pushButtonFaq9,
            ui->pushButtonFaq10
    };
}

SettingsFaqWidget::~SettingsFaqWidget(){
    delete ui;
}


