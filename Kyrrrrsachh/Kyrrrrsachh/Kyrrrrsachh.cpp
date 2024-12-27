#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <locale.h>
#include <string.h>
#include <string>



FILE* f;
void menu() {

    printf("======================================================= \n");
    printf("1) Случайный неориентированный граф\n");
    printf("2) Случайный ориентированный граф\n");
    printf("3) Задать вручную неориентированный граф\n");
    printf("4) Задать вручную ориентированный граф\n");
    printf("5) Вывести титульный лист заново\n");
    printf("6) Выход из программы\n");
    printf("======================================================= \n");
}



void RandNeOrientGraf(int** matrix, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrix[i][j] = 0;
            }
            if (i < j) {
                if (rand() % 100 > 50) {
                    matrix[i][j] = rand() % 15;
                }
                else {
                    matrix[i][j] = 0;
                }
                matrix[j][i] = matrix[i][j];
            }
        }
    }
}

void titulniyList() {
    printf("\n");
    printf(" Министерство наука и высшего образования Российской Федерации\n");
    printf(" Пензенский государственный университет\n");
    printf(" Кафедра «Вычислительная кафедра»\n");

    printf("\n\n");
    printf(" КУРСОВОЙ ПРОЕКТ\n");
    printf(" по дисциплине:\n ЛОГИКА И ОСНОВЫ АЛГОРИТМИЗАЦИИ В ИНЖЕНЕРНЫХ ЗАДАЧАХ\n");
    printf(" тема проекта:\n РЕАЛИЗАЦИЯ АЛГОРИТМА ДЕЙКСТРЫ\n ");



    printf("\n\n\n");
    printf(" Выполнил:\n");
    printf(" студент группы 23ВВВ2\n");
    printf(" Федоров Б.М.\n");
    printf("\n\n");
    printf(" Приняла:\n");
    printf(" Юрова О.В.\n");
    printf("\n\n\n");
    printf(" Пенза 2024\n");





    time_t startTime = time(nullptr);

    while (difftime(time(nullptr), startTime) < 5) {}
    system("cls");
}

void RandOrientGraf(int** matrix, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrix[i][j] = 0;
            }
            if (i < j) {
                if (rand() % 100 > 50) {
                    matrix[i][j] = rand() % 10;
                    if (rand() % 100 > 50)
                        matrix[j][i] = 0;
                    else
                        matrix[j][i] = matrix[i][j];
                }
                else
                    if (rand() % 100 > 50) {
                        matrix[j][i] = rand() % 10;
                        matrix[i][j] = 0;
                    }
                    else {
                        matrix[i][j] = 0;
                        matrix[j][i] = 0;
                    }
            }
        }
}


void NeOrGraf(int** matrix, int n, int temp) {
    using namespace std;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++) {

            bool flag = 0;

            do
            {
                string value;
                value.resize(5);
                printf("Введите расстояние %d - %d (от 0 до 9999): ", i + 1, j + 1);

                getline(cin, value);

                flag = 0;


                for (int i = 0; i < value.size(); i++)
                {
                    if (!isdigit(value[i]) || isspace(value[i]))
                        flag = 1;
                }

                if (!flag)
                {
                    if (std::atoi(value.c_str()) > 9999)
                        flag = 1;
                    if (value.size() == 0)
                        flag = 1;
                }

                if (flag == 1)
                {
                    std::cout << "!!! Введите корректные данные!" << std::endl << endl;
                }
                else
                {
                    temp = std::atoi(value.c_str());
                    break;
                }
            } while (flag);

            matrix[i][j] = temp;
            matrix[j][i] = temp;
        }
    }
}


void OrGraf(int** matrix, int n, int temp) {
    using namespace std;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
            
                bool flag = 0;

                do
                {
                    string value;
                    value.resize(5);
                    printf("Введите расстояние %d - %d (от 0 до 9999): ", i + 1, j + 1);

                    getline(cin, value);

                    flag = 0;


                    for (int i = 0; i < value.size(); i++)
                    {
                        if (!isdigit(value[i]) || isspace(value[i]))
                            flag = 1;
                    }

                    if (!flag)
                    {
                        if (std::atoi(value.c_str()) > 9999)
                            flag = 1;
                        if (value.size() == 0)
                            flag = 1;
                    }

                    if (flag == 1)
                    {
                        std::cout << "!!! Введите корректные данные!" << std::endl << endl;
                    }
                    else
                    {
                        temp = std::atoi(value.c_str());
                        break;
                    }
                } while (flag);

                matrix[i][j] = temp;
            
        }
    }
}

