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

    QVarLengthArray<int>        arr;
    QVector<int>                vec;
    QList<int>                  list;
    QLinkedList<int>            lList;
    QStack<int>                 stack;
    QQueue<int>                 queue;
//    QSet<int>                   set;
//    QMap<int, QString>          map;
//    QMultiMap<int, QString>     mMap;
//    QHash<int, QString>         hash;
//    QMultiHash<int, QString>    mHash;

    // контейнеры могут быть вложены друг в друга

    arr << 1 << 2 << 3 << 4;            // заполнение контейнера
    vec << 5 << 6 << 7 << 8;
    list << 5 << 6 << 7 << 8;
    lList << 9 << 10 << 11 << 12;
    stack << 13 << 14 << 15 << 16 << 17;
    queue << 18 << 19 << 20 << 21;
    qDebug() << "Introduction";
    qDebug() << (vec == list);          // сравнение содержимого
    qDebug() << (list != stack);

    vec = stack; // присваивание
    qDebug() << (vec == stack);

    qDebug() << arr[0];
    qDebug() << vec[0];
    qDebug() << list[0];
    //qDebug() << lList[0];
    qDebug() << stack[0];
    qDebug() << queue[0];

    qDebug() << *arr.begin(); // TODO check adress or value
    qDebug() << *vec.begin();
    qDebug() << *list.begin();
    //qDebug() << lList.begin();
    qDebug() << *stack.begin();
    qDebug() << *queue.begin();

    arr.insert(arr.begin(),1); // вставка элемента в позицию (pos, value);
    vec.insert(0,1);
    list.insert(0,2);
    lList.insert(lList.begin(),1);
    stack.insert(0,3);
    queue.insert(0,4);
    qDebug() << arr << vec << list /*<< lList*/ << stack << queue;

    arr.clear(); // удаляет все
    vec.clear();
    list.clear();
    lList.clear();
    stack.clear();
    queue.clear();
    qDebug() << arr << vec << list /*<< lList*/ << stack << queue;

    arr << 1 << 2 << 3 << 4;            // заполнение контейнера
    vec << 5 << 6 << 7 << 8;
    list << 5 << 6 << 6 << 8;
    lList << 9 << 10 << 11 << 12;
    stack << 13 << 14 << 15 << 16 << 17;
    queue << 18 << 19 << 20 << 21;

    vec.remove(0); // удаляет один элемент
    list.remove(0);
    //lList.remove(0);
    stack.remove(0);
    queue.remove(0);
    qDebug() << arr << vec << list /*<< lList*/ << stack << queue;

    qDebug() << arr.size() << arr.count(); // size - stl style
    qDebug() << vec.size() << vec.count();
    qDebug() << list.size() << list.count();
    qDebug() << stack.size() << stack.count();
    qDebug() << queue.size() << queue.count();

    // Доступ к элементам


    qDebug() << vec.value(0) << vec.value(0, -1) << vec.at(1) << vec[1];
    qDebug() << list.value(0) << list.value(0, -1) << list.at(1) << list[1];
    qDebug() << stack.value(0) << stack.value(0, -1) << stack.at(1) << stack[1];
    qDebug() << queue.value(0) << queue.value(0, -1) << queue.at(1) << queue[1];

    qDebug() << vec.empty() << vec.isEmpty(); // empty - stl style
    qDebug() << list.empty() << list.isEmpty();
    qDebug() << stack.empty() << stack.isEmpty();
    qDebug() << queue.empty() << queue.isEmpty();

    // итераторы в стиле Java
    qDebug() << "Java iterators";
    QList<QString> strList;
    strList << "One" << "Two" << "Three";

    QListIterator<QString> it(strList);

    it.toFront();               // Перемещает итератор на начало контейнера
    it.toBack();                // Перемещает итератор на конец контейнера
    it.hasNext();               // Возвращает true если есть следующий элемент
    it.hasPrevious();           // Возвращает true если есть предыдущий элемент
    it.next();                  // Возвращает значение след. эл-та и перемещает итератор на след. позицию
    it.previous();              // Возвращает значение пред. эл-та и перемещает итератор на пред. позицию
    it.peekNext();              // Просто возвращает след. значение без изменения позиции
    it.peekPrevious();          // Просто возвращает пред. значение без изменения позиции
    it.findNext("Two");         // Поиск в прямом направлении
    it.findPrevious("One");     // Поиск в обратном направлении

    while(it.hasNext())
    {
        qDebug () << "Element:" << it.next();
    } 

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

    // Итераторы в стиле STL


    //ключевое слово foreach
    qDebug() << arr << vec << list /*<< lList*/ << stack << queue;

    qDebug() << "Key word foreach: arr";
    foreach(int i, arr)
    {
        qDebug() << "Element + 5:" << i + 1;
    }

    qDebug() << "Key word foreach: list";
    foreach(int i, list)
    {
        qDebug() << "Element + 5:" << i + 2;
    }

    qDebug() << "Key word foreach: lList";
    foreach(int i, lList)
    {
        qDebug() << "Element + 5:" << i + 3;
    }

    qDebug() << "Key word foreach: stack";
    foreach(int i, stack)
    {
        qDebug() << "Element + 5:" << i + 4;
    }

    qDebug() << "Key word foreach: queue";
    foreach(int i, queue)
    {
        qDebug() << "Element + 5:" << i + 5;
    }
    return a.exec();
}
