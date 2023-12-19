#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <openssl/sha.h>
#include <openssl/evp.h>

// Функция получения данных от пользователя
std::string getUserData() {
    std::string data;
    std::cout << "Введите данные: ";
    std::getline(std::cin, data);
    return data;
}

// Функция чтения внешнего ресурса из файла
std::vector<char> readExternalResource(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    // Получаем размер файла
    file.seekg(0, std::ios::end);
    std::streamsize fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // Проверяем, что размер файла не равен 0
    if (fileSize <= 0) {
        std::cerr << "Ошибка: файл " << filename << " пуст." << std::endl;
        exit(EXIT_FAILURE);
    }

    // Создаем вектор с нужным размером и считываем данные
    std::vector<char> data(fileSize);
    file.read(data.data(), fileSize);

    // Здесь проверки хэш-значения и ЭЦП ресурса (Пока не сделал)

    return data;
}

// Функция обработки данных
void processData(std::vector<char>& data) {
    // Здесь код обработки данных (Надо сделать)

    // Шифруем данные (AES)
    unsigned char aesKeyData[16] = { 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef, 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef };
    std::vector<char> encryptedData(data.size());

    // Вставить функцию encryptAES

    // Хэшируем данные (SHA-256)
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(data.data()), data.size(), hash);
}

int main() {
    setlocale(LC_ALL, "Russian");
    // Запрос данных у пользователя
    std::string userData = getUserData();

    // Чтение внешних ресурсов
    std::vector<char> resourceData = readExternalResource("C:\\Users\\Антон\\source\\repos\\maisabpo2\\x64\\Debug\\external_resource.dat");

    // Обработка данных
    processData(resourceData);

    // Очистка буфера памяти
    std::fill(resourceData.begin(), resourceData.end(), 0);

    std::cout << "Программа выполнена успешно." << std::endl;

    return 0;
}
