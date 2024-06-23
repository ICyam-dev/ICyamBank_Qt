#include "headers/winmain.h"
#include "headers/winfolder.h"
#include "ui_winmain.h"

WinMain::WinMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WinMain)
{
    ui->setupUi(this);

    //Mise en place du menu de la fentre principale
    QMenu *menuFile = menuBar()->addMenu(tr("File"));
    QAction *actionOpen = new QAction(QIcon(":/icone/menu/NewFolder-16.png"), tr("Open a File..."), this);

    // Connecter l'action "Open a File..." au slot openWinFolder
    connect(actionOpen, &QAction::triggered, this, &WinMain::openWinFolder);

    menuFile->addAction(actionOpen);

}

WinMain::~WinMain()
{
    delete ui;
}

void WinMain::openWinFolder()
{
    WinFolder winFolderDialog(this);
    winFolderDialog.exec(); // Ouvre en mode modal
}
