#include "headers/winfolder.h"
#include "ui_winfolder.h"
#include <QCloseEvent>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QStandardPaths>
#include <QDebug>

WinFolder::WinFolder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinFolder)
{
    ui->setupUi(this);

    // Mettre à jour le titre de la fenêtre avec le texte par défaut en anglais
    ui->labelTitre->setText(tr("Get a bank folder"));

    // Mettre à jour la description avec le texte par défaut en anglais
    ui->labelDescription->setText(tr("<p>This window allows you to manage bank folders.</p><p>Select a folder from the dropdown list to start.</p>"));

    // Ajouter l'élément "New bank file..." à la comboBox_Folder
    ui->comboBox_Folder->addItem(tr("New bank file..."));

    // Déterminer le chemin pour le fichier "folder.icb" selon le système d'exploitation
    QString filePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/folder.icb";

    // Lire le fichier "folder.icb" et ajouter les dossiers à la comboBox_Folder
    QFile file(filePath);
    if (!file.exists()) {
        // Créer le fichier s'il n'existe pas
        if (!file.open(QIODevice::WriteOnly)) {
            qDebug() << "Unable to create file";
            return;
        }
        file.close();
    }

    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(';');
            for (const QString &field : fields) {
                QStringList parts = field.split(',');
                if (parts.size() == 2) {
                    QString folderName = parts.at(0).trimmed();
                    QString folderPath = parts.at(1).trimmed();
                    ui->comboBox_Folder->addItem(folderName, folderPath);
                }
            }
        }
        file.close();
    } else {
        qDebug() << "Unable to open file";
    }
}

WinFolder::~WinFolder()
{
    delete ui;
}

void WinFolder::on_Btn_Ok_clicked()
{
    this->accept(); // Ferme la fenêtre modale
}

void WinFolder::closeEvent(QCloseEvent *event)
{
    event->ignore(); // Ignore l'événement de fermeture
}
