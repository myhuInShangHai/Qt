#include "CProcessDelegate.h"
#include <QPainter>
#include <QApplication>
#include <QMouseEvent>

CProcessDelegate::CProcessDelegate(QObject *parent) :
    QItemDelegate(parent)
{

}

CProcessDelegate::~CProcessDelegate()
{

}

void CProcessDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if( option.state & QStyle::State_Selected )
        painter->fillRect( option.rect, option.palette.highlight() );

    // 数据是存储在QStandardItemModel的QStandardItem，会自动根据当前行进行匹配（我认为）
    int value = index.model()->data( index, Qt::DisplayRole ).toInt(); // 这句，取得当前行的数据
    double factor = double(value)/1000.0; // 计算比例因子

    painter->save(); // 保存旧画板（我认为）
    // 进度条背景色
    if( factor > 0.8 )
    {
        painter->setBrush( Qt::red ); // 超过0.8画纯红色
        factor = 1;
    }
    else
        painter->setBrush( QColor( 0, int(factor*255), 255-int(factor*255) ) ); // 否则颜色依次变淡

    painter->setPen( Qt::black ); // 画笔颜色（这里没用到，我认为）
    // 前面都是准备工作，这里才是真正画进度条
    painter->drawRect( option.rect.x()+2, option.rect.y()+2, int(factor*(option.rect.width()-5)), option.rect.height()-5 );
    painter->restore(); // 恢复新画板（我认为）

}


QWidget *CProcessDelegate::createEditor( QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index ) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    QSlider *slider = new QSlider( parent );

    slider->setAutoFillBackground( true );
    slider->setOrientation( Qt::Horizontal );
    slider->setRange( 0, 1000 );
    slider->installEventFilter( const_cast<CProcessDelegate*>(this) );

    return slider;
}

void CProcessDelegate::updateEditorGeometry( QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index ) const
{

    editor->setGeometry( option.rect );
}

void CProcessDelegate::setEditorData( QWidget *editor, const QModelIndex &index ) const
{
    int value = index.model()->data( index, Qt::DisplayRole ).toInt();
    static_cast<QSlider*>( editor )->setValue( value );
}

void CProcessDelegate::setModelData( QWidget *editor, QAbstractItemModel *model, const QModelIndex &index ) const
{
    model->setData( index, static_cast<QSlider*>( editor )->value() );
}







//-------------------
//-------------------
CProcess2Delegate::CProcess2Delegate(QObject *parent) :
    QItemDelegate(parent)
{

}

void CProcess2Delegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int value = index.model()->data(index).toInt();
    QStyleOptionProgressBarV2 progressBarOption;
    progressBarOption.rect = option.rect.adjusted(4, 4, -4, -4);
    progressBarOption.minimum = 0;
    progressBarOption.maximum = 1000;
    progressBarOption.textAlignment = Qt::AlignRight;
    progressBarOption.textVisible = true;
    progressBarOption.progress = value;
    progressBarOption.text = tr("%1%").arg(progressBarOption.progress / 10);

    painter->save();
    if (option.state & QStyle::State_Selected) {
        painter->fillRect(option.rect, option.palette.highlight());
        painter->setBrush(option.palette.highlightedText());
    }
    QApplication::style()->drawControl(QStyle::CE_ProgressBar, &progressBarOption, painter);

    painter->restore();
}


