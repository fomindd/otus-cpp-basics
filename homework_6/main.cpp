#include "seq_container.h"
#include "list_container.h"
#include "iomanip"

int main() {

    std::cout << "Последовательный контейнер" << std::endl;
    SeqContainer<int> seq_container;

    std::cout << "Добавление в контейнер десяти элементов (0, 1 ... 9)" << std::endl;
    for (int i = 0; i < 10; i++) {
    seq_container.push_back(i);
    }
    seq_container.display();

    std::cout << "Вывод размера контейнера на экран: " << seq_container.size() << std::endl << "\n";

    std::cout << "Удаление третьего (по счёту), пятого и седьмого элементов:" << std::endl;
    seq_container.erase(2);
    seq_container.erase(3);
    seq_container.erase(4);
    seq_container.display();

    std::cout << "Добавление элемента 10 в начало контейнера:" << std::endl;
    seq_container.insert(0, 10);
    seq_container.display();

    std::cout << "Добавление элемента 20 в середину контейнера:" << std::endl;
    seq_container.insert(4, 20);
    seq_container.display();

    std::cout << "Добавление элемента 30 в конец контейнера:" << std::endl;
    seq_container.push_back(30);
    seq_container.display();



    std::cout << "Контейнер спискового типа" << std::endl;
    ListContainer<int> list_container;

    std::cout << "Добавление в контейнер десяти элементов (0, 1 ... 9):" << std::endl;
    for (int i = 0; i < 10; i++) {
    list_container.push_back(i);
    }
    list_container.display();

    std::cout << "Вывод размера контейнера на экран: " << list_container.size() << std::endl;

    std::cout << "Удаление третьего (по счёту), пятого и седьмого элементов:" << std::endl;
    list_container.erase(2);
    list_container.erase(3);
    list_container.erase(4);
    list_container.display();

    std::cout << "Добавление элемента 10 в начало контейнера:" << std::endl;
    list_container.insert(0, 10);
    list_container.display();

    std::cout << "Добавление элемента 20 в середину контейнера:" << std::endl;
    list_container.insert(4, 20);
    list_container.display();

    std::cout << "Добавление элемента 30 в конец контейнера:" << std::endl;
    list_container.push_back(30);
    list_container.display();

    return 0;
}
