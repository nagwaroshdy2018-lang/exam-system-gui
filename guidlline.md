# Run Guideline

This project has two runnable apps:
- Console app (`app.cpp` -> `app.exe`)
- Qt GUI app (`main.cpp` -> `ExamSystemQt.exe`)

## 1. Open PowerShell in project folder
```powershell
cd C:\Users\almetr\Downloads\Projectxxxx
```

## 2. Run Console App (quickest)
If `app.exe` already exists:
```powershell
.\app.exe
```

Rebuild console app if needed:
```powershell
g++ -std=c++11 -o app.exe app.cpp
.\app.exe
```

## 3. Build and Run Qt GUI App (Windows + Qt 6.10.2 MinGW)
Use these commands from project root:
```powershell
$env:PATH = "C:\Qt\6.10.2\mingw_64\bin;C:\Qt\Tools\mingw1310_64\bin;" + $env:PATH

cd .\build\Desktop_Qt_6_10_2_MinGW_64_bit-Debug
& C:\Qt\Tools\mingw1310_64\bin\mingw32-make.exe -j4
Start-Process .\debug\ExamSystemQt.exe
```

## 4. Optional: Build Qt from scratch (if build folder is broken)
From project root:
```powershell
$env:PATH = "C:\Qt\6.10.2\mingw_64\bin;C:\Qt\Tools\mingw1310_64\bin;" + $env:PATH

mkdir build-qt-win -ErrorAction SilentlyContinue
cd build-qt-win
& C:\Qt\6.10.2\mingw_64\bin\qmake.exe ..\ExamSystemQt.pro
& C:\Qt\Tools\mingw1310_64\bin\mingw32-make.exe -j4


```

## 5. Notes
- Data files used by both apps:
  - `questions.txt`
  - `students.txt`
  - `results.txt`
- Admin login:
  - Username: `admin`
  - Password: `admin`
- Student ID must be exactly 4 digits and exist in `students.txt`.
