1. 
Clang, проверка:
```
kamil in ~ λ clang --version
clang version 20.1.3
Target: x86_64-pc-windows-msvc
Thread model: posix
InstalledDir: C:\Program Files\LLVM\bin
```

1.1 Если нет, скачайте установщик с github
https://github.com/llvm/llvm-project/releases
я установил LLVM-20.1.3-win64.exe



2. Зайти в корень проекта и сделать:
mkdir build
cd build

3. Если винда, и мы в vs code, скачиваем три базовых расширения для C++, cmake, conan.

4. В Vs Code, нажать  Ctrl + Shift + P, и написать:
 CMake: Configure

сделать базовую конфигурацию на clang, и выбрать конфигуратор CMake [Это обязательно, и наче будут приколы как на первой фото, на второй норм вариант]
(То есть, все зависимости видны через cmake/clang и VS Code понимает, что и как подключено, и не будет визуальных ошибок.

## 📦 Требования

- **Clang** ≥ 20.1.3

Проверка:
```bash
clang --version
```

Пример вывода:
```
clang version 20.1.3
Target: x86_64-pc-windows-msvc
Thread model: posix
InstalledDir: C:\Program Files\LLVM\bin
```

Если не установлен, скачать отсюда:  
👉 [LLVM Releases](https://github.com/llvm/llvm-project/releases)

> Я установил: `LLVM-20.1.3-win64.exe`

---

## 🛠️ Сборка проекта

1. Перейти в корень проекта:

```bash
mkdir build
cd build
```

2. Установить расширения в **VS Code**:

- `C/C++` (ms-vscode.cpptools)
- `CMake Tools` (ms-vscode.cmake-tools)
- `Conan` (conan-conan-vscode)

3. В **VS Code** нажмите `Ctrl + Shift + P` → **CMake: Configure**

Настройка: выбрать `Clang` в качестве компилятора и CMake-конфигуратор. Это критично, иначе возможны проблемы с отображением зависимостей и кода.

---

## ⚙️ Сборка

Находясь в папке `build`, выполнить:

```bash
conan install .. --build=missing --profile=default -of .

cmake .. -G Ninja -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Release

cmake --build .
```

Пример успешной сборки:

```bash
kamil in ~\FerriteLabsEngine\build λ cmake --build .
[4/4] Linking CXX executable EngineMain.exe
```

---

Поддержка Mac/Linux в скором времени будет сделана
