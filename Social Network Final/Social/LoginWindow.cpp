// loginwindow.h
#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include "socialNetwork.h"

class LoginWindow : public QMainWindow {
    Q_OBJECT

public:
    LoginWindow(SocialNetwork* network, QWidget *parent = nullptr) : QMainWindow(parent), socialNetwork(network) {
        setupUi();
        connectSignals();
    }

private slots:
    void handleLogin() {
        QString username = usernameEdit->text();
        QString password = passwordEdit->text();
        
        // Try to login using your existing backend
        for (int i = 0; i < socialNetwork->users.size(); i++) {
            if (socialNetwork->users.get(i)->getusername() == username.toStdString() && 
                socialNetwork->users.get(i)->getpassword() == password.toStdString()) {
                QMessageBox::information(this, "Success", "Login successful!");
                // Here you would transition to the main app window
                // mainWindow = new MainWindow(socialNetwork, i);
                // mainWindow->show();
                // this->hide();
                return;
            }
        }
        
        QMessageBox::warning(this, "Error", "Invalid username or password");
    }

    void switchToSignup() {
        // Clear previous inputs
        usernameEdit->clear();
        passwordEdit->clear();
        
        if (isLoginMode) {
            // Switch to signup mode
            setWindowTitle("Sign Up");
            ageEdit->show();
            ageLabel->show();
            confirmPasswordEdit->show();
            confirmPasswordLabel->show();
            loginButton->setText("Sign Up");
            switchModeButton->setText("Switch to Login");
            isLoginMode = false;
        } else {
            // Switch to login mode
            setWindowTitle("Login");
            ageEdit->hide();
            ageLabel->hide();
            confirmPasswordEdit->hide();
            confirmPasswordLabel->hide();
            loginButton->setText("Login");
            switchModeButton->setText("Switch to Sign Up");
            isLoginMode = true;
        }
    }

private:
    void setupUi() {
        setWindowTitle("Login");
        QWidget* centralWidget = new QWidget(this);
        setCentralWidget(centralWidget);
        
        QVBoxLayout* layout = new QVBoxLayout(centralWidget);
        
        // Create widgets
        QLabel* titleLabel = new QLabel("Social Network", this);
        titleLabel->setAlignment(Qt::AlignCenter);
        QFont titleFont = titleLabel->font();
        titleFont.setPointSize(16);
        titleFont.setBold(true);
        titleLabel->setFont(titleFont);
        
        usernameEdit = new QLineEdit(this);
        usernameEdit->setPlaceholderText("Username");
        
        passwordEdit = new QLineEdit(this);
        passwordEdit->setPlaceholderText("Password");
        passwordEdit->setEchoMode(QLineEdit::Password);
        
        confirmPasswordEdit = new QLineEdit(this);
        confirmPasswordEdit->setPlaceholderText("Confirm Password");
        confirmPasswordEdit->setEchoMode(QLineEdit::Password);
        
        ageLabel = new QLabel("Age:", this);
        ageEdit = new QLineEdit(this);
        ageEdit->setPlaceholderText("Enter your age");
        
        loginButton = new QPushButton("Login", this);
        switchModeButton = new QPushButton("Switch to Sign Up", this);
        
        // Add widgets to layout
        layout->addWidget(titleLabel);
        layout->addWidget(usernameEdit);
        layout->addWidget(passwordEdit);
        layout->addWidget(confirmPasswordLabel);
        layout->addWidget(confirmPasswordEdit);
        layout->addWidget(ageLabel);
        layout->addWidget(ageEdit);
        layout->addWidget(loginButton);
        layout->addWidget(switchModeButton);
        
        // Initial setup for login mode
        confirmPasswordEdit->hide();
        confirmPasswordLabel->hide();
        ageEdit->hide();
        ageLabel->hide();
        
        // Set fixed window size
        setFixedSize(400, 500);
    }

    void connectSignals() {
        connect(loginButton, &QPushButton::clicked, this, &LoginWindow::handleLogin);
        connect(switchModeButton, &QPushButton::clicked, this, &LoginWindow::switchToSignup);
    }

    // Member variables
    QLineEdit* usernameEdit;
    QLineEdit* passwordEdit;
    QLineEdit* confirmPasswordEdit;
    QLabel* confirmPasswordLabel;
    QLineEdit* ageEdit;
    QLabel* ageLabel;
    QPushButton* loginButton;
    QPushButton* switchModeButton;
    bool isLoginMode = true;
    SocialNetwork* socialNetwork;
};

#endif // LOGINWINDOW_H