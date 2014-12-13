#ifndef WINSCREENENDGAME_H
#define WINSCREENENDGAME_H

#include <QDialog>

namespace Ui {
class WinScreenEndGame;
}

class WinScreenEndGame : public QDialog
{
    Q_OBJECT

public:
    explicit WinScreenEndGame(QWidget *parent = 0);
    ~WinScreenEndGame();

private slots:
    void on_ReturnToMain_clicked();

private:
    Ui::WinScreenEndGame *ui;
};

#endif // WINSCREENENDGAME_H
