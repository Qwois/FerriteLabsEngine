## 📦 Требования
- **Clang** ≥ 20.1.3


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
