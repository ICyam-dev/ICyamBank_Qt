#include "headers/winfolder.h"
#include "ui_winfolder.h"

WinFolder::WinFolder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinFolder)
{
    ui->setupUi(this);

    // Mettre à jour le titre de la fenêtre avec le texte traduit
    ui->labelTitre->setText(tr("Obtain a bank file"));
}

WinFolder::~WinFolder()
{
    delete ui;
}

void WinFolder::on_Btn_Ok_clicked()
{
    this->accept(); // Ferme la fenêtre modale
}
