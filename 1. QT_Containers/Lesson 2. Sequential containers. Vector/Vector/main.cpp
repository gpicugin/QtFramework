#include <QCoreApplication>
#include <QVector>
#include <QVectorIterator>
#include <vector>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<int> vec1, vec2;
    vec1 << 1 << 2 << 3; // добавление элементов в контейнер
    qDebug() << vec1;
    vec2 += 4; // добавление элементов в контейнер
    vec2 += 5;
    vec2 += 6;
    qDebug() << vec2;
    QVector<int> result;
    result = vec1 + vec2; // объединение контейнеров
    qDebug() << result;
    qDebug() << result.at(0); // доступ по индексу, аналогично

    qDebug() << result.front(); // возвращают сылку на первый элемент. fraont() - по STL
    qDebug() << result.first();

    qDebug() << result.back(); // возвращают сылку на последний элемент. back() - по STL
    qDebug() << result.last();

    qDebug() << result.contains(7); // проверяет, содержится ли элемент в контейнере
    QVector<int>::iterator it;
    it = result.end() - 1;
    result.erase(it);   // удаляет элемент по итератору, можно сделать как диапазон
    qDebug() << result;

    qDebug() << result.indexOf(2); // возвращает индекс первого вхождения значения или -1
    qDebug() << result.indexOf(10);

    result << 2;
    qDebug() << result.lastIndexOf(2); // возвращает индекс последнего вхождения значения или -1

    QVector<int> tmp = result.mid(0, result.size()/2); // возвращает контейнер, с копиями элементов, задаются первой позицией и количеством
    qDebug() << tmp;
    qDebug() << result;
    result.pop_back(); // удаляет последний элемент
    result.pop_front(); // удаляет первый элемент
    result.push_front(0); // добавляет в начало
    result.prepend(-1);
    result.push_back(4); // добавляет в конец
    result.append(5);
    qDebug() << result;
    result.replace(result.size() -1, 6); // заменяет элемент, в позиции значением
    qDebug() << result;


    // часть про вектор

    QVector<int> vec;
    vec << 1 << 2 << 3 << 4 << 5 << 6;
    int* arr = vec.data();
    for(int i = 0; i < vec.size(); ++i)
    {
        qDebug() << arr[i];
    }

    vec.fill(0); // присваивает одно и то же значение всем элементам
    qDebug() << vec;
    vec.reserve(10); // резервирует память для кол-ва элементов
    vec.resize(10);
    qDebug() << vec;
    QList<int> list = vec; // vector == list
    return a.exec();
}
