#include <QCoreApplication>

#include <QByteArray>
#include <QBitArray>
#include <QQueue>
#include <QStack>
#include <QImage>
#include <QBuffer>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // QByteArray - не шаблонный класс!
    // Может использоваться как буфер сырых данных

    QByteArray byteArr1;

    char* arr = new char[100];
    for(int i = 0; i < 100; i++)
    {
        arr[i] = 'a' + rand() % 26;         // a-z
    }

    QByteArray byteArr2(arr, 100);          // data, size
    QByteArray byteArr3(5, 5);              // size, char
    QByteArray byteArr4(byteArr2);          // copy constructor

    qDebug() << byteArr1;
    qDebug() << byteArr2;
    qDebug() << byteArr3;
    qDebug() << byteArr4;

    // Modify
    qDebug() << "Modify";
    byteArr2.chop(10);
    qDebug() << byteArr2;

    byteArr1 = byteArr2.chopped(10);
    byteArr4 = byteArr2.right(10);
    qDebug() << byteArr1;
    qDebug() << byteArr4;

    qDebug() << byteArr2.compare(byteArr1);
    qDebug() << byteArr2.contains('g');
    qDebug() << byteArr2.contains(byteArr1);

    qDebug() << byteArr2.count('g');
    qDebug() << byteArr2.count(byteArr1);

    byteArr1 = "123";
    qDebug() << byteArr1.repeated(3);


    QByteArray x("apple");
    qDebug() << x.rightJustified(8, '.');    // "...apple"

    QByteArray xCompressed = qCompress(x);
    qDebug() << xCompressed;
    qDebug() << qUncompress(xCompressed);

    byteArr1.setRawData(arr, 100);
    qDebug() << byteArr1;

    QByteArray text = QByteArray::fromHex("517420697320677265617421");
    qDebug() << text.data();

    QString path("../Others/");
    QImage imageSrc(path + "image.jpg");
    QByteArray src;
    QBuffer buffer(&src);
    buffer.open(QIODevice::WriteOnly);
    imageSrc.save(&buffer, "JPG"); // writes image into buffer in JPG format


    QByteArray imageData = QByteArray::fromBase64(buffer.data().toBase64());
    QImage imageDst;
    imageDst.loadFromData(imageData);
    qDebug() << imageDst.save(path + "image2.png");

    // QBitArray - не шаблонный класс!
    // Может использоваться для хранения большого кол-ва битовых переменных
    // и работой с битовыми масками

    QBitArray bitArr1(8);
    QBitArray bitArr2(8);

    for(int i = 0; i < 8; i++)
    {
        bitArr1[i] = rand() % 2;
    }
    bitArr2 = ~bitArr1;
    qDebug() << bitArr1;
    qDebug() << bitArr2;
    qDebug() << (bitArr1 & bitArr2); // AND
    qDebug() << (bitArr1 | bitArr2); // OR
    qDebug() << (bitArr1 ^ bitArr1); // XOR
    qDebug() << (bitArr1 ^ bitArr2); // XOR

    // QQueue - очередь
    // FIFO
    // Обслуживание запросов, которые не могут быть выполнены мнгновенно
    // На основе QList

    QQueue<int> queue;
    queue << 1 << 2 << 3 << 4 << 5;
    qDebug() << queue.dequeue();        // remove + return;
    qDebug() << queue;

    queue.enqueue(6);
    qDebug() << queue;

    int& head = queue.head();
    head -=7;
    qDebug() << queue;

    // QStack - стек
    // LIFO
    // Стек используется для временного сохранения состояния
    // не выполненного до конца задания. Рекурсия
    // На основе QList

    QStack<int> stack;
    stack << 1 << 2 << 3 << 4 << 5;

    stack.pop();
    qDebug() << stack;

    stack.push(6);
    qDebug() << stack;

    int& top = stack.top();

    top -= 6;
    qDebug() << stack;

    return a.exec();
}
