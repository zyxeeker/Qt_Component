//
// Created by zyx on 2021/7/21.
//

#ifndef QT_COMPONENT_SCALABLEMENU_H
#define QT_COMPONENT_SCALABLEMENU_H

#include <QWidget>
#include <QPushButton>
#include <QSplitter>
#include <QFrame>
#include <QSplitterHandle>

QT_BEGIN_NAMESPACE
namespace Ui { class ScalableMenu; }
QT_END_NAMESPACE

class ScalableMenu : public QWidget {
Q_OBJECT

public:
    explicit ScalableMenu(int rMin, int rMax, int btnW, int btnH, int handleW = 5, QWidget *parent = nullptr);

    ~ScalableMenu() override;

private:
    Ui::ScalableMenu *ui;
    QPushButton *m_button;
    int m_maxWidth;
    int m_minWidth;
    int m_handleWidth;
    int m_btnWidth;
    int m_btnHeight;
private:
    void _Init();

    void _SetBtnPos();

    void _SetBtnIcon();

private slots:

    void BtnClicked();

    void SplitterMoved(int pos, int index);

protected:
    void showEvent(QShowEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;
};


#endif //QT_COMPONENT_SCALABLEMENU_H
