# My test task from TrueConf

## Task
```shell
Необходимо:

1.заполнить случайными числами от 1 до 9 значения контейнеров vector[i] и map[i];

2.удалить случайное число элементов (не более 15) в каждом контейнере;

3.после этого провести синхронизацию, чтобы в vector и map остались только имеющиеся в обоих контейнерах элементы (дубликаты не удалять).
```

`This project was code for MACOS`

## Building and running the project
1. Download/Clone this repo

        git clone https://github.com/bMicheal42/test_task_cpp.git
        
2. `cd` into the root directory
        
        cd test_task_cpp
        
3. Use `cmake` or just `clang++ -std=c++2a main.cpp`    

### My comments
```
1. Program install random size for std::vector and std::map from 0 to MAX_SIZE_
   no explanation in the task (you can change max size in define).
2. No sorting used.
3. Added outputs for better visualization.
```
