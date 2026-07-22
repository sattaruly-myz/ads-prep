# 1. Stack (стек)

## Идея

Стек работает по правилу **LIFO** (*Last In, First Out*): последним положили — первым достали. Представь стопку тарелок: взять можно только верхнюю.

Основные операции:

- `push(x)` — положить `x` наверх;
- `pop()` — удалить верхний элемент;
- `top()` — посмотреть верхний элемент, не удаляя его;
- `empty()` — проверить, пуст ли стек.

В C++ обычно используют `std::stack<int>`. У него нет итераторов: это сознательно ограничивает доступ верхушкой.

```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << s.top() << '\n'; // 30
    s.pop();                      // удалили 30
    std::cout << s.top() << '\n'; // 20
}
```

`push`, `pop`, `top` и `empty` работают за `O(1)` амортизированно/обычно; память для `n` элементов — `O(n)`. Нельзя делать `top()` или `pop()` у пустого стека: сначала проверяй `empty()`.

## Собственная реализация на `vector`

```cpp
#include <stdexcept>
#include <vector>

class IntStack {
    std::vector<int> data;
public:
    void push(int x) { data.push_back(x); }
    void pop() {
        if (data.empty()) throw std::out_of_range("empty stack");
        data.pop_back();
    }
    int top() const {
        if (data.empty()) throw std::out_of_range("empty stack");
        return data.back();
    }
    bool empty() const { return data.empty(); }
};
```

## Где применяется

Стек нужен для вызовов функций, обхода графа DFS, проверки скобок, вычисления выражений и операции Undo/Redo.

Пример проверки скобок: открывающую скобку кладём в стек, для закрывающей проверяем, совпадает ли она с верхушкой.

```cpp
#include <stack>
#include <string>

bool balanced(const std::string& text) {
    std::stack<char> s;
    for (char c : text) {
        if (c == '(' || c == '[' || c == '{') s.push(c);
        else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) return false;
            char open = s.top(); s.pop();
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) return false;
        }
    }
    return s.empty();
}
```

## Запомни

У стека есть одна доступная сторона — **top**. Если нужна работа с началом и концом, это уже `deque`.

## Самопроверка

1. Какое значение останется на вершине после `push(1), push(2), pop(), push(3)`?
2. Реализуй функцию, которая переворачивает строку с помощью стека.
3. Почему проверка скобок занимает `O(n)`, а не `O(n²)`?
