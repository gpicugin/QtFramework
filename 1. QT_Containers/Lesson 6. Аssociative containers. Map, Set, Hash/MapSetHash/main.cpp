#include <QCoreApplication>
#include <QMap>
#include <QMultiMap>
#include <QSet>
#include <QHash>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QMap<QString, int> map {{"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}};
    QMultiMap<QString, int> multimap {{"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}};
    qDebug() << map;

    map.insert("M", 1000);
    qDebug() << map;

    map.insert("H", 5000);

    QMap<QString, int>::const_iterator c_it;
    c_it = map.constFind("H");

    qDebug() << c_it.key() << c_it.value();

    map.erase(c_it);

    map["F"] = 4;                               // аналог insert

    if(map.find("F") != map.end())
        map.erase(map.find("F"));               // небезопасная операция

    qDebug() << map;

    map.insert("I",2);                          // перезаписывает значение ключа
    map.insert("I",3);
    map.insert("I",4);
    map.insert("I",5);
    map.insert("I",1);
    qDebug() << map.count("I");

    multimap.insert("I",2);                     // добавляет новое значение к ключу
    multimap.insert("I",3);
    multimap.insert("I",4);
    multimap.insert("I",5);
    multimap.insert("I",1);

    qDebug() << multimap.count("I");
    qDebug() << multimap;
    //qDebug() << multimap["I"];                // какое значение выбрать?? Так нельзя
    qDebug() << multimap.values("I");

    QMap<QString, int>::const_iterator it = map.constBegin();
    while (it != map.constEnd())
    {
        qDebug() << it.key() << ": " << it.value() << Qt::endl;
        ++it;
    }

    foreach (int value, map)
        qDebug() << value << Qt::endl;

    QMap<QString, int>::const_key_value_iterator ckv_it = map.constKeyValueBegin();
    while (ckv_it != map.constKeyValueEnd())
    {
        qDebug() << *ckv_it << Qt::endl;        // возвращает пару ключ-значение
        ckv_it++;
    }

    qDebug() << *map.equal_range("C").first << *map.equal_range("C").second; // TODO check

    it = map.find("I");
    while (it != map.end() && it.key() == "I")
    {
        qDebug() << it.value() << Qt::endl;
        it++;
    }

    qDebug() << map.keys();
    qDebug() << map.values();

    //----------------------------------------------------------------------------------------------------------------//
    // QSet

    QSet<QString> classA = {"Grag", "Alex", "Nick", "Phill", "Jane"};
    QSet<QString> classB;
    classB << "Kate" << "Jessica" << "Sarah" << "Robert" << "Mark" << "Mark" << "Jane";

    qDebug() << classA;
    qDebug() << classB;
    qDebug() << (classA & classB);          // пересечение
    qDebug() << (classA + classB);          // объединение
    qDebug() << (classA | classB);          // объединение (аналог)
    qDebug() << (classA - classB);          // разность

    classA.remove("Alex");
    qDebug() << classA;
    classA.remove("Jamal");
    qDebug() << classA.values();
    //----------------------------------------------------------------------------------------------------------------//
    // QHash

    QHash<QString, int> hash = { {"one", 1},  {"two", 2},  {"three", 3},  {"four", 4},  {"five", 5}};
    qDebug() << hash;
    hash.insert("five", 6);
    qDebug() << hash;

    return a.exec();
}
