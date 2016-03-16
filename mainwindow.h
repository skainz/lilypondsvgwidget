#ifndef BRAILLE_MUSIC_EDITOR_H
#define BRAILLE_MUSIC_EDITOR_H

#include <QMainWindow>
#include <QMap>
#include <QPointer>
#include <QProcess>
#include <QScrollArea>
#include <QSoundEffect>
#include <QTemporaryDir>
#include <QTextBlock>
#include <QTextEdit>

#include <config.hpp>
/*#include <bmc/braille/ast/ast.hpp>
#include <boost/optional.hpp>
*/
#include "lilypondsvgcontainer.h"


QT_BEGIN_NAMESPACE
class QAction;
class QTextCharFormat;
class QMenu;
class QPrinter;
QT_END_NAMESPACE

class BrailleMusicEditor : public QMainWindow
{
    Q_OBJECT

public:
    BrailleMusicEditor(QWidget *parent = 0);

protected:
    virtual void closeEvent(QCloseEvent *e) Q_DECL_OVERRIDE;

private:
    void setupSoundEffects();
    void setupFileActions();
    void setupEditActions();
    void setupOptionsActions();
    bool load(const QString &f);
    bool maybeSave();
    void setCurrentFileName(const QString &fileName);
    void goTo(int line, int column);
    void showEmptySVG();
    
private slots:
    void fileNew();
    void fileOpen();
    bool fileSave();
    bool fileSaveAs();
    void fileCompile();
    void fileExportMusicXML();
    void fileExportLilyPond();
    void filePrint();
    void filePrintPreview();
    void filePrintPdf();

    void editReformat();

    void textFamily(const QString &f);
    void textSize(const QString &p);

    void showOptions();

    void cursorPositionChanged();
    void textChanged();

    void clipboardDataChanged();
    void about();
    void reportBug();
    void printPreview(QPrinter *);

    void runLilyPond(bool);
    void lilyPondStarted();
    void lilyPondFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void lilyPondError(QProcess::ProcessError error);

    void goToObject(int id);
    void highlightObject(int id);
signals:
  void scoreAvailable(bool);

private:
    void mergeFormatOnWordOrSelection(const QTextCharFormat &format);
    void fontChanged(const QFont &f);
    void colorChanged(const QColor &c);
    void resizeEvent(QResizeEvent *event) override;

    QAction *actionSave;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;

    QToolBar *tb;
    QString fileName;
    QTextEdit *textEdit;
    QScrollArea *svgScrollArea;

//    boost::optional<::bmc::braille::ast::score> score;
    QProcess lilypond;
    QScopedPointer<QTemporaryDir> tmpdir;
    QString lilypondCode;

    QSoundEffect ok, fail;

};

#endif // BRAILLE_MUSIC_EDITOR_H
