#include "stdafx.h"
#include "Login.h"

using namespace forms;

Login::Login(FormType type, QWidget *parent)
	: QDialog(parent)
{
	setWindowTitle("Авторизация");

	QGridLayout* gridLayout = new QGridLayout(this);
	gridLayout->setSpacing(6);
	gridLayout->setContentsMargins(11, 11, 11, 11);

	QLabel* label_Password = new QLabel(this);
	label_Password->setText("Пароль");

	inputPassword = new QLineEdit(this);
	inputPassword->setEchoMode(QLineEdit::Password);

	QDialogButtonBox* buttonBox = new QDialogButtonBox(this);
	buttonBox->setStandardButtons(QDialogButtonBox::Cancel | QDialogButtonBox::Ok);
	connect(buttonBox, &QDialogButtonBox::accepted, this, &Login::accept);
	connect(buttonBox, &QDialogButtonBox::rejected, this, &Login::reject);

	switch (type) {
	case FormType::PasswordOnly:
		gridLayout->addWidget(label_Password, 1, 1, 1, 1);
		gridLayout->addWidget(inputPassword, 1, 2, 1, 1);
		gridLayout->addWidget(buttonBox, 2, 1, 1, 2);
		break;

	case FormType::UserPassword:
	default: {
		QLabel* label_User = new QLabel(this);
		label_User->setText("Пользователь");

		inputUser = new QLineEdit(this);

		QFrame* line = new QFrame(this);
		line->setFrameShape(QFrame::HLine);
		line->setFrameShadow(QFrame::Sunken);

		gridLayout->addWidget(label_User, 1, 1, 1, 1);
		gridLayout->addWidget(inputUser, 1, 2, 1, 1);
		gridLayout->addWidget(line, 2, 1, 1, 2);
		gridLayout->addWidget(label_Password, 3, 1, 1, 1);
		gridLayout->addWidget(inputPassword, 3, 2, 1, 1);
		gridLayout->addWidget(buttonBox, 4, 1, 1, 2);
	}
	}

	//QMetaObject::connectSlotsByName(this);
	setLayout(gridLayout);
}

Login::~Login()
{
}

QString Login::getLogin() const
{
	if (inputUser)
		return inputUser->text();
	else
		return QString();
}

QString Login::getPassword() const
{
	return inputPassword->text();
}

Login* forms::Login::createUserPassword(QWidget* parent)
{
	return new Login(Login::FormType::UserPassword, parent);
}

Login* forms::Login::createPasswordOnly(QWidget* parent)
{
	return new Login(Login::FormType::PasswordOnly, parent);
}