void vivodGrafa(int** G, int n) {
    f = fopen("рез.txt", "w");
    printf("   ");
    fprintf(f, "   ");
    for (int i = 0; i < n; i++) {
        printf("%4d", i + 1);
        fprintf(f, "%5d", i + 1);
    }
    printf("\n\n");
    fprintf(f, "\n\n");
    for (int i = 0; i < n; i++) {
        printf("%3d", i + 1);
        fprintf(f, "%3d", i + 1);
        for (int j = 0; j < n; j++) {

            printf("%4d", G[i][j]);
            fprintf(f, "%5d", G[i][j]);
        }
        printf("\n");
        fprintf(f, "\n");
        
    }
    printf("\n");
}

void Vershini(int** G, int n, int* minimalrast, int* pos) {
    for (int i = 0; i < n; i++) {
        minimalrast[i] = 10000;
        pos[i] = -1;       //вершины помечаются непосещенными
    }
}

void Algoritm(int** G, int start_index, int n, int min, int s, int* pos, int* minimalrast, int temp) {
    minimalrast[start_index] = 0;
    do {
        min = 10000; // значение минимального веса расстояния
        s = 10000; // значение для хранения индекса вершины с минимальным весом расстояния
        for (int i = 0; i < n; i++) {
            if ((pos[i] == -1) && (minimalrast[i] < min)) {   // Если вершину ещё не обошли и вес меньше min
                min = minimalrast[i];// Обновляем min на минимальный вес
                s = i; // Запоминаем индекс вершины с минимальным расстоянием
            }
        }

        if (s != 10000) { // если нашли путь с минимальным расстоянием
            for (int i = 0; i < n; i++) { // обновляем вес для соседних вершин
                if (G[s][i] > 0) { // налчие ребра между вериной s и вершиной i
                    temp = min + G[s][i];       // вычисление веса для вершины i
                    if (temp < minimalrast[i]) {    // если новый вес меньше текущего веса i
                        minimalrast[i] = temp; // обновляем минимальный вес i
                    }
                }

            }
            pos[s] = 0;  //вершина помечается посещенной
        }
    } while (s < 10000);//пока не будут обработаны все вершины
    printf("\nКратчайшие расстояния от вершины %d до остальных вершин\n", start_index + 1);
    fprintf(f, "\nКратчайшие расстояния от вершины %d до остальных вершин\n", start_index + 1);
    for (int i = 0; i < n; i++) {
        if (minimalrast[i] == 10000) {// Проверяем, является ли минимальный вес для вершины i недостижимым
            printf("(недостижима)  ");// Если недостижима, выводим сообщение в консоль
        }
        else {
            printf("%7d ", minimalrast[i]);// Если достижима, выводим минимальный вес
        }
        if (minimalrast[i] == 10000) {
            fprintf(f, "(недостижима)  "); // Если недостижима, записываем сообщение в файл
        }
        else {
            fprintf(f, "%7d ", minimalrast[i]); // Если достижима, записываем минимальный вес в файл
        };
    }
    printf("\n\nПроизведена запись в файл(рез.txt)\n", start_index + 1);
}

