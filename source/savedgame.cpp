#include "savedgame.h"
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QDir>
#include <QDebug>
#include <QStringList>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>

SavedGame::SavedGame()
{
}

bool SavedGame::Load(QString const& configPath, QString const& configFileName)
{

    QDir qDir;
    IsLoaded = false;

    configFile = new QFile(configPath + configFileName);
    QStringList sqlValues;

    if (!configFile->exists()) {
        return false;
    } else {
        if (!configFile->open(QIODevice::ReadOnly)) {
            qDebug() << "Cannot open file: " << qPrintable(configFile->errorString()) << endl;
        } else {
            QTextStream in(configFile);
            if (!in.atEnd()) {
                QString inLine = in.readLine();
                sqlValues = inLine.split('|');
            }
            configFile->close();

            if (sqlValues.count() == 4) {

                QString host = sqlValues.at(0);
                QString user = sqlValues.at(1);
                QString password = sqlValues.at(2);
                QString dbname = sqlValues.at(3);

                this->db = QSqlDatabase::addDatabase("QMYSQL");
                db.setHostName(host);
                db.setDatabaseName(dbname);
                db.setUserName(user);
                db.setPassword(password);
                if (db.open()) {
                    this->IsLoaded = true;
                    this->savedGames.clear();
                    QSqlQuery query;
                    query.exec("SELECT * FROM saved_games order by id desc");
                    while (query.next()) {
                        QString game("%1|%2|%3");
                        game = game.arg(query.value(1).toString()).arg(query.value(2).toString()).arg(query.value(3).toString());
                        this->savedGames.append(game);
                    }
                    db.close();
                }

                qDebug() << "Number Of Games Loaded: " << this->savedGames.count();
                return true;
            }
        }
    }
    return false;
}



QStringList SavedGame::GetSavedGameList() {
    return this->savedGames;
}

QString SavedGame::GetSavedGame(int gameNumber) {
    return this->savedGames.at(gameNumber);
}

int SavedGame::GetSavedGameCount() {
    return this->savedGames.count();
}

bool SavedGame::GetIsLoaded()
{
    return this->IsLoaded;
}

void SavedGame::AddGame(int x, int y, int experience) {
    QString game("%1|%2|%3");
    game = game.arg(x).arg(y).arg(experience);
    qDebug() << "Added Game: " << game;
    try {
        if (db.open()) {
            qDebug() << "AddGame: Database opened!" << endl;
            this->IsLoaded = true;
            this->savedGames.clear();
            QSqlQuery query;
            query.prepare("INSERT INTO saved_games (x, y, health) values (:x,:y,:health)");
            query.bindValue(":x",x);
            query.bindValue(":y",y);
            query.bindValue(":health",experience);
            if (query.exec()) {
              qDebug() << "AddGame: Game added!" << endl;
            }
            db.close();
            this->savedGames.append(game);
        }
        else
        {
            qDebug() << "AddGame: Unable to open database!" << endl;
        }
    } catch (std::exception exc) {
        qDebug() << "Unable to save game: " << exc.what() << endl;
    }
}
