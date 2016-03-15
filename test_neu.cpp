#include <QApplication>
#include <QMainWindow>
#include <QDebug>
#include <QSettings>
#include <QGridLayout>
#include <QTextEdit>
#include <QWidget>
#include <QPainter>
#include <QLine>
#include <QColor>
#include <QPaintEngine>
#include <QSvgWidget>

class QTE : public QTextEdit {


 public:
  explicit QTE(QWidget *parent = 0 ) : QTextEdit() {}


  void paintEvent(QPaintEvent *pe)
  {
    qDebug() << "p";

    
    QTextEdit::repaint();

        QPaintEngine *qpe=paintEngine();
    qDebug() << &qpe;
    return;
    QPainter  *mypainter=qpe->painter();

    			  return;
    //    QPainter mypainter(this);
    QPen pen(Qt::red);
    mypainter->setPen(Qt::blue);
    mypainter->setPen(pen);
    pen.setWidth(10);
    mypainter->drawLine(0,0,width()/2,height()/2);;
    
  }
};

  


int main(int argc, char **argv)
{
  QApplication app(argc,argv);

  QVBoxLayout *vbox = new QVBoxLayout;
  
  QTE *textEdit = new QTE;

   QFont textFont("Monospace");

   

  textFont.setStyleHint(QFont::TypeWriter);
  textEdit->setFont(textFont);

  QSvgWidget *svg=new QSvgWidget(QCoreApplication::arguments().at(1));

  qDebug() << QCoreApplication::arguments().at(1);
  //  svg->load(QCoreApplication::arguments().at(1));
  
  QMainWindow mw;
  //  vbox->addWidget(ruler1);
  
  //vbox->addWidget(textEdit);
  QWidget *c = new QWidget;
  c->setLayout(vbox);

  vbox->addWidget(svg);

  
  //OptionsDialog od;

    mw.setCentralWidget(c);
  mw.show();

  //  svgRenderer.show();
  //  od.show();

  //  vbox->show();
    
  return app.exec();
}
