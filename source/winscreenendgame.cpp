#include "winscreenendgame.h"
#include "ui_winscreenendgame.h"
#include <QApplication>

WinScreenEndGame::WinScreenEndGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinScreenEndGame)
{

    ui->setupUi(this);

    //Setting Background image for TitleScreen Ui - Miguel
    QPixmap bg(":/Background.png");
    bg = bg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bg);
    this->setPalette(palette);


}

WinScreenEndGame::~WinScreenEndGame()
{
    delete ui;
}

void WinScreenEndGame::on_ReturnToMain_clicked()
{
    //Exit the entire program
    //WinScreenEndGame endgame;
    //endgame.setModal(true);
    //endgame.exec();


    //End the game it is now working
    QApplication::quit();
}
