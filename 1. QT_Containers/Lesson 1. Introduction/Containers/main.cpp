#include <QCoreApplication>
#include <QDebug>

// Последовательные
#include <QVector>
#include <QList>
#include <QLinkedList>
#include <QStack>
#include <QQueue>
#include <QVectorIterator>
#include <QListIterator>
#include <QMutableVectorIterator>
#include <QMutableListIterator>

// Ассоциативные
#include <QSet>
#include <QMap>
#include <QMultiMap>
#include <QHash>
#include <QMultiHash>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVarLengthArray<int>    arr;
    QVector<int>            vec;
    QList<int>              list;
    QLinkedList<int>        lList;
    QStack<int>             stack;
    QQueue<int>             queue;
    // контейнеры могут быть вложены друг в друга

    arr << 1 << 2 << 3 << 4;            // заполнение контейнера
    vec << 1 << 2 << 3 << 4;
    list << 1 << 2 << 3 << 4;
    lList << 1 << 2 << 3 << 4;
    stack << 1 << 2 << 3 << 4 << 5;
    queue << 1 << 2 << 3 << 4;
    qDebug() << "Intriduction";
    qDebug() << (vec == list);          // сравнение содержимого
    qDebug() << (vec != stack);

    vec = stack; // присваивание
    qDebug() << (vec == stack);

    qDebug() << vec[vec.size() - 1];

    vec.clear(); // удаляет все
    list.clear();
    stack.clear();
    queue.clear();
    qDebug() << vec << list << stack << queue;

    vec.insert(0,1); // вставка элемента в позицию (pos, value);
    list.insert(0,2);
    stack.insert(0,3);
    queue.insert(0,4);
    qDebug() << vec << list << stack << queue;

    vec.remove(0); // удаляет один элемент
    list.remove(0);
    stack.remove(0);
    queue.remove(0);
    qDebug() << vec << list << stack << queue;


    qDebug() << vec.size() << vec.count(); // size - stl style
    qDebug() << list.size() << list.count();
    qDebug() << stack.size() << stack.count();
    qDebug() << queue.size() << queue.count();

    qDebug() << vec.value(0) << vec.value(0, -1); // возврат значения, также как at() и []
    qDebug() << list.value(0) << list.value(0, -1);
    qDebug() << stack.value(0) << stack.value(0, -1);
    qDebug() << queue.value(0) << queue.value(0, -1);

    qDebug() << vec.empty() << vec.isEmpty(); // empty - stl style
    qDebug() << list.empty() << list.isEmpty();
    qDebug() << stack.empty() << stack.isEmpty();
    qDebug() << queue.empty() << queue.isEmpty();

    // итераторы в стиле Java
    qDebug() << "Java iterators";
    QList<QString> strList;
    strList << "One" << "Two" << "Three";
    QListIterator<QString> it(strList);
    while(it.hasNext())
    {
        qDebug () << "Element:" << it.next () ;
    }



    it.toFront(); // перед первым элементом
    if(it.hasNext())
    {
        qDebug() << it.next();
        qDebug() << it.peekNext();
    }
    qDebug() << it.findNext("Three");

    it.toBack(); // после последнего элемента
    if(it.hasPrevious())
    {
        qDebug() <<  it.previous();
        qDebug() << it.peekPrevious();
    }
    qDebug() << it.findPrevious("One");

    QMutableListIterator<QString> mut_it(strList);
    mut_it.toBack();
    mut_it.insert("Four");
    qDebug() << strList;
    mut_it.setValue("4");
    qDebug() << strList;
    mut_it.remove();
    qDebug() << strList;

    // итераторы в стиле STL
    qDebug() << "STL iterators";

    QVector<QString> strVec;

    strVec << "1" << "2" << "3";

    QVector<QString>::iterator vecIt;

    for(vecIt = strVec.begin(); vecIt != strVec.end(); ++vecIt)
    {

        qDebug() << "Element:" << *vecIt;

    }

    vecIt = strVec.end();
    for (;vecIt != strVec.begin();)
    {
        --vecIt;
        qDebug() << "Element:" << *vecIt;
    }
    vec.clear();
    vec << 3 << 2 << 1;
    std::sort(vec.begin(), vec.end());
    qDebug() << vec;

    //ключевое слово foreach
    qDebug() << "Key word foreach";
    foreach(int i, vec)
    {
        qDebug() << "Element + 5:" << i + 5;
    }
    return a.exec();
}