int main() {
    int num = 0, min = NULL, s = NULL;
    int** G;	// указатель на указатель на строку элементов
    int* minimalrast, * pos, start_index;
    int n = 0, temp = NULL, start = NULL, save;
    int value = 0;

    int count;
    setlocale(LC_ALL, "rus");

    using namespace std;

    titulniyList();

    while (true) {
        system("cls");
        menu();

        
        bool flag = 0;

        do
        {
            string value;
            value.resize(5);
            cout << "Введите номер операции ( 1 < номер < 6 ): ";

            getline(cin, value);

            flag = 0;

            if (value[0] == '0')
                flag = 1;

            for (int i = 0; i < value.size(); i++)
            {
                if (!isdigit(value[i]) || isspace(value[i]))
                    flag = 1;
            }

            if (!flag)
            {
                if (value.size() == 0 && std::atoi(value.c_str()) == 0)
                    flag = 1;
                if (std::atoi(value.c_str()) > 6)
                    flag = 1;
            }

            if (flag == 1)
            {
                std::cout << "!!! Введите корректные данные!" << std::endl << endl;
                
            }
            else
            {
                num = std::atoi(value.c_str());
                break;
            }
        } while (flag);

        

        if (num == 1) {
            system("cls");

            bool flag = 0;

            do
            {
                string value;
                value.resize(5);
                cout << "Введите размер графа (от 2 до 500): ";

                getline(cin, value);

                flag = 0;

                if (value[0] == '0')
                    flag = 1;

                for (int i = 0; i < value.size(); i++)
                {
                    if (!isdigit(value[i]) || isspace(value[i]))
                        flag = 1;
                }

                if (!flag)
                {
                    if (value.size() == 1 && std::atoi(value.c_str()) == 1)
                        flag = 1;
                    if (std::atoi(value.c_str()) > 500)
                        flag = 1;
                    if (value.size() == 0)
                        flag = 1;
                }

                if (flag == 1)
                {
                    std::cout << "!!! Введите корректные данные!" << std::endl << endl;
                }
                else
                {
                    n = std::atoi(value.c_str());
                    break;
                }
            } while (flag);


            G = (int**)malloc(n * sizeof(int*));
            for (int i = 0; i < n; i++) {
                G[i] = (int*)malloc(n * sizeof(int));
            }
            minimalrast = (int*)malloc(n * sizeof(int));
            pos = (int*)malloc(n * sizeof(int));
            
            RandNeOrientGraf(G, n);
            vivodGrafa(G, n);

            flag = 0;

            do
            {
                string value;
                value.resize(5);
                cout << "Введите номер вершины: ";

                getline(cin, value);

                flag = 0;

                if (value[0] == '0')
                    flag = 1;

                for (int i = 0; i < value.size(); i++)
                {
                    if (!isdigit(value[i]) || isspace(value[i]))
                        flag = 1;
                }

                if (!flag)
                {
                    if (value.size() == 0 && std::atoi(value.c_str()) == 0)
                        flag = 1;
                    if (std::atoi(value.c_str()) > n)
                        flag = 1;
                }

                if (flag == 1)
                {
                    std::cout << "!!! Вершина отсутствует. Введите другую!" << std::endl << endl;
                    
                }
                else
                {
                    start_index = std::atoi(value.c_str());
                    break;
                }
            } while (flag);

            start_index--;
            Vershini(G, n, minimalrast, pos);
            Algoritm(G, start_index, n, min, s, pos, minimalrast, temp);
            
            printf("\nДля продолжения нажмите любую кнопку...");
            for (int i = 0; i < n; i++) {
                free(G[i]);
            }
            free(G);
            free(minimalrast);
            free(pos);
            getchar();
            getchar();
        }

        if (num == 2) {
            system("cls");

            bool flag = 0;

            do
            {
                string value;
                value.resize(5);
                cout << "Введите размер графа (от 2 до 500): ";

                getline(cin, value);

                flag = 0;

                if (value[0] == '0')
                    flag = 1;

                for (int i = 0; i < value.size(); i++)
                {
                    if (!isdigit(value[i]) || isspace(value[i]))
                        flag = 1;
                }

                if (!flag)
                {
                    if (value.size() == 1 && std::atoi(value.c_str()) == 1)
                        flag = 1;
                    if (std::atoi(value.c_str()) > 500)
                        flag = 1;
                    if (value.size() == 0)
                        flag = 1;
                }

                if (flag == 1)
                {
                    
                    std::cout << "!!! Введите корректные данные!" << std::endl << endl;
                }
                else
                {
                    n = std::atoi(value.c_str());
                    break;
                }
            } while (flag);

            G = (int**)malloc(n * sizeof(int*));
            for (int i = 0; i < n; i++) {
                G[i] = (int*)malloc(n * sizeof(int));
            }
            minimalrast = (int*)malloc(n * sizeof(int));
            pos = (int*)malloc(n * sizeof(int));
            
            RandOrientGraf(G, n);
            vivodGrafa(G, n);

            flag = 0;

            do
            {
                string value;
                value.resize(5);
                cout << "Введите номер вершины: ";

                getline(cin, value);

                flag = 0;

                if (value[0] == '0')
                    flag = 1;

                for (int i = 0; i < value.size(); i++)
                {
                    if (!isdigit(value[i]) || isspace(value[i]))
                        flag = 1;
                }

                if (!flag)
                {
                    if (value.size() == 0 && std::atoi(value.c_str()) == 0)
                        flag = 1;
                    if (std::atoi(value.c_str()) > n)
                        flag = 1;
                }

                if (flag == 1)
                {
                    std::cout << "!!! Вершина отсутствует. Введите другую!" << std::endl << endl;
                    
                }
                else
                {
                    start_index = std::atoi(value.c_str());
                    break;
                }
            } while (flag);

            start_index--;
            Vershini(G, n, minimalrast, pos);
            Algoritm(G, start_index, n, min, s, pos, minimalrast, temp);
            
            printf("\nДля продолжения нажмите любую кнопку...");
            for (int i = 0; i < n; i++) {
                free(G[i]);
            }
            free(G);
            free(minimalrast);
            free(pos);
            getchar();
            getchar();
        }

        if (num == 3) {
            system("cls");
            bool flag = 0;

            do
            {
                string value;
                value.resize(5);
                cout << "Введите размер графа (от 2 до 500): ";

                getline(cin, value);

                flag = 0;

                if (value[0] == '0')
                    flag = 1;

                for (int i = 0; i < value.size(); i++)
                {
                    if (!isdigit(value[i]) || isspace(value[i]))
                        flag = 1;
                }

                if (!flag)
                {
                    if (value.size() == 1 && std::atoi(value.c_str()) == 1)
                        flag = 1;
                    if (std::atoi(value.c_str()) > 500)
                        flag = 1;
                    if (value.size() == 0)
                        flag = 1;
                }

                if (flag == 1)
                {
                    std::cout << "!!! Введите корректные данные!" << std::endl << endl;
                }
                else
                {
                    n = std::atoi(value.c_str());
                    break;
                }
            } while (flag);

            G = (int**)malloc(n * sizeof(int*));
            for (int i = 0; i < n; i++) {
                G[i] = (int*)malloc(n * sizeof(int));
            }
            minimalrast = (int*)malloc(n * sizeof(int));
            pos = (int*)malloc(n * sizeof(int));

            
            NeOrGraf(G, n, temp);
            vivodGrafa(G, n);

            flag = 0;

            do
            {
                string value;
                value.resize(5);
                cout << "Введите номер вершины: ";

                getline(cin, value);

                flag = 0;

                if (value[0] == '0')
                    flag = 1;

                for (int i = 0; i < value.size(); i++)
                {
                    if (!isdigit(value[i]) || isspace(value[i]))
                        flag = 1;
                }

                if (!flag)
                {
                    if (value.size() == 0 && std::atoi(value.c_str()) == 0)
                        flag = 1;
                    if (std::atoi(value.c_str()) > n)
                        flag = 1;
                }

                if (flag == 1)
                {
                    std::cout << "!!! Вершина отсутствует. Введите другую!" << std::endl << endl;
                }
                else
                {
                    start_index = std::atoi(value.c_str());
                    break;
                }
            } while (flag);

            start_index--;
            Vershini(G, n, minimalrast, pos);
            Algoritm(G, start_index, n, min, s, pos, minimalrast, temp);
            
            printf("\nДля продолжения нажмите любую кнопку...");
            for (int i = 0; i < n; i++) {
                free(G[i]);
            }
            free(G);
            free(minimalrast);
            free(pos);
            getchar();
            getchar();
        }

        if (num == 4) {
            system("cls");
            bool flag = 0;

            do
            {
                string value;
                value.resize(5);
                cout << "Введите размер графа (от 2 до 500): ";

                getline(cin, value);

                flag = 0;

                if (value[0] == '0')
                    flag = 1;

                for (int i = 0; i < value.size(); i++)
                {
                    if (!isdigit(value[i]) || isspace(value[i]))
                        flag = 1;
                }

                if (!flag)
                {
                    if (value.size() == 1 && std::atoi(value.c_str()) == 1)
                        flag = 1;
                    if (std::atoi(value.c_str()) > 500)
                        flag = 1;
                    if (value.size() == 0)
                        flag = 1;
                }

                if (flag == 1)
                {
                    std::cout << "!!! Введите корректные данные!" << std::endl << endl;
                }
                else
                {
                    n = std::atoi(value.c_str());
                    break;
                }
            } while (flag);

            G = (int**)malloc(n * sizeof(int*));
            for (int i = 0; i < n; i++) {
                G[i] = (int*)malloc(n * sizeof(int));
            }
            minimalrast = (int*)malloc(n * sizeof(int));
            pos = (int*)malloc(n * sizeof(int));

            
            OrGraf(G, n, temp);
            vivodGrafa(G, n);

            flag = 0;

            do
            {
                string value;
                value.resize(5);
                cout << "Введите номер вершины: ";

                getline(cin, value);

                flag = 0;

                if (value[0] == '0')
                    flag = 1;

                for (int i = 0; i < value.size(); i++)
                {
                    if (!isdigit(value[i]) || isspace(value[i]))
                        flag = 1;
                }

                if (!flag)
                {
                    if (value.size() == 0 && std::atoi(value.c_str()) == 0)
                        flag = 1;
                    if (std::atoi(value.c_str()) > n)
                        flag = 1;
                }

                if (flag == 1)
                {
                    std::cout << "!!! Вершина отсутствует. Введите другую!" << std::endl << endl;
                }
                else
                {
                    start_index = std::atoi(value.c_str());
                    break;
                }
            } while (flag);

            start_index--;
            Vershini(G, n, minimalrast, pos);
            Algoritm(G, start_index, n, min, s, pos, minimalrast, temp);
            
            printf("\nДля продолжения нажмите любую кнопку...");
            for (int i = 0; i < n; i++) {
                free(G[i]);
            }
            free(G);
            free(minimalrast);
            free(pos);
            getchar();
            getchar();
        }


        if (num == 5) {
            system("cls");
            titulniyList();
        }

        if (num == 6) {
            break;
        }
    }
}