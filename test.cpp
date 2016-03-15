#include <QApplication>
#include <QMainWindow>
#include <QDebug>
#include <QSettings>
#include <QGridLayout>
#include <QTextEdit>
#include <QWidget>
#include <OptionsDialog.h>
#include <QPainter>
#include <QLine>
#include <QColor>

class QTE : public QTextEdit {


 public:
  explicit QTE(QWidget *parent = 0 ) : QTextEdit(parent) {}


  void paintEvent(QPaintEvent *)
  {
    qDebug() << "p";

    
    QPainter painter(this);
    
    painter.setPen(Qt::blue);
    QLine line=QLine(0,0,100,100);
    painter.drawLine(line);
          QTextEdit::paintEvent();
  
  }
};

  


int main(int argc, char **argv)
{

  QCoreApplication::setOrganizationName("blind.guru");
  QCoreApplication::setOrganizationDomain("blind.guru");
  QCoreApplication::setApplicationName("bmc");
  

  QGridLayout *ruler=new QGridLayout();
  QApplication app (argc, argv);

  
  for (int i =0; i < 20; i++)
    {
      QLabel *l=new QLabel("1");
      ruler->addWidget(l,0,i);
    }

  QTextEdit *ruler1=new QTextEdit;
  ruler1->setText("-----------------------------------------------------------------------------");

  //  ruler1->SetSizePolicy(QSizePolicy::Fixed);
  QVBoxLayout *vbox=new QVBoxLayout;

  QTE *textEdit = new QTE;

   QFont textFont("Monospace");

   

  textFont.setStyleHint(QFont::TypeWriter);
  textEdit->setFont(textFont);


  
  QMainWindow mw;
  //  vbox->addWidget(ruler1);
  
  vbox->addWidget(textEdit);
  QWidget *c = new QWidget;
  c->setLayout(vbox);

  

  
  //OptionsDialog od;

  mw.setCentralWidget(c);
  mw.show();
  
  //  od.show();

  //vbox.show();
    
  return app.exec();
}
