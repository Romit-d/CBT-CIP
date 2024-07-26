#ifndef FCLACULATOR_H
#define FCLACULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class FClaculator;
}
QT_END_NAMESPACE

class FClaculator : public QMainWindow
{
    Q_OBJECT

public:
    FClaculator(QWidget *parent = nullptr);
    ~FClaculator();

private:
    Ui::FClaculator *ui;

private slots:
    void numpressed();
    void equalbutton();
    void buttonmathpressed();
    void changesign();
    void refresh();
};
#endif // FCLACULATOR_H
