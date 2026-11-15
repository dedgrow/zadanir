
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>

void Sozdat(int*& ptr, int size)
{
    ptr = new int[size];
}

void Zapolnit(int* ptr, int size)
{
    for (int i = 0; i < size; i++)
    {
        ptr[i] = rand() % 21 - 10;
    }
}

void Pechat(int* ptr, int size)
{
    std::cout << "Массив: ";

    for (int i = 0; i < size; i++)
    {
        std::cout << ptr[i] << " ";
    }

    std::cout << "\nРазмер: " << size << "\n\n";
}

void UdalitMassiv(int*& ptr, int& size)
{
    delete[] ptr;
    ptr = nullptr;
    size = 0;
}

void Dobavit(int*& ptr, int& size, int element)
{
    int* noviy = new int[size + 1];

    for (int i = 0; i < size; i++)
    {
        noviy[i] = ptr[i];
    }

    noviy[size] = element;

    delete[] ptr;
    ptr = noviy;
    size++;
}

void Vstavit(int*& ptr, int& size, int element, int index)
{
    if (index < 0 || index > size)
    {
        std::cout << "Неверный индекс!\n";
        return;
    }

    int* noviy = new int[size + 1];

    for (int i = 0; i < index; i++)
    {
        noviy[i] = ptr[i];
    }

    noviy[index] = element;

    for (int i = index; i < size; i++)
    {
        noviy[i + 1] = ptr[i];
    }

    delete[] ptr;
    ptr = noviy;
    size++;
}

void UdalitElement(int*& ptr, int& size, int index)
{
    if (index < 0 || index >= size)
    {
        std::cout << "Неверный индекс!\n";
        return;
    }

    int* noviy = nullptr;

    if (size > 1)
    {
        noviy = new int[size - 1];

        for (int i = 0; i < index; i++)
        {
            noviy[i] = ptr[i];
        }

        for (int i = index + 1; i < size; i++)
        {
            noviy[i - 1] = ptr[i];
        }
    }

    delete[] ptr;
    ptr = noviy;
    size--;
}

int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    srand(time(NULL));

    int size = 5;
    int* ptr = nullptr;

    std::cout << "1. Создание массива\n";
    Sozdat(ptr, size);

    std::cout << "2. Заполнение случайными числами\n";
    Zapolnit(ptr, size);
    Pechat(ptr, size);

    std::cout << "3. Добавление числа 100 в конец\n";
    Dobavit(ptr, size, 100);
    Pechat(ptr, size);

    std::cout << "4. Вставка числа 50 по индексу 2\n";
    Vstavit(ptr, size, 50, 2);
    Pechat(ptr, size);

    std::cout << "5. Удаление элемента по индексу 3\n";
    UdalitElement(ptr, size, 3);
    Pechat(ptr, size);

    std::cout << "6. Удаление массива\n";
    UdalitMassiv(ptr, size);

    if (ptr == nullptr)
    {
        std::cout << "Память освобождена!\n";
    }

    return 0;
}
