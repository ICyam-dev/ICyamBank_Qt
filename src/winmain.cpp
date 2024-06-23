#include "headers/winmain.h"
#include "ui_winmain.h"

WinMain::WinMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WinMain)
{
    ui->setupUi(this);

    //Mise en place du menu de la fentre principale
    QMenu *menuFile = menuBar()->addMenu(tr("File"));
    QAction *actionOpen = new QAction(QIcon(":/icone/menu/NewFolder-16.png"), tr("Open a File..."), this);


    menuFile->addAction(actionOpen);
}

WinMain::~WinMain()
{
    delete ui;
}
