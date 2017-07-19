#include "GCreateDatabase.h"
#include "ui_GCreateDatabase.h"
#include "GSplashScreen.h"
#include "GPicto.h"
#include "GDatabaseAccess.h"

GCreateDatabase::GCreateDatabase(QWidget* parent) :
    QFrame(parent), ui(new Ui::GCreateDatabase) {
    ui->setupUi(this);
    createObjects();
    createConnexions();
    GSplashScreen::Instance()->showMessage("GCreateDatabase : loading GCreateDatabase module...");
}

GCreateDatabase::~GCreateDatabase() {
    delete ui;
}

void GCreateDatabase::createObjects() {
    ui->m_title->setIcon(GPicto::Instance()->getPicto(fa::cog));
    ui->m_create->setIcon(GPicto::Instance()->getPicto(fa::plus));
}

void GCreateDatabase::createConnexions() {
    connect(ui->m_create, SIGNAL(clicked()), this, SLOT(slotCreateClicked()));
}

void GCreateDatabase::slotCreateClicked() {
    GDatabaseAccess::Instance()->run();
}
