# 7. Doubly-linked lists (двусвязные списки)

## Идея

Узел двусвязного списка хранит `prev` и `next`:

`nullptr <- [prev | value | next] <-> [prev | value | next] -> nullptr`

Можно идти вперёд и назад. Если есть указатель на конкретный узел, его удаление занимает `O(1)`: соединяем его соседей. Цена — дополнительный указатель и более сложное поддержание связей.

```cpp
#include <iostream>

struct Node {
    int value;
    Node* prev = nullptr;
    Node* next = nullptr;
};

void insertAfter(Node* node, Node* fresh) {
    fresh->prev = node;
    fresh->next = node->next;
    if (node->next) node->next->prev = fresh;
    node->next = fresh;
}

void erase(Node*& head, Node*& tail, Node* node) {
    if (node->prev) node->prev->next = node->next;
    else head = node->next;
    if (node->next) node->next->prev = node->prev;
    else tail = node->prev;
    delete node;
}
```

После `erase` указатель `node` недействителен. При удалении первого или последнего элемента обязательно обновляй `head` или `tail`. В пустом списке оба равны `nullptr`.

## Сложности

| Операция | Сложность |
|---|---:|
| вставка/удаление известного узла | `O(1)` |
| поиск по значению | `O(n)` |
| движение на один шаг в любую сторону | `O(1)` |
| доступ по индексу | `O(n)` |

## STL-вариант

В реальном коде чаще используют `std::list<int>`: он уже двусвязный и управляет памятью. Итератор указывает на узел, поэтому `list.erase(it)` — `O(1)` (если итератор уже найден), а поиск `std::find` — `O(n)`.

```cpp
#include <list>
#include <iterator>

std::list<int> values = {1, 2, 3};
auto it = values.begin();
std::advance(it, 1); // it указывает на 2; сам advance для list — O(n)
values.insert(it, 99);
values.erase(it);    // O(1), но it после erase недействителен
```

## Где применяется

История браузера (назад/вперёд), LRU-cache, текстовые редакторы и списки, где часто удаляют элементы в середине при наличии итератора.

## Самопроверка

1. Какие четыре ссылки нужно изменить при вставке узла между двумя существующими?
2. Почему двусвязный список использует больше памяти, чем односвязный?
3. Реализуй `pushFront` и `pushBack`, поддерживая корректные `head` и `tail` для пустого и непустого списка.
