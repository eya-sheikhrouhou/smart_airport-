#ifndef ARDUINO_H
#define ARDUINO_H
#include<QtSerialPort/QSerialport>
#include<QtSerialport/QSerialportInfo>


class Arduino
{
public:
    int connect_arduino();//permet de conecter le pc a arduino
    int close_arduino();//permet de fermer la connection
    int write_to_arduino(QByteArray);//envoyer les donnees vers arduino
    QByteArray read_from_arduino();
    QSerialPort* getserial();//accesseur
    QString getarduino_port_name();
    Arduino();
private:
    QSerialPort* serial;//objet rassemble des infos(vitesse,bits de donnee..)
    //et des fonctions(envoi,lecture de réception)sur ce qu est une voie serie pour arduino
   static const quint16 arduino_uno_vendor_id=9025;
   static const quint16 arduino_uno_producy_id=67;
   QString arduino_port_name;
   bool arduino_is_available;
   QByteArray data ; //contenat les donnes lues a partir d arduino
};

#endif // ARDUINO_H
