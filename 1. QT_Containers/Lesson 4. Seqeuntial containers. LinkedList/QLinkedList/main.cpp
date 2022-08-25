#include <QCoreApplication>
#include <QDebug>
#include <QLinkedList>
#include <QLinkedListIterator>


template<typename T>
struct Llist
{
    T* prevNext;
    T data;
    T* nextElm;
};

template<typename T>
void out(QLinkedList<T> input)
{
    QString qStr("QLinkedList:{");
    int count = 0;
    foreach (T t, input)
    {
        qStr += QString::number(t);
        if(count != input.size() - 1)
            qStr += ", ";
        count++;
    }
    qStr += "}";
    qDebug() << qStr;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QLinkedList<int> lList1;                                // без параметров

    QVector<int> vec{1,2,3,4,5,6};
    QLinkedList<int> lList2(vec.begin(), vec.end());        // input_iterator_first, input_iterator_second

    std::initializer_list<int> iList{9,8,7,6,5,4,3,2,1};
    QLinkedList<int> lList3(iList);                         // size, value

    QLinkedList<int> lList4(lList3);                        // copy constructor

    QLinkedList<int>* plList = new QLinkedList<int>{11, 12, 13, 14};
    QLinkedList<int> lList5(*plList);

    QLinkedList<int> lList6{9,8,7,6,5,4,3,2,1};

    lList1 << 1 << 2 << 3;        // добавление элементов в контейнер

    lList2 += 4;                  // добавление элементов в конец контейнера
    lList2 += 5;
    lList2 += 6;

    lList3.push_front(6);
    lList3.prepend(5);

    lList4.push_back(8);
    lList4.append(9);

    out(lList1);
    out(lList2);
    out(lList3);
    out(lList4);
    out(lList5);
    out(lList6);

    // Емкость и размер двусвязного списка
    //qDebug() << lList2.capacity();
    qDebug() << lList2.count();
    qDebug() << lList2.size();
    qDebug() << lList2.empty();
    qDebug() << lList3.isEmpty();

    // Доступ к элементам двусвязного списка
    //qDebug() << lList1[1];
    //qDebug() << lList1.at(1);
    //qDebug() << lList1.value(1);
    qDebug() << lList1.front(); // возвращают cсылку на первый элемент. front() - по STL
    qDebug() << lList1.first();

    qDebug() << lList1.back(); // возвращают cсылку на последний элемент. back() - по STL
    qDebug() << lList1.last();

    QLinkedList<int>::iterator it;
    it = lList1.begin();
//    qDebug() << it;
    qDebug() << *it;

    it = lList1.end() - 1;
    qDebug() << *it;

    // Поиск в двусвязном списке
    out(lList3);
    qDebug() << lList3.contains(6);
    qDebug() << lList3.count(6);

//    qDebug() << lList3.indexOf(10, 2); // value, pos
//    qDebug() << lList3.indexOf(7);
//    qDebug() << lList3.lastIndexOf(7);
    qDebug() << lList3.startsWith(5);
    qDebug() << lList3.endsWith(9);

    // Модификация двусвязного списка
    it = lList4.begin();
    lList4.insert(it, -1);                // iterator before, value
    out(lList4);

    lList4.erase(it);                     // удаляет элемент по итератору, можно сделать как диапазон
    out(lList4);

    lList1.clear();                       // удаляет все элементы из двусвязного списка
    out(lList1);

    int val;
    val = lList4.takeFirst();
    qDebug() << val;
    out(lList4);


//    val = lList4.takeAt(lList4.size()/2);
//    qDebug() << val;
//    out(lList4);


    val = lList4.takeLast();
    qDebug() << val;
    out(lList4);

    lList1 << 1 << 2 << 3 << 4 << 5 << 5 << 5 << 6;
    out(lList1);
    lList1.removeFirst();
    out(lList1);
    lList1.removeLast();
    out(lList1);
    lList1.removeOne(3);
    out(lList1);
    lList1.removeAll(5);

//    lList4.replace(lList4.size() -1, 6);    // заменяет элемент, в позиции значением
//    out(lList4);

//    lList4.fill(3);
//    out(lList4);

    // Операторы
    QLinkedList<int> result;
    qDebug() << (lList1 != lList2);
    qDebug() << (lList1 == lList2);
    result = lList1 + lList2;
    result += lList3;
    out(result);

    // to std container
    QLinkedList<int> lList;
    lList << 1 << 2 << 3 << 4 << 5 << 6;

    std::list<int> std_list = lList.toStdList();
    qDebug() << std_list;
    QLinkedList<int> from_std_list = QLinkedList<int>::fromStdList(std_list);
    out(from_std_list);

    foreach(int val, lList)
    {
        qDebug() << val;
    }

    return a.exec();
}
