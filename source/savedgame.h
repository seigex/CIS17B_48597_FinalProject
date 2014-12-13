#ifndef SAVEDGAME_H
#define SAVEDGAME_H

#include <QString>
#include <QFile>
#include <QStringList>
#include <QSqlDatabase>

class SavedGame
{
private:
    QFile *configFile;
    QStringList savedGames;
    bool SaveGamesToFile();
    bool SaveGamesToDB();
    bool IsLoaded;
    QSqlDatabase db;

public:
    SavedGame();
    bool Load(QString const& configPath, QString const& configFileName);
    QStringList GetSavedGameList();
    int GetSavedGameCount();
    QString GetSavedGame(int gameNumber);
    bool GetIsLoaded();

    void AddGame(int x, int y, int experience);

    bool SaveGame();
    bool DeleteGame();
    int* getGame(int gameNumber);
    bool isLoaded();

};

#endif // SAVEDGAME_H
