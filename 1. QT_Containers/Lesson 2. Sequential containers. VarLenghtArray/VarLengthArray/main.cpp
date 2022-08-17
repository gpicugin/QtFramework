#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // Конструкторы
    QVarLengthArray<int> arr1;          // без параметров
    QVarLengthArray<int> arr2(3);       // size == 3
    QVarLengthArray<int> arr3{9,8,7,6,5,4,3,2,1};
    QVarLengthArray<int> arr4(arr3);    // copy constructor
    QVarLengthArray<int>* pArr = new QVarLengthArray<int>{1,2,3,4};
    QVarLengthArray<int> arr5(*pArr);

    arr1 << 1 << 2 << 3;        // добавление элементов в контейнер

    arr2 += 4;                  // добавление элементов в конец контейнера
    arr2 += 5;
    arr2 += 6;

    arr3.prepend(5);

    arr4.push_back(8);
    arr4.append(9);

    qDebug() << arr1;
    qDebug() << arr2;
    qDebug() << arr3;
    qDebug() << arr4;
    qDebug() << arr5;

    // Емкость и размер массива
    qDebug() << arr2.capacity();
    qDebug() << arr2.count();
    qDebug() << arr2.size();
    qDebug() << arr2.length();
    qDebug() << arr3.empty();
    qDebug() << arr3.isEmpty();

    // Доступ к элементам массива
    qDebug() << arr1[1];
    qDebug() << arr1.at(1);         // const T& (pos)
    qDebug() << arr1.value(1);      // (pos)
    qDebug() << arr1.value(17, -1); // (pos, defValue)
    qDebug() << arr1.front();       // возвращают cсылку на первый элемент. front() - по STL
    qDebug() << arr1.first();

    qDebug() << arr1.back();        // возвращают cсылку на последний элемент. back() - по STL
    qDebug() << arr1.last();

    QVarLengthArray<int>::iterator it;
    it = arr1.begin();
    qDebug() << it;
    qDebug() << *it;

    it++;
    qDebug() << it;
    qDebug() << *it;

    it = arr1.end() - 1;
    qDebug() << it;
    qDebug() << *it;

    // Поиск в массиве
    qDebug() << arr3;
    qDebug() << arr3.contains(5);
    //qDebug() << arr3.count(7);
    qDebug() << arr3.indexOf(10, 2);    // value, pos
    qDebug() << arr3.indexOf(7);
    qDebug() << arr3.lastIndexOf(7);
    //qDebug() << arr3.startsWith(5);
    //qDebug() << arr3.endsWith(9);

    // Модификация массива
    arr4.insert(1, 1);                  // pos, value
    qDebug() << arr4;

    it = arr4.begin();
    arr4.insert(it, -1);                // iterator before, value
    qDebug() << arr4;

    arr4.insert(arr4.size()/2, 3, 3);   // (pos, count,value)
    qDebug() << arr4;

    arr4.insert(arr4.begin(), 2, -1);   // (iterator before, count, value)
    qDebug() << arr4;

    arr4.remove(0, 2);                  // (pos, count)
    qDebug() << arr4;

    arr4.erase(it);                     // удаляет элемент по итератору, можно сделать как диапазон (it_begin, it_end)
    qDebug() << arr4;

    arr4.replace(arr4.size() -1, 6);    // заменяет элемент, в позиции значением
    qDebug() << arr4;

    arr1.clear();                         // удаляет все элементы из массива
    qDebug() << arr1;

    //arr1.push_front(1);
    arr1.push_back(999);
    qDebug() << arr1;

    //arr1.pop_front();
    arr1.pop_back();
    qDebug() << arr1;

    // Операторы
    qDebug() << (arr1 != arr2);
    qDebug() << (arr1 == arr2);
    arr1 += 5;
    qDebug() << arr1;
    qDebug() << arr1[0];

    // Другие методы
    QVarLengthArray<int> tmp;
    tmp.reserve(100);
    qDebug() << tmp.capacity();
    tmp.squeeze();
    qDebug() << tmp.capacity();

    QVarLengthArray<int> arr;
    arr << 1 << 2 << 3 << 4 << 5 << 6;
    int* array = arr.data();
    for(int i = 0; i < arr.size(); ++i)
    {
        qDebug() << array[i];
    }

    std::vector<int> vec(arr.begin(), arr.end());
    qDebug() << vec;
    return a.exec();
}
