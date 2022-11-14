#ifndef VOYAGEUR_H
#define VOYAGEUR_H
#include<QString>
#include <QDate>
#include<QSqlQuery>
#include<QSqlQueryModel>
//pour stat
#include <QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
//*********************

class voyageur
{
public:
    voyageur(int,QString,QString,QString,QDate);
    //setters
    void setcin(int n);
    void setnom(QString n);
    void setprenom(QString n);
    void setadresse(QString n);
    void setdate(QDate n);
    //getters
    int getcin();
    QString getnom();
    QString getprenom();
    QString getadresse();
    QDate getdate();
    //fonctionalités de base relatives a l entite voyageur
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int cin,QString tel,QString nom,QString prenom,QDate dat);

QSqlQueryModel * trie_NOM();
QSqlQueryModel *trie_ADRESSE();
QSqlQueryModel * trie_CIN();
//QSqlQueryModel * chercher(QString nom);
QSqlQueryModel* recherchernom(QString a);
QSqlQueryModel* rechercheradresse(QString nom);
QSqlQueryModel* recherchercin(QString cin);

bool recherchercin(int cin);

int statistique(QString adresse);





    voyageur();
private:
    int cin;
    QString nom,prenom,adresse;
    QDate date_naissance;


};

#endif // VOYAGEUR_H
