# Exam System GUI + Console

A C++ Exam Management System with two interfaces:

- Console version
- Qt GUI version

It supports Admin question management and Student exam-taking with timer, scoring, and file-based persistence.

## Features

- Admin login and question CRUD (Add / View / Update / Delete)
- Student login with ID validation
- Timed exam flow
- Question shuffling
- Score calculation and pass/fail result
- Prevent duplicate exam attempts
- English/German localization support
- Shared data files:
  - `questions.txt`
  - `students.txt`
  - `results.txt`

## Tech Stack

- C++11
- Qt Widgets (GUI)
- File-based storage (`.txt`)

## Project Structure

- `app.cpp` -> Console entry point
- `main.cpp` -> Qt GUI entry point
- `Admin.h` -> Console admin logic
- `ExamTaker.h` -> Console student/exam logic
- `Question.h`, `question.cpp` -> Question model
- `examdata.h`, `examdata.cpp` -> GUI data layer
- `mainwindow.*` -> Role/language selection window
- `adminwindow.*` -> Admin GUI
- `studentwindow.*` -> Student GUI

## Build and Run (Qt GUI - Windows)

```powershell
cd C:\Users\almetr\Downloads\Projectxxxx
$env:PATH = "C:\Qt\6.10.2\mingw_64\bin;C:\Qt\Tools\mingw1310_64\bin;" + $env:PATH

cd .\build\Desktop_Qt_6_10_2_MinGW_64_bit-Debug
C:\Qt\Tools\mingw1310_64\bin\mingw32-make.exe -j4
Start-Process .\debug\ExamSystemQt.exe
