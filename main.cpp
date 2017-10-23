#include <experimental/filesystem>
#include <iostream>
#include <cstring>

using namespace std;
namespace fs = std::experimental::filesystem;
using std::endl;

int getDirSize(string dirAddress, double size) {
    for(auto& p: fs::directory_iterator(dirAddress)) {
      //Проверка на то, является ли файл, размер которого мы хотим узнать, директорией
      if(fs::is_directory(p)) {
        fs::path nextDir = p;
        getDirSize(nextDir, size);
      }
      else {
        size = size + file_size(p);
      }
    }
    return size;
};

void GetInfo(string path) {
    //Проверка на существование репозитория
    if(!fs::exists(path)) {
      throw runtime_error("Такой директории не существует!!!");
    }
    //Проверка на то, является ли файл директорией
    if(!fs::is_directory(path)) {
      throw runtime_error("Это не директория!!!");
    }
    //Имя директории
    fs::path dirPath = path;
    fs::path textDir = dirPath.filename();
    //Дата модификации
    auto ftime = fs::last_write_time(dirPath);
    time_t cftime = decltype(ftime)::clock::to_time_t(ftime);

    //Вывод данных о директории
    cout << " " << endl;
    cout << "Имя директории: " << textDir << endl;
    cout << "Размер: " << double(getDirSize(dirPath, 0))/1000 << " Kb" << endl;
    cout << " " << endl;
};

int main() {
    try {
        string path;
        cout << "Укажите дирректорию:" << endl;
        cin >> path;

      GetInfo(path);

    } catch(const std::exception& e) {
        cout << e.what() << endl;
    }
}
