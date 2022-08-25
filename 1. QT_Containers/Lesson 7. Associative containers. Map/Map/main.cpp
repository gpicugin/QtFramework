#include <QCoreApplication>
#include <QMap>
#include <QMultiMap>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString, int> map { {"one", 1}, {"two", 2}, {"three", 3} }; // Key, Value

    qDebug() << map;

    QMap<QString, int>::const_iterator cit;

    cit = map.constFind("two");
    qDebug() << *cit;

    QMap<QString, int>::const_key_value_iterator ckvit;

    ckvit = map.constKeyValueBegin();

    for(; ckvit != map.constKeyValueEnd(); ++ckvit)
        qDebug() << ckvit->first << ckvit->second;

    qDebug() << map.contains("four");

    qDebug() << map.keys();
    qDebug() << map.values();

    qDebug() << map.value("one");           // Самое важное

    std::map<QString, int> std_map = map.toStdMap();
    qDebug() << std_map;


    qDebug() << map["two"];

    return a.exec();
}
