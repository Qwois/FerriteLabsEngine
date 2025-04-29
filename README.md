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

> Важный аспект, установить через python Ninja и Conan:
```
pip install conan
pip install ninja
```


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


❗Важно: --profile=default, это ваш profile conan, обычно они лежат здесь:
"C:\Users\kamil\.conan2\profiles\macos"
"C:\Users\kamil\.conan2\profiles\windows"
"C:\Users\kamil\.conan2\profiles\default"


cmake .. -G Ninja -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_BUILD_TYPE=Release

cmake --build .
```
---

Вот пример номарльного профиля conan:
```
[settings]
os=Windows
arch=x86_64
compiler=clang
compiler.version=20
compiler.libcxx=libc++
compiler.cppstd=20
compiler.runtime=dynamic
compiler.runtime_type=Release
compiler.runtime_version=v143
build_type=Release


[conf]
tools.cmake.cmaketoolchain:generator=Ninja
tools.build:compiler_executables={"c": "clang", "cpp": "clang"}
```
❗Подмечу❗
Убедитесь, что используйте именно clang, а не clang-cl, бывает такое, что для автоматизации работы, вы можете свой conan профиль скинуть ChatGPT, а он любит на свое усмотрение менять параметры.
Поэтому нельзя использовать clang-cl, так как он не поддерживает такие флаги как:
```
-isystem, -std=c++20, -O3 и тд
```

---

Пример успешной сборки:

```bash
kamil in ~\FerriteLabsEngine\build λ cmake --build .
[4/4] Linking CXX executable EngineMain.exe
```

---

Поддержка Mac/Linux в скором времени будет сделана
