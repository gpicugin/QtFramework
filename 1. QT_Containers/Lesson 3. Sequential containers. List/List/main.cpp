#include <QCoreApplication>
#include <QList>
#include <QListIterator>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Конструкторы
    QList<int> list1;          // без параметров
    QList<int> list2(3);       // size == 3
    QList<int> list3(3, 7);    // size, value
    QList<int> list4(list3);    // copy constructor
    QList<int>* plist = new QList<int>(4,4);
    QList<int> list5(*plist);
    QList<int> list6{9,8,7,6,5,4,3,2,1};

    list1 << 1 << 2 << 3;        // добавление элементов в контейнер

    list2 += 4;                  // добавление элементов в конец контейнера
    list2 += 5;
    list2 += 6;

    list3.push_front(6);
    list3.prepend(5);

    list4.push_back(8);
    list4.append(9);

    qDebug() << list1;
    qDebug() << list2;
    qDebug() << list3;
    qDebug() << list4;
    qDebug() << list5;
    qDebug() << list6;

    // Емкость и размер вектора
    qDebug() << list2.capacity();
    qDebug() << list2.count();
    qDebug() << list2.size();
    qDebug() << list3.empty();
    qDebug() << list3.isEmpty();

    // Доступ к элементам вектора
    qDebug() << list1[1];
    qDebug() << list1.at(1);         // const T& (pos)
    qDebug() << list1.value(1);      // (pos)
    qDebug() << list1.value(17, -1); // (pos, defValue)
    qDebug() << list1.front();       // возвращают cсылку на первый элемент. front() - по STL
    qDebug() << list1.first();

    qDebug() << list1.back();        // возвращают cсылку на последний элемент. back() - по STL
    qDebug() << list1.last();

    QList<int>::iterator it;
    it = list1.begin();
    qDebug() << it;
    qDebug() << *it;

    it++;
    qDebug() << it;
    qDebug() << *it;

    it = list1.end() - 1;
    qDebug() << it;
    qDebug() << *it;

    // Поиск в векторе
    qDebug() << list3;
    qDebug() << list3.contains(5);
    qDebug() << list3.count(7);
    qDebug() << list3.indexOf(10, 2);    // value, pos
    qDebug() << list3.indexOf(7);
    qDebug() << list3.lastIndexOf(7);
    qDebug() << list3.startsWith(5);
    qDebug() << list3.endsWith(9);

    // Модификация вектора
    list4.insert(0, 1);                  // pos, value
    qDebug() << list4;

    it = list4.begin();
    list4.insert(it, -1);                // iterator before, value
    qDebug() << list4;

    list4.insert(list4.begin(), 2, -1);   // iterator before, count, value
    qDebug() << list4;

    list4.remove(0, 2);                  // pos, count
    qDebug() << list4;

    list4.erase(it);                     // удаляет элемент по итератору, можно сделать как диапазон
    qDebug() << list4;

    list4.replace(list4.size() -1, 6);    // заменяет элемент, в позиции значением
    qDebug() << list4;


    list4.swapItemsAt(0, list4.size() - 1);// меняет местами 2 элемента
    qDebug() << list4;

    qDebug() << list1;
    qDebug() << list4;
    list4.swap(list1);                    // меняет вектор1 и вектор4 местами
    qDebug() << list1;
    qDebug() << list4;

    list1.clear();                       // удаляет все элементы из вектора
    qDebug() << list1;

    list1.push_front(1);
    list1.push_back(999);
    qDebug() << list1;

    list1.pop_front();
    list1.pop_back();
    qDebug() << list1;

    int val;
    val = list4.takeFirst();
    qDebug() << val << list4;

    val = list4.takeAt(list4.size()/2);
    qDebug() << val << list4;

    val = list4.takeLast();
    qDebug() << val << list4;

    list4.fill(3);
    qDebug() << list4;

    list4.fill(0, 15);                   // value, size
    qDebug() << list4;

    // Операторы
    QList<int> result;
    qDebug() << (list1 != list2);
    qDebug() << (list1 == list2);
    result = list1 + list2;
    result += list3;
    result << list4;
    result << 11;
    qDebug() << result;
    qDebug() << result[0];

    // Другие методы
    QList<int> tmp = result.mid(0, result.size()/2); // возвращает контейнер, с копиями элементов, задаются первой позицией и количеством
    tmp.reserve(100);
    tmp.squeeze();

    QList<int> list;
    list << 1 << 2 << 3 << 4 << 5 << 6;
    int* arr = list.data();
    for(int i = 0; i < list.size(); ++i)
    {
        qDebug() << arr[i];
    }

    // to std container
    std::vector<int> vec(list.begin(), list.end());
    qDebug() << vec;
}
