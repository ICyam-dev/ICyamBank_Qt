#ifndef WINFOLDER_H
#define WINFOLDER_H

#include <QDialog>

namespace Ui {
class WinFolder;
}

class WinFolder : public QDialog
{
    Q_OBJECT

public:
    explicit WinFolder(QWidget *parent = nullptr);
    ~WinFolder();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_Btn_Ok_clicked();

private:
    Ui::WinFolder *ui;
};

#endif // WINFOLDER_H
