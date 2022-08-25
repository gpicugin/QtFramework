#include <QCoreApplication>
#include <QSet>
#include <QTextStream>
QTextStream cout(stdout);
QTextStream cin(stdin);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSet<int> set;

    set << 50 << 45 << 55 << 49 << 1 << 51;

    qDebug() << set;


    qDebug() << set.size();
    set.insert(1);
    set.insert(1);
    qDebug() << set.size(); // не изменился, хранит уникальные значения

    // не может изменить элемет, который в нем хранится

    QSet<int> set1;
    QSet<int> set2;
    for(int i = 0; i < 20; i++)
    {
        set1 << rand() % 10;
        set2 << rand() % 10;
    }

    qDebug() << set1;
    qDebug() << set2;

    QSet<int>::const_iterator it1, it2;

    it1 = set1.find(10);
    it2 = set1.find(1);

    qDebug() << (it1 == set1.end());
    qDebug() << *it2; // << *it1;


    int val = rand() % 60 + 1;
    qDebug() << val;
    if(set.find(val) != set.end())
        qDebug() << val << " was found!";
    else
        qDebug() << val << " was not found!";

    it1 = set.find(45);
    set.erase(it1);
    qDebug() << set;


    qDebug() << set.remove(100) << set;
    qDebug() << *set.insert(100) << set;


    QSet<int> set3 {10, 13 ,21};
    qDebug() << (set1 | set3);
    return a.exec();
}
