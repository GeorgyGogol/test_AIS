#pragma once

#include "generalforms_global.h"

class QDialog;
class QLineEdit;

namespace forms {

	class GENERALFORMS_EXPORT Login : public QDialog
	{
		Q_OBJECT

	public:
		enum FormType : short {
			UserPassword, PasswordOnly
		};

	public:
		Login(FormType type, QWidget *parent = nullptr);
		~Login();

	private:
		QLineEdit* inputUser;
		QLineEdit* inputPassword;

	public:
		QString getLogin() const;
		QString getPassword() const;

		static Login* createUserPassword(QWidget* parent = nullptr);
		static Login* createPasswordOnly(QWidget* parent = nullptr);

	};

}

