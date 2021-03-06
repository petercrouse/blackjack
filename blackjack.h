#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "deck.h"
#include "handview.h"
#include <QMainWindow>

class QActionGroup;

namespace Ui {
class BlackJack;
}

class BlackJack : public QMainWindow
{
    Q_OBJECT
public:
    explicit BlackJack(QWidget *parent = 0);
    ~BlackJack();
    void loadSettings();   
    void deal();
protected:
    virtual void readSettings();
    virtual void writeSettings();
private slots:
    void actionEvent(QAction *event);
    void closeEvent(QCloseEvent *event);    
private:
    Ui::BlackJack *ui;
    Deck deck;
    Hand *player;
    Hand *dealer;
    HandView* playerView;
    HandView* dealerView;
    QActionGroup* actionGroup;
    void drawCard(Card* card, QString name);
    int pScore;
    int dScore;
};

#endif // BLACKJACK_H
