#include "MainWindow.h"
#include <QApplication>
#include <boost/locale.hpp>
#include <fstream>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

#include "Person.h"
#include "Group.h"
#include <QLocale>
#include <QMessageBox>
#include <iostream>

using boost::multiprecision::cpp_dec_float_50;

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
