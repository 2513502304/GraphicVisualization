#pragma once
#pragma execution_character_set("utf-8")

#include <QDialog>
#include <QSpinBox>

using namespace std;

namespace Ui
{
    class AttributeDialog;
}

class AttributeDialog : public QDialog
{
    Q_OBJECT

public:
    // 绘图状态
    enum DrawState
    {
        NoDrawState,
        DrawPointState,
        DrawLineState,
        DrawPolylineState,
        DrawRectangleState,
        DrawCircleState,
        DrawSectorState,
        DrawPolygonState,
        DrawCurveState,
        DrawTextState,
        DrawPixmapState
    };

public:
    explicit AttributeDialog(QWidget *parent = nullptr);

    ~AttributeDialog();

    Ui::AttributeDialog *ui;

    // 当前状态
    DrawState state;

    // 设置当前状态
    void setState(DrawState state);
};
